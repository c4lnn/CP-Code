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
int n;
LL m;
LL calc(LL i,LL j) {
    return i*i+100000*i+j*j-100000*j+i*j;
}
bool check(LL k) {
    LL tot=0;
    for(int j=1;j<=n;j++) {
        if(calc(1,j)>=k) continue;
        int l=1,r=n;
        while(l<r) {
            int mid=l+r+1>>1;
            if(calc(mid,j)<k) l=mid;
            else r=mid-1;
        }
        tot+=l;
    }
    return tot<m;
}
int main() {
    int T;scanf("%d",&T);
    while(T--) {
        scanf("%d%lld",&n,&m);
        LL l=LLONG_MAX,r=LLONG_MIN;
        for(int j=1;j<=n;j++) {
            l=min(l,calc(1,j));
            r=max(r,calc(n,j));
        }
        while(l<r) {
            LL mid=l+r+1>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        printf("%lld\n",l);
    }
    return 0;
}