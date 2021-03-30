#include<bits/stdc++.h>
using namespace std;
int a,b,c,t;
int maze[50][50][50];
int dir[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
struct Node
{
    int x;
    int y;
    int z;    
    int dis;
}; 
int bfs(int x,int y,int z)
{
    queue<Node>q;
    Node now,next;
    now.x=0;
    now.y=0;
    now.z=0;
    now.dis=0;
    maze[0][0][0]=1;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        if(now.x==a-1&&now.y==b-1&&now.z==c-1)
        {
            if(now.dis<=t)
                return now.dis;
            else
                return -1;    
        }    
        for(int i=0;i<6;i++)
        {
            int tx=now.x+dir[i][0];
            int ty=now.y+dir[i][1];
            int tz=now.z+dir[i][2];
            if(tx>=0&&ty>=0&&tz>=0&&tx<a&&ty<b&&tz<c&&!maze[tx][ty][tz])
            {
                maze[tx][ty][tz]=1;
                next.x=tx;
                next.y=ty;
                next.z=tz;
                next.dis=now.dis+1;
                q.push(next);        
            }
        }
        q.pop();
    }
    return -1;
}
int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&t); 
        memset(maze,0,sizeof(maze));
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                for(int k=0;k<c;k++)
                    scanf("%d",&maze[i][j][k]);
        printf("%d\n",bfs(0,0,0));
    }
    return 0;
} 