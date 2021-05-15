#include<bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e4+5;
int a[N],fa[N];
map<PII,bool> mp;
VI res;
struct Q {
	char c;
	int x,y;
	Q() {}
	Q(char c,int x,int y):c(c),x(x),y(y) {}
}q[N*5];
int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y) {
	int tx=find(x),ty=find(y);
	if(tx==ty) return;
	if(a[tx]>a[ty]||a[tx]==a[ty]&&tx<ty) fa[ty]=tx;
	else fa[tx]=ty;
}
int main() {
	int n;
	bool f=false;
    while(~scanf("%d",&n)) {
    	mp.clear();
    	res.clear();
    	for(int i=0;i<n;i++) fa[i]=i;
    	for(int i=0;i<n;i++) scanf("%d",&a[i]);
    	int m;
    	scanf("%d",&m);
    	for(int i=1;i<=m;i++) {
    		int x,y;
    		scanf("%d%d",&x,&y);
    		if(x>y) swap(x,y);
    		mp[MP(x,y)]=true;
    	}
    	int o;
    	scanf("%d",&o);
    	char s[20];
    	for(int i=1;i<=o;i++) {
    		scanf("%s",s);
    		if(s[0]=='q') {
    			int x;
    			scanf("%d",&x);
    			q[i]=Q('q',x,-1);
    		}
    		else {
    			int x,y;
    			scanf("%d%d",&x,&y);
    			if(x>y) swap(x,y);
    			mp[MP(x,y)]=false;
    			q[i]=Q('d',x,y);
    		}
    	}
    	for(auto it:mp) {
    		if(it.second==true) {
    			int x=it.first.first,y=it.first.second;
    			merge(x,y);
    		}
    	}
    	for(int i=o;i>=1;i--) {
    		if(q[i].c=='q') {
    			int tx=find(q[i].x);
    			if(a[tx]>a[q[i].x]) res.PB(tx);
    			else res.PB(-1);
    		}
    		else merge(q[i].x,q[i].y);
    	}
    	if(f) puts("");
    	else f=true;
    	for(int i=SZ(res)-1;i>=0;i--) printf("%d\n",res[i]);
    }
    return 0;
}