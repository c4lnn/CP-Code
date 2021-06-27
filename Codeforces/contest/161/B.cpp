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
const int N=1e3+5;
int c[N];
bool cmp(int a,int b) {
    return c[a]>c[b];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    VI a,b;
    for(int i=1;i<=n;i++) {
        int t;cin>>c[i]>>t;
        if(t==1) a.PB(i);
        else b.PB(i);
    }
    sort(ALL(a),cmp);
    DB sum=0;
    int mn=INT_MAX,t=k;
    for(int i=0;i<SZ(a);i++) {
        if(t>1) sum+=c[a[i]]/2.0,--t;
        else mn=min(mn,c[a[i]]),sum+=c[a[i]];
    }
    for(int i=0;i<SZ(b);i++) mn=min(mn,c[b[i]]),sum+=c[b[i]];
    if(SZ(a)>=k) sum-=mn/2.0;
    cout<<fixed<<setprecision(1)<<sum<<'\n';
    if(SZ(a)<k) {
        for(int i=0;i<SZ(a);i++) cout<<1<<' '<<a[i]<<'\n';
        for(int i=0;i<SZ(b);i++) {
            if(t>1) --t,cout<<1<<' '<<b[i]<<'\n';
            else if(t==1) {
                cout<<SZ(b)-i<<' '<<b[i]<<' ';
                --t;
            }
            else cout<<b[i]<<" \n"[i==SZ(b)-1];
        }
    }
    else {
        for(int i=0;i<k-1;i++) cout<<1<<' '<<a[i]<<'\n';
        cout<<SZ(b)+SZ(a)-(k-1)<<' ';
        for(int i=k-1;i<SZ(a);i++) cout<<a[i]<<' ';
        for(int i=0;i<SZ(b);i++) cout<<b[i]<<" \n"[i==SZ(b)-1];
    }
    return 0;
}