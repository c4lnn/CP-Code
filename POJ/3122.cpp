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
const DB PI=acos(-1);
const int N=1e4+5;
int n,f;
DB a[N];
bool check(DB mid) {
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=a[i]/mid;
    return cnt>=f;
}
int main() {
    int T;scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&f);
        ++f;
        for(int i=1;i<=n;i++) {
            scanf("%lf",&a[i]);
            a[i]=a[i]*a[i]*PI;
        }
        DB l=0,r=1e9;
        while(r-l>1e-5) {
            DB mid=(l+r)/2;
            if(check(mid)) l=mid;
            else r=mid;
        }
        printf("%.4f\n",l);
    }
    return 0;
}