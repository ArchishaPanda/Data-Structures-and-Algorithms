#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct StackInfo{
    int* arr;
    int top;
    int size;
    int nElems;
};
typedef struct StackInfo* Stack;

Stack InitStack(int size)
{
    Stack S=(struct StackInfo*)malloc(sizeof(struct StackInfo));
    S->arr=(int*)malloc(sizeof(int)*size);
    S->top=-1;
    S->nElems=0;
    S->size=size;
    return S;
}

bool isEmpty(Stack S)
{
    if(S->nElems==0)
    return true;
    else
    return false;
}

void Push(Stack S,int x)
{
    S->arr[S->top+1]=x;
    S->nElems++;
    S->top++;
}

int Pop(Stack S)
{
    int a=S->arr[S->top];
    S->top--;
    S->nElems--;
    return a;
}



struct stnode{
    int val;
    struct stnode* next;
};

struct GraphNode{
    int total_vertices;
    struct stnode** arr;
};
typedef struct GraphNode* Graph;

Graph CreateGraph(int v)
{
    Graph G=(Graph)malloc(sizeof(struct GraphNode));
    G->total_vertices=v;
    G->arr=(struct stnode**)malloc(sizeof(struct stnode*)*v);
    for(int i=0;i<v;i++)
    {
        G->arr[i]=(struct stnode*)malloc(sizeof(struct stnode));
        G->arr[i]->val=i;
        G->arr[i]->next=NULL;
    }
    return G;   
}

int edge_already_exists(Graph G,int u,int v)
{
    int flag=0;
    struct stnode* ptr=G->arr[u];
    while(ptr!=NULL)
    {
        if(ptr->val==v)
        {
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==1)
    return 1;
    else
    return 0;
}

void InsertEdge(Graph G,int u,int v)
{
    if(edge_already_exists(G,u,v)==1)
    {
        printf("Edge already exists\n");
        return;
    }
    struct stnode* newnode=(struct stnode*)malloc(sizeof(struct stnode));
    newnode->next=NULL;
    newnode->val=v;

    struct stnode* ptr=G->arr[u];
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    return;   
}

void PrintGraph(Graph G)
{
    for(int i=0;i<G->total_vertices;i++)
    {
        struct stnode* ptr=G->arr[i]->next;
        printf("%d : ",i);
        
        while(ptr!=NULL)
        {
            printf("%d ",ptr->val);
            ptr=ptr->next;
        }
        printf("\n");
    }
    printf("Graph done\n");
}

void DFS_Stack(Graph G,int startnode)
{
    int visited[G->total_vertices];
    for(int i=0;i<G->total_vertices;i++)
    {
        visited[i]=0;
    }
    Stack S=InitStack(G->total_vertices);
    Push(S,G->arr[startnode]->val);
    visited[0]=1;
    while(!isEmpty(S))
    {
        int v=Pop(S);
        printf("%d ",v);
        
        struct stnode* ptr=G->arr[v];
        ptr=ptr->next;
        while(ptr!=NULL)
        {
            if(visited[ptr->val]==0)
            {
                visited[ptr->val]=1;
                Push(S,ptr->val);
            }
            ptr=ptr->next;
        }
    }
}




int main()
{
    Graph G=CreateGraph(10);
    InsertEdge(G,0,1);
    InsertEdge(G,0,4);
    InsertEdge(G,1,2);
    InsertEdge(G,1,3);

    InsertEdge(G,2,9);
    InsertEdge(G,2,7);
    InsertEdge(G,2,8);

    InsertEdge(G,4,5);
    InsertEdge(G,4,6);

    InsertEdge(G,7,8);

    InsertEdge(G,8,3);

    InsertEdge(G,1,0);
    InsertEdge(G,4,0);
    InsertEdge(G,2,1);
    InsertEdge(G,3,1);

    InsertEdge(G,9,2);
    InsertEdge(G,7,2);
    InsertEdge(G,8,2);

    InsertEdge(G,5,4);
    InsertEdge(G,6,4);

    InsertEdge(G,8,7);

    InsertEdge(G,3,8);
    

    PrintGraph(G);
    DFS_Stack(G,0);
}



