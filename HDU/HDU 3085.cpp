#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int N=805;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

int n,m;
char g[N][N];
int vis[N][N];
pii a,b,z1,z2;

bool valid1(int x,int y) {
    if(x>=1&&x<=n&&y>=1&&y<=m&&g[x][y]!='X')
        return true;
    return false;
}
bool valid2(int x,int y,int s) {
    if(abs(x-z1.first)+abs(y-z1.second)>2*s&&abs(x-z2.first)+abs(y-z2.second)>2*s)
        return true;
    else return false;
}
void bfs() {
    memset(vis,0,sizeof vis);
    queue<pii> q1,q2;
    q1.push(a),q2.push(b);
    vis[a.first][a.second]=1;
    vis[b.first][b.second]=2;
    for(int k=1;!q1.empty()&&!q2.empty();k++) {
        for(int i=0;i<3;i++) {
            for(int j=0,len=q1.size();j<len;j++) {
                int x=q1.front().first,y=q1.front().second;
                q1.pop();
                if(!valid2(x,y,k)) continue;
                for(int i=0;i<4;i++) {
                    int tx=x+dx[i],ty=y+dy[i];
                    if(valid1(tx,ty)&&valid2(tx,ty,k)&&vis[tx][ty]!=1) {
                        if(vis[tx][ty]==2) {
                            cout<<k<<endl;
                            return;
                        }
                        vis[tx][ty]=1;
                        q1.push(make_pair(tx,ty));
                    }
                }
            }
        }
        for(int j=0,len=q2.size();j<len;j++) {
            int x=q2.front().first,y=q2.front().second;
            q2.pop();
            if(!valid2(x,y,k)) continue;
            for(int i=0;i<4;i++) {
                int tx=x+dx[i],ty=y+dy[i];
                if(valid1(tx,ty)&&valid2(tx,ty,k)&&vis[tx][ty]!=2) {
                    if(vis[tx][ty]==1) {
                        cout<<k<<endl;
                        return;
                    } 
                    vis[tx][ty]=2;
                    q2.push(make_pair(tx,ty));
                }
            }
        }
    }
    cout<<-1<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        z1.first=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>g[i][j];
                if(g[i][j]=='M') a=make_pair(i,j);
                else if(g[i][j]=='G') b=make_pair(i,j);
                else if(g[i][j]=='Z') {
                    if(z1.first) z2=make_pair(i,j);
                    else z1=make_pair(i,j);
                }
            }
        }
        bfs();
    } 
    return 0;
}