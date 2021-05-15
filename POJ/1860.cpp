#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=105;
int n,m,s,cnt[N];
DB v,dist[N];
bool st[N];
struct E {
    int v;
    DB r,c;
    E() {}
    E(int v,DB r,DB c):v(v),r(r),c(c) {}
};
vector<E> g[N];
bool spfa() {
    //for(int i=1;i<=n;i++) dist[i]=0,st[i]=false;
    queue<int> q;
    q.push(s);
    dist[s]=v;
    cnt[s]=1;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        st[u]=false;
        for(int i=0;i<SZ(g[u]);i++) {
            int v=g[u][i].v;
            DB r=g[u][i].r,c=g[u][i].c;
            if(dist[v]<(dist[u]-c)*r) {
                dist[v]=(dist[u]-c)*r;
                cnt[v]++;
                if(cnt[v]>=n) return true;
                if(!st[v]) st[v]=true,q.push(v);
            }
        }
    }
    return false;
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    scanf("%d%d%d%lf",&n,&m,&s,&v);
    for(int i=1;i<=m;i++) {
        int u,v;
        DB r1,c1,r2,c2;
        scanf("%d%d%lf%lf%lf%lf",&u,&v,&r1,&c1,&r2,&c2);
        g[u].PB(E(v,r1,c1));
        g[v].PB(E(u,r2,c2));
    }
    puts(spfa()?"YES":"NO");
    return 0;
}