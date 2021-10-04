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
const int N=1e4+5;
int a[N],sum[N];
int main() {
    int n,k;cin>>n>>k;
    for(int i=1;i<n;i++) {
        cout<<"and"<<' '<<i<<' '<<i+1<<endl;
        cin>>sum[i];
    }
    for(int i=1;i<n;i++) {
        cout<<"or"<<' '<<i<<' '<<i+1<<endl;
        int t;cin>>t;
        sum[i]+=t;
    }
    cout<<"and"<<' '<<1<<' '<<3<<endl;
    cin>>sum[0];
    cout<<"or"<<' '<<1<<' '<<3<<endl;
    int t;cin>>t;
    sum[0]+=t;
    a[1]=(sum[0]+sum[1]-sum[2])/2;
    for(int i=2;i<=n;i++) a[i]=sum[i-1]-a[i-1];
    sort(a+1,a+1+n);
    cout<<"finish"<<' '<<a[k]<<endl;
    return 0;
}