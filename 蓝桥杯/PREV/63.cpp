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
    int a=0,b=0;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        if(x>=60) ++a;
        if(x>=85) ++b;
    }
    cout<<(int)(100.0*a/n+0.5)<<"%\n"<<(int)(100.0*b/n+0.5)<<"%\n";
    return 0;
}