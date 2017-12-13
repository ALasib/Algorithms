#include<bits/stdc++.h>
#define MaxE 10000
#define MaxN 100

using namespace std;
const long long inf=(long long)1e18;
long long dis[MaxN];
int par[MaxN],edge_u[MaxE],edge_v[MaxE],edge_cost[MaxE];
int src,node,edge;

void bell_man_ford()
{
    bool negative_cycle=false;
    bool update;
    dis[src]=0;

    for(int step=1;step<=node;step++)
    {
        update=false;
        for(int i=1;i<=edge;i++)
        {
            int u=edge_u[i];
            int v=edge_v[i];
            int w=edge_cost[i];

            if(dis[u]+w<dis[v])
            {
                update=true;
                if(step==node)
                    negative_cycle=true;
                dis[v]=dis[u]+w;
                par[v]=u;
            }
        }

        if(!update)
            break;
    }

    if(!negative_cycle)
    {
        for(int i=1;i<=node;i++)
            printf("shortest distance for %d is : %lld\n",i,dis[i]);
    }

    else
        printf("There is negative cycle\n");

    return;
}

int main()
{

    printf("Please enter how many nodes and edges:\n");
    scanf("%d%d",&node,&edge);
    fill(dis,dis+MaxN,inf);

    printf("Enter the connected nodes and their corressponding cost:\n");
    for(int i=1;i<=edge;i++)
        scanf("%d%d%d",&edge_u[i],&edge_v[i],&edge_cost[i]);



    printf("Enter the source node:\n");
    scanf("%d",&src);

    bell_man_ford();
    return 0;
}

