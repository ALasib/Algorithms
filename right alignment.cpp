#include<bits/stdc++.h>

using namespace std;
string str;
vector<int>v;

int main()
{
    getline(cin,str);
    int len=str.size();
    int fs;
    cin>>fs;
    string s="";
    int now=fs-1;
    while(now<len)
    {
        while(isalnum(str[now]))
            now--;
        v.push_back(now);
        now+=fs;
    }
    v.push_back(len);

    int l=v.size();
    int pre=-1;
    for(int i=0;i<l;i++)
    {
        int space=fs-(v[i]-pre);
        while(space--)
            s+=' ';
        for(int j=pre+1;j<v[i];j++)
            s+=str[j];
        pre=v[i];
        if(pre==len)
            break;
        s+='\n';
    }

    cout<<s;
    return 0;
}

