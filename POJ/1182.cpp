#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=5e5+5;
int n,k,fa[N],w[N],res;
int find(int x) {
    if(x==fa[x]) return x;
    int rt=find(fa[x]);
    w[x]=(w[x]+w[fa[x]])%3;
    return fa[x]=rt;
}
void merge(int a,int b,int t) {
    int ta=find(a),tb=find(b);
    fa[ta]=tb;
    w[ta]=(-w[a]+t+w[b]+3)%3;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=k;i++) {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(x>n||y>n||(t==2&&x==y)) {res++;continue;}
        if(find(x)==find(y)) {
            if(t==1&&w[x]!=w[y]) res++;
            else if(t==2&&(w[x]-w[y]+3)%3!=1) res++;
        }
        else merge(x,y,t-1);
    }
    printf("%d\n",res);
    return 0;
}