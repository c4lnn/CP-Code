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
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        int n;
        scanf("%d",&n);
        bool f=false;
        int pre=-1;
        for(int i=1;i<=n;i++) {
            int x;
            scanf("%d",&x);
            if(x==pre) f=true;
            pre=x;
        }
        if(f) puts("NO");
        else puts("YES");
    }
    return 0;
}