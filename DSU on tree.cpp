#include<bits/stdc++.h>
#define mx 100005
#define pii pair<int,int>
 
using namespace std;
vector<int>graph[mx];
vector<pii>qur[mx];
int BC[mx],res[mx],cnt[mx],clr[mx],ans[mx],sz[mx],n,m;
bool mark[mx];
 
void getsz(int u,int p)
{
      BC[u]=-1;
      sz[u]=1;
      int best=-1;
      int len=graph[u].size();
 
      for(int i=0;i<len;i++)
      {
           int v=graph[u][i];
           if(v==p) continue;
           getsz(v,u);
           sz[u]+=sz[v];
           if(sz[v]>best)
           {
                best=sz[v];
                BC[u]=v;
           }
      }
}
 
void add(int u,int p,int x)
{
       if(x==-1)
          ans[cnt[clr[u]]]--;
       cnt[clr[u]]+=x;
       if(x==1)
            ans[cnt[clr[u]]]++;
 
       int len=graph[u].size();
       for(int i=0;i<len;i++)
       {
             int v=graph[u][i];
             if(v!=p and mark[v]==0)
                  add(v,u,x);
       }
}
 
void dfs(int u,int p,int clean)
{
      int len=graph[u].size();
      for(int i=0;i<len;i++)
      {
           int v=graph[u][i];
           if(v!=p and v!=BC[u])
               dfs(v,u,0);
      }
 
      if(BC[u]!=-1)
      {
            dfs(BC[u],u,1);
            mark[BC[u]]=1;
      }
 
      add(u,p,1);
      int len1=qur[u].size();
      for(int i=0;i<len1;i++)
      {
            pii temp=qur[u][i];
            res[temp.second]=ans[temp.first];
      }
 
      if(BC[u]!=-1)
         mark[BC[u]]=0;
 
      if(clean==0)
           add(u,p,-1);
}
 
int main()
{
      cin>>n>>m;
      for(int i=1;i<=n;i++)
         scanf("%d",&clr[i]);
      for(int i=0;i<n-1;i++)
      {
          int u,v;
          scanf("%d%d",&u,&v);
          graph[u].push_back(v);
          graph[v].push_back(u);
      }
 
      for(int i=0;i<m;i++)
      {
            int v,k;
            scanf("%d%d",&v,&k);
            qur[v].push_back(pii(k,i));
      }
 
      getsz(1,0);
      dfs(1,0,0);
      for(int i=0;i<m;i++)
          printf("%d\n",res[i]);
      return 0;
}
