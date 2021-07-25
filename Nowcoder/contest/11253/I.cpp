#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const int N=25;
const int DIR1[4][2]={1,0,0,-1,0,1,-1,0};
const int DIR2[4][2]={1,0,0,1,0,-1,-1,0};
const char C[4]={'D','L','R','U'};
char s1[N][N],s2[N][N];
bool st[N][N][N][N];
struct R {
    int x1,y1,x2,y2,d;
    R() {}
    R(int x1,int y1,int x2,int y2,int d):x1(x1),y1(y1),x2(x2),y2(y2),d(d) {}
} pre[N][N][N][N];
bool valid(char s[][N],int x,int y) {
    if(x<0||x>=20||y<0||y>=20||s[x][y]=='#') return 0;
    return 1;
}
void bfs() {
    queue<R> q;
    q.emplace(19,19,19,0,0);
    while(SZ(q)) {
        auto u=q.front();
        q.pop();
        if(u.x1==0&&u.y1==19&&u.x2==0&&u.y2==0) {
            cout<<u.d<<'\n';
            VI a;
            for(int x1=0,y1=19,x2=0,y2=0;;) {
                s1[x1][y1]='A';
                s2[x2][y2]='A';
                if(x1==19&&y1==19&&x2==19&&y2==0) break;
                R t=pre[x1][y1][x2][y2];
                a.PB(t.d);
                x1=t.x1;
                x2=t.x2;
                y1=t.y1;
                y2=t.y2;
            }
            for(int i=SZ(a)-1;~i;i--) cout<<C[a[i]];
            cout<<'\n';
            for(int i=0;i<20;i++) {
                for(int j=0;j<20;j++)  cout<<s1[i][j];
                cout<<' ';
                for(int j=0;j<20;j++) cout<<s2[i][j];
                cout<<'\n';
            }
            return;
        }
        for(int i=0;i<4;i++) {
            int tx1=u.x1+DIR1[i][0],ty1=u.y1+DIR1[i][1];
            int tx2=u.x2+DIR2[i][0],ty2=u.y2+DIR2[i][1];
            if(!valid(s1,tx1,ty1)&&!valid(s2,tx2,ty2)) continue;
            if(!valid(s1,tx1,ty1)) tx1=u.x1,ty1=u.y1;
            if(!valid(s2,tx2,ty2)) tx2=u.x2,ty2=u.y2;
            if(!st[tx1][ty1][tx2][ty2]) {
                pre[tx1][ty1][tx2][ty2]={u.x1,u.y1,u.x2,u.y2,i};
                q.emplace(tx1,ty1,tx2,ty2,u.d+1);
                st[tx1][ty1][tx2][ty2]=true;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<20;i++) {
        string s;
        getline(cin,s);
        for(int j=0;j<20;j++) s1[i][j]=s[j];
        for(int j=21;j<41;j++) s2[i][j-21]=s[j];
    }
    bfs();
    return 0;
}