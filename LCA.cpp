//@Begin of source code
#include<bits/stdc++.h>
#define mx 1002
#define pb push_back
 
using namespace std;
int L[mx];
int P[mx][mx];
int T[mx],n;
vector<int>graph[mx];
 
void dfs(int from,int u,int dep)
{
       T[u]=from;
       L[u]=dep;
 
       for(int i=0;i<graph[u].size();i++)
       {
             int v=graph[u][i];
 
             if(v==from)
                continue;
 
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
                 P[i][j] = P[P[i][j - 1]][j - 1];
  }
 
int lca_query(int p, int q)
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
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];
 
      if (p == q)
          return p;
 
  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
 
      return T[p];
  }
 
int main()
{
       graph[0].pb(1);
       graph[0].pb(2);
       graph[2].pb(3);
       graph[2].pb(4);
       dfs(0,0,0);
       lca_init();
       printf("%d\n",lca_query(3,4));
       return 0;
}
 
//@End of source code
