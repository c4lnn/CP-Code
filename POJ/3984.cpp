#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int maze[5][5];
int move[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct Node
{
    int x;
    int y;
    int prex;
    int prey;
}s[5][5];
void bfs(int x,int y)
{
    queue<Node>q;
    s[0][0].x=0;
    s[0][0].y=0;
    q.push(s[0][0]);
    while(!q.empty())
    {
        Node temp=q.front();
        int tx=temp.x;
        int ty=temp.y;
        if(tx==4&&ty==4)
            return;
        for(int i=0;i<4;i++)
        {
            int row=tx+move[i][0];
            int col=ty+move[i][1];
            if(row>=0&&row<5&&col>=0&&col<5&&maze[row][col]!=1)
            {
                maze[row][col]=1;
                s[row][col].x=row;
                s[row][col].y=col;
                s[row][col].prex=tx;
                s[row][col].prey=ty;
                q.push(s[row][col]);
            }
        }
        q.pop();
    }
}
void print(int x,int y)
{
    if(x==0&&y==0)
    {
        printf("(%d, %d)\n",s[0][0].x,s[0][0].y);
        return;
    }
    int prex=s[x][y].prex;
    int prey=s[x][y].prey;
    print(prex,prey);
    printf("(%d, %d)\n",s[x][y].x,s[x][y].y);
}
int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin>>maze[i][j];
    bfs(0,0);
    print(4,4);
    return 0;
}