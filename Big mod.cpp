#include<bits/stdc++.h>

using namespace std;

LL big_mod(LL base,LL power)
{
       if(!power) return 1;
       if(power==1) return base%mod;
       LL temp=big_mod(base,power/2);
       temp=(temp*temp)%mod;
       if(power%2==0) return temp;
       else return (temp*base)%mod;
}
/*power=mod-2*/
