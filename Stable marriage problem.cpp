#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<stdio.h>
#define N 4

using namespace std;

bool preference(int prefer[2*N][N],int w,int m,int m1)
{
       //cout<<"ok"<<endl;
       for(int i=0;i<N;i++)
       {
               if(prefer[w][i]==m1)
                    return true;
               /*if current husband is preferable*/

               if(prefer[w][i]==m)
                    return false;

               /*if current husband is less preferable*/
       }
}

void stable_marriage(int prefer[2*N][N])
{
       int wo_partner[N];
    /*wo_partner[i] stores the husband of women n+i...initialy all the value of this array is set as -1,which means that all are free at the begining*/
       bool m_free[N];
       /*stores the availability of the men... initialy all the value of this array is set as false ,which indicates that initally all are available*/
       memset(wo_partner,-1,sizeof(wo_partner));
       memset(m_free,false,sizeof(m_free));

       int married=0;

       while(married<N)
       {
             int m;
             for(m=0;m<N;m++)
                if(!m_free[m])
                     break;

             for(int i=0;i<N and m_free[m]==false;i++)
             {
                    int w=prefer[m][i];

                    /*if the women is free*/

                    if(wo_partner[w-N]==-1)
                    {
                           wo_partner[w-N]=m;
                           m_free[m]=true;
                           married++;
                    }

                   else
                   {
                         /*if the current women is not free*/
                         int m1=wo_partner[w-N];
                         /*current partner of w*/
                         /* if the current partner is less preferable*/

                         if(preference(prefer,w,m,m1)==false)
                         {
                                wo_partner[w-N]=m;
                                m_free[m]=true;
                                m_free[m1]=false;/*frre the priveous husband*/
                         }

                   }
             }
       }

          /*print the solution*/
          cout<<"Women     Men"<<endl;
          for(int i=0;i<N;i++)
             cout<<" "<<i+N<<"\t"<<wo_partner[i]<<endl;
}

int main()
{

       int prefer[2*N][N] = { {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
      stable_marriage(prefer);

      return 0;


}
