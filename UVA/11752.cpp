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
const int N=70;
const int M=64;
vector<__int128> res;
VI p;
int mn[N];
void get_prime() {
    for(int i=2;i<=M;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>M) break;
            mn[i*x]=x;
        }
    }
}
__int128 fast_pow(__int128 n,int k) {
    __int128 ret=1;
    while(k) {
        if(k&1) ret*=n;
        n=n*n;
        k>>=1;
    }
    return ret;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    get_prime();
    vector<unsigned long long> res;
    __int128 mx=ULONG_LONG_MAX;
    for(int i=2;i<=64;i++) {
        if(mn[i]==i) continue;
        for(int j=2;;j++) {
            __int128 t=fast_pow((__int128)j,i);
            if(t>mx) break;
            res.PB((unsigned long long)t);
        }
    }
    res.PB(1);
    sort(ALL(res));
    res.resize(unique(ALL(res))-res.begin());;
    for(auto x:res) printf("%llu\n",x);
    return 0;
}