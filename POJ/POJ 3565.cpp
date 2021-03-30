#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
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
const int N=105;
const DB INF=2e9;
int n,ma[N],mb[N],vb[N],pre[N];
DB w[N][N],la[N],lb[N],slk[N],x[N<<1],y[N<<1];
void KM() {
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) vb[j]=pre[j]=0,slk[j]=INF;
        int b=0,p=-1;
        for(mb[b]=i;mb[b];b=p) {
            DB d=INF;
            int a=mb[b];
            vb[b]=1;
            for(int j=1;j<=n;j++)
                if(!vb[j]) {
                    DB t=la[a]+lb[j]-w[a][j];
                    if(slk[j]-t>1e-8) slk[j]=t,pre[j]=b;
                    if(d-slk[j]>1e-8) d=slk[j],p=j;
                }
            for(int j=0;j<=n;j++) {
                if(vb[j]) la[mb[j]]-=d,lb[j]+=d;
                else slk[j]-=d;
            }
        }
        for(;b;b=pre[b]) mb[b]=mb[pre[b]],ma[mb[b]]=b;
    }
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n<<1;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=n+1;j<=n<<1;j++)
            w[i][j-n]=-sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    KM();
    for(int i=1;i<=n;i++) printf("%d\n",ma[i]);
    return 0;
}