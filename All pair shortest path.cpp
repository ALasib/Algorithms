#include<bits/stdc++.h>
#define inf 99999999
int path[202][202];
int dis_matrix[202][202];
int nodes,edges,src,dis;

using namespace std;
long long all_pair_shortest_path()
{
    int i,j,k;
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            if(dis_matrix[i][j]!=inf && i!=j)
                path[i][j]=i;
            else
                path[i][j]=-1;
        }
    }

    for(k=0;k<nodes;k++)
    {
        for(i=0;i<nodes;i++)
        {
            for(j=0;j<nodes;j++)
            {
                if(dis_matrix[i][k]==inf || dis_matrix[k][j]==inf)
                    continue;
                if(dis_matrix[i][j]>dis_matrix[i][k]+dis_matrix[k][j])
                {
                    dis_matrix[i][j]=dis_matrix[i][k]+dis_matrix[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }

    for(i=0;i<nodes;i++)
    {
        if(dis_matrix[i][i]<0)
        {
            printf("Sorry there is negative weight cycle in the graph\n");
            exit(1);
        }
    }
    return dis_matrix[src][dis];
}

int main()
{
    int n1,n2,cost;
    for(int i=0;i<200;i++)
        for(int j=0;j<200;j++)
            dis_matrix[i][j]=inf;

    printf("Please enter how many nodes and edges:\n");
    scanf("%d%d",&nodes,&edges);

    for(int i=0;i<edges;i++)
    {
        scanf("%d%d%d",&n1,&n2,&cost);
        dis_matrix[n1][n2]=cost;
    }

    printf("Please enter the source and destination:\n");
    scanf("%d%d",&src,&dis);
    long long res=all_pair_shortest_path();

    if(res==inf)
        printf("There is no shortest path\n");
    else
    {
        printf("The shortest distance is : %lld\n",res);
        list<int>shortest_path;
        shortest_path.push_back(dis);
        int j=path[src][dis];

        while(j!=src)
        {
            shortest_path.push_back(j);
            j=path[src][j];
        }
        shortest_path.push_back(src);
        reverse(shortest_path.begin(),shortest_path.end());

        printf("The shortest path between %d and %d is : ",src,dis);
        for(list<int>::iterator it=shortest_path.begin();it!=shortest_path.end();++it)
            printf("%d ",*it);
    }

    return 0;
}

