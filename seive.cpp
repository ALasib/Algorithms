void seive()
{
    int i,j;
    int x;
    x = sqrt(n);
   
    for(i=1;i<=n;i++)
        prime[i] = true;

    prime[1] = false;

    for(i=4;i<=n;i+=2)
        prime[i] = false;

    for(i=3;i<=x;i+=2)
    {
        if(prime[i]==true)
        {
            for(j=i*i;j<=n;j+=i)
                prime[j] = false;
        }
    }

}
