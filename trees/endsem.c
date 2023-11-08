#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct TreeNode{
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode* Tree;

void BoundaryLeft(Tree T)
{
    if(T==NULL)
    return;

    if(T->left)
    {   
        printf("%d ",T->key);
        BoundaryLeft(T->left);
    }
    else if(T->right)
    {   
        printf("%d ",T->key);
        BoundaryLeft(T->right);
    }
}

void BoundaryRight(Tree T)
{
    if(T==NULL)
    return;

    if(T->right)
    {   
        printf("%d ",T->key);
        BoundaryRight(T->right);
    }
    else if(T->left)
    {   
        printf("%d ",T->key);
        BoundaryLeft(T->left);
    }
}

void printleaves(Tree T)
{
    if(T==NULL)
    return;

    printleaves(T->left);
    if(T->left==NULL && T->right==NULL)
    printf("%d ",T->key);
    printleaves(T->right);
}
void BoundaryTraversal(Tree T)
{
    if(T==NULL)
    return;

    printf("%d ",T->key);
    BoundaryLeft(T->left);
    printleaves(T->left);
    printleaves(T->right);
    BoundaryRight(T->right);
}

void Mirror(Tree T)
{
    if(T==NULL)
    return;

    mirror(T->left);
    mirror(T->right);

    struct TreeNode* temp=T->left;
    T->left=T->right;
    T->right=temp;
}

bool isStructSame(Tree T1,Tree T2)
{
    if(T1==NULL && T2==NULL)
    return true;

    if(T1!=NULL && T2!=NULL && isStructSame(T1->left,T2->left) && isStructSame(T2->right,T1->right))
    return true;

    return false;
}

bool isIdentical(Tree T1,Tree T2)
{
    if(T1==NULL && T2==NULL)
    return;

    if(T1!=NULL && T2!=NULL)
    {
        if(T1->key==T2->key && isIdentical(T1->left,T2->left) && isIdentical(T1->right,T2->right))
        return true;

        return false;
    }
}

bool isMirror(Tree a,Tree b)
{
    if(a==NULL && b==NULL)
    return true;

    if(a->key==b->key && isMirror(a->left,b->right) && isMirror(a->right,b->left))
    return true;

    return false;
}