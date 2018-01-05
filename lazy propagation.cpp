#include<bits/stdc++.h>
#define mx 100015

int arr[mx];

using namespace std;
struct info
{
    int prop;
    int sum;
}tree[4*mx];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=arr[b];
        tree[node].prop=0;
        return;
    }

    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].prop=0;
}

void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum+=(e-b+1)*x;
        tree[node].prop+=x;
        return;
    }

    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

int query(int node,int b,int e,int i,int j,int carry)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
       return tree[node].sum+(e-b+1)*carry;

    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}

int main()
{
    int n,carry = 0;
    cout<<"Enter how many number in an array:"<<endl;
    cin>>n;
    cout<<"Please insert the elements:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    init(1,0,n-1);
    update(1,0,n-1,0,6,6);
    update(1,0,n-1,1,1,2);
    update(1,0,n-1,0,3,7);
    cout<<query(1,0,n-1,0,1,carry)<<endl;
    return 0;
}
