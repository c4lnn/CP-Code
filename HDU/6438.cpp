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
struct R {
    int x,y;
    R() {}
    R(int x,int y):x(x),y(y) {}
    bool operator < (const R &T) const {
        return x>T.x||x==T.x&&y>T.y;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        priority_queue<R> q;
        VI a(n+1);
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            if(SZ(q)&&q.top().x<a[i]) {
                auto u=q.top();
                q.pop();
                q.emplace(a[i],u.y==0x3f3f3f3f?u.x:u.y);
            }
            q.emplace(a[i],0x3f3f3f3f);
        }
        pair<LL,int> res=MP(0,0);
        while(SZ(q)) {
            auto u=q.top();
            q.pop();
            if(u.x>u.y) res.FI+=u.x-u.y,res.SE+=2;
        }
        cout<<res.FI<<' '<<res.SE<<'\n';
    }
    return 0;
}