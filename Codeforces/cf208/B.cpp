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
char a[55][2];
bool dfs(int x) {
    if(x==1) return true;
    if(a[x][0]==a[x-1][0]||a[x][1]==a[x-1][1]) {
        int t1=a[x-1][0],t2=a[x-1][1];
        a[x-1][0]=a[x][0],a[x-1][1]=a[x][1];
        if(dfs(x-1)) return true;
        a[x-1][0]=t1,a[x-1][1]=t2;
    }
    if(a[x-1][0]==a[x][0]&&a[x-1][1]==a[x][1]&&a[x-3][0]==a[x][0]&&a[x-3][1]==a[x][1]) return false;
    if(a[x][0]==a[x-3][0]||a[x][1]==a[x-3][1]) {
        int t1=a[x-3][0],t2=a[x-3][1];
        a[x-3][0]=a[x][0],a[x-3][1]=a[x][1];
        if(dfs(x-1)) return true;
        a[x-3][0]=t1,a[x-3][1]=t2;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
    cout<<(dfs(n)?"YES":"NO")<<'\n';
    return 0;
}