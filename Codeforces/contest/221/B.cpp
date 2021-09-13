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
bool st[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;cin>>x;
    int t=x;
    while(t) {
        st[t%10]=true;
        t/=10;
    }
    int res=0;
    for(int i=1;i*i<=x;i++) if(x%i==0) {
        int a=i,b=x/i;
        while(a) {
            if(st[a%10]) {++res;break;}
            a/=10;
        }
        if(a==b) continue;
        while(b) {
            if(st[b%10]) {++res;break;}
            b/=10;
        }
    }
    cout<<res<<'\n';
    return 0;
}