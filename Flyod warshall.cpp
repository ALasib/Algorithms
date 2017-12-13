#include<bits/stdc++.h>
#define inf 99999999
using namespace std;
int dis_matrix[110][110],next[110][110];
int src,dis,nodes,edges;

void floyd_warshall()
{
          int i,j,k;

          for(int i=1;i<=nodes;i++)
                for(int j=1;j<=nodes;j++)
                       next[i][j]=j;

          for(k=1;k<=nodes;k++)
                 for(i=1;i<=nodes;i++)
                        for(j=1;j<=nodes;j++)
                            {
                                 if(dis_matrix[i][j]>dis_matrix[i][k]+dis_matrix[k][j])
                                 {
                                         dis_matrix[i][j]=dis_matrix[i][k]+dis_matrix[k][j];
                                         next[i][j]=next[i][k];
                                 }
                           }

}

int main()
{
         int i,j,k;
         printf("Please enter how many nodes and edges:\n");
         scanf("%d%d",&nodes,&edges);

         for(int i=1;i<=nodes;i++)
              for(int j=1;j<=nodes;j++)
                    dis_matrix[i][j]=inf;

         for(int i=0;i<edges;i++)
         {
                int n1,n2,cost;
                scanf("%d%d%d",&n1,&n2,&cost);
                dis_matrix[n1][n2]=cost;
         }

         floyd_warshall();

         printf("Enter source and destination\n");
         scanf("%d%d",&src,&dis);

        printf("Minimum distance between %d and %d is: %d\n",src,dis,dis_matrix[src][dis]);
        printf("The path is:\n");

        j=src;

        while(j!=dis)
        {
                printf("%d->",j);
                j=next[j][dis];
        }

        printf("%d\n",dis);

        return 0;
}
