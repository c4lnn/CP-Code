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
bool cmp(PII a,PII b) {
    return a.FI<b.FI||a.FI==b.FI&&a.SE<b.SE;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n;i++) {
            string s;
            int ed,c;
            cin>>s;
            scanf("%d%d",&ed,&c);
            a.EB(s,ed,c);
        }
        for(int i=0;i<(1<<n);i++) {
            for(int j=0;j<n;j++) {
                if(1&(i<<j))
            }
        }
    }
    return 0;
}