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
int a[21],n,mn=INT_MAX;
void dfs(int x,int sum,int res) {
    if(x==n) {mn=min(mn,res^sum);return;}
    dfs(x+1,sum|a[x+1],res);
    dfs(x+1,a[x+1],res^sum);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(0,0,0);
    cout<<mn<<'\n';
    return 0;
}