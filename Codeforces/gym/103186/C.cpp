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
    int n,m;cin>>n>>m;
    int sum=0;
    VI a(n+1);
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        cin>>a[x];
        sum+=a[x];
    }
    for(int i=1;i<=n;i++) {
        if(i==m) {
            if(a[i]<60) a[i]=60;
        }
        else {
            if(a[i]*n>=sum) {
                a[i]-=2;
                a[i]=max(0,a[i]);
            }
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<a[i]<<" \n"[i==n];
    }
    return 0;
}