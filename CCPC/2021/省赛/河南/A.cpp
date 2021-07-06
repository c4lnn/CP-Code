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
const int N=1e3+5;
int a[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>a[i][j];
        }
    }
    int h,w;cin>>h>>w;
    for(int i=1;i+h-1<=n;i++) {
        for(int j=1;j+w-1<=m;j++) {
            if(a[i][j]==a[i+h-1][j]&&a[i][j]==a[i][j+w-1]&&a[i][j]==a[i+h-1][j+w-1]) {
                return cout<<"YES"<<'\n',0;
            }
        }
    }
    cout<<"NO"<<'\n';
    return 0;
}