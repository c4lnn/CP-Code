#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+5;
int n,m,k,sa[N],id[N],rk[N],oldrk[N<<1],cnt[N],ht[N],len_a,len_b,st[N][2];
char s[N],a[N],b[N];
void get_sa() {
    m='z';
    for(int i=1;i<=m;i++) cnt[i]=0;
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
void get_ht() {
    for(int i=1,t=0;i<=n;i++) {
        if(t) t--;
        while(s[i+t]==s[sa[rk[i]-1]+t]) t++;
        ht[rk[i]]=t;
    }
}
void solve() {
    long long res=0,tot=0;
    for(int i=1,top=0,cnt;i<=n;i++) {
        if(ht[i]>=k) {
            cnt=0;
            if(sa[i-1]<=len_a) tot+=ht[i]-k+1,cnt++;
            while(top&&ht[i]<=st[top][0]) {
                tot-=(st[top][0]-ht[i])*st[top][1];
                cnt+=st[top][1];
                top--;
            }
            st[++top][0]=ht[i],st[top][1]=cnt;
            if(sa[i]>len_a+1) res+=tot;
        }
        else top=0,tot=0;
    }
    tot=0;
    for(int i=1,top=0,cnt;i<=n;i++) {
        if(ht[i]>=k) {
            cnt=0;
            if(sa[i-1]>len_a+1) tot+=ht[i]-k+1,cnt++;
            while(top&&ht[i]<=st[top][0]) {
                tot-=(st[top][0]-ht[i])*st[top][1];
                cnt+=st[top][1];
                top--;
            }
            st[++top][0]=ht[i],st[top][1]=cnt;
            if(sa[i]<=len_a) res+=tot;
        }
        else top=0,tot=0;
    }
    printf("%lld\n",res);
}
int main() {
    while(~scanf("%d",&k)&&k) {
        scanf("%s%s",a+1,b+1);
        len_a=strlen(a+1),len_b=strlen(b+1);
        n=len_a+1+len_b;
        for(int i=1;i<=len_a;i++) s[i]=a[i];
        s[len_a+1]='#';
        for(int i=1;i<=len_b;i++) s[len_a+1+i]=b[i];
        s[n+1]=0;
        get_sa();
        get_ht();
        solve();
    }
    return 0;
}