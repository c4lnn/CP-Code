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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int k;string s;cin>>k>>s;
        bool f=false;
        for(auto c:s) {
            if(c=='1'||c=='4'||c=='6'||c=='8'||c=='9') {
                cout<<1<<'\n'<<c<<'\n';
                f=true;
                break;
            }
        }
        if(f) continue;
        vector<bool> vis(10);
        cout<<2<<'\n';
        for(auto c:s) {
            if(c=='2'||c=='5') {
                if(vis[2]) {cout<<2<<c<<'\n';break;}
                if(vis[3]) {cout<<3<<c<<'\n';break;}
                if(vis[5]) {cout<<5<<c<<'\n';break;}
                if(vis[7]) {cout<<7<<c<<'\n';break;}
            }
            else if(c=='3') {
                if(vis[3]) {cout<<33<<'\n';break;}
            }
            else if(c=='7') {
                if(vis[2]) {cout<<27<<'\n';break;}
                if(vis[5]) {cout<<57<<'\n';break;}
                if(vis[7]) {cout<<77<<'\n';break;}
            }
            vis[c-'0']=true;
        }
    }
    return 0;
}