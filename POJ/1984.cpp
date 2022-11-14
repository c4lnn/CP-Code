#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=10005;
int dx[N<<2],dy[N<<2],fa[N<<2],res[N];
struct R {
    int a,b,l;
    char d;
    R() {}
    R(int a,int b,int l,char d):a(a),b(b),l(l),d(d) {}
}r[N<<2];
struct Q {
    int a,b,c,id;
    Q() {}
    Q(int a,int b,int c,int id):a(a),b(b),c(c),id(id) {}
    bool operator < (const Q &a) const {
        return c<a.c;
    }
}q[N];
int find(int x) {
    if(x==fa[x]) return x;
    int root=find(fa[x]);
    dx[x]+=dx[fa[x]];
    dy[x]+=dy[fa[x]];
    return fa[x]=root;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) {
        int a,b,l;
        char s[2];
        scanf("%d%d%d%s",&a,&b,&l,s);
        r[i]=R(a,b,l,s[0]);
    }
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        q[i]=Q(a,b,c,i);
    }
    sort(q+1,q+1+k);
    int cnt=1;
    for(int i=1;i<=m;i++) {
        int x=r[i].a,y=r[i].b;
        int tx=find(x),ty=find(y);
        fa[tx]=ty;
        if(r[i].d=='N') {
            dx[tx]=dx[y]-dx[x];
            dy[tx]=dy[y]-dy[x]+r[i].l;
        } else if(r[i].d=='S') {
            dx[tx]=dx[y]-dx[x];
            dy[tx]=dy[y]-dy[x]-r[i].l;
        } else if(r[i].d=='E') {
            dx[tx]=dx[y]-dx[x]+r[i].l;
            dy[tx]=dy[y]-dy[x];
        } else if(r[i].d=='W') {
            dx[tx]=dx[y]-dx[x]-r[i].l;
            dy[tx]=dy[y]-dy[x];
        }
        while(q[cnt].c==i) {
            int tx=find(q[cnt].a),ty=find(q[cnt].b);
            if(tx!=ty) {
                res[q[cnt].id]=-1;
            } else {
                res[q[cnt].id]=abs(dx[q[cnt].a]-dx[q[cnt].b])+abs(dy[q[cnt].a]-dy[q[cnt].b]);
            }
            ++cnt;
        }
    }
    for(int i=1;i<=k;i++) printf("%d\n",res[i]);
    return 0;
}