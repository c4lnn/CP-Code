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
    int T;scanf("%d",&T);
    while(T--) {
        int n,m;scanf("%d%d",&n,&m);
        VI a(n+1);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        LL sum=0;
        int res=n+1;
        for(int l=1,r=1;r<=n;r++) {
            sum+=a[r];
            while(l<r&&sum-a[l]>=m) sum-=a[l++];
            if(sum>=m) res=min(res,r-l+1);
        }
        printf("%d\n",res==n+1?0:res);
    }
    return 0;
}