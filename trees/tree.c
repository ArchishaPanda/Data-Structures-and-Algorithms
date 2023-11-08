#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode{
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode* Tree;

struct QueNode{
    Tree treenode;
    struct QueNode* next;
};
struct Queue{
    struct QueNode* front;
    struct QueNode* rear;
};
typedef struct Queue* Que;

Que InitQue()
{
    Que Q=(Que)malloc(sizeof(struct Queue));
    Q->front=NULL;
    Q->rear=NULL;
    return Q;
}

bool IsEmpty(Que Q)
{
    if(Q->front==NULL && Q->rear==NULL)
        return true;
    else
        return false;
}
void Enqueue(Que Q,Tree new)
{
    struct QueNode* node=(struct QueNode*)malloc(sizeof(struct QueNode));
    node->treenode=new;
    node->next=NULL;
    if(IsEmpty(Q))
    {
        Q->front=node;
        Q->rear=node;
    }

    Q->rear->next=node;
    Q->rear=node;     
}

Tree Dequeue(Que Q)
{
    Tree val;
    if(Q->front==Q->rear)
    {
        val=Q->front->treenode;
        Q->front=NULL;
        Q->rear=NULL;
        return val;        
    }
    else if(!IsEmpty(Q))
    {
        val=Q->front->treenode;
        struct QueNode* ptr=Q->front;
        Q->front=Q->front->next;
        free(ptr);
        return val;
    }
}



Tree CreateNode(int n)
{
    Tree node=(Tree)malloc(sizeof(struct TreeNode));
    node->left=NULL;
    node->right=NULL;
    node->key=n;
    return node;
}

Tree Insert(Tree T,int n)
{
    Tree newnode=CreateNode(n);
    if(T==NULL)
    {
        T=newnode;
        return T;
    }
    
    Tree trav=T;
    Tree prev=T;
    while(trav!=NULL)
    {
        prev=trav;
        if(n<trav->key)
        trav=trav->left;
        else
        trav=trav->right;//trav=NULL prev=T
    }
    if(n<prev->key)
        prev->left=newnode;
    else
        prev->right=newnode;
    return T;
}

void inorder(Tree T)
{
    if(T==NULL)
        return;
    inorder(T->left);
    printf("%d ",T->key);
    inorder(T->right);
}
void preorder(Tree T)
{
    if(T==NULL)
        return;
    printf("%d ",T->key);
    preorder(T->left);
    preorder(T->right);
}

void postorder(Tree T)
{
    if(T==NULL)
        return;
    postorder(T->left);
    postorder(T->right);
    printf("%d ",T->key);
}

int* level_order(Tree T,int n)
{
    int* arr=(int*)malloc(sizeof(int));
    int i=0;
    Que Q=InitQue();
    Enqueue(Q,T);
    while(!IsEmpty(Q))
    {
        Tree nod=Dequeue(Q);
        // printf("%d ",nod->key);
        arr[i++]=nod->key;
        if(nod->left!=NULL)
            Enqueue(Q,nod->left);
        if(nod->right!=NULL)
            Enqueue(Q,nod->right);
    }
    return arr;
}
int findmax(int a , int b)
{
    if(a>b)
    return a;
    else
    return b;
}

int depth(Tree T)
{
   int d;
   //depth of tree=max(depth of left tree,depth of right tree)+1
   if(T->left==NULL && T->right==NULL)
   {
    return 1;
   }
   if(T->left==NULL && T->right!=NULL)
    {
        d=depth(T->right);
        return d;
    }
    if(T->left!=NULL && T->right==NULL)
    {
        d=depth(T->left);
        return d;
    }
    d=findmax(depth(T->left),depth(T->right))+1;
    return d;
}

void mirror(Tree T)
{
    if(T==NULL)
        return;

    Tree temp;
    mirror(T->left);
    mirror(T->right);
    temp=T->left;
    T->left=T->right;
    T->right=temp;
}

int identical(Tree T,Tree Q)
{
    if(T==NULL && Q==NULL)
    return 1;
    if(T!=NULL && Q==NULL)
    return 0;
    if(T==NULL && Q!=NULL)
    return 0;

    else if(T->key==Q->key && identical(T->left,Q->left)==1 && identical(T->right,Q->right)==1)
        return 1;
    else
    return 0;
}

int structure(Tree T,Tree Q)
{
    if(T->left==NULL && T->right==NULL && Q->left==NULL && Q->right==NULL && T->key==Q->key)
        return 1;
    if(identical(T->left,Q->left)==1 && identical(T->right,Q->right)==1)
        return 1;
    else
    return 0;
}

int LowestCommonAncestor(Tree T,int n,int a,int b)
{
    int *arr=level_order(T,n);
    int indexa,indexb;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==a)
        indexa=i;
        if(arr[i]==b)
        indexb=i;
    }
    int flag=0;
    while(indexa>=0 && indexb>=0 && (indexa-1)/2 != (indexb-1)/2)
    {
        if(indexa==indexb)
        {
            flag=1;
            break;
        }
        indexa=(indexa-1)/2;
        indexb=(indexb-1)/2;
    }
    if(flag==1)
    return indexa;
}

int main()
{
    Tree T=NULL;
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        T=Insert(T,x);
    }
    int lca=LowestCommonAncestor(T,n,15,25);
}