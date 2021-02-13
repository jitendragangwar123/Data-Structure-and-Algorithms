#include<stdio.h>
#define MAX 30

//definition of edge datastructure

typedef struct edge
{
    int u,v,w;
}edge;

//definition of edgelist

typedef struct edgelist
{
    edge data[MAX];
    int n;
}edgelist;
 
edgelist elist;
 
int G[MAX][MAX],n;
edgelist spanlist;
 
//sorts edgelist array 
 
void sort()
{
    int i,j;
    edge temp;
    
    for(i=1;i<elist.n;i++)
        for(j=0;j<elist.n-1;j++)
            if(elist.data[j].w>elist.data[j+1].w)
            {
                temp=elist.data[j];
                elist.data[j]=elist.data[j+1];
                elist.data[j+1]=temp;
            }
} 

//this function is used to find cycle within graph 

void union1(int belongs[],int c1,int c2)
{
    int i;
    
    for(i=0;i<n;i++)
        if(belongs[i]==c2)
            belongs[i]=c1;
}

//Kruskal algorithm

void kruskal()
{
    int belongs[MAX],i,j,cno1,cno2;
    elist.n=0;
 
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
        {
            if(G[i][j]!=0)
            {
                elist.data[elist.n].u=i;
                elist.data[elist.n].v=j;
                elist.data[elist.n].w=G[i][j];
                elist.n++;
            }
        }
 
    sort();
    
    for(i=0;i<n;i++)
        belongs[i]=i;
    
    spanlist.n=0;
    
    for(i=0;i<elist.n;i++)
    {
        cno1=find(belongs,elist.data[i].u);
        cno2=find(belongs,elist.data[i].v);
        
        if(cno1!=cno2)
        {
            spanlist.data[spanlist.n]=elist.data[i];
            spanlist.n=spanlist.n+1;
            union1(belongs,cno1,cno2);
        }
    }
}
 
//finds cycle within 
 
int find(int belongs[],int vertexno)
{
    return(belongs[vertexno]);
}

//This function prints edges of minimum cost spanning tree and it's minimum cost

void print()
{
    int i,cost=0;
    printf("\nEdges present in the minimum Spanning Tree\n");
    for(i=0;i<spanlist.n;i++)
    {
        printf("\nFrom Vertex %d to Vertex %d with Cost %d",spanlist.data[i].u+1,spanlist.data[i].v+1,spanlist.data[i].w);
        cost=cost+spanlist.data[i].w;
    }
 
    printf("\n\nCost of the minimum spanning tree = %d\n",cost);
}

//Driver Function
 
void main()
{
    int i,j,total_cost;
    printf("Implementation of Kruskal's Minimum Spanning Tree Algorithm\n");
    printf("\nEnter number of vertices:");
    
    scanf("%d",&n);
    
    printf("\nEnter the adjacency matrix:\n");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
            
    kruskal();
    print();
}