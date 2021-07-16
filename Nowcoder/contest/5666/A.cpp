#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
int n,nxt[2],pre[2],a[N],b[N],res[N];
int m,p,sa[N],id[N],rk[N],oldrk[N<<1],cnt[N];
void init() {
    for(int i=0;i<2;i++) nxt[i]=pre[i]=0;
    memset(b,0,sizeof b);
    for(int i=1;i<=n;i++) res[i]=i,a[i]=0;
}
void get_sa(int *s) {
    m=300;
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) cnt[rk[i]=s[i]]++;
    for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
    for(int w=1,p;w<n;w<<=1,m=p) {
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
bool cmp(int x,int y) {
    return a[x]<a[y]||a[x]==a[y]&&rk[x+a[x]]<rk[y+a[y]];
}
int main() {
    while(~scanf("%d",&n)) {
        scanf("%s",s+1);
        init();
        for(int i=1;i<=n;i++) {
            if(pre[s[i]-'a']) b[i]=i-pre[s[i]-'a'];
            pre[s[i]-'a']=i;
        }
        for(int i=n;i>=1;i--) {
            if(!nxt[(s[i]-'a')^1]) a[i]=n-i+2;
            else a[i]=nxt[(s[i]-'a')^1]-i+1;
            nxt[s[i]-'a']=i;
        }
        get_sa(b);
        rk[n+1]=0;
        rk[n+2]=-1;
        sort(res+1,res+1+n,cmp);
        for(int i=1;i<=n;i++) printf("%d ",res[i]);
        puts("");
    }
    return 0;
}