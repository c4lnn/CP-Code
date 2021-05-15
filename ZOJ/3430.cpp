#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
const int M=256;
int n,m,mp[M],temp[N],cnt,tr[N][M],tot[N],fail[N];
char s[N];
bool vis[N];
void decode(char *s) {
	temp[0]=0;
	for(int i=0,len=0,x=0;s[i]&&s[i]!='=';i++) {
		len+=6;
		x=(x<<6)|mp[s[i]];
		if(len>=8) {
			temp[++temp[0]]=(x>>(len-8))&0xff;
			len-=8;
		}
	}
}
void init() {
	memset(tr,0,sizeof tr);
	for(int i=1;i<=cnt;i++) tot[i]=0,fail[i]=0;
	cnt=0;
}
void insert(int *s) {
	int u=0;
	for(int i=1;i<=s[0];i++) {
		int v=s[i];
		if(!tr[u][v]) tr[u][v]=++cnt;
		u=tr[u][v];
	}
	tot[u]++;
}
void build() {
	queue<int> q;
	for(int i=0;i<M;i++) if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int i=0;i<M;i++) {
			if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
			else tr[u][i]=tr[fail[u]][i];
		}
	}
}
int query(int *s) {
	memset(vis,false,sizeof vis);
	int res=0,u=0;
	for(int i=1;i<=s[0];i++) {
		int v=s[i];
		u=tr[u][v];
		for(int j=u;j;j=fail[j]) if(tot[j]&&!vis[j]) vis[j]=true,res++;
	}
	return res;
}
int main() {
	for(int i=0;i<26;i++) mp[i+'A']=i;
	for(int i=26;i<52;i++) mp[i-26+'a']=i;
	for(int i=52;i<62;i++) mp[i-52+'0']=i;
	mp['+']=62,mp['/']=63;
    while(~scanf("%d",&n)) {
    	init();
    	while(n--) {
    		scanf("%s",s);
    		decode(s);
    		insert(temp);
    	}
    	build();
    	scanf("%d",&m);
    	while(m--) {
 			scanf("%s",s);
 			decode(s);
    		printf("%d\n",query(temp));
    	}
    	puts("");
    }
    return 0;
}