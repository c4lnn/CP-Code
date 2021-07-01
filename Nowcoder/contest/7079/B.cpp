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
const int MOD=199999;
long long s[MOD+1],ss[MOD+1],sss[MOD+1];
int main() {
    for(int i=1;i<=MOD;i++) s[i]=(s[i-1]+i)%MOD;
    for(int i=1;i<=MOD;i++) ss[i]=(ss[i-1]+i*s[i]%MOD)%MOD;
    sss[0]=1;
    for(int i=1;i<=MOD;i++) sss[i]=sss[i-1]*ss[i]%MOD*i%MOD;
    int T;
    scanf("%d",&T);
    while(T--) {
        int x;
        scanf("%d",&x);
        if(x<=MOD) printf("%lld\n",sss[x]);
        else puts("0");
    }
    return 0;
}