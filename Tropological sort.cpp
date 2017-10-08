//@BEGIN OF SOURCE CODE
#include<bits/stdc++.h>

using namespace std;

void trop_sort()
{
        bool sig=1;
        for(int i=0;i<mx;i++)
        {
              if(indegree[i]==0 && graph[i].size()==0)
                   ans.push_back(i);
              else
                   s.insert(pii(indegree[i],i));
        }
 
        while(!s.empty())
        {
               pii top=*s.begin();
               s.erase(s.begin());
               if(top.first!=0)
               {
                     sig=0;
                     break;
               }
 
               ans.push_back(top.second);
               int len=graph[top.second].size();
               for(int i=0;i<len;i++)
               {
                      int v=graph[top.second][i];
                      it=s.find(pii(indegree[v],v));
                      if(it!=s.end())
                          s.erase(pii(indegree[v],v));
                      indegree[v]--;
                      s.insert(pii(indegree[v],v));
               }
        }
 
        if(sig==0)
             printf("Cycle\n");
        else
        {
              for(int i=0;i<mx;i++)
                  printf("%d",ans[i]);
              printf("\n");
        }
}
//@END OF SOURCE CODE
