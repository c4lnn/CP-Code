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
    int n;cin>>n;
    priority_queue<int,VI,greater<int>> q;
    VI a(n+1);
    LL res=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(SZ(q)&&q.top()<a[i]) {
            auto u=q.top();
            q.pop();
            res+=a[i]-u;
            q.emplace(a[i]);
        }
        q.emplace(a[i]);
    }
    cout<<res<<'\n';
    return 0;
}