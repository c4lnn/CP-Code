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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
int n,k;
VI a;
bool check(int mid) {
    unordered_map<int,int> mp;
    deque<PII> dq;
    int sum=0,cnt=0;
    for(int i=0;i<n;i++) {
        int x=a[i];
        while(SZ(dq)&&mp[dq.front().FI]!=dq.front().SE) dq.pop_front();
        if(mp.count(x)) {
            ++sum;
            dq.EB(x,i);
            mp[x]=i;
        }
        else if(cnt<mid) {
            dq.EB(x,i);
            mp[x]=i;
            ++cnt;
        }
        else {
            mp.erase(dq.front().FI);
            dq.pop_front();
            dq.EB(x,i);
            mp[x]=i;

        }
    }
    return sum>=k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l=1,r=1e9;
    while(l<r) {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l==1e9) cout<<"cbddl"<<'\n';
    else cout<<l<<'\n';
    return 0;
}