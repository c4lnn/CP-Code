#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
int main() {
    vector<DB> power(10001);
    power[0]=1;
    for(int i=1;i<=10000;i++) power[i]=power[i-1]/2;
    int T;scanf("%d",&T);
    while(T--) {
        int n,x1,y1,x2,y2,x3,y3;
        scanf("%d%d%d%d%d%d%d",&n,&x1,&y1,&x2,&y2,&x3,&y3);
        DB len=x3-x2,h=y1-y2,x=x3-x1;
        DB res=len*h/2;
        if(n>=3) res+=(len+len+x)*h/2;
        if(n>3) {
            n-=3;
            res+=h/2*(2*len*n+x*(4*n-3*(1-power[n])));
        }
        printf("%.3f\n",res);
    }
    return 0;
}