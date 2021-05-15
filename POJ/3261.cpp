#include<cstdio>
#include<deque>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
//head
const int N=2e4+5,M=1e6+5;
int n,k,m,a[N],sa[N],id[N],rk[N],oldrk[N],cnt[M],ht[N];
void get_sa() {
    m=1000000;
    for(int i=1;i<=n;i++) cnt[rk[i]=a[i]]++;
    for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
    for(int w=1,p=0;w<n;w<<=1,m=p) {
        p=0;
        for(int i=n;i>n-w;i--) id[++p]=i;
        for(int i=1;i<=n;i++) if(sa[i]>w) id[++p]=sa[i]-w;
        for(int i=1;i<=m;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) cnt[rk[id[i]]]++;
        for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for(int i=n;i>=1;i--) sa[cnt[rk[id[i]]]--]=id[i];
        for(int i=1;i<=n;i++) oldrk[i]=rk[i];
        p=0;
        for(int i=1;i<=n;i++) rk[sa[i]]=((oldrk[sa[i]]==oldrk[sa[i-1]]&&oldrk[sa[i]+w]==oldrk[sa[i-1]+w])?p:++p);
    }
}
void get_ht() {
    for(int i=1,t=0;i<=n;i++) {
        if(t) t--;
        while(a[i+t]==a[sa[rk[i]-1]+t]) t++;
        ht[rk[i]]=t;
    }
}
void get_res() {
    deque<int>dq;
    int res=0;
    for(int i=2;i<=n;i++) {
        if(!dq.empty()&&i-dq.front()+1>k-1) dq.pop_front();
        while(!dq.empty()&&ht[dq.back()]>=ht[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=k) res=max(res,ht[dq.front()]);
    }
    printf("%d\n",res);
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    get_sa();
    get_ht();
    get_res();
    return 0;
}