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
const int N=15;
int n,s,k[N];
LL M,m[N],a[N],e[N][N*10];
vector<LL> res;
set<LL> y[N];
LL ex_GCD(LL a,LL b,LL &x,LL &y) {
    if(!b) {x=1,y=0;return a;}
    LL ret=ex_GCD(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}
LL CRT(LL *m,LL *a,int n) {
    LL res=0;
    for(int i=1;i<=n;i++) {
        LL b=M/m[i],x,y;
        LL d=ex_GCD(b,m[i],x,y);
        x=(x%M+M)%M;
        res=(res+a[i]*b%M*x%M)%M;
    }
    return res;
}
void dfs(int pos) {
    if(pos>n) {
        res.PB(CRT(m,a,n));
        return;
    }
    for(int i=1;i<=k[pos];i++) {
        a[pos]=e[pos][i];
        dfs(pos+1);
    }
}
void solve(int x) {
    for(int i=1;i<=n;i++) {
        if(i==x) sort(e[x]+1,e[x]+1+k[x]);
        else {
            y[i].clear();
            for(int j=1;j<=k[i];j++) y[i].insert(e[i][j]);
        }
    }
    for(int i=0;s;i++) {
        for(int j=1;j<=k[x];j++) {
            LL v=i*m[x]+e[x][j];
            if(!v) continue;
            bool f=true;
            for(int k=1;k<=n;k++) {
                if(k==x) continue;
                if(!y[k].count(v%m[k])) {f=false;break;}
            }
            if(f) {
                printf("%lld\n",v);
                if(--s==0) return;
            }
        }
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&s)&&n) {
        LL tot=1;
        int mn=1;
        for(int i=1;i<=n;i++) {
            scanf("%lld%d",&m[i],&k[i]);
            tot*=k[i];
            for(int j=1;j<=k[i];j++) scanf("%lld",&e[i][j]);
            if(k[mn]*m[i]>k[i]*m[mn]) mn=i;
        }
        if(tot<=10000) {
            M=1;for(int i=1;i<=n;i++) M*=m[i];
            res.clear();
            dfs(1);
            sort(ALL(res));
            for(int i=0;s;i++) {
                for(int j=0;j<SZ(res);j++) {
                    LL t=i*M+res[j];
                    if(t>0) {
                        printf("%lld\n",t);
                        if(--s==0) break;
                    }
                }
            }
        }
        else solve(mn);
        puts("");
    }
    return 0;
}