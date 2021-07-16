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
int n,k,R,x[11],y[11],r[11],res;
bool a[11];
void dfs(int cur,int t) {
    if(cur==k) {
        int tot=0;
        for(int i=1;i<=n;i++) if(a[i]) ++tot;
        res=max(res,tot);
        return;
    }
    bool tt[11];
    memcpy(tt,a,sizeof a);
    for(int i=t+1;i<225;i++) {
        int tx=i/15,ty=i%15;

        for(int j=1;j<=n;j++)
            if((tx-x[j])*(tx-x[j])+(ty-y[j])*(ty-y[j])<=(R+r[j])*(R+r[j]))
                a[j]=true;
        dfs(cur+1,i);
        memcpy(a,tt,sizeof tt);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>R;
    for(int i=1;i<=n;i++) {
        cin>>x[i]>>y[i]>>r[i];
        x[i]+=7,y[i]+=7;
    }
    dfs(0,-1);
    cout<<res<<'\n';
    return 0;
}