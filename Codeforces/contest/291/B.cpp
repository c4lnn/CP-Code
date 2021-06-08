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
string s,ss;
bool l;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    getline(cin,s);
    for(int i=0;i<SZ(s);i++) {
        if(s[i]=='"') {
            if(l) {
                l=false;
                cout<<'<'<<ss<<'>'<<'\n';
                ss="";
            }
            else l=true;
        }
        else if(s[i]==' ') {
            if(l) ss+=s[i];
            else {
                if(SZ(ss)) {
                    cout<<'<'<<ss<<'>'<<'\n';
                    ss="";
                }
            }
        }
        else {
            ss+=s[i];
        }
    }
    if(SZ(ss)) cout<<'<'<<ss<<'>'<<'\n';
    return 0;
}