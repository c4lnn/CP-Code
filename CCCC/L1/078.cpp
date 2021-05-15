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
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
int main() {
    int n,m;cin>>n>>m;
    getchar();
    for(int i=1;i<=n;i++) {
        string s;getline(cin,s);
        if(s.find("qiandao")!=string::npos||s.find("easy")!=string::npos) continue;
        if(!m) {
            return cout<<s<<'\n',0;
        }
        --m;
    }
    cout<<"Wo AK le"<<'\n';
    return 0;
}