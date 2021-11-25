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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
int tp,fp,fn,tn;
bool cmp(PII &a,PII &b) {
    return a.FI>b.FI;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    VPII a(n);
    for(int i=0;i<n;i++) {
        char c;cin>>c>>a[i].FI;
        a[i].SE=(c=='+');
        if(c=='+') ++fn;
        else ++tn;
    }
    sort(ALL(a),cmp);
    DB res=0,pre_x=0,pre_y=0;
    for(int i=0;i<n;i++) {
        if(a[i].SE) --fn,++tp;
        else --tn,++fp;
        if(i<n-1&&a[i].FI==a[i+1].FI) continue;
        res+=pre_y*(1.0*fp/(tn+fp)-pre_x);
        pre_x=1.0*fp/(tn+fp);
        pre_y=1.0*tp/(tp+fn);
    }
    cout<<fixed<<setprecision(15)<<res<<'\n';
    return 0;
}