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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e7+5;
bool st[N];
VI p;
LL n;
void get_prime() {
    for(int i=2;i<=10000000;i++) {
        if(st[i]) continue;
        p.PB(i);
        for(int j=i+i;j<=10000000;j+=i) st[j]=true;
    }
}
LL solve(LL t) {
    LL res=1;
    for(auto x:p) {
        if(x*x>t) break;
        int tot=0;
        while(t%x==0) {
            ++tot;
            t/=x;
        }
        res*=2*tot+1;
    }
    if(t>1) res*=3;
    return res;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    get_prime();
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",cs,solve(n)+1>>1);
    }
    return 0;
}