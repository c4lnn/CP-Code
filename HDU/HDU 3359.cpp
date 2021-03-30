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
const DB EPS=1e-9;
const int N=120;
double a[N][N],x[N]; // a 是增广矩阵，b 是解
bool free_x[N]; // 是否为自由变量
int sgn(DB x) {return fabs(x)<EPS?0:(x>0?1:-1);}
int gauss(int n,int m) { // n 个方程，m 个变量
    memset(x,0,sizeof x);
    memset(free_x,true,sizeof free_x);
    int r=0,c=0;
    while(r<n&&c<m) {
        int R=r;
        for(int i=r+1;i<n;i++) if(fabs(a[i][c])>fabs(a[R][c])) R=i;
        if(R!=r) for(int j=c;j<=m;j++) swap(a[r][j],a[R][j]);
        if(!sgn(a[r][c])) {a[r][c]=0;++c;continue;}
        for(int i=r+1;i<n;i++) {
            if(a[i][c]) {
                DB t=a[i][c]/a[r][c];
                for(int j=c;j<=m;j++) a[i][j]-=a[r][j]*t;
            }
        }
        ++r,++c;
    }
    for(int i=r;i<n;i++) if(sgn(a[i][m])) return -1;
    if(r<m) {
        for(int i=r-1;i>=0;i--) {
            int cnt=0,k=-1;
            for(int j=0;j<m;j++) if(sgn(a[i][j])&&free_x[j]) ++cnt,k=j;
            if(cnt>1) continue;
            DB s=a[i][m];
            for(int j=0;j<m;j++) if(j!=k) s-=a[i][j]*x[j];
            x[k]=s/a[i][k];
            free_x[k]=false;
        }
        return m-r; // 自由变量个数
    }
    for(int i=m-1;i>=0;i--) {
        DB s=a[i][m];
        for(int j=i+1;j<m;j++) s-=a[i][j]*x[j];
        x[i]=s/a[i][i];
    }
    return 0;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int n,m,d;
    bool f=false;
    while(~scanf("%d%d%d",&m,&n,&d)&&n) {
        memset(a,0,sizeof a);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                scanf("%lf",&a[i*m+j][n*m]);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int tot=0;
                for(int k=0;k<n;k++) {
                    for(int l=0;l<m;l++) {
                        if(abs(k-i)+abs(l-j)<=d) {
                            a[i*m+j][k*m+l]=1;
                            ++tot;
                        }
                    }
                }
                a[i*m+j][n*m]*=tot;
            }
        }
        gauss(n*m,n*m);
        if(!f) f=true;
        else puts("");
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                printf("%8.2f",x[i*m+j]);
            }
            puts("");
        }
    }
    return 0;
}