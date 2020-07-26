#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct bin_tree
{
    int data;
    bin_tree *prev;
    bin_tree *next;
};

struct queue
{
    struct bin_tree* data;
    queue* next;
};
struct queue* head=NULL;


struct bin_tree* getnode(int x)
{
    struct bin_tree *temp= new bin_tree();
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
};

struct bin_tree* insert(int x, struct bin_tree *root)
{
    if(root==NULL)
    {
        root=getnode(x);
    }
    else if(x<=root->data)
    {
        struct bin_tree *temp=insert(x,root->prev);
        if(root->prev==NULL)
        root->prev=temp;
    }
    else
    {
        struct bin_tree *temp=insert(x,root->next);
        if(root->next==NULL)
        root->next=temp;
    }
    return root;

}
void push(struct bin_tree* x)
{
    struct queue* ptr=new queue();
    struct queue* temp=head;
    ptr->data=x;
    ptr->next=NULL;
    if(head==NULL)
        head=ptr;
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }

}

void pop()
{
    struct queue* temp=head;
    head=head->next;
    free(temp);
}

void breadth(struct bin_tree* root)
{
    if(root==NULL)
        return;
    push(root);
    //struct queue* temp=head;
    while(head!=NULL)
    {
        printf("%d ",head->data->data);
        if(head->data->prev!=NULL)push(head->data->prev);
        if(head->data->next!=NULL)push(head->data->next);
        pop();
    }

}



void print(struct bin_tree *root)
{

    printf("%d ",root->data);
    if(root->prev!=NULL)
    print(root->prev);
    if(root->next!=NULL)
    print(root->next);

}

int main()
{

    struct bin_tree *root=NULL;
    root=insert(15,root);
    root=insert(10,root);
    root=insert(1,root);
    root=insert(20,root);
    root=insert(17,root);
    root=insert(25,root);
    root=insert(5,root);
    root=insert(255,root);
    root=insert(65,root);
    root=insert(0,root);
    root=insert(0,root);
    print(root);
    printf("\n");
    breadth(root);
    return 0;

}
