//Algorithm used: Sieve + PHI function 
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
#define MAX 5000015

using namespace std;
bool isprime[MAX+5];
unsigned long long ans[MAX+5];
vector<int>prime;

void sieve()
{
    int  i,j,x;
    x = sqrt(MAX);

    isprime[0]=false;
    isprime[1] = false;

    for(i=4;i<=MAX;i+=2)
        isprime[i] = false;

    for(i=3;i<=x;i+=2)
    {
        if(isprime[i]==true)
        {
            for(j=i*i;j<=MAX;j+=i)
                isprime[j] = false;
        }
    }
   return;
}

int main()
{
    int test,caseno=0;
    unsigned long long a,b,i,j;

    memset(isprime,true,sizeof(isprime));
    sieve();

    for ( i = 2; i <= MAX; i++)
        {
	    if(isprime[i])
            {
		prime.push_back(i);
	    }
    }

    for(i=0;i<=MAX;i++)
        ans[i]=i;

    for(i=0;i<prime.size();i++)
    {
        for(j=prime[i];j<=MAX;j+=prime[i])
             ans[j] =(((ans[j] *  (prime[i] - 1)))/ prime[i]);
    }

    for(i=1;i<=MAX;i++)
    {
        ans[i]=(ans[i]*ans[i]);
        ans[i]+=ans[i-1];
    }

    scanf("%d",&test);
    while(test--)
    {
        scanf("%llu%llu",&a,&b);
        printf("Case %d: %llu\n",++caseno,ans[b]-ans[a-1]);
    }
    return 0;
}
