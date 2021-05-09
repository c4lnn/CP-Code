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
    int n;cin>>n;
    VI a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    multiset<int> s;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        s.insert(x);
    }
    for(int i=1;i<=n;i++) {
        auto pos=s.lower_bound(n-a[i]);
        if(pos==s.end()) pos=s.begin();
        cout<<(a[i]+*pos)%n<<" \n"[i==n];
        s.erase(pos);
    }
    return 0;
}