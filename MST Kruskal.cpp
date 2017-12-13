#include<bits/stdc++.h>
#define mxn 200

using namespace std;
struct edge
{
    int u,v,w;
};

int par[mxn],node,m;
vector<edge>path;

bool cmp(edge a,edge b)
{
    return a.w<b.w;
}

int find_representator(int r)
{
    if(par[r]==r)
        return r;
    else
        return par[r]=find_representator(par[r]);
}

int mst()
{
        sort(path.begin(),path.end(),cmp);
        for(int i=1;i<=node;i++)
                par[i]=i;
        int cnt=0,min_cost=0,len;
        len=path.size();

        for(int i=0;i<len;i++)
        {
                int src=find_representator(path[i].u);
                int dis=find_representator(path[i].v);

                if(src!=dis)
                {
                        par[src]=dis;
                        cnt++;
                        min_cost+=path[i].w;

                        if(cnt==node-1)
                                break;
                }
        }

        return min_cost;
}

int main()
{
        int src,dis,cost;
        edge temp;
        printf("Enter how many nodes and edges:\n");
        scanf("%d%d",&node,&m);

        printf("Enter the source,destination and their corresponding cost:\n");
        for(int i=0;i<m;i++)
        {
                scanf("%d%d%d",&src,&dis,&cost);
                temp.u=src;
                temp.v=dis;
                temp.w=cost;
                path.push_back(temp);
        }

        printf("The minimum cost is: %d\n",mst());
        return 0;
}
