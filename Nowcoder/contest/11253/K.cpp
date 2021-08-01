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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    VI a(n+1),cnt(n+1);
    for(int i=1;i<=k;i++) {
        int x,y;cin>>x>>y;
        a[x]=y;
    }
    for(int i=1,t=0;i<=n;i++) {
        ++t;
        if(a[i]) {
            if(a[i]>t) return cout<<-1<<'\n',0;
            t=a[i];
        }
        else a[i]=t;
    }
    for(int i=1;i<=n;i++) ++cnt[a[i]];
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int i=1;i<=n;i++) cout<<cnt[a[i]]--<<" \n"[i==n];
    return 0;
}