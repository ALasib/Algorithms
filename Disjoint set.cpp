// @BEGIN_OF_SOURCE_CODE
#include<bits/stdc++.h>
 
int par[100],ranks[100];
 
using namespace std;
map<int,int>mymap;
 
void make_set(int n)
{
    par[n]=n;
    ranks[n]=0;
}
 
int find_representator(int n)
{
    if(par[n]==n)
        return n;
    else
    return par[n]=find_representator(par[n]);
}
 
void make_union(int a,int b)
{
    int u=find_representator(a);
    int v=find_representator(b);
 
    if(u==v)
        return;
    else
    {
        if(ranks[u]>ranks[v])
            par[v]=u;
        else if(ranks[u]<ranks[v])
            par[u]=v;
        else if(ranks[u]==ranks[v])
        {
            par[v]=u;
            ranks[u]=ranks[v]+1;
        }
    }
}
 
 
int main()
{
    int i,n,num,n1,n2;
    printf("Please enter how many numbers :\n");
    scanf("%d",&n);
 
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        mymap[num]=i+1;
        make_set(mymap[num]);
    }
 
    printf("Make union of the disjoint set :\n");
 
    while(true)
    {
        scanf("%d%d",&n1,&n2);
        if(n1==-1 || n2==-1)
            break;
        make_union(mymap[n1],mymap[n2]);
    }
 
    return 0;
}
// @END_OF_SOURCE_CODE
