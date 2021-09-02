#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n;cin>>n;
    VPII res;
    LL sum=0;
    for(LL l=1,r=1;;r++) {
        sum+=r*r;
        while(l<r&&sum>n) sum-=l*l,++l;
        if(sum==n) res.PB(MP(r-l+1,l));
        if(r==l&&sum>n) break;
    }
    cout<<SZ(res)<<'\n';
    for(int i=0;i<SZ(res);i++) {
        cout<<res[i].FI<<' ';
        for(int j=res[i].SE;j<=res[i].SE+res[i].FI-1;j++) cout<<j<<" \n"[j==res[i].SE+res[i].FI-1];
    }
    return 0;
}