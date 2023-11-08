#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct treenode{
    int val;
    struct treenode* left;
    struct treenode* right;
    int height;
};

typedef struct treenode* AVLTree;

int maximum(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}

AVLTree CreateNode(int val)
{
    AVLTree T=(AVLTree)malloc(sizeof(struct treenode));
    T->left=NULL;
    T->right=NULL;
    T->height=0;
    T->val=val;
    return T;
}

int height(AVLTree T)
{
    if(T==NULL)
    return -1;
    
    return T->height;
}

AVLTree SingleRotateWithLeft(AVLTree k2)
{
    AVLTree k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;

    k2->height=maximum(height(k2->left),height(k2->right))+1;
    k1->height=maximum(height(k1->left),height(k1->right))+1;

    return k1;
}

AVLTree SingleRotateWithRight(AVLTree k2)
{
    AVLTree k1=k2->right;
    k2->right= k1->left;
    k1->left=k2;

    k2->height=maximum(height(k2->left),height(k2->right))+1;
    k1->height=maximum(height(k1->left),height(k1->right))+1;

    return k1;
}

AVLTree DoubleRotateWithLeft(AVLTree k2)
{
    AVLTree k1=k2->left;
    AVLTree k3=k1->right;
    k2->left=SingleRotateWithRight(k1);
    k3=SingleRotateWithLeft(k2);
    return k3;
}

AVLTree DoubleRotateWithRight(AVLTree k2)
{
    AVLTree k1=k2->right;
    AVLTree k3=k1->left;
    k2->right=SingleRotateWithLeft(k1);
    k3=SingleRotateWithRight(k2);
    return k3;
}

AVLTree Insert(AVLTree T,int val)
{
    AVLTree newnode=CreateNode(val);
    if(T==NULL)
    {
        T=newnode;
        return T;
    }
    else
    {
        if(val>T->val)
        {
            T->right=Insert(T->right,val);
            if(height(T->right)-height(T->left)==2)
            {
                if(val>T->right->val)
                {
                    T=SingleRotateWithRight(T);
                }
                else
                {
                    T=DoubleRotateWithRight(T);
                }
            }         
            T->height=maximum(height(T->left),height(T->right))+1;
        }
        else if(val<T->val)
        {
            T->left=Insert(T->left,val);
            if(height(T->left)-height(T->right)==2)
            {
                if(val<T->left->val)
                {
                    T=SingleRotateWithLeft(T);
                }
                else
                {
                    T=DoubleRotateWithLeft(T);
                }
            }
            T->height=maximum(height(T->left),height(T->right))+1;
        }
    }
    return T;
}

// AVLTree DeleteNode(AVLTree T,int x)
// {
//     if(!Find(T,x))
//     {
//         printf("No such node exists\n");
//         return T;
//     }
//     else
//     {
        
//     }
// }

bool Find(AVLTree T,int x)
{
    if(T==NULL)
    return false;

    if(T->val==x)
    return true;

    bool y,z;
    if(x<T->val)
    y=Find(T->left,x);

    if(x>T->val)
    z=Find(T->right,x);    
}

void PrintInorder(AVLTree T)
{
    if(T==NULL)
    return;

    PrintInorder(T->left);
    printf("%d ",T->val);
    PrintInorder(T->right);
}

void PrintPreorder(AVLTree T)
{
    if(T==NULL)
    return;

    printf("%d ",T->val);
    PrintPreorder(T->left);
    PrintPreorder(T->right);
}

int main()
{
    AVLTree T=CreateNode(1);
    T=Insert(T,3);
    T=Insert(T,2);
    // T=Insert(T,4);
    // T=Insert(T,6);
    // T=Insert(T,5);
    // T=Insert(T,7);
    PrintInorder(T);
    printf("\n");
    PrintPreorder(T);
    printf("\n");

    int n;
    scanf("%d",&n);
    if(Find(T,n))
    printf("%d found!!\n",n);
    else
    printf("%d not found!!\n",n);
}