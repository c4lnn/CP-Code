#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const int N=160000;
struct node {
    int mn;
    int mx;
}st[20];
int n,m,k,sa[N],id[N],rk[N],oldrk[N<<1],cnt[N],ht[N],f[N],s[N];
char a[N];
void get_sa() {
    m=400;
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
bool check(int t) {
    bool is_first=false;
    for(int i=1;i<=k;i++) st[i].mn=0x3f3f3f3f,st[i].mx=0;
    for(int i=1;i<=n;i++) {
        if(ht[i]>=t) {
            if(is_first==true) {
                is_first=false;
                st[f[sa[i-1]]].mn=st[f[sa[i-1]]].mx=sa[i-1];
            }
            st[f[sa[i]]].mn=min(st[f[sa[i]]].mn,sa[i]),st[f[sa[i]]].mx=max(st[f[sa[i]]].mx,sa[i]);
        }
        else {
            if(is_first==false) {
                is_first=true;
                int tot=0;
                for(int j=1;j<=k;j++) {
                    if(st[j].mx!=0&&st[j].mn!=st[j].mx&&st[j].mn+t-1<st[j].mx) tot++;
                    st[j].mn=0x3f3f3f3f,st[j].mx=0;
                }
                if(tot==k) return true;
            }
        }
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
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&k);
        n=0;
        for(int i=1;i<=k;i++) {
            scanf("%s",a+1);
            int len=strlen(a+1);
            for(int j=1;j<=len;j++) s[++n]=a[j],f[n]=i;
            if(i<k) s[++n]=300+i;
        }
        s[n+1]=0;
        get_sa();
        get_ht();
        solve();
    }
    return 0;
}