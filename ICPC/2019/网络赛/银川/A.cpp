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
const int N=5e6+5;
int n, p, q, m;
unsigned int mx[N],SA, SB, SC;
unsigned int rng61() {
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA; SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
int top;
void PUSH(unsigned int x) {
    ++top;
    mx[top]=max(mx[top-1],x);
}
void POP() {
    if(top) --top;
}
void gen(){
    scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
    LL res=0;
    top=0;
    mx[top]=0;
    for(int i = 1; i <= n; i++) {
        if(rng61() % (p + q) < p)
            PUSH(rng61() % m + 1);
        else
            POP();
        res^=(1ll*i*mx[top]);
    }
    cout<<res<<'\n';
}
int main() {
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        cout<<"Case #"<<cs<<": ";
        gen();
    }
    return 0;
}