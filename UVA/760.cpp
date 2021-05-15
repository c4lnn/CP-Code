#include<bits/stdc++.h>
using namespace std;
const int N=605;
int len1,len2,n,m,sa[N],id[N],rk[N],oldrk[N<<1],cnt[N],ht[N],mx;
char s1[N],s2[N],s[N];
set<string>res;
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
    mx=0;
    for(int i=1,t=0;i<=n;i++) {
        if(t) t--;
        while(s[i+t]==s[sa[rk[i]-1]+t]) t++;
        ht[rk[i]]=t;
        if(t&&t>=mx&&!((i<len1+1)^(sa[rk[i]-1]>len1+1))) {
            if(t>mx) res.clear();
            string temp="";
            for(int j=0;j<t;j++) temp+=s[i+j];
            res.insert(temp.substr(0,t)); 
            mx=t;
        }
    }
}
int main() {
    bool f=false;
    while(~scanf("%s%s",s1,s2)) {
        if(!f) f=true;
        else puts("");
        len1=strlen(s1),len2=strlen(s2);
        n=len1+1+len2;
        for(int i=1;i<=len1;i++) s[i]=s1[i-1];
        s[len1+1]='#';
        for(int i=1;i<=len2;i++) s[i+1+len1]=s2[i-1];
        s[n+1]=0;
        get_sa();
        get_ht();
        if(!mx) puts("No common sequence.");
        else for(auto x:res) cout<<x<<endl;
    }
    return 0;
}