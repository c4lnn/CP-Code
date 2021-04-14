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
const int N=55;
LL p[N],a[6],b[6];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=5;i++) cin>>a[i];
    LL sum=0;
    for(int i=1;i<=n;i++) {
        sum+=p[i];
        for(int j=5;j>=1;j--) {
            int num=sum/a[j];
            b[j]+=num;
            sum-=num*a[j];
        }
    }
    for(int i=1;i<=5;i++) cout<<b[i]<<" \n"[i==5];
    cout<<sum<<'\n';
    return 0;
}