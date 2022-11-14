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
const int N=2005;
int fa[N],w[N];
int find(int x) {
    if(x==fa[x]) return x;
    int root=find(fa[x]);
    w[x]^=w[fa[x]];
    return fa[x]=root;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) fa[i]=i,w[i]=0;
        bool f=false;
        for(int i=1;i<=m;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            int tx=find(x),ty=find(y);
            if(tx==ty&&!(w[x]^w[y])) {
                f=true;
            } else if(tx!=ty) {
                fa[tx]=ty;
                w[tx]=w[x]^w[y]^1;
            }
        }
        printf("Scenario #%d:\n",cs);
        puts(f?"Suspicious bugs found!":"No suspicious bugs found!");
        puts("");
    }
    return 0;
}