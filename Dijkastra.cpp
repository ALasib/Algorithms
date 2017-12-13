#include<bits/stdc++.h>
#define MAX 100000
#define INF 99999999

using namespace std;
#define ll long long
#define pii pair<ll,ll>
long long dis[MAX];
int par[MAX];
vector<pii >graph[MAX];
int src,dist;

long long dijkastra()
{
    set<pii >s;
    for(int i=0;i<MAX;i++)
        dis[i]=INF;
    memset(par,-1,sizeof(par));

    s.insert(pii(0,src));
    dis[src]=0;

    while(!s.empty())
    {
        pii top=*s.begin();
        s.erase(top);
        int u=top.second;

        if(u==dist)
            return dis[u];

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i].first;
            int weight=graph[u][i].second;

            if(dis[u]+weight<dis[v])
            {
                if(dis[v]!=INF)
                    s.erase(pii(dis[v],v));
                dis[v]=dis[u]+weight;
                par[v]=u;
                s.insert(pii(dis[v],v));
            }
        }
    }

    return -1;
}

int main()
{
    int edges,nodes,i,n1,n2,cost;
    list<int>path;
    printf("Please enter how many nodes:\n");
    scanf("%d",&nodes);
    printf("Please enter how many edges:\n");
    scanf("%d",&edges);

    for(i=0;i<edges;i++)
    {
         scanf("%d%d%d",&n1,&n2,&cost);
         graph[n1].push_back(pii(n2,cost));
         graph[n2].push_back(pii(n1,cost));
    }

    printf("Please enter the source and destination:\n");
    scanf("%d%d",&src,&dist);

    long long res=dijkastra();
    if(res==-1)
        printf("There is no such path.\n");
    else
        {
            printf("The shortest distance is : %d\n",res);

            int temp=dist;
            while(par[temp]!=-1)
                {
                    path.push_back(temp);
                    temp=par[temp];
                }
            path.push_back(temp);
            reverse(path.begin(),path.end());

            printf("The shortest path is: ");
            for(list<int>::iterator it=path.begin();it!=path.end();++it)
                printf("%d ",*it);
            printf("\n");
        }
    return 0;
}



