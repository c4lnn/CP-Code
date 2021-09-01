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
const int N=5e5+5;
int n,m,a[N];
bool check(int mid) {
    int t=m;
    for(int i=1;i<=n;i++) {
        t-=ceil(1.0*a[i]/mid);
        if(t<0) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n>>m) {
        if(n==-1&&m==-1) break;
        for(int i=1;i<=n;i++) cin>>a[i];
        int l=1,r=5e6;
        while(l<r) {
            int mid=l+r>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        cout<<l<<'\n';
    }
    return 0;
}