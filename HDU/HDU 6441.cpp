#include <bits/stdc++.h>
#define int long long
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=4e4+5;
PII res[N];
signed main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    for(int i=3;i<=40000;i++) {
        if(i&1) {
            int t=(i-1)/2;
            res[i]=MP(2*t*t+2*t,2*t*t+2*t+1);
        }
        else {
            int t=i/2;
            res[i]=MP(t*t-1,t*t+1);
        }
    }
    int tt;
    scanf("%lld",&tt);
    while(tt--) {
        int n,a;
        scanf("%lld%lld",&n,&a);
        if(n==0||n>2||n==2&&a<=2) puts("-1 -1");
        else if(n==1) printf("1 %lld\n",a+1);
        else printf("%lld %lld\n",res[a].FI,res[a].SE);
    }
    return 0;
}