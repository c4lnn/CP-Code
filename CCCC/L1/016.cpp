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
const int A[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char T[]="10X98765432";
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        string s;cin>>s;
        bool f=false;
        int z=0;
        for(int j=0;j<17;j++) {
            if(s[j]>='0'&&s[j]<='9') z+=(s[j]-'0')*A[j];
            else {f=true;break;}
        }
        z%=11;
        if(T[z]!=s[17]) f=true;
        if(f) ++cnt,cout<<s<<'\n';
    }
    if(!cnt) cout<<"All passed";
    return 0;
}