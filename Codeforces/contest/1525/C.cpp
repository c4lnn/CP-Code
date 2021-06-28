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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const int N=3e5+5;
int stk1[N],stk2[N],res[N];
pair<pair<int,char>,int> a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++) res[i]=-1;
        for(int i=1;i<=n;i++) cin>>a[i].FI.FI;
        for(int i=1;i<=n;i++) cin>>a[i].FI.SE;
        for(int i=1;i<=n;i++) a[i].SE=i;
        sort(a+1,a+1+n);
        int top1=0,top2=0;
        for(int i=1;i<=n;i++) {
            if(a[i].FI.FI&1) {
                if(a[i].FI.SE=='R') stk1[++top1]=i;
                else {
                    if(top1>=1) res[a[i].SE]=res[a[stk1[top1]].SE]=(a[i].FI.FI-a[stk1[top1]].FI.FI)/2,--top1;
                    else a[i].FI.FI=-a[i].FI.FI,stk1[++top1]=i;
                }
            }
            else {
                if(a[i].FI.SE=='R') stk2[++top2]=i;
                else {
                    if(top2>=1) res[a[i].SE]=res[a[stk2[top2]].SE]=(a[i].FI.FI-a[stk2[top2]].FI.FI)/2,--top2;
                    else a[i].FI.FI=-a[i].FI.FI,stk2[++top2]=i;
                }
            }
        }
        while(top1>1) res[a[stk1[top1]].SE]=res[a[stk1[top1-1]].SE]=(m-a[stk1[top1]].FI.FI+m-a[stk1[top1-1]].FI.FI)/2,top1-=2;
        while(top2>1) res[a[stk2[top2]].SE]=res[a[stk2[top2-1]].SE]=(m-a[stk2[top2]].FI.FI+m-a[stk2[top2-1]].FI.FI)/2,top2-=2;
        for(int i=1;i<=n;i++) {
            cout<<res[i]<<" \n"[i==n];
        }
    }
    return 0;
}