#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
char name[100];
int rollno;
char grade;};

void Read(struct student students[],int n) {
    for(int i=0;i<n;i++) {
        printf("Enter details for student %d:\n", i+1);
        printf("Enter name: ");
        scanf("%s",students[i].name);
        printf("Enter roll number: ");
        scanf("%d",&students[i].rollno);
        printf("Enter grade: ");
        scanf(" %c",&students[i].grade);}}

void Display(struct student students[],int n) {
    for(int i=0;i<n;i++) {
        printf("Details for student %d:\n",i+1);
        printf("Name: %s\n",students[i].name);
        printf("Roll Number: %d\n",students[i].rollno);
        printf("Grade: %c\n",students[i].grade);}}

int main() {
    int n,i,j;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct student students[n];
    Read(students,n);

    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(students[j].rollno>students[j + 1].rollno) {
                struct student temp=students[j];
                students[j]=students[j+1];
                students[j+1]=temp;}}}

    printf("Sorted Student Information: \n");
    Display(students,n);

}