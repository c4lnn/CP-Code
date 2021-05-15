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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
const int N=10005;
int n,in[N],len[N],pre[N];
VI g[N];
void topo() {
    int mx=1;
    queue<int> q;
    for(int i=1;i<=n;i++) if(!in[i]) {
        q.push(i);
        len[i]=1;
    }
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(auto v:g[u]) {
            if(--in[v]==0) {
                len[v]=len[u]+1;
                mx=max(mx,len[v]);
                pre[v]=u;
                q.push(v);
            }
        }
    }
    VI res(mx);
    for(int i=0;i<mx;i++) res[i]=0x3f3f3f3f;
    for(int i=1;i<=n;i++) if(len[i]==mx) {
        VI t;
        for(int j=i;j;j=pre[j]) t.PB(j);
        reverse(ALL(t));
        for(int j=0;j<SZ(t);j++) {
            if(t[j]>res[j]) break;
            else if(t[j]<res[j]) {
                for(int k=0;k<SZ(t);k++) res[k]=t[k];
                break;
            }
        }
    }
    cout<<SZ(res)<<'\n';
    for(int i=0;i<SZ(res);i++) cout<<res[i]-1<<" \n"[i==SZ(res)-1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) {
        int k;cin>>k;
        for(int j=1;j<=k;j++) {
            int v;cin>>v;
            ++v;
            g[i].PB(v);
            ++in[v];
        }
    }
    topo();
    return 0;
}