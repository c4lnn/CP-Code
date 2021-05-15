#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
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
const int N=505;
int fa[N],w[N],st[N];
struct R {
	int x,y,z;
	R() {}
	R(int x,int y,int z):x(x),y(y),z(z) {}
}r[N<<2];
int find(int x) {
	if(x==fa[x]) return x;
	int root=find(fa[x]);
	w[x]=(w[x]+w[fa[x]])%3;
	return fa[x]=root;
}
int main() {
	int n,m;
    while(~scanf("%d%d",&n,&m)) {
    	for(int i=1;i<=m;i++) {
    		int x,y;
    		char c;
    		scanf("%d%c%d",&x,&c,&y);
    		if(c=='=') r[i]=R(x,y,0);
    		else if(c=='<') r[i]=R(x,y,2);
    		else if(c=='>') r[i]=R(x,y,1);
    	}
    	int cnt=0;
    	PII res=MP(0,0);
    	for(int i=0;i<n;i++) {
    		int f=0;
    		for(int j=0;j<n;j++) fa[j]=j,w[j]=0;
    		for(int j=1;j<=m;j++) {
    			if(r[j].x==i||r[j].y==i) continue;
    			int tx=find(r[j].x),ty=find(r[j].y);
    			if(tx==ty) {
    				if((w[r[j].x]-w[r[j].y]+3)%3!=r[j].z) {
    					f=j;
    					break;
    				}
    			} else {
    				fa[tx]=ty;
    				w[tx]=(w[r[j].y]+r[j].z-w[r[j].x]+3)%3;
    			}
    		}
    		if(!f) res.FI=i,cnt++;
    		else res.SE=max(res.SE,f);
    	}
    	if(cnt==1) {
    		printf("Player %d can be determined to be the judge after %d lines\n",res.FI,res.SE);
    	} else if(cnt==0) {
    		puts("Impossible");
    	} else {
    		puts("Can not determine");
    	}
    }
    return 0;
}