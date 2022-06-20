//Also try middle and right alignment. This is a famous interview question
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

    int j=0;
    for(int i=0;i<len;i++)
    {
        if(i==v[j])
        {
            s+='\n';
            j++;
        }
        else
            s+=str[i];
    }

    cout<<s;
    return 0;
}
