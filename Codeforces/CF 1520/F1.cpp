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
void solve(int l,int r,int k) {
    if(l==r) {
        cout<<"! "<<l<<endl;
        return;
    }
    int mid=l+r>>1;
    cout<<"? "<<l<<' '<<mid<<endl;
    int lsum;cin>>lsum;
    if(mid-l+1-lsum>=k) solve(l,mid,k);
    else solve(mid+1,r,k-(mid-l+1-lsum));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,t,k;cin>>n>>t>>k;
    solve(1,n,k);
    return 0;
}