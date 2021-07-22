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
const int N=5e3+5;
bool st[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) if(!st[i][j]) {
            for(int k=1;i+k<N;k++) {
                for(int l=0;j+l<N;l+=k) {
                    st[i+k][j+l]=true;
                }
            }
            for(int k=1;j+k<N;k++) {
                for(int l=0;i+l<N;l+=k) {
                    st[i+l][j+k]=true;
                }
            }
            break;
        }
    }
    int T;cin>>T;
    while(T--) {
        int n,m;cin>>n>>m;
        cout<<(st[n][m]?"Alice":"Bob")<<'\n';
    }
    return 0;
}