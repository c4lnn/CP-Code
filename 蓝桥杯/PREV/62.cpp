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
    int n;cin>>n;
    VPII a(n);
    for(int i=0;i<n;i++) cin>>a[i].FI>>a[i].SE;
    sort(ALL(a));
    a.resize(unique(ALL(a))-a.begin());
    int res=0;
    for(int i=0;i<SZ(a);i++) {
        vector<pair<DB,DB> > p;
        for(int j=0;j<i;j++) if(a[i].FI!=a[j].FI) {
            DB x=-1.0*(a[i].SE-a[j].SE)/(a[i].FI-a[j].FI);
            DB y=a[i].FI*x+a[i].SE;
            p.PB(MP(x,y));
        }
        sort(ALL(p));
        p.resize(unique(ALL(p))-p.begin());
        res+=SZ(p)+1;
    }
    cout<<res+1<<'\n';
    return 0;
}