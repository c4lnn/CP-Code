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
int a[105];
bool dp[1000005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    int d=0,mn=INT_MAX;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        dp[a[i]]=true;
        d=__gcd(d,a[i]);
        mn=min(mn,a[i]);
    }
    if(d!=1) return cout<<"INF"<<'\n',0;
    int cnt=0,res=0;
    for(int i=1;;i++) {
        if(dp[i]) {
            ++cnt;
            if(cnt==mn) break;
            for(int j=1;j<=n;j++) {
                dp[i+a[j]]=true;
            }
        }
        else cnt=0,++res;
    }
    cout<<res<<'\n';
    return 0;
}