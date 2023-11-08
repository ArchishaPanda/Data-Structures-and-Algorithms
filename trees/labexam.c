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
    int x;
    struct QueNode* next;
};
struct QueInfo{
    struct QueNode* front;
    struct QueNode* rear;
};
typedef struct QueInfo* Queue;

Queue InitQue()
{
    Queue Q=(Queue)malloc(sizeof(struct QueInfo));
    Q->front=NULL;
    Q->rear=NULL;
    return Q;
}

bool IsEmpty(Queue Q)
{
    if(Q->front==NULL && Q->rear==NULL)
    return true;

    return false;
}

Queue Enqueue(Queue Q,int x)
{
    struct QueNode* newnode=(struct QueNode*)malloc(sizeof(struct QueNode));
    newnode->next=NULL;
    newnode->x=x;

    if(Q->front==NULL && Q->rear==NULL)
    {
        Q->front=newnode;
        Q->rear=newnode;
        return Q;
    }

    Q->rear->next=newnode;
    Q->rear=newnode;
    return Q;
}

int Dequeue(Queue* Q)
{
    struct QueNode* node=(*Q)->front;
    if((*Q)->front==(*Q)->rear)
    {
        (*Q)->front=NULL;
        (*Q)->rear=NULL;
    }

    (*Q)->front=(*Q)->front->next;
    return node->x;
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
    
    else if(n>T->key)
    T->right=Insert(T->right,n);
    else if(n<T->key)
    T->left=Insert(T->left,n);

    return T;
}

int height(Tree T)
{
    if(T==NULL)
    return 0;

    int left=height(T->left);
    int right=height(T->right);

    if(left>right)
    return left+1;
    else
    return right+1;
}

int* level_order(Tree T,int n)
{
    int* arr=(int*)malloc(sizeof(int));
    int i=0;
    Queue Q=InitQue();
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
void inorder(Tree T)
{
    if(T==NULL)
    return;

    inorder(T->left);
    printf("%d ",T->key);
    inorder(T->right);
}

void print_current_level(Tree T,int level)
{
    if(T==NULL)
    return;

    if(level==1)
    printf("%d ",T->key);

    else
    {
        print_current_level(T->right,level-1);
        print_current_level(T->left,level-1);        
    }
}
// void level_order(Tree T,int h)
// {
//     for(int i=h;i>=1;i--)
//     {
//         print_current_level(T,i);
//         printf("\n");
//     }
// }

int SearchIn(int* inorder,int x,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==x)
        return i;
    }
}
int preindex=0;
Tree ConstructBT(int startindex,int endindex,int* inorder,int* preorder)
{
    if(startindex>endindex)
    return NULL;
    int root=preorder[preindex++];
    Tree temp=(Tree)malloc(sizeof(struct TreeNode));
    temp->key=root;
    temp->left=NULL;
    temp->right=NULL;

    int index=SearchIn(inorder,temp->key,startindex,endindex);

    if(startindex==endindex)
    return temp;
    
    else
    {
        temp->left=ConstructBT(startindex,index-1,inorder,preorder);
        temp->right=ConstructBT(index+1,endindex,inorder,preorder);
        return temp;
    }
}

int level=0;
int return_level(Tree T,int x)
{   
    if(T==NULL)
    return 0;

    if(x<T->key)
    {
        level++;
        return_level(T->left,x);
    }
    else if(x>T->key)
    {
        level++;
        return_level(T->right,x);
    }

    else if(x==T->key)
    return level;
    
}

bool IsPerfect(Tree T)
{
    if(T==NULL)
    return true;

    if(T->left==NULL && T->right==NULL)
    return true;

    if(T->left==NULL && T->right!=NULL)
    return false;

    if(T->right==NULL && T->left!=NULL)
    return false;

    return(IsPerfect(T->left)&&IsPerfect(T->right));
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