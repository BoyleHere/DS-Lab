#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void iterativeInOrderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;
    struct TreeNode* stack[100];
    int top = -1;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}


void iterativePostOrderTraversal(struct TreeNode* root) {
    struct TreeNode* stack[100];
    int top = -1;
    struct TreeNode* lastVisited = NULL;

    do {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }

        while (root == NULL && top != -1) {
            root = stack[top];
            if (root->right == NULL || root->right == lastVisited) {
                printf("%d ", root->data);
                lastVisited = root;
                top--;
                root = NULL;
            } else {
                root = root->right;
            }
        }
    } while (top != -1);
}


void iterativePreOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    struct TreeNode* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* current = stack[top--];
        printf("%d ", current->data);
        if (current->right) stack[++top] = current->right;
        if (current->left) stack[++top] = current->left;
    }
}


bool findParentHelper(struct TreeNode* root, int element, int parent, int* result) {
    if (root == NULL) return false;

    if (root->data == element) {
        *result = parent;
        return true;
    }

    return findParentHelper(root->left, element, root->data, result) ||
           findParentHelper(root->right, element, root->data, result);
}


bool findParent(struct TreeNode* root, int element) {
    if (root == NULL) return false;
    if (root->data == element) {
        printf("Element is the root, it has no parent.\n");
        return true;
    }

    int parent = -1;
    int result = -1;
    if (findParentHelper(root, element, parent, &result)) {
        printf("Parent of %d is: %d\n", element, result);
        return true;
    } else {
        printf("Element not found.\n");
        return false;
    }
}


int findDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}


bool printAncestors(struct TreeNode* root, int element) {
    if (root == NULL) return false;

    if (root->data == element) return true;

    if (printAncestors(root->left, element) || printAncestors(root->right, element)) {
        printf("%d ", root->data);
        return true;
    }

    return false;
}


int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

struct TreeNode* buildBinaryTree() {
    int data;
    struct TreeNode* root = NULL;
    printf("Enter root node data (or -1 to exit): ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    root = createNode(data);
    printf("Enter left subtree of %d:\n", data);
    root->left = buildBinaryTree();
    printf("Enter right subtree of %d:\n", data);
    root->right = buildBinaryTree();
    return root;
}

int main() {
    struct TreeNode* root = NULL;
    int choice, elementToFindParent, elementToFindAncestors;

    while (1) {
        printf("\nBinary Tree Operations Menu:\n");
        printf("1. Build Binary Tree\n");
        printf("2. In-order Traversal\n");
        printf("3. Post-order Traversal\n");
        printf("4. Pre-order Traversal\n");
        printf("5. Find Parent\n");
        printf("6. Find Depth\n");
        printf("7. Find Ancestors\n");
        printf("8. Count Leaf Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Building Binary Tree:\n");
                root = buildBinaryTree();
                break;
            case 2:
                if (root) {
                    printf("In-order Traversal: ");
                    iterativeInOrderTraversal(root);
                    printf("\n");
                } else {
                    printf("Binary tree is empty. Build a tree first.\n");
                }
                break;
            case 3:
                if (root) {
                    printf("Post-order Traversal: ");
                    iterativePostOrderTraversal(root);
                    printf("\n");
                } else {
                    printf("Binary tree is empty. Build a tree first.\n");
                }
                break;
            case 4:
                if (root) {
                    printf("Pre-order Traversal: ");
                    iterativePreOrderTraversal(root);
                    printf("\n");
                } else {
                    printf("Binary tree is empty. Build a tree first.\n");
                }
                break;
            case 5:
                if (root) {
                    printf("Enter element to find its parent: ");
                    scanf("%d", &elementToFindParent);
                    findParent(root, elementToFindParent);
                } else {
                    printf("Binary tree is empty. Build a tree first.\n");
                }
                break;
            case 6:
                if (root) {
                    int depth = findDepth(root);
                    printf("Depth of the tree: %d\n", depth);
                } else {
                    printf("Binary tree is empty. Build a tree first.\n");
                }
                break;
            case 7:
                if (root) {
                    printf("Enter element to find its ancestors: ");
                    scanf("%d", &elementToFindAncestors);
                    printf("Ancestors of %d: ", elementToFindAncestors);
                    if (!printAncestors(root, elementToFindAncestors)) {
                        printf("Element not found.");
                    }
                    printf("\n");
                } else {
                    printf("Binary tree is empty. Build a tree first.\n");
                }
                break;
            case 8:
                if (root) {
                    int leafNodeCount = countLeafNodes(root);
                    printf("Number of leaf nodes: %d\n", leafNodeCount);
                } else {
                    printf("Binary tree is empty. Build a tree first.\n");
                }
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }


    return 0;
}
