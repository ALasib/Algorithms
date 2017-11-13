#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#define inf 1<<30

using namespace std;
int dp[(1<<15)+2];
int n;
int cost[20][20];

int Set(int mask,int pos)
{
       return mask=mask|(1<<pos);
}

bool check(int mask,int pos)
{
       return (bool) (mask&(1<<pos));
}

int bitmask_dp(int mask)
{
       if(mask==(1<<n)-1)
          return 0;

       if(dp[mask]!=-1)
          return dp[mask];

       int small=inf;

       for(int i=0;i<n;i++)
       {
             if(check(mask,i)==0)
             {
                   int price=cost[i][i];

                   for(int j=0;j<n;j++)
                       if(j!=i and check(mask,j)!=0)
                           price+=cost[i][j];

                   int temp=price+bitmask_dp(Set(mask,i));
                   small=min(small,temp);
             }
       }

       return dp[mask]=small;
}

int main()
{
       memset(dp,-1,sizeof(dp));
       cin>>n;

       for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
              scanf("%d",&cost[i][j]);

       int ans=bitmask_dp(0);
       cout<<ans<<endl;

       return 0;
}
