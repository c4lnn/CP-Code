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
const int N=305;
int n,m,u[N],v[N];
bool st[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
        int res=0x3f3f3f3f;
        for(int i=0;i<1<<n;i++) {
            for(int j=0;j<n;j++) st[j]=false;
            for(int j=0;j<n;j++) if((1<<j)&i) st[j]=true;
            int tot=0;
            for(int j=1;j<=m;j++) if(!(st[u[j]]^st[v[j]])) tot++;
            res=min(res,tot);
        }
        printf("%d\n",res);
    }
    return 0;
}