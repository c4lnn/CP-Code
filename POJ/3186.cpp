#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=2005;
int n,a[N],dp[N][N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=n;j>=i;j--)
            dp[i][j]=max(dp[i-1][j]+(i-1+n-j)*a[i-1],dp[i][j+1]+(i-1+n-j)*a[j+1]);
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,dp[i][i]+n*a[i]);
    printf("%d\n",res);
    return 0;
}