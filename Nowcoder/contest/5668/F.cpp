#include<bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define int long long
using namespace std;
typedef double DB;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=2e6+5;
int m,p[N],mn[N];  //mn[i] 为 i的最小质因数
void Euler_seive(int n) {  //注意筛后 mn[1]=0
    for(int i=2;i<=n;i++) {
        if(mn[i]==0) mn[i]=i,p[++m]=i;
        for(int j=1;j<=m;j++) {
            if(p[j]>mn[i]||p[j]*i>n) break;
            mn[i*p[j]]=p[j];
        }
    }
}
int gcd(int a,int b) {return b?gcd(b,a%b):a;}
int exgcd(int a,int b,int &x,int &y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    int ret=exgcd(b,a%b,x,y);
    int z=x;
    x=y;
    y=z-(a/b)*y;
    return ret;
}
int get(int x) {
    if(mn[x]==x||x==1) return x;
    int ret=1;
    int t=x;
    while(t%mn[x]==0) t/=mn[x],ret*=mn[x];
    return ret;
}
signed main() {
    Euler_seive(2000000);
    int T;
    scanf("%lld",&T);
    while(T--) {
        int a,b;
        scanf("%lld%lld",&a,&b);
        int c,d,f,e;
        int g=gcd(a,b);
        if(g!=1) printf("%lld %lld %lld %lld\n",a/g+1,b/g,1,b/g);
        else {
            f=get(b);
            if(f==b) puts("-1 -1 -1 -1");
            else {
                d=b/f;
                g=exgcd(f,d,c,e);
                if(c<0) printf("%lld %lld %lld %lld\n",e*a,f,-c*a,d);
                else printf("%lld %lld %lld %lld\n",c*a,d,-e*a,f);
            }
        }
    }
    return 0;
}