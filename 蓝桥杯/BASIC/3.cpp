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
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++) {
        int t=m;
        for(int j=i;~j&&t;j--) cout<<(char)('A'+j),--t;
        for(int j=1;j<=t;j++) cout<<(char)('A'+j);
        cout<<'\n';
    }
    return 0;
}