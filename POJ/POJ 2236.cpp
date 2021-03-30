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
const int N=1005;
int n,d,fa[N];
PII a[N];
VI v;
bool judge(PII a,PII b) {
	return (a.FI-b.FI)*(a.FI-b.FI)+(a.SE-b.SE)*(a.SE-b.SE)-d*d<=0;
}
int get(int x) {
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y) {
	fa[get(x)]=get(y);
}
int main() {
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].FI,&a[i].SE);
    for(int i=1;i<=n;i++) fa[i]=i;
    char s[3];
    while(~scanf("%s",s)) {
    	if(s[0]=='O') {
    		int x;
    		scanf("%d",&x);
    		for(int i=0;i<SZ(v);i++) if(judge(a[x],a[v[i]])) merge(get(x),get(v[i]));
    		v.PB(x);
    	}
    	else {
    		int x,y;
    		scanf("%d%d",&x,&y);
    		puts(get(x)==get(y)?"SUCCESS":"FAIL");
    	}
    }
    return 0;
}