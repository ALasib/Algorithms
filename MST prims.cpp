#include<bits/stdc++.h>
#define MaxN 100
#define MaxE 10000
#define ll long long
#define inf 10000000
using namespace std;

#define pii pair<ll,ll>
vector<pii >graph[MaxN+5];
int par[MaxN+5],cost[MaxN+5];
bool exist[MaxN+5];
int src,node,edge;

void mst_prims()
{

    fill(par,par+MaxN,-1);
    fill(cost,cost+MaxN,inf);
    int u;
    long long min_cost=0;
    set<pii >s;
    s.insert(pii(0,src));
    cost[src]=0;
    exist[src]=true;

    while(!s.empty())
    {
        pii top=*s.begin();
        u=top.second;
        min_cost+=cost[u];
        s.erase(s.begin());
        exist[u]=false;

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i].first;
            int w=graph[u][i].second;

            if(cost[v]==inf)
            {
                cost[v]=w;
                s.insert(pii(cost[v],v));
                par[v]=u;
                exist[v]=true;
            }

            else
            {
                if(!exist[v])
                    continue;
                else
                {
                    if(w<cost[v])
                    {
                        s.erase(pii(cost[v],v));
                        cost[v]=w;
                        exist[v]=true;
                        par[v]=u;
                        s.insert(pii(cost[v],v));
                    }
                }
            }
        }

    }

   printf("\nThe minimum distance is: %lld\n",min_cost);

    return;
}

int main()
{
    int i,n1,n2,w;
    printf("Please enter how many nodes and edges:\n");
    scanf("%d%d",&node,&edge);

    printf("Enter the edges and their cost:\n");
    for(i=0;i<edge;i++)
    {
        scanf("%d%d%d",&n1,&n2,&w);
        graph[n1].push_back(pii(n2,w));
        graph[n2].push_back(pii(n1,w));
    }

    printf("Enter a source:\n");
    scanf("%d",&src);

    mst_prims();
    return 0;
}
