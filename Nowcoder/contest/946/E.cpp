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
const int N=100;
int tot;
LL d[N];
bool add(LL x) { // 插入
    for(int i=62;~i;i--) if((x>>i)&1) {
        if(!d[i]) {d[i]=x;return true;}
        x^=d[i];
    }
    return false;
}
void calc() { // 统计线性基元素数量
    tot=0;
    for(int i=0;i<63;i++) if(d[i]) ++tot;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        LL x;cin>>x;
        add(x);
    }
    calc();
    cout<<(tot&1?"First":"Second")<<'\n';
    return 0;
}