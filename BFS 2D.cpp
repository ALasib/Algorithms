void bfs()
{
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    Q.push(src);
    level[src.first][src.second]=0;
    vis[src.first][src.second]=1;
    par[src.first][src.second]=src;

    while(!Q.empty())
    {
        pii top=Q.front();
        Q.pop();
        if(top==dis)break;

        for(int i=0;i<8;i++)
        {
            int tx=top.first+fx[i];
            int ty=top.second+fy[i];

            if(tx>0 and tx<=row and ty>=1 and ty<=clmn and !vis[tx][ty])
            {
                vis[tx][ty]=1;
                level[tx][ty]=level[top.first][top.second]+1;
                par[tx][ty]=top;
                Q.push(pii(tx,ty));
            }
        }
    }
}
