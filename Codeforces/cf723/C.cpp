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
const int N=2005;
int n,m,a[N],cnt[N],f[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int mn=n/m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]<=m) ++cnt[a[i]];
    }
    int tot=0;
    for(int i=1;i<=m;i++) {
        while(cnt[i]<mn)
            for(int j=1;j<=n;j++)
                if(a[j]>m||cnt[a[j]]>mn) {
                    ++cnt[i];
                    if(a[j]<=m) --cnt[a[j]];
                    a[j]=i;
                    ++tot;
                    break;
                }
    }
    cout<<mn<<' '<<tot<<'\n';
    for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    return 0;
}