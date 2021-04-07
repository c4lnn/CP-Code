#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=5e5+5;
int P[]={2,3,5,7,11,13,17};
int n,k,mx,res,x[N],a[N];
char s[N][10];
int qpow(int a,int b) {
    int ret=1;
    while(b) {
        if(b&1) ret*=a;
        a*=a;
        b>>=1;
    }
    return ret;
}
void dfs(int i,int k,int sum,int d) {
    if(i==7) {
        if(sum>mx||sum==mx&&d<res) mx=sum,res=d;
        return;
    }
    int lim=min(k,(int)(log(n/d)/log(P[i])));
    for(int j=lim;~j;j--) dfs(i+1,j,sum*(j+1),d*qpow(P[i],j));
}
int lowbit(int x) {
    return x&-x;
}
void upd(int x,int v) {
    for(int i=x;i<=n;i+=lowbit(i)) a[i]+=v;
}
int qry(int x) {
    int ret=0;
    for(int i=x;i>=1;i-=lowbit(i)) ret+=a[i];
    return ret;
}
int main() {
    while(~scanf("%d%d",&n,&k)) {
        for(int i=1;i<=n;i++) scanf("%s%d",s[i],&x[i]);
        dfs(0,log(n)/log(2),1,1);
        for(int i=1;i<=n;i++) a[i]=lowbit(i);
        for(int i=0;i<res;i++) {
            int t=qry(k);
            if(i) {
                if(x[k]<0) ++x[k];
                x[k]=(x[k]%(n-i)+(n-i))%(n-i);
                t+=x[k];
                if(t>n-i) t=t-n+i;
                if(!t) t=n-i;
            }
            int l=1,r=n;
            while(l<r) {
                int mid=l+r>>1;
                if(qry(mid)>=t) r=mid;
                else l=mid+1;
            }
            upd(k=l,-1);
        }
        printf("%s %d\n",s[k],mx);
    }
    return 0;
}