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
    int k;cin>>k;
    if(!k) return cout<<0<<'\n',0;
    VI a(12);
    for(int i=0;i<12;i++) cin>>a[i];
    sort(ALL(a),greater<int>());
    int sum=0;
    for(int i=0;i<12;i++) {
        sum+=a[i];
        if(sum>=k) return cout<<i+1<<'\n',0;
    }
    cout<<-1<<'\n';
    return 0;
}