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
    int n;
    while(cin>>n) {
        if(!n) break;
        VI a(n+1),l(n+1),r(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        stack<int> s;
        for(int i=1;i<=n;i++) {
            while(SZ(s)&&a[s.top()]>=a[i]) s.pop();
            l[i]=SZ(s)?s.top()+1:1;
            s.push(i);
        }
        while(SZ(s)) s.pop();
        for(int i=n;i>=1;i--) {
            while(SZ(s)&&a[s.top()]>=a[i]) s.pop();
            r[i]=SZ(s)?s.top()-1:n;
            s.push(i);
        }
        LL res=0;
        for(int i=1;i<=n;i++) res=max(res,1ll*(r[i]-l[i]+1)*a[i]);
        cout<<res<<'\n';
    }
    return 0;
}