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
    int n;cin>>n;
    string s="/";
    for(int i=1;i<=n;i++) {
        string o;cin>>o;
        if(o[0]=='p') cout<<s<<'\n';
        else if(o[0]=='c') {
            string path;cin>>path;
            for(int j=0;j<SZ(path);j++) {
                if(j==0&&path[j]=='/') s='/';
                else if(path[j]=='.') {
                    if(SZ(s)>1) s.erase(SZ(s)-1);
                    while(s[SZ(s)-1]!='/') s.erase(SZ(s)-1);
                    j+=2;
                }
                else s+=path[j];
            }
            if(s[SZ(s)-1]!='/') s+='/';
        }
    }
    return 0;
}