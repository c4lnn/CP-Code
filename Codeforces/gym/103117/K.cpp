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
bool st[N];
VI res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) if(!st[i]) {
        res.PB(i);
        st[i]=true;
        for(int j=i+k;j<=n;j+=k) res.PB(j),st[j]=true;
    }
    for(int i=0;i<SZ(res);i++) cout<<res[i]<<" \n"[i==SZ(res)-1];
    return 0;
}