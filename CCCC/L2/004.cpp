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
const int N=1005;
int ch1[N][2],ch2[N][2],a[N];
VI t1,t2,res;
void dfs1(int l,int r,int fa) {
    if(l>r) return;
    ch1[fa][a[l]>=a[fa]]=l;
    int i=l+1;
    while(i<=r&&a[i]<a[l]) ++i;
    dfs1(l+1,i-1,l);
    dfs1(i,r,l);
}
void dfs2(int l,int r,int fa) {
    if(l>r) return;
    ch2[fa][a[l]<a[fa]]=l;
    int i=l+1;
    while(i<=r&&a[i]>=a[l]) ++i;
    dfs2(l+1,i-1,l);
    dfs2(i,r,l);
}
void dfs3(int u,int ch[][2],VI &t) {
    if(u) {
        dfs3(ch[u][0],ch,t);
        t.PB(a[u]);
        dfs3(ch[u][1],ch,t);
    }
}
void dfs4(int u,int ch[][2]) {
    if(u) {
        dfs4(ch[u][0],ch);
        dfs4(ch[u][1],ch);
        res.PB(u);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) {
        if(a[i]>=a[1]) {
            dfs1(2,i-1,1);
            dfs1(i,n,1);
            break;
        }
    }
     for(int i=2;i<=n;i++) {
        if(a[i]<a[1]) {
            dfs2(2,i-1,1);
            dfs2(i,n,1);
            break;
        }
    }
    dfs3(1,ch1,t1);
    dfs3(1,ch2,t2);
    bool f1=true,f2=true;
    for(int i=1;i<SZ(t1);i++) if(t1[i]<t1[i-1]) {
        f1=false;
        break;
    }
    for(int i=1;i<SZ(t2);i++) if(t2[i]>t2[i-1]) {
        f2=false;
        break;
    }
    if(f1||f2) {
        cout<<"YES"<<'\n';
        if(f1) dfs4(1,ch1);
        else dfs4(1,ch2);
        for(int i=0;i<SZ(res);i++) cout<<a[res[i]]<<" \n"[i==SZ(res)-1];
    }
    else cout<<"NO"<<'\n';
    return 0;
}