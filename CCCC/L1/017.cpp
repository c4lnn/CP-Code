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
    string s;cin>>s;
    DB f1=1,f2=1;
    int len=SZ(s);
    if(s[0]=='-') --len,f1=1.5;
    int cnt=0;
    for(auto c:s) if(c=='2') ++cnt;
    if((s[SZ(s)-1]-'0')%2==0) f2=2;
    printf("%.2lf\%\n",100.0*cnt/len*f1*f2);
    return 0;
}