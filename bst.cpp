#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct bst
{
    int data;
    bst *prev;
    bst *next;
};

struct bst* getnode(int x)
{
    struct bst *temp= new bst();
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
};

struct bst* insert(int x, struct bst *root)
{
    if(root==NULL)
    {
        root=getnode(x);
    }
    else if(x<=root->data)
    {
        struct bst *temp=insert(x,root->prev);
        if(root->prev==NULL)
        root->prev=temp;
    }
    else
    {
        struct bst *temp=insert(x,root->next);
        if(root->next==NULL)
        root->next=temp;
    }
    return root;

}

void search(int x,struct bst* root)
{
    static int i=1;
    if(x==root->data)
    {
        printf("\n%d found after %d iterations",x,i);
        i=1;
        return;
    }
    else if(x<root->data)
    {
        if(root->prev==NULL)
        {
            printf("\n%d not found even after %d iterations",x,i);
            i=1;
            return;
        }
        i++;
        search(x,root->prev);

    }
    else if(x>root->data)
    {
        if(root->next==NULL)
        {
            printf("\n%d not found even after %d iterations",x,i);
            i=1;
            return;
        }
        i++;
        search(x,root->next);

    }
}


void print(struct bst *root)
{

    printf("%d ",root->data);
    if(root->prev!=NULL)
    print(root->prev);
    if(root->next!=NULL)
    print(root->next);

}

int main()
{

    struct bst *root=NULL;
    root=insert(15,root);
    root=insert(10,root);
    root=insert(1,root);
    root=insert(20,root);
    root=insert(17,root);
    root=insert(25,root);
    root=insert(5,root);
    root=insert(255,root);
    root=insert(65,root);
    print(root);
    search(5,root);
    search(255,root);
    search(151,root);

    return 0;

}
