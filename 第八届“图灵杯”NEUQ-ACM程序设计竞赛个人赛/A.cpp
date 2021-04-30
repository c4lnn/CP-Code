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
int t,cnt=0;
void solve(int x) {
    if(x+1>10) return;
    cout<<1<<' '<<x<<'\n';
    solve(x+1);
    solve(x+1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin>>k;
    cout<<1023+k<<'\n';
    solve(0);
    int a=1024%k,b=1024/k;
    for(int i=1;i<=a;i++) {
        cout<<2<<' '<<b+1<<' ';
        for(int j=1;j<=b+1;j++) cout<<10<<" \n"[j==b+1];
    }
    for(int i=1;i<=k-a;i++) {
        cout<<2<<' '<<b<<' ';
        for(int j=1;j<=b;j++) cout<<10<<" \n"[j==b];
    }
    return 0;
}