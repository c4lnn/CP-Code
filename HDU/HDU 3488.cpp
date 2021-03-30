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
const int N=205;
const int INF=0x3f3f3f3f;
int n,m,w[N][N],la[N],lb[N],ma[N],mb[N],vb[N],slk[N],pre[N];
int KM() {
    for(int i=1;i<=n;i++) {
        la[i]=lb[i]=mb[i]=0;
        for(int j=1;j<=n;j++)
            la[i]=max(la[i],w[i][j]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) vb[j]=pre[j]=0,slk[j]=INF;
        int b=0,p=-1;
        for(mb[b]=i;mb[b];b=p) {
            int d=INF,a=mb[b];
            vb[b]=1;
            for(int j=1;j<=n;j++)
                if(!vb[j]) {
                    int t=la[a]+lb[j]-w[a][j];
                    if(t<slk[j]) slk[j]=t,pre[j]=b;
                    if(slk[j]<d) d=slk[j],p=j;
                }
            for(int j=0;j<=n;j++) {
                if(vb[j]) la[mb[j]]-=d,lb[j]+=d;
                else slk[j]-=d;
            }
        }
        for(;b;b=pre[b]) mb[b]=mb[pre[b]],ma[mb[b]]=b;
    }
    int res=0;
    for(int i=1;i<=n;i++) res+=la[i]+lb[i];
    return res;
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                w[i][j]=-INF;
        for(int i=1;i<=m;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            w[a][b]=max(w[a][b],-c);
        }
        printf("%d\n",-KM());
    }
    return 0;
}