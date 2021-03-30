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
const int N=55;
int n,a[N][N],b[N][N];
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        bool f=false;
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++) {
                scanf("%d",&b[i][j]);
                if(!b[i][j]) continue;
                if(i==1&&j==1) f=true;
                else if(b[i][j]) f=false;
            }
        if(f)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) {
                    printf("%d",a[i][j]);
                    if(j==n) puts("");
                    else printf(" ");
                }
        else
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) {
                    printf("0");
                    if(j==n) puts("");
                    else printf(" ");
                }
    }
    return 0;
}