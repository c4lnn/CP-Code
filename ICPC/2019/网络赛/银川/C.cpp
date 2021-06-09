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
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int n,m;cin>>n>>m;
        string s,t;cin>>s>>t;
        int d=(s[0]-t[0]+26)%26;
        cin>>t;
        cout<<"Case #"<<cs<<": ";
        for(int i=0;i<m;i++) cout<<(char)((t[i]-'A'+d)%26+'A');
        cout<<'\n';
    }

    return 0;
}