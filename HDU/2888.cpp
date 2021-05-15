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
const int N=301;
int a[N][N],st[N][N][9][9];
void init(int n,int m) {
    int t1=log2(n);
    int t2=log2(m);
    for(int i=0;i<=t1;i++)
        for(int j=0;j<=t2;j++)
            for(int k=1;k<=n-(1<<i)+1;k++)
                for(int l=1;l<=m-(1<<j)+1;l++) {
                    if(!i&&!j) st[k][l][i][j]=a[k][l];
                    else if(!i) st[k][l][i][j]=max(st[k][l][i][j-1],st[k][l+(1<<j-1)][i][j-1]);
                    else st[k][l][i][j]=max(st[k][l][i-1][j],st[k+(1<<i-1)][l][i-1][j]);
                }
}
int query(int x1,int y1,int x2,int y2) {
    int t1=log2(x2-x1+1);
    int t2=log2(y2-y1+1);
    return max({st[x1][y1][t1][t2],st[x2-(1<<t1)+1][y1][t1][t2],
                st[x1][y2-(1<<t2)+1][t1][t2],st[x2-(1<<t1)+1][y2-(1<<t2)+1][t1][t2]});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    while(cin>>n>>m) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        init(n,m);
        int q;cin>>q;
        while(q--) {
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            int mx=query(x1,y1,x2,y2);
            cout<<mx<<' '<<(max({a[x1][y1],a[x1][y2],a[x2][y1],a[x2][y2]})==mx?"yes":"no")<<'\n';
        }
    }
    return 0;
}