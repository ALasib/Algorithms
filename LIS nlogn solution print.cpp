#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#define mx 5000

using namespace std;
int arr[mx];
int par[mx];
int n;

struct table
{
       int val,index;
}tail_table[mx];

void print_lis(int len)
{
       set<int>s;
       s.insert(tail_table[len].val);
       int temp=tail_table[len].index;
       len--;

       while(par[temp]!=-1 and len>0)
       {
             temp=par[temp];
             int sig=arr[temp];
             s.insert(sig);
             len--;
       }

       while(!s.empty())
       {
             int k=*s.begin();
             cout<<k<<" ";
             s.erase(k);
       }
}

int lis()
{
        int len = 0;
        tail_table[0].val = INT_MIN;
        tail_table[0].index=0;

        for (int i = 1; i <= n; ++i)
        {
            if (arr[i] > tail_table[len].val)
               {
                    tail_table[++len].val = arr[i];
                    tail_table[len].index=i;

                    if(arr[i]>tail_table[1].val)
                        par[i]=tail_table[len-1].index;
               }

            else
            {
                int low = 1, high = len;

                while (low <= high)
                {
                    int mid = (low + high) >> 1;

                    if (arr[i] > tail_table[mid].val)
                        low = mid + 1;

                    else
                        high = mid - 1;
                }

                tail_table[low].val = arr[i];
                tail_table[low].index=i;

                 if(arr[i]>tail_table[1].val)
                        par[i]=tail_table[low-1].index;
            }

        }

        return len;
}

int main()
{
      while(scanf("%d",&n)==1)
      {
            for(int i=1;i<=n;i++)
                scanf("%d",&arr[i]);

            memset(par,-1,sizeof(par));

            int res=lis();
            printf("%d\n",res);
            print_lis(res);
      }

      return 0;
}
