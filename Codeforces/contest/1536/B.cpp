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
string s,res;
bool dfs(int x,string ss) {
    if(!x) {
        if(s.find(ss)==string::npos) {
            res=ss;
            return false;
        }
        return true;
    }
    for(int i=0;i<26;i++) {
        if(!dfs(x-1,ss+(char)('a'+i))) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        cin>>s;
        for(int i=1;;i++) {
            if(!dfs(i,"")) {
                cout<<res<<'\n';
                break;
            }
        }
    }
    return 0;
}