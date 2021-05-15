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
const int N=30;
int n,fa[N];
struct E {
	int u,v,w;
	E() {}
	E(int u,int v,int w):u(u),v(v),w(w) {}
	bool operator < (const E &a) const {
		return w>a.w;
	}
};
int find(int x) {
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    while(~scanf("%d",&n)&&n) {
    	for(int i=0;i<n;i++) fa[i]=i;
    	int res=0;
    	priority_queue<E> q;
    	for(int i=1;i<n;i++) {
    		char s[2];
    		int k;
    		scanf("%s%d",s,&k);
    		int u=s[0]-'A',w;
    		for(int j=1;j<=k;j++) {
    			scanf("%s%d",s,&w);
    			int v=s[0]-'A';
    			q.push(E(u,v,w));
    		}
    	}
    	while(!q.empty()) {
    			int u=q.top().u,v=q.top().v,w=q.top().w;
    			q.pop();
    			int tx=find(u),ty=find(v);
    			if(tx==ty) continue;
    			fa[tx]=ty;
    			res+=w;
    		}
    	printf("%d\n",res);
    }
    return 0;
}