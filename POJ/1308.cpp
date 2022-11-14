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
const int N=1e5+5;
int fa[N],mx;
VPII e;
set<int> s;
int find(int x) {
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int x,y;
    int cas=0;
    while(~scanf("%d%d",&x,&y)) {
        if(x==-1&&y==-1) break;
        if(x==0&&y==0) {
            for(int i=1;i<=mx;i++) fa[i]=i;
            bool f=false;
            int tot=s.size();
            s.clear();
            for(int i=0;i<e.size();i++) {
                int x=e[i].FI,y=e[i].SE;
                int tx=find(x),ty=find(y);
                if(tx==ty) {
                    f=true;
                    break;
                }
                fa[tx]=ty;
                tot--;
            }
            ++cas;
            if(!f&&tot<=1) printf("Case %d is a tree.\n",cas);
            else printf("Case %d is not a tree.\n",cas);
            e.clear();
            mx=0;
        }
        else {
            e.PB(MP(x,y));
            mx=max(mx,max(x,y));
            s.insert(x),s.insert(y);
        }
    }
    return 0;
}