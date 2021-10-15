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
const int N=1005;
char a[N][N],b[N][N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++) scanf("%s",b[i]+1);
    int tot=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i][j]!=b[i][j]) tot++;
        }
    }
    if(tot<=n*m/2) for(int i=1;i<=n;i++) printf("%s\n",a[i]+1);
    else {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) putchar(a[i][j]=='X'?'.':'X');
            puts("");
        }
    }
    return 0;
}