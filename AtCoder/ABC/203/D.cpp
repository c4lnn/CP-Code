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
const int N=808;
int n,m,k,a[N][N],s[N][N];
bool check(int mid) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]>mid);
        }
    }
    for(int i=m;i<=n;i++) {
        for(int j=m;j<=n;j++) {
            if(s[i][j]-s[i-m][j]-s[i][j-m]+s[i-m][j-m]<=k) return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    k=m*m/2;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    int l=0,r=1e9;
    while(l<r) {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';
    return 0;
}