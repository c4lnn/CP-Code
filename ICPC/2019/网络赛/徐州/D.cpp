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
    string s,t;cin>>t;
    int q;cin>>q;
    while(q--) {
        cin>>s;
        if(SZ(s)<SZ(t)) {
            if(t.find(s)!=string::npos) cout<<"my child!"<<'\n';
            else cout<<"oh, child!"<<'\n';
        }
        else if(SZ(s)>SZ(t)) {
            if(s.find(t)!=string::npos) cout<<"my teacher!"<<'\n';
            else cout<<"senior!"<<'\n';
        }
        else {
            if(s==t) cout<<"jntm!"<<'\n';
            else cout<<"friend!"<<'\n';
        }
    }
    return 0;
}