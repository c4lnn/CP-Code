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
int n,a[1005];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d",&n)) {
        memset(a,0x3f,sizeof a);
        for(int i=1;i<=n;i++) {
            int x;
            scanf("%d",&x);
            *lower_bound(a,a+n,x)=x;
        }
        printf("%d\n",lower_bound(a,a+n,0x3f3f3f3f)-a);
    }
    return 0;
}