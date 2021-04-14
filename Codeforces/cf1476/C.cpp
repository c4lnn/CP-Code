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
const int N=2e5+5;
LL a[N],b[N],c[N],d[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>c[i],--c[i];
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) {
            cin>>b[i];
            if(a[i]>b[i]) swap(a[i],b[i]);
        }
        for(int i=2;i<n;i++) d[i]=c[i]-(b[i+1]-a[i+1]);
        LL sum=b[2]-a[2],res=0;
        for(int i=2;i<=n;i++) {
            res=max({res,sum+c[i]+2,b[i]-a[i]+c[i]+2});
            if(a[i+1]==b[i+1]) sum=0;
            else sum=max(sum,b[i]-a[i])+d[i]+2;
        }
        cout<<res<<'\n';
    }
    return 0;
}