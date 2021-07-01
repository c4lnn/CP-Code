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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=5e3+5;
int n,k;
LL a[N][N],s[N][N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>a[i+j][i-j+n];
        }
    }
    for(int i=1;i<=n+n+k+k;i++) {
        for(int j=1;j<=n+n+k+k;j++) {
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    LL res=0;
    for(int i=1;i<=n+n;i++) {
        int a=i+2*(k-1);
        for(int j=1;j<=n+n;j++) {
            if((i+j-n)&1) continue;
            int b=j+2*(k-1);
            res=max(res,s[a][b]-s[i-1][b]-s[a][j-1]+s[i-1][j-1]);
        }
    }
    cout<<res<<'\n';
    return 0;
}