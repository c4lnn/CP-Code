#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
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
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int f=INT_MAX;
    for(int i=1;i<=k;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        f=min({f,x-1,n-x,y-1,m-y});
    }
    puts(f<=4?"YES":"NO");
    return 0;
}