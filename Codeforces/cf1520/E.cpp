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
const int N=1e6+5;
LL sum1[N],sum2[N],sum3[N],sum4[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;string s;cin>>n>>s;
        VI a;
        for(int i=0;i<n;i++) if(s[i]=='*') a.PB(i);
        int mid=SZ(a)>>1;
        LL res=0;
        for(int i=0;i<SZ(a);i++) {
            if(i<mid) res+=a[mid]-(mid-i)-a[i];
            else res+=a[i]-a[mid]-(i-mid);
        }
        cout<<res<<'\n';
    }
    return 0;
}