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
//head
const int N=1e4+5;
int n,a[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=0;
    for(int i=1;i<=n;i++) {
        int t=1;
        for(int j=i-1;j>=1;j--) {
            if(a[j]>=a[i]) ++t;
            else break;
        }
        for(int j=i+1;j<=n;j++) {
            if(a[j]>=a[i]) ++t;
            else break;
        }
        res=max(res,t*a[i]);
    }
    cout<<res<<'\n';
    return 0;
}