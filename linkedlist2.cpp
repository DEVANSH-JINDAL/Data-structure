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

void print(struct Node* temp )
{
    if(temp==0)
        return;
    printf("%d",temp->data);
    print(temp->next);
}

void rprint(struct Node* temp )
{
    if(temp==0)
        return;
    rprint(temp->next);
    printf("%d",temp->data);
}

void rev(struct Node* temp)
{
    if(temp->next == 0)
    {
        head=temp;
        return;
    }

    rev(temp->next);
    temp->next->next=temp;
    temp->next=0;
}

int main()
{
    head=0;
    ins(7);print(head);
    printf("\n");
    ins(6);print(head);
    printf("\n");
    ins(5);print(head);
    printf("\n");
    ins(4);print(head);
    printf("\n");
    ins(3);print(head);
    printf("\n");
    ins(2);print(head);
    printf("\n");
    ins(1);print(head);
    printf("\n");
    rev(head);
    print(head);
    return 0;
}
