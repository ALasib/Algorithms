// @BEGIN_OF_SOURCE_CODE
#include<bits/stdc++.h>
#define mx 100001
 
int arr[mx];
int tree[3*mx];
using namespace std;
void init(int node,int b,int e)
{
    if(b==e)
       {
            tree[node]=arr[b];
            return;
       }
 
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
 
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
 
int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
 
void update(int node,int b,int e,int i,int new_value)
{
    if(i>e || i<b)
        return;
    if(b==e)
    {
        tree[node]=new_value;
        return;
    }
 
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    update(left,b,mid,i,new_value);
    update(right,mid+1,e,i,new_value);
    tree[node]=tree[left]+tree[right];
}
 
int main()
{
    int n;
    cout<<"Please enter how many number in an array:"<<endl;
    cin>>n;
    cout<<"Please insert the elements:"<<endl;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    init(1,1,n);
    update(1,1,n,2,0);
    cout<<query(1,1,n,1,3)<<endl;
    update(1,1,n,2,2);
    cout<<query(1,1,n,2,2)<<endl;
    return 0;
 
}
// @END_OF_SOURCE_CODE
