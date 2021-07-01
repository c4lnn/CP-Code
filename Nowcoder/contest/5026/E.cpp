//SA + 二分
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,k,sa[N],id[N],rk[N],oldrk[N],cnt[N],ht[N];
char s[N];
void get_sa() {
    m='z';
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
bool check(int t) {
    priority_queue<int,vector<int>,greater<int> >q;
    q.push(sa[1]);
    int l=2,idx1,idx2,num=0;
    while(l<=n+1) {
        if(ht[l]<t) {
            num=1;
            idx1=q.top(),q.pop();
            while(!q.empty()) {
                idx2=q.top(),q.pop();
                if(idx2-idx1>=t) {
                    num++;
                    idx1=idx2;
                }
            }
            if(num>=k) return true;
        }
        q.push(sa[l]);
        l++;
    }
    return false;
}
void solve() {
    int l=0,r=n;
    while(l<r) {
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
}
int main() {
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    get_sa();
    get_ht();
    solve();
    return 0;
}
//hash字符串 + 二分
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=200010;
const int base=131;
char s[N];
int n,k,f[N];
ull h[N],p[N];
unordered_map<ull,int>last;
ull calc(int l,int r) {
    return h[r]-h[l-1]*p[r-l+1];
}
bool check(int x) {
    last.clear();
    for(int i=1;i<=n-x+1;i++) {
        if(i-x>=1) last[calc(i-x,i-1)]=i-x;
        f[i]=f[last[calc(i,i+x-1)]]+1;
        if(f[i]>=k) return true;
    }
    return false;
}
int main() {
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) h[i]=h[i-1]*base+s[i]-'a';
    p[0]=1;
    for(int i=1;i<=n;i++) p[i]=p[i-1]*base;
    int l=0,r=n;
    while(l<r) {
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}