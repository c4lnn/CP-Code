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
//head
const int N=1e6+5;
char s[N];
int n,sa[N],id[N],rk[N],oldrk[N<<1],cnt[N],ht[N];
void DA() {
    int m=200; // 初始最大排名
    for(int i=1;i<=m;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) ++cnt[rk[i]=s[i]];
    for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
    for(int w=1,p;w<n;w<<=1,m=p) {
        p=0;
        for(int i=n;i>n-w;i--) id[++p]=i;
        for(int i=1;i<=n;i++) if(sa[i]>w) id[++p]=sa[i]-w;
        for(int i=1;i<=m;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) ++cnt[rk[id[i]]];
        for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for(int i=n;i>=1;i--) sa[cnt[rk[id[i]]]--]=id[i];
        for(int i=1;i<=n;i++) oldrk[i]=rk[i];
        p=0;
        for(int i=1;i<=n;i++)
            rk[sa[i]]=(oldrk[sa[i]]==oldrk[sa[i-1]]&&oldrk[sa[i]+w]==oldrk[sa[i-1]+w])?p:++p;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s+1;
    n=strlen(s+1);
    DA();
    for(int i=1;i<=n;i++) cout<<sa[i]<<" \n"[i==n];
    return 0;
}