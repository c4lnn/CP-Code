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
const int N=35;
string s;
int n,m,cnt[N];
DB dist[N];
bool st[N];
vector<pair<int,DB> > g[N];
map<string,int> mp;
bool dijkstra() {
    for(int i=1;i<=n;i++) cnt[i]=dist[i]=0,st[i]=false;
    queue<int> q;
    q.push(1);
    dist[1]=1;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        st[u]=false;
        for(int i=0;i<SZ(g[u]);i++) {
            int v=g[u][i].FI;
            DB w=g[u][i].SE;
            if(dist[v]<dist[u]*w) {
                dist[v]=dist[u]*w;
                cnt[v]++;
                if(cnt[v]>=n) return true;
                if(!st[v]) {
                    q.push(v);
                    st[v]=true;
                }
            }
        }
    }
    return false;
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    int cs=0;
    while(~scanf("%d",&n)&&n) {
        mp.clear();
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++) {
            cin>>s;
            mp[s]=i;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            cin>>s;
            int u=mp[s];
            DB w;
            scanf("%lf",&w);
            cin>>s;
            int v=mp[s];
            g[u].PB(MP(v,w));
        }
        printf("Case %d: ",++cs);
        puts(dijkstra()?"Yes":"No");
    }
    return 0;
}