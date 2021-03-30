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
    int n;
    while(~scanf("%d",&n)) {
        int t,cnt=0;
        for(int i=1;i<=n;i++) {
            int x;
            scanf("%d",&x);
            if(cnt==0) cnt++,t=x;
            else if(x==t) cnt++;
            else cnt--;
        }
        printf("%d\n",t);
    }
    return 0;
}