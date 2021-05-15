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
const int c[]={0,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5};
LL t[20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n;
    cin>>n;
    LL res=0;
    t[1]=1;
    for(int i=2;i<=17;i++) t[i]=t[i-1]*10;
    for(int i=4;i<t[i+1];i++) {
        if(n<t[i]) break;
        res+=(min(n,t[i+1]-1)-t[i]+1)*c[i];
    }
    cout<<res<<'\n';
    return 0;
}