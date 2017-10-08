#include<bits/stdc++.h>
#define mx 10005
 
using namespace std;
typedef long long LL;
LL arr[mx],n,m,block,ans[mx];
 
struct query
{
    LL L,R,IND;
    query(){}
    query(LL _L,LL _R,LL _IND)
    {
        L=_L; R=_R; IND=_IND;
    }
};
 
vector<query>qur;
 
bool cmp(query x,query y)
{
    if(x.L/block != y.L/block)
        return x.L/block < y.L/block;
    return x.R < y.R;
}
 
void MO()
{
    block=(LL)sqrt(n);
    sort(qur.begin(),qur.end(),cmp);
    LL currL=0,currR=0;
    LL sum=0;
 
    for(LL i=0;i<m;i++)
    {
        LL first=qur[i].L, last=qur[i].R;
 
        while(currL < first)
        {
            sum-=arr[currL];
            currL++;
        }
 
        while(currL > first)
        {
            sum+=arr[currL-1];
            currL--;
        }
 
        while(currR <= last)
        {
            sum+=arr[currR];
            currR++;
        }
 
        while(currR > last+1)
        {
            sum-=arr[currR-1];
            currR--;
        }
        ans[qur[i].IND]=sum;
    }
}
 
int main()
{
    scanf("%lld%lld",&n,&m);
    for(LL i=0;i<n;i++)scanf("%lld",&arr[i]);
    for(LL i=0;i<m;i++)
    {
        LL u,v;
        scanf("%lld%lld",&u,&v);
        qur.push_back(query(u,v,i));
    }
 
    MO();
    for(LL i=0;i<m;i++) printf("%lld\n",ans[i]);
    return 0;
}
