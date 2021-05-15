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
    int a,b;scanf("%d%d",&a,&b);
    VI dp(a*b+1);
    dp[0]=1;
    int res=0;
    for(int i=1;i<=a*b;i++) {
        if(i-a>=0) dp[i]|=dp[i-a];
        if(i-b>=0) dp[i]|=dp[i-b];
        if(!dp[i]) res=i;
    }
    printf("%d\n",res);
    return 0;
}