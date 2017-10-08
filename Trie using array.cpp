#include<bits/stdc++.h>
using namespace std;

struct prefix_trie
{
    int sz;
    struct Trie
    {
        int next[27];
        int endmark;
        void clean()
        {
            for(int i=0;i<26;i++)
                next[i] = -1;
            endmark = 0;
        }
    };

    Trie *arr = new Trie[100099];
    void init()
    {
        arr[0].clean();
        sz = 0;
    }

    void Insert(char *s)
    {
        int idx = 0;
        for(int i=0;i<s[i]; i++)
        {
            int x = s[i]-'a';
            if(arr[idx].next[x] == -1)
            {
                sz++;
                arr[sz].clean();
                arr[idx].next[x] = sz;
            }
            idx = arr[idx].next[x];
        }
        arr[idx].endmark++;
    }

    int query(char *s)
    {
        int idx = 0;
        for(int i=0;i<s[i]; i++)
        {
            int x = s[i]-'a';
            if(arr[idx].next[x] == -1)
                return 0;
            idx = arr[idx].next[x];
        }
        return arr[idx].endmark;
    }
};

int main()
{
    /*main code*/
}
