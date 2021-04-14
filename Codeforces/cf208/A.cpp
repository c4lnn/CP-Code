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
    string s;cin>>s;
    for(int i=0,f=0;i<SZ(s);i++) {
        if(s[i]=='W'&&i+1<SZ(s)&&s[i+1]=='U'&&i+2<SZ(s)&&s[i+2]=='B') {
            if(f) cout<<' ';
            i+=2;
        }
        else cout<<s[i],f=1;
    }
    cout<<'\n';
    return 0;
}