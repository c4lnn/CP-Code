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
int n,q,pos[51];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    memset(pos,-1,sizeof pos);
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        if(pos[x]==-1) pos[x]=i;
    }
    for(int i=1;i<=q;i++) {
        int t;cin>>t;
        cout<<pos[t]<<" \n"[i==1];
        for(int j=1;j<=50;j++) if(pos[j]!=-1&&pos[j]<pos[t]) ++pos[j];
        pos[t]=1;
    }
    return 0;
}