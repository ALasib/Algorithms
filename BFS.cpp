#include<bits/stdc++.h>

using namespace std;

int main()
{

    queue<int>que;
    bool visited[100];
    int start,level[100],parent[100];
    memset(visited,false,sizeof(visited));

    printf("\nPlease enter the starting node:");
    scanf("%d",&start);

    que.push(start);
    visited[start]=true;
    level[start]=0;

    while(!que.empty())
    {
        int front=que.front();
        printf("%d ",front);
        que.pop();

        for(vector<int>::iterator it=nodes[front].begin();it!=nodes[front].end();++it)
            if(!visited[*it])
               {
                   visited[*it]=true;
                   level[*it]=level[front]+1;
                   parent[*it]=front;
                   que.push(*it);
              }
    }
    return 0;
}
