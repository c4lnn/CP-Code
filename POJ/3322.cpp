#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

#define DEBUG cout<<"DEBUG"<<endl

typedef long long ll;
typedef unsigned long long ull;

const int N=505;
const int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
const int nxtx[3][4]={{-2,1,0,0},{-1,1,0,0},{-1,2,0,0}};
const int nxty[3][4]={{0,0,-2,1},{0,0,-1,2},{0,0,-1,1}};
const int nxtl[3][4]={{2,2,1,1},{1,1,0,0},{0,0,2,2}};

int n,m;
char s[N][N];
struct rec
{
    int x;
    int y;
    int lie;
};
rec st,ed;
int vis[N][N][3];
queue<rec>q;

void init()
{
    memset(vis,-1,sizeof vis);
    while(!q.empty()) q.pop();
}
bool valid(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m) return true;
    return false;
}
bool valid(rec a)
{
    if(!valid(a.x,a.y)) return false;
    if(a.lie==0&&s[a.x][a.y]=='.') return true;
    else if(a.lie==1&&s[a.x][a.y]!='#'&&a.y+1<=m&&s[a.x][a.y+1]!='#') return true;
    else if(a.lie==2&&s[a.x][a.y]!='#'&&a.x+1<=n&&s[a.x+1][a.y]!='#') return true;
    return false;
}
void parse_st_ed()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='O') ed.x=i,ed.y=j,ed.lie=0,s[i][j]='.';
            else if(s[i][j]=='X')
            {

                for(int k=0;k<4;k++)
                {
                    int tx=i+dx[k],ty=j+dy[k];
                    if(valid(tx,ty)&&s[tx][ty]=='X')
                    {
                         s[i][j]=s[tx][ty]='.';
                        st.x=min(i,tx),st.y=min(j,ty);
                        st.lie=k<2?1:2;
                        break;
                    }
                }
                if(s[i][j]=='X') st.x=i,st.y=j,st.lie=0,s[i][j]='.';
            }
        }
}
bool bfs()
{
    q.push(st);
    vis[st.x][st.y][st.lie]=0;
    while(!q.empty())
    {
        rec now=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int t=now.lie;
            rec temp;
            temp.x=now.x+nxtx[t][i],temp.y=now.y+nxty[t][i],temp.lie=nxtl[t][i];
            if(vis[temp.x][temp.y][temp.lie]==-1&&valid(temp))
            {
                vis[temp.x][temp.y][temp.lie]=vis[now.x][now.y][now.lie]+1;
                if(temp.x==ed.x&&temp.y==ed.y&&temp.lie==ed.lie) return true;
                q.push(temp);
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    while(cin>>n>>m&&n&&m)
    {
        init();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>s[i][j];
        parse_st_ed();
        if(bfs()) cout<<vis[ed.x][ed.y][ed.lie]<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}