#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

};
struct Node* ins(int x,struct Node* head)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=head;
    ptr->data=x;
    ptr->next=NULL;
    if(head==NULL)
        return ptr;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    return head;
}
struct Node* instart(int x,struct Node* head)
{
    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
    return head;
}
void print(struct Node* temp )
{
    if(temp==0)
        return;
    printf("%d ",temp->data);
    print(temp->next);
}


void part(int x,struct Node* head)
{
    struct Node* temp=head;
    struct Node* tail=NULL;
    struct Node* tail2=NULL;
    while(temp!=NULL)
    {
        if(temp->data<x)
            tail=ins(temp->data,tail);
        else if(temp->data==x)
            tail2=instart(temp->data,tail2);
        else
            tail2=ins(temp->data,tail2);
        temp=temp->next;
    }
    temp=tail;
    if(temp==NULL)
    {
        print(tail2);
        return ;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=tail2;
    print(tail);
}

int main()
{
    struct Node* head=NULL;
    int x;
    head=ins(1,head);
    head=ins(5,head);
    head=ins(3,head);
    head=ins(2,head);
    head=ins(4,head);
    head=ins(2,head);
    head=ins(3,head);
    print(head);
    cout<<endl;
    cin>>x;
    part(x,head);
    return 0;
}
