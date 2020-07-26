#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;

void ins(int x)
{
    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
}

void insend(int x)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=head;
    ptr->data=x;
    ptr->next=0;
    while(temp->next!=0)
    {
        temp=temp->next;
    } 
    temp->next=ptr;
}

void mid1(int x, int y)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=head;
    ptr->data=x;
    while(temp->data!=y)
    {
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
}

void dell()
{
    struct Node* ptr=head;
    struct Node* temp=head;
    while(ptr->next!=0)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=0;
}

void del1()
{
    struct Node* ptr=head;
    head=ptr->next;
}

void deln(int n)
{
    struct Node* ptr=head;
    int i=0;
    while(i<n-2)
    {
        ptr=ptr->next;
        i++;
    }
    struct Node* temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
}

void rev()
{
    struct Node *temp, *prev, *nex;
    temp=head;
    prev=0;
    while(temp!=0)
    {
        nex=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nex;
    }
    head=prev;

}

void print()
{
    struct Node* temp =head;
    while(temp!=0)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");

}
int main()
{
    head=0;
    ins(7);print();
    ins(6);print();
    ins(4);print();
    ins(1);print();
    insend(8);print();
    insend(9);print();
    mid1(5,4);print();
    mid1(2,1);print();
    mid1(3,2);print();
    dell();print();
    del1();print();
    deln(3);print();
    rev();print();
    rev();print();
    return 0;
}
