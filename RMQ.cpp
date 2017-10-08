//@Begin of source code
#include<bits/stdc++.h>
#define mxn 100005
 
using namespace std;
typedef long long LL;
LL arr[mxn],n,table[mxn][40];
 
void sparse_table()
{
        LL i,j;
        //initialize table for the intervals with length 1
        for(i=0;i<n;i++)
            table[i][0]=i;
 
        //compute values from smaller to bigger intervals
         for (j = 1; 1 << j <= n; j++)
          {
                for (i = 0; i + (1 << j) - 1 < n; i++)
                {
                       if (arr[table[i][j - 1]] < arr[table[i + (1 << (j - 1))][j - 1]])
                           table[i][j] = table[i][j - 1];
                       else
                            table[i][j] = table[i + (1 << (j - 1))][j - 1];
                }
          }
}
 
LL query(LL i,LL j)
{
       LL d=j-i+1;
       LL lg=0,k=1;
       while(k*2<=d)
           k*=2,lg++;
 
       if(arr[table[i][lg]]<=arr[table[j-k+1][lg]])
             return table[i][lg];
       else
             return table[j-k+1][lg];
}
 
int main()
{
       scanf("%lld",&n);
       for(LL i=0;i<n;i++) scanf("%lld",&arr[i]);
       sparse_table();
       LL res=query(0,n-1);
       printf("%lld\n",res);
       return 0;
}
//End of source code
