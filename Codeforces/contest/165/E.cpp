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
const int N=(1<<22)+1;
int a[N],mx[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    memset(mx,-1,sizeof mx);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        mx[a[i]]=a[i];
    }
    for(int i=0;i<1<<22;i++) {
        for(int j=0;j<22;j++) if(i&(1<<j)) {
            mx[i]=max(mx[i],mx[i^(1<<j)]);
        }
    }
    for(int i=1;i<=n;i++) cout<<mx[((1<<22)-1)^a[i]]<<" \n"[i==n];
    return 0;
}