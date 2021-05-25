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
    LL n,k,res=0;int t;cin>>n>>k>>t;
    for(int i=0;i<t;i++) {
        LL a=n*i,b=n*i+1;
        if(a&1) b/=2;
        else a/=2;
        res+=(1+(a%k)*(b%k)%k)%k;
    }
    cout<<res<<'\n';
    return 0;
}