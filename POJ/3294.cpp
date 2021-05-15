#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=110000;
int n,m,k,sa[N],id[N],rk[N],oldrk[N<<1],cnt[N],ht[N],f[N],s[N];
char ss[N];
bool st[N];
vector<int>res;
void get_sa() {
    m=1300;
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
	bool res_is_first=false,ht_is_first=false;
	int tot=0;
	for(int i=1;i<=n;i++) {
		if(ht[i]>=t) {
			if(!ht_is_first) {		
				memset(st,false,sizeof st);
				st[f[sa[i-1]]]=true;
				ht_is_first=true;
				tot++;
			} 
			if(!st[f[sa[i]]]) st[f[sa[i]]]=true,tot++;
		}
		else {
			if(ht_is_first) {
				ht_is_first=false;
				if(tot>=k) {
					if(!res_is_first) res.clear(),res_is_first=true;
					res.push_back(sa[i-1]);
				}
				tot=0;
			}
		}
	}
	if(!res_is_first) return false;
	else return true;
}
void solve() {
    int l=0,r=n;
    while(l<r) {
    	int mid=l+r+1>>1;
    	if(check(mid)) l=mid;
    	else r=mid-1;
    }
    if(l) {
    	for(int i=0;i<res.size();i++) {
    		for(int j=0;j<l;j++) printf("%c",s[res[i]+j]);
    		puts("");
    	}
    }
    else puts("?");
}
int main() {
    while(~scanf("%d",&k)&&k) {
        n=0;
        for(int i=1;i<=k;i++) {
            scanf("%s",ss+1);
            int len=strlen(ss+1),t=0;
            for(int j=1;j<=len;j++) s[++n]=ss[j],f[n]=i;
            if(i<k) s[++n]=300+i;
        }
        s[n+1]=0;
        k=k/2+1;
        get_sa();
        get_ht();
        solve();
        puts("");
    }
    return 0;
}