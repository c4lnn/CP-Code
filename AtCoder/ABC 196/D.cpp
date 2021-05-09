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
int n,m,res;
void dfs(int i,int bit,int a,int b) {
    if(i==n*m-1) ++res;
    else if(bit>>i&1) dfs(i+1,bit,a,b);
    else {
        if(b) dfs(i+1,bit|1<<i,a,b-1);
        if(a) {
            if(i%m!=m-1&&!(bit&1<<(i+1))) dfs(i+1,bit|1<<(i+1),a-1,b);
            if(i+m<n*m&&!(bit&1<<(i+m))) dfs(i+1,bit|1<<(i+m),a-1,b);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin>>n>>m>>a>>b;
    dfs(0,0,a,b);
    cout<<res<<'\n';
    return 0;
}