#include<bits/stdc++.h>
#define mx 1000010

using namespace std;
string text,pattern;
int fal[mx];
int len_p,len_t;

void kmp_preprocess()
{
        int len=0,k=1;
        fal[0]=0;
        len_p=pattern.size();

        while(k<len_p)
        {
                if(pattern[k]==pattern[len])
                    fal[k++]=++len;
                else
                {
                    if(len)
                        len=fal[len-1];
                    else
                        fal[k++]=0;
                }
        }

        return;
}

void kmp_match()
{
        int i=0,j=0;
        len_t=text.size();
        int cnt=0;

        while(i<len_t)
        {
                if(pattern[j]==text[i])
                {
                        i++;
                        j++;

                        if(j==len_p)
                        {
                                int res=i-len_p;
                                cnt++;
                                //printf("There is a match at index: %d\n",res);
                                j=fal[j-1];
                        }
                }

                else
                {
                        if(j)
                            j=fal[j-1];
                        else
                            i++;
                }
        }
        cout<<cnt<<endl;
        return;
}

int main()
{
        printf("Enter the text :\n");
        getline(cin,text);

        printf("Enter the pattern you want to match :\n");
        getline(cin,pattern);

        kmp_preprocess();
        kmp_match();
        return 0;
}
