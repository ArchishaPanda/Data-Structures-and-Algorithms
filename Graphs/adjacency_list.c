#include<stdio.h>
#include<stdlib.h>

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

void DFS(Graph G,int* visited,int vertex)
{
    if(visited[vertex]==1)
    return;

    visited[vertex]=1;
    printf("%d ",vertex);
    struct stnode* ptr=G->arr[vertex];
    while(ptr!=NULL)
    {
        DFS(G,visited,ptr->val);
        ptr=ptr->next;
    }
}

void DFSDriver(Graph G,int startvertex)
{
    int* visited=(int*)malloc(sizeof(int)*G->total_vertices);
    for(int i=0;i<G->total_vertices;i++)
    {
        visited[i]=0;
    }
    DFS(G,visited,startvertex);
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
    

    PrintGraph(G);
    DFSDriver(G,0);
}



