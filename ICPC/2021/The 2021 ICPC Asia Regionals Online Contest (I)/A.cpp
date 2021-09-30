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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k,n;cin>>k>>n;
    VI cnt(k);
    set<int> s;
    for(int i=0;i<k;i++) s.insert(i);
    priority_queue<PII,VPII,greater<PII>> q;
    for(int i=0;i<n;i++) {
        int a,b;cin>>a>>b;
        while(SZ(q)&&q.top().FI<=a) {
            s.insert(q.top().SE);
            q.pop();
        }
        if(!SZ(s)) continue;
        auto pos=s.lower_bound(i%k);
        if(pos==s.end()) pos=s.begin();
        ++cnt[*pos];
        q.emplace(a+b,*pos);
        s.erase(pos);
    }
    int mx=0;
    for(int i=0;i<k;i++) if(cnt[i]>mx) mx=cnt[i];
    VI res;
    for(int i=0;i<k;i++) if(cnt[i]==mx) res.PB(i);
    for(int i=0;i<SZ(res);i++) {
        cout<<res[i];
        if(i!=SZ(res)-1) cout<<' ';
    }
    return 0;
}