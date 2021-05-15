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
int dfs(LL n,LL m) {
    if(n<m) swap(n,m);
    if(!m) return 0;
    if(n%m==0) return 1;
    if(n<m+m) return dfs(n-m,m)^1;
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n,m;
    while(cin>>n>>m) {
        if(!n&&!m) break;
        cout<<(dfs(n,m)?"Stan wins":"Ollie wins")<<'\n';
    }
    return 0;
}