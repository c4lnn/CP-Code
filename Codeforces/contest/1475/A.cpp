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
//head
map<LL,bool> mp;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<=60;i++) mp[1ll<<i]=true;
    int T;
    cin>>T;
    while(T--) {
        LL n;
        cin>>n;
        if(n==1||mp.count(n)) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
    return 0;
}