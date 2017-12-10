#include<bits/stdc++.h>
#define mx 1000

using namespace std;
bool visited[mx],ap[mx];
int disc[mx],low[mx],parent[mx],nodes,t;
vector<int>Graph[mx];

void init()
{
    memset(parent,-1,sizeof(parent));
    memset(visited,0,sizeof(visited));
    memset(ap,0,sizeof(ap));
    for(int i=0;i<mx;i++)
        Graph[i].clear();
}

void dfs(int u)
{

    // Count of children in DFS Tree
    int children = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++t;

    // Go through all vertices aadjacent to this
    vector<int>::iterator i;
    for (i = Graph[u].begin(); i != Graph[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u

        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            dfs(v);

            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);

            // u is an articulation point in following cases

            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == -1 && children > 1)
               ap[u] = true;

            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != -1 && low[v] >= disc[u])
               ap[u] = true;
        }

        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}

int main()
{
    int edges;
    cin>>nodes>>edges;
    init();
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    t=0;
    for(int i=1;i<=nodes;i++)
        if(!visited[i]) dfs(i);
    for(int i=1;i<=nodes;i++)
        if(ap[i])cout<<i<<" ";
    cout<<endl;
    return 0;
}
