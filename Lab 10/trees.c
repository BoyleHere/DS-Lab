#include <stdio.h>
#include <stdlib.h>


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


void inOrderTraversal(struct TreeNode* root) {
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


void postOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    struct TreeNode* stack1[100];
    struct TreeNode* stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;

    while (top1 >= 0) {
        struct TreeNode* current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left) stack1[++top1] = current->left;
        if (current->right) stack1[++top1] = current->right;
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}


void preOrderTraversal(struct TreeNode* root) {
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


int findParent(struct TreeNode* root, int element) {
    if (root == NULL) return -1;

    if ((root->left && root->left->data == element) || (root->right && root->right->data == element)) {
        return root->data;
    }

    int leftParent = findParent(root->left, element);
    if (leftParent != -1) return leftParent;

    int rightParent = findParent(root->right, element);
    if (rightParent != -1) return rightParent;

    return -1;
}


int findDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}


int printAncestors(struct TreeNode* root, int element) {
    if (root == NULL) return 0;

    if (root->data == element) return 1;

    if (printAncestors(root->left, element) || printAncestors(root->right, element)) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}


int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("i.) In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("ii.) Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("iii.) Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    int elementToFindParent = 5;
    int parent = findParent(root, elementToFindParent);
    if (parent != -1) {
        printf("iv.) Parent of %d is: %d\n", elementToFindParent, parent);
    } else {
        printf("iv.) Parent of %d not found.\n", elementToFindParent);
    }

    printf("v.) Depth of the tree: %d\n", findDepth(root));

    int elementToFindAncestors = 5;
    printf("vi.) Ancestors of %d: ", elementToFindAncestors);
    int found = printAncestors(root, elementToFindAncestors);
    if (!found) {
        printf("Element not found.");
    }
    printf("\n");

    printf("vii.) Number of leaf nodes: %d\n", countLeafNodes(root));


    return 0;
}
