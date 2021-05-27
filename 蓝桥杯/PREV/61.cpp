#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
int cnt[5],dp[500];
struct R {
    int l,w[55];
    bool operator < (const R &T) const {
        return l>T.l;
    }
}a[10005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=6;i++) {
        int x;cin>>x;
        for(int j=1;j<=x;j++) {
            int t;cin>>t;
            ++cnt[t];
        }
    }
    for(int i=2;i<=4;i++) cnt[i]+=cnt[i-1];
    int m;cin>>m;
    for(int i=1;i<=m;i++) {
        int p;cin>>a[i].l>>p;
        for(int j=1;j<=p;j++) {
            cin>>a[i].w[j];
        }
        for(int j=p+1;j<=50;j++) a[i].w[j]=a[i].w[p];
    }
    sort(a+1,a+1+m);
    for(int i=1;i<=m;i++) {
        for(int j=cnt[4]-cnt[a[i].l-1];j>=1;j--) {
            for(int k=1;k<=cnt[4]-cnt[a[i].l-1];k++) if(j-k>=0) {
                dp[j]=max(dp[j],dp[j-k]+a[i].w[k]);
            }
        }
    }
    int res=0;
    for(int i=1;i<=cnt[4];i++) res=max(res,dp[i]);
    cout<<res<<'\n';
    return 0;
}