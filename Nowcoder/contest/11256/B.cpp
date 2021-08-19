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
    int n;DB c;cin>>n>>c;
    vector<DB> w(n);
    DB res=0;
    for(int i=0;i<n;i++) {
        cin>>w[i];
        res+=w[i];
    }
    sort(ALL(w));
    DB sum=c,pre=0;
    for(int i=0;i<n;i++) {
       sum+=pre*pow(0.5,n-i);
       pre+=w[i];
    }
    cout<<fixed<<setprecision(6)<<min(sum,res)<<'\n';
    return 0;
}