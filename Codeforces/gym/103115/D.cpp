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
const int N=1e5+5;
vector<char> a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,l,r;cin>>n>>l>>r;
    string s;cin>>s;
    if(l==r) {
        int sz=0;
        for(int i=0;i<l;i++) {
            for(int j=i;j<n;j+=l) {
                a[i].PB(s[j]);
            }
            sort(ALL(a[i]));
            sz=max(sz,SZ(a[i]));
        }
        for(int i=0;i<sz;i++) {
            for(int j=0;j<l;j++) if(i<SZ(a[j])) {
                cout<<a[j][i];
            }
        }
    }
    else if(n>=2*l) {
        sort(ALL(s));
        cout<<s<<'\n';
    }
    else {
        a[0].PB(s[0]);
        for(int i=l;i<n;i++) a[0].PB(s[i]);
        for(int i=1;i<n-l;i++) a[0].PB(s[i]);
        sort(ALL(a[0]));
        int pos=0;
        for(int i=0;i<n-l;i++) cout<<a[0][pos++];
        for(int i=n-l;i<l;i++) cout<<s[i];
        for(int i=l;i<n;i++) cout<<a[0][pos++];
    }
    return 0;
}