// @BEGIN_OF_SOURCE_CODE
#include<bits/stdc++.h>
#define mx 100010
 
using namespace std;
int tree[mx];
int arr[mx];
int n;
 
void input()
{
        int i;
        scanf("%d",&n);
 
        for(i=0;i<n;i++)
            scanf("%d",arr+i);
}
 
int query(int index)
{
        int sum=0;
        index++;
 
        while(index>0)
        {
              sum+=tree[index];
              index-=index & (-index);
        }
 
        return sum;
}
 
void update(int index,int val)
{
      index++;
 
      while(index<=n)
      {
            tree[index]+=val;
            index+=index & (-index);
      }
}
 
void construct_BIT()
{
        memset(tree,0,sizeof(tree));
 
        for(int i=0;i<n;i++)
            update(i,arr[i]);
}
 
int main()
{
       int k,m,x;
 
       input();
       construct_BIT();
 
       scanf("%d",&k);/*sum from index 0 to k*/
       printf("sum from index 0 to %d : %d\n",k,query(k));
 
       scanf("%d%d",&m,&x);/* index m have to change with value x*/
       update(m,x);
       arr[m]+=x;
 
       printf("sum from index 0 to %d : %d\n",k,query(k));
       return 0;
}
 
// @END_OF_SOURCE_CODE
