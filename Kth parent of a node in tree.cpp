#include<bits/stdc++.h>

using namespace std;
/*This function calculate the kth parent of node p*/
int Kth_par(int p,int k)
{
         int log,i;
         for (log = 1; 1 << log <= k; log++);
         log--;
 
         for (i = log; i >= 0; i--)
          if ((1 << i) <=k)
              p = P[p][i],k-=(1<<i);
          return p;
}
