#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,sa[N],id[N],rk[N],oldrk[N],cnt[N],mx;
char s[N];
void get_sa() {
    n=strlen(s+1);
    m='z';
    memset(oldrk,0,sizeof oldrk);
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
void get_mx() {
    mx=0;
    for(int i=1,t=0;i<=n;i++) {
        if(t) t--;
        while(s[i+t]==s[sa[rk[i]-1]+t]) t++;
        if(t>mx) mx=t;
    } 
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s",s+1);
        get_sa();
        get_mx();
        printf("%d\n",mx);
    }
    return 0;
}