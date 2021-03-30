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
int check(int x) {
    int res=0;
    for(int i=5;i<=x;i*=5) {
        res+=x/i;
    }
    return res;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        int q;
        scanf("%d",&q);
        int l=0,r=0x3f3f3f3f;
        int res=0x3f3f3f3f;
        while(l<r) {
            int mid=l+r>>1;
            int t=check(mid);
            if(t>=q) {
                r=mid;
                if(t==q) res=min(res,mid);
            }
            else l=mid+1;
        }
        printf("Case %d: ",cs);
        if(res==0x3f3f3f3f)  puts("impossible");
        else printf("%d\n",l);
    }
    return 0;
}