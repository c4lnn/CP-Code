#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
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
    int n;cin>>n;
    VI a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=0;
    for(int i=1;i<=n;i++) {
        int mn=a[i],mx=a[i];
        ++res;
        for(int j=i+1;j<=n;j++) {
            mn=min(mn,a[j]);
            mx=max(mx,a[j]);
            if(mx-mn==j-i) ++res;
        }
    }
    cout<<res<<'\n';
    return 0;
}