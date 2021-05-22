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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    int x;
    VI a;
    while(cin>>x) {
        a.PB(x);
    }
    sort(ALL(a));
    PII res;
    for(int i=1;i<SZ(a);i++) {
        if(a[i]>a[i-1]+1) res.FI=a[i-1]+1;
        else if(a[i]==a[i-1]) res.SE=a[i];
    }
    cout<<res.FI<<' '<<res.SE<<'\n';
    return 0;
}