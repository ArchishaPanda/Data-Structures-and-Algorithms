#include<stdio.h>
#include<stdlib.h>

struct GraphNode{
    long int** arr;
    long int total_vertices;
};
typedef struct GraphNode* Graph;

Graph CreateGraph(long int n)
{
    Graph G=(struct GraphNode*)malloc(sizeof(struct GraphNode));
    G->total_vertices=n;
    G->arr=(long int **)malloc(sizeof(long int*)*n);
    for(long int i=0;i<n;i++)
    {
        G->arr[i]=(long int*)malloc(sizeof(long int)*n);
    }

    for(long int i=0;i<n;i++)
    {
        for(long int j=0;j<n;j++)
        {
            G->arr[i][j]=0;
        }
    }
    return G;
}

void PrintGraph(Graph G)
{
    for(int i=0;i<G->total_vertices;i++)
    {
        for(int j=0;j<G->total_vertices;j++)
        {
            printf("%ld ",G->arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    long int n,m;
    long int u,v;
    scanf("%ld %ld",&n,&m);
    Graph G=CreateGraph(n);
    for(long int i=0;i<m;i++)
    {
        scanf("%ld %ld",&u,&v);

        G->arr[u-1][v-1]=1;
        G->arr[v-1][u-1]=1;
    }
    PrintGraph(G);
    //Main logic
    printf("%d ",1);
    long int* visitedPlanets=(long int*)calloc(n,sizeof(long int));
    visitedPlanets[0]=1;
    long int count=1;
    long int sourcePlanet=0;
    long int j;
    int flag;    
    while(count<n)
    {    
        flag=0;       
        for(j=0;j<n;j++)
        {
            if(G->arr[sourcePlanet][j]==1 && visitedPlanets[j]==0)
            {
                printf("%ld ",j+1);                
                visitedPlanets[j]=1;                
                count++;
                flag=1;
                break;
            }           
        }
        if(flag==1)
        sourcePlanet=j;
        else
        {
            for(long int l=0;l<n;l++)
            {
                if(G->arr[sourcePlanet][l]==1)
                {
                    sourcePlanet=l;
                    break;
                }
            }
        }
    }
    printf("\n");
}