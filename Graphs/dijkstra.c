// 6 9
// 1 2 7
// 1 3 1
// 1 4 2
// 2 3 5
// 2 5 1
// 3 5 4
// 3 6 3
// 4 6 1
// 5 6 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define INF 1000
struct stnode{
    int val;
    int cost;
    struct stnode* next;
};

struct GraphNode{
    int total_vertices;
    struct stnode** arr;
};
typedef struct GraphNode* Graph;

struct heapnode{
    int vertex;
    int dv_vertex;
};
struct stheap{
    struct heapnode** arr;
    int size;
    int capacity;
};
typedef struct stheap* Heap;

Graph CreateGraph(int v)
{
    Graph G=(Graph)malloc(sizeof(struct GraphNode));
    G->total_vertices=v;
    G->arr=(struct stnode**)malloc(sizeof(struct stnode*)*v);
    for(int i=0;i<v;i++)
    {
        G->arr[i]=(struct stnode*)malloc(sizeof(struct stnode));
        G->arr[i]->val=i;
        G->arr[i]->cost=-1;
        G->arr[i]->next=NULL;
    }
    return G;   
}
void InsertEdge(Graph G,int u,int v,int cost)
{
    struct stnode* newnode=(struct stnode*)malloc(sizeof(struct stnode));
    newnode->next=NULL;
    newnode->val=v;
    newnode->cost=cost;

    struct stnode* ptr=G->arr[u];
    newnode->next=ptr->next;
    ptr->next=newnode;
}

void PrintGraph(Graph G)
{
    for(int i=0;i<G->total_vertices;i++)
    {
        struct stnode* ptr=G->arr[i]->next;
        printf("%d : ",i+1);
        
        while(ptr!=NULL)
        {
            printf("%d ",ptr->val+1);
            ptr=ptr->next;
        }
        printf("\n");
    }
    printf("Graph done\n");
}

Heap CreateHeap(int capacity)
{
    Heap H=(Heap)malloc(sizeof(struct stheap));
    H->arr=(struct heapnode**)malloc(sizeof(struct heapnode*)*capacity);
    for(int i=0;i<capacity;i++)
    {
        H->arr[i]=(struct heapnode*)malloc(sizeof(struct heapnode));
    }
    H->capacity=capacity;
    H->size=0;
    return H;
}

void Insert(Heap H,int i,int dvofi)
{
    struct heapnode* x=(struct heapnode*)malloc(sizeof(struct heapnode));
    x->dv_vertex=dvofi;
    x->vertex=i;

    if(H->size==H->capacity)
    {
        printf("Heap is full\n");
        return;
    }
    int last=H->size;
    H->arr[last]=x;
    H->size++;
    int index=last;
    while(H->arr[(index-1)/2]->dv_vertex>H->arr[index]->dv_vertex)
    {
        struct heapnode* temp=H->arr[(index-1)/2];
        H->arr[(index-1)/2]=H->arr[index];
        H->arr[index]=temp;
        index=(index-1)/2;
    }
}

void minheapify(Heap H,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int smallest=i;

    if(left<H->size && H->arr[left]->dv_vertex<H->arr[i]->dv_vertex)
    smallest=left;

    if(right<H->size && H->arr[right]->dv_vertex<H->arr[smallest]->dv_vertex)
    smallest=right;

    if(smallest!=i)
    {
        struct heapnode* temp=H->arr[i];
        H->arr[i]=H->arr[smallest];
        H->arr[smallest]=temp;
        minheapify(H,smallest);
    }
}

struct heapnode* ExtractMin(Heap H)
{
    if(H->size==0)
    {
        printf("Heap is empty\n");
    }
    struct heapnode* returnvalue=H->arr[0];
    H->arr[0]=H->arr[H->size-1];
    H->size=H->size-1;
    minheapify(H,0);
    return returnvalue;
}

void decreasekey(Heap H,int newvalue,int vertex)
{
    int index;
    for(int i=0;i<H->size;i++)
    {
        if(H->arr[i]->vertex==vertex)
        {
            index=i;
            break;
        }
    }
    H->arr[index]->dv_vertex=newvalue;
    while(H->arr[index]->dv_vertex<H->arr[(index-1)/2]->dv_vertex)
    {
        struct heapnode* temp=H->arr[index];
        H->arr[index]=H->arr[(index-1)/2];
        H->arr[(index-1)/2]=temp;
        index=(index-1)/2;
    }
}

bool IsEmpty(Heap H)
{
    if(H->size==0)
    return true;

    return false;
}


void Dijkstra(Graph G,int destination)
{
    //Step 1
    int* dv=(int*)malloc(G->total_vertices*sizeof(int));
    int* pv=(int*)malloc(G->total_vertices*sizeof(int));
    int* known=(int*)malloc(G->total_vertices*sizeof(int));
    dv[0]=0;
    for(int i=0;i<G->total_vertices;i++)
    {
        pv[i]=-1;
        known[i]=0;
        if(i!=0)
        dv[i]=INF;
       
    }
    struct stnode* ptr=G->arr[0]->next;
    while(ptr!=NULL)
    {
        dv[ptr->val]=ptr->cost;
        ptr=ptr->next;
    }

    //Step 2
    Heap H=CreateHeap(G->total_vertices);
    for(int i=0;i<G->total_vertices;i++)
    {
        Insert(H,i,dv[i]);
    }

    //Step 3
    while(!IsEmpty(H))
    {
        struct heapnode* u;
        u=ExtractMin(H);
        known[u->vertex]=1;
        struct stnode* ptr=G->arr[u->vertex]->next;
        while(ptr!=NULL)
        {
            int current_cost=dv[ptr->val];
            int newcost=dv[u->vertex]+ptr->cost;
            if(known[ptr->val]==0 && newcost<current_cost)
            {
                dv[ptr->val]=newcost;
                pv[ptr->val]=u->vertex;
                decreasekey(H,newcost,ptr->val);      //what will the index be?
            }
            ptr=ptr->next;
        }
    }
    //Print
    for(int i=0;i<G->total_vertices;i++)
    {
        printf("%d ",dv[i]);
    }
    printf("\n");
}
int main()
{
    int u,v,cost;
    int n,m;
    scanf("%d %d",&n,&m);
    Graph G=CreateGraph(n);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&cost);
        InsertEdge(G,u,v,cost);
        InsertEdge(G,v,u,cost);
    }
    PrintGraph(G);
    Dijkstra(G,5);
}
    
