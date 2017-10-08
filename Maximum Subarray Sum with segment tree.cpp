#include <bits/stdc++.h>
#define mx 50010
 
using namespace std;
struct node
{
   int sum,prefixsum;
   int suffixsum,maxsum;
};
 
node tree[4*mx];
int arr[mx];
 
void build(int index,int start,int en)
{
   if(start == en)
   {
      tree[index].sum = arr[start];
      tree[index].prefixsum = arr[start];
      tree[index].suffixsum = arr[start];
      tree[index].maxsum = arr[start];
      return;
   }
 
    int mid = (start+en)/2;
    build(2*index+1,start,mid);
    build(2*index+2,mid+1,en);
 
    tree[index].sum =
         tree[2*index+1].sum + tree[2*index+2].sum;
    tree[index].prefixsum =
         max(tree[2*index+1].prefixsum,
            tree[2*index+1].sum + tree[2*index+2].prefixsum);
    tree[index].suffixsum =
         max(tree[2*index+2].suffixsum,
            tree[2*index+2].sum + tree[2*index+1].suffixsum);
    tree[index].maxsum =
         max(tree[index].prefixsum,
            max(tree[index].suffixsum,
               max(tree[2*index+1].maxsum,
                  max(tree[2*index+2].maxsum,
                     tree[2*index+1].suffixsum
                        +tree[2*index+2].prefixsum
                     )
                  )
               )
            );
}
 
void update(int index,int start,int en,int l,int val)
{
    if(l<start || en<l)
      return;
   if(start == en)
   {
      tree[index].sum = val;
      tree[index].prefixsum = val;
      tree[index].suffixsum = val;
      tree[index].maxsum = val;
      return;
   }
 
    int mid = (start+en)/2;
    update(2*index+1,start,mid,l,val);
    update(2*index+2,mid+1,en,l,val);
 
    tree[index].sum =
         tree[2*index+1].sum + tree[2*index+2].sum;
    tree[index].prefixsum =
         max(tree[2*index+1].prefixsum,
            tree[2*index+1].sum + tree[2*index+2].prefixsum);
    tree[index].suffixsum =
         max(tree[2*index+2].suffixsum,
            tree[2*index+2].sum + tree[2*index+1].suffixsum);
    tree[index].maxsum =
         max(tree[index].prefixsum,
            max(tree[index].suffixsum,
               max(tree[2*index+1].maxsum,
                  max(tree[2*index+2].maxsum,
                     tree[2*index+1].suffixsum
                        +tree[2*index+2].prefixsum
                     )
                  )
               )
            );
}
 
node query(int index,int start,int en,int l,int r)
{
   node result;
   result.sum=result.prefixsum=INT_MIN;
   result.suffixsum=result.maxsum=INT_MIN;
 
   if(r<start || en<l)
      return result;
   if(l<=start && en<=r)
      return tree[index];
 
   int mid = (start+en)/2;
   if (l > mid)
         return query(2*index+2, mid+1, en, l, r);
   if (r <= mid)
         return query(2*index+1, start, mid, l, r);
 
   node left = query(2*index+1,start,mid,l,r);
   node right = query(2*index+2,mid+1,en,l,r);
 
   result.sum = left.sum + right.sum;
   result.prefixsum =
      max(left.prefixsum, left.sum + right.prefixsum);
   result.suffixsum =
      max(right.suffixsum, right.sum + left.suffixsum);
   result.maxsum =
      max(result.prefixsum,
         max(result.suffixsum,
            max(left.maxsum,
               max(right.maxsum,
                  left.suffixsum + right.prefixsum))));
   return result;
}
 
int main() {
   int n,m,a,b;
   scanf("%d",&n);
 
   for(int i=0;i<n;++i)
      scanf("%d",&arr[i]);
 
   build(0,0,n-1);
 
   scanf("%d",&m);
 
   for(int i=0;i<m;++i)
   {
      int op;
      scanf("%d",&op);
 
      if(op==0)
      {
           scanf("%d%d",&a,&b);
           update(0,0,n-1,a-1,b);
      }
      else
      {
           scanf("%d%d",&a,&b);
           printf("%d\n",query(0,0,n-1,a-1,b-1).maxsum);
      }
   }
   return 0;
}
