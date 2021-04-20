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
 const int N=2e5+5;
 int cnt[N];
 int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    LL res=0;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        res+=cnt[x^k];
        ++cnt[x];
    }
    cout<<res<<'\n';
    return 0;
 }