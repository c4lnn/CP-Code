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
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int n;cin>>n;
        VI a(n+1),l(n+1,0x3f3f3f3f),r(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        stack<int> s;
        for(int i=1;i<=n;i++) {
            while(SZ(s)&&a[s.top()]<=a[i]) {
                l[i]=min(l[i],s.top());
                s.pop();
            }
            s.push(i);
        }
        while(SZ(s)) s.pop();
        for(int i=n;i>=1;i--) {
            while(SZ(s)&&a[s.top()]<=a[i]) {
                r[i]=max(r[i],s.top());
                s.pop();
            }
            s.push(i);
        }
        cout<<"Case "<<cs<<":\n";
        for(int i=1;i<=n;i++) cout<<(l[i]==0x3f3f3f3f?0:l[i])<<' '<<r[i]<<'\n';
    }
    return 0;
}