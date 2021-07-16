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
//head
int qpow(int a,int b) {
    int ret=1;
    while(b) {
        if(b&1) ret*=a;
        a*=a;
        b>>=1;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,n;
    cin>>a>>n;
    int t1=a[SZ(a)-1]-'0',t2=t1;
    if(SZ(a)>1) t2+=(a[SZ(a)-2]-'0')*10;
    if(SZ(n)==1&&n[0]=='1') return cout<<t1<<'\n',0;
    if(SZ(n)==1&&n[0]=='2') return cout<<qpow(t1,t2<4?t2:t2%4+4)%10<<'\n',0;
    else {
        int t=qpow(t2,t1<2?t1:t1%2+2);
        return cout<<qpow(t1,t<4?t:t%4+4)%10<<'\n',0;
    }
    return 0;
}