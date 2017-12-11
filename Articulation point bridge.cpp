/*Articulation point bridge*/

#include<bits/stdc++.h>
#define mx 10005
#define pii pair<int,int>

using namespace std;
bool visited[mx];
int disc[mx],low[mx],parent[mx],nodes,t;
vector<int>Graph[mx];
vector<pii>ans;
map<pii,int>ap;

void init()
{
    memset(parent,-1,sizeof(parent));
    memset(visited,0,sizeof(visited));
    for(int i=0;i<mx;i++)
        Graph[i].clear();
    ans.clear();
    ap.clear();
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


            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (low[v] > disc[u])
            {
                 if(ap[pii(min(u,v),max(u,v))]==0)
                 {
                     ap[pii(min(u,v),max(u,v))]=1;
                     ans.push_back(pii(min(u,v),max(u,v)));
                 }
            }
        }

        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}


    

