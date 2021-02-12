# include<stdio.h>
# define INF 999
# define M 6

void floyd_warshall(int [][M]);
void main(void)
{
    int matrix[M][M]=  {{0,5,6,INF,INF,INF}, 
                        {5,0,8,3,4,INF}, 
                        {6,8,0,INF,6,INF}, 
                        {INF,3,INF,0,3,7},
                        {INF,4,6,3,0,7},
                        {INF,INF,INF,7,7,0}}; 
    floyd_warshall(matrix);
    
    
}

void floyd_warshall(int matrix[][M])
{
    int graph[M][M],i,j,k;
    
    for(i=0;i<M;i++)
    {
        for(j=0;j<M;j++)
        {
            graph[i][j]=matrix[i][j];
        }
    }
    
    for(k=0;k<M;k++)
    {
        for(i=0;i<M;i++)
        {
            for(j=0;j<M;j++)
            {
                if(graph[i][k]+graph[k][j]<graph[i][j])
                    graph[i][j]=graph[i][k]+graph[k][j];
            }
        }
       
    printf("\nAdjacency Matrix:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<M;j++)
        {
            if(graph[i][j]==999)
                printf("%4s","INF");
            else
                printf("%4d",graph[i][j]);
        }
        printf("\n");
    } 
    }
}
