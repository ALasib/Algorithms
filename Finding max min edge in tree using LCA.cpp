#include<bits/stdc++.h>
#define mx 100005
#define pii pair<int,int>
 
using namespace std;
int L[mx];
int P[mx][20];
int T[mx],n;
vector<pii>Graph[mx];
pii cost[mx][20];
 
void dfs(int from,int u,int dep)
{
       T[u]=from;
       L[u]=dep;
 
       for(int i=0;i<Graph[u].size();i++)
       {
             int v=Graph[u][i].first;
 
             if(v==from)
                continue;
 
             cost[v][0].first=cost[v][0].second=Graph[u][i].second;
             dfs(u,v,dep+1);
       }
}
 
 void lca_init()
  {
      int i, j;
 
  //we initialize every element in P with -1
      for (i = 0; i < n; i++)
          for (j = 0; 1 << j < n; j++)
              P[i][j] = -1;
 
  //the first ancestor of every node i is T[i]
      for (i = 0; i < n; i++)
          P[i][0] = T[i];
 
  //bottom up dynamic programing
      for (j = 1; 1 << j < n; j++)
         for (i = 0; i < n; i++)
             if (P[i][j - 1] != -1)
                 cost[i][j].first=min(cost[i][j-1].first,cost[P[i][j-1]][j-1].first),
                 cost[i][j].second=max(cost[i][j-1].second,cost[P[i][j-1]][j-1].second),
                 P[i][j] = P[P[i][j - 1]][j - 1];
  }
 
pii lca_query(int p, int q)
  {
      int log, i;
 
  //if p is situated on a higher level than q then we swap them
      if (L[p] < L[q])
         swap(p,q);
 
  //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= L[p]; log++);
      log--;
 
  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      pii ans;
      ans.first=2000000;
      ans.second=-ans.first;
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              ans.first=min(ans.first,cost[p][i].first),
              ans.second=max(ans.second,cost[p][i].second),
              p = P[p][i];
 
      if (p == q)
          return ans;
 
  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              ans.first=min(ans.first,min(cost[p][i].first,cost[q][i].first)),
              ans.second=max(ans.second,max(cost[p][i].second,cost[q][i].second)),
              p = P[p][i], q = P[q][i];
 
      ans.first=min(ans.first,min(cost[p][0].first,cost[q][0].first));
      ans.second=max(ans.second,max(cost[p][0].second,cost[q][0].second));
      return ans;
  }
 
  int main()
  {
      scanf("%d",&n);
      for(int i=0;i<n-1;i++)
      {
          int u,v,w;
          scanf("%d%d%d",&u,&v,&w);
          u--; v--;
          Graph[u].push_back(pii(v,w));
          Graph[v].push_back(pii(u,w));
      }
