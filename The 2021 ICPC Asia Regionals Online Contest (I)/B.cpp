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
const int N=105;
int top;
PII p[N],stk[N];
int solve(PII a,PII b) {
    return a.FI*b.SE-a.SE*b.FI;
}
int main() {
    int n=0,x,y;
    while(~scanf("%d,%d,",&x,&y)) {
        p[++n]=MP(x,y);
    }
    if(n<=2) cout<<"ERROR";
    else {
        sort(p+1,p+1+n);
        // 有重复点需要去重，至少三个不相同的点才能构成凸包，根据题意判断点或线段的特殊情况
        for(int i=1;i<=2;i++) stk[++top]=p[i];
        for(int i=3;i<=n;i++) {
            while(top>=2&&solve(MP(stk[top].FI-stk[top-1].FI,stk[top].SE-stk[top-1].SE),MP(p[i].FI-stk[top].FI,p[i].SE-stk[top].SE))<=0) --top;
            stk[++top]=p[i];
        }
        int temp=top;
        stk[++top]=p[n-1];
        for(int i=n-2;i>=1;i--) {
            while(top>=temp&&solve(MP(stk[top].FI-stk[top-1].FI,stk[top].SE-stk[top-1].SE),MP(p[i].FI-stk[top].FI,p[i].SE-stk[top].SE))<=0) --top;
            stk[++top]=p[i];
        }
        // 1 和 top 为同一个点，凸包上共有 top - 1 个点
        if(top-1==n) {
            int mn=0x3f3f3f3f,pos=0;
            for(int i=1;i<top;i++) if(stk[i].FI*stk[i].FI+stk[i].SE*stk[i].SE<mn) {
                mn=stk[i].FI*stk[i].FI+stk[i].SE*stk[i].SE;
                pos=i;
            }
            VPII res;
            for(int i=pos;i>=1;i--) res.PB(stk[i]);
            for(int i=top-1;i>pos;i--) res.PB(stk[i]);
            for(int i=0;i<SZ(res);i++) {
                cout<<res[i].FI<<','<<res[i].SE;
                if(i!=SZ(res)-1) cout<<',';
            }
        }
        else cout<<"ERROR";
    }
    return 0;
}