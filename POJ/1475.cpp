#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int,int>pii;

const int N=22;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
const char dman[]="nswe";
const char dbox[]="NSWE";

int n,m;
char s[N][N];
string fbox[N][N][4];
int vis[N][N][4];
string path[N][N];
pii man,box,ed;
struct node
{
    int x,y,dir;
    node(){}
    node(int a,int b,int c)
    {
        x=a;
        y=b;
        dir=c;
    }
};

bool valid(pii a)
{
    int x=a.first,y=a.second;
    if(x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]!='#') return true;
    else return false;
}
void prase()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='S') man=make_pair(i,j);
            else if(s[i][j]=='B') box=make_pair(i,j);
            else if(s[i][j]=='T') ed=make_pair(i,j);
        }
}
bool bfs_man(pii st,pii ed,pii box,string &seq)
{
    if(st==ed) return true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
                if(path[i][j]!="")
                    path[i][j]="";
    queue<pii>q;
    q.push(st);
    while(!q.empty())
    {
        pii now=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            pii t=make_pair(now.first+dx[i],now.second+dy[i]);
            if(t!=box&&valid(t)&&path[t.first][t.second]=="\0")
            {
                path[t.first][t.second]=path[now.first][now.second]+dman[i];
                if(t==ed)
                {
                    seq=path[t.first][t.second];
                    return true;
                }
                q.push(t);
            }
        }
    }
    return false;
}
void bfs_box()
{
    int sum_box=0;
    pair<string,int>res=make_pair("",0);
    memset(vis,-1,sizeof vis);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<4;k++)
                if(fbox[i][j][k]!="")
                    fbox[i][j][k]="";
    queue<node>q;
    for(int i=0;i<4;i++)
    {
        pii nxt_box=make_pair(box.first+dx[i],box.second+dy[i]);
        pii nxt_man=make_pair(box.first-dx[i],box.second-dy[i]);
        string seq="";
        if(valid(nxt_box)&&valid(nxt_man)&&bfs_man(man,nxt_man,box,seq)==true)
        {
            fbox[nxt_box.first][nxt_box.second][i]=seq+dbox[i];
            vis[nxt_box.first][nxt_box.second][i]=1;
            if(nxt_box==ed)
            {
                cout<<fbox[nxt_box.first][nxt_box.second][i]<<endl;
                return;
            }
            q.push(node(nxt_box.first,nxt_box.second,i));
        }
    }
    while(!q.empty())
    {
        node now=q.front();
        q.pop();
        if(make_pair(now.x,now.y)==ed) continue;
        for(int i=0;i<4;i++)
        {
            pii nxt_box=make_pair(now.x+dx[i],now.y+dy[i]);
            pii nxt_man=make_pair(now.x-dx[i],now.y-dy[i]);
            pii pre_man=make_pair(now.x-dx[now.dir],now.y-dy[now.dir]);
            string seq="";
            if(valid(nxt_box)&&bfs_man(pre_man,nxt_man,make_pair(now.x,now.y),seq)==true&&(vis[nxt_box.first][nxt_box.second][i]==-1||fbox[now.x][now.y][now.dir].length()+seq.length()+1<fbox[nxt_box.first][nxt_box.second][i].length()))
            {
                if(vis[nxt_box.first][nxt_box.second][i]==-1) q.push(node(nxt_box.first,nxt_box.second,i));
                fbox[nxt_box.first][nxt_box.second][i]=fbox[now.x][now.y][now.dir]+seq+dbox[i];
                vis[nxt_box.first][nxt_box.second][i]=vis[now.x][now.y][now.dir]+1;
                if(nxt_box==ed)
                {
                    if(res.first==""||vis[nxt_box.first][nxt_box.second][i]==res.second&&fbox[nxt_box.first][nxt_box.second][i].size()<res.first.size())
                       {
                        res.first=fbox[nxt_box.first][nxt_box.second][i];
                        res.second=vis[nxt_box.first][nxt_box.second][i];
                    }
                }
            }
        }
    }
    if(res.first=="") cout<<"Impossible."<<endl;
    else cout<<res.first<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int k=1;;k++)
    {
        cin>>n>>m;
        if(!n||!m) break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>s[i][j];
        cout<<"Maze #"<<k<<endl;
        prase();
        bfs_box();
        cout<<endl;
    }
    return 0;
}