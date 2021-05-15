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
int dp[35][35][35];
VI lim;
int dfs(int x,int tot0,int tot1,int a,int b) {
    if(!x) return (!a)&(tot0>=tot1);
    if(!a&&!b&&dp[x][tot0][tot1]!=-1) return dp[x][tot0][tot1];
    int mx=b?lim[x]:1;
    int ret=0;
    for(int i=0;i<=mx;i++) ret+=dfs(x-1,tot0+((!a)&(!i)),tot1+i,a&(!i),b&(i==mx));
    if(!a&&!b) dp[x][tot0][tot1]=ret;
    return ret;
}
int solve(int x) {
    lim.clear();
    lim.PB(-1);
    while(x) lim.PB(x%2), x/=2;
    return dfs(SZ(lim)-1,0,0,true,true);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    memset(dp,-1,sizeof dp);
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",solve(b)-solve(a-1));
    return 0;
}