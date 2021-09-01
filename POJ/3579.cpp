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
const int N=1e5+5;
int n,k,a[N];
bool check(int mid) {
    int cnt=0;
    for(int i=1;i<n;i++) {
        int r=upper_bound(a+i+1,a+1+n,a[i]+mid)-a-1;
        if(r>i) cnt+=r-i;
    }
    return cnt>=k;
}
int main() {
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        k=(n*(n-1)/2+1)/2;
        sort(a+1,a+1+n);
        int l=0,r=2e9;
        while(l<r) {
            int mid=(1ll*l+r)/2;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}