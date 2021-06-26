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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<LL> sum(n+1),b(n+1),l(n+1),r(n+1);
    for(int i=1;i<=n;i++) {
        LL x;
        cin>>x;
        sum[i]=sum[i-1]+x;
    }
    for(int i=1;i<=n;i++) cin>>b[i];
    stack<int> s;
    for(int i=1;i<=n;i++) {
        while(SZ(s)&&b[s.top()]>b[i]) r[s.top()]=i,s.pop();
        s.push(i);
    }
    while(SZ(s)) r[s.top()]=n+1,s.pop();
    for(int i=n;i;i--) {
        while(SZ(s)&&b[s.top()]>b[i]) l[s.top()]=i,s.pop();
        s.push(i);
    }
    LL res=0;
    for(int i=1;i<=n;i++) res=max(res,(sum[r[i]-1]-sum[l[i]])*b[i]);
    cout<<res<<'\n';
    return 0;
}