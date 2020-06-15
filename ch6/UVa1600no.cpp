//UVa1600no.cpp
//Greatljc

#include<bits/stdc++.h>
using namespace std;

const int maxn=25;
int id[maxn][maxn],d[maxn][maxn][maxn],r,c,k;
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};

struct P
{
    int x,y,K;
    P(int x,int y,int K):x(x),y(y),K(K) {}
};

void bfs()
{
    queue<P>q;
    d[1][1][0]=0;
    P u(1,1,0);
    q.push(u);
    while(!q.empty())
    {
        P u=q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=u.x+dx[i],yy=u.y+dy[i];
            if(xx>=1&&xx<=r&&yy>=1&&yy<=c)
            {
                P v(xx,yy,u.K);
                if(id[xx][yy]==1&&v.K+1<=k&&d[xx][yy][v.K+1]==-1)
                {
                    v.K++;
                    d[xx][yy][v.K]=d[u.x][u.y][u.K]+1;
                    q.push(v);
                }
                else if(id[xx][yy]==0&&d[xx][yy][0]==-1)
                {
                    d[xx][yy][0]=d[u.x][u.y][u.K]+1;
                    v.K=0;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(d,-1,sizeof d);
        scanf("%d%d%d",&r,&c,&k);
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
               scanf("%d",&id[i][j]);
        bfs();
        printf("%d\n",d[r][c][0]);
    }
}