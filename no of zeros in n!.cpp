int count_zero(int n)
{
    int c=0;
    while(n!=0)
    {
       n=n/5;
       c+=n;
    }
    return c;
}
