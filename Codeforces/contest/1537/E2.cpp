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
    int n,m;cin>>n>>m;
    string s;cin>>s;
    for(int i=1;i<n;i++) {
        if(s[i]>s[0]) {
            for(int k=0;k<m;k++) cout<<s[k%i];
            cout<<'\n';
            return 0;
        }
        else if(s[i]==s[0]) {
            bool f=false;
            for(int j=1;j<=i-1;j++) {
                if(i+j>=n) {
                    for(int k=0;k<m;k++) cout<<s[k%i];
                    cout<<'\n';
                    return 0;
                }
                if(s[i+j]>s[j]) {
                    for(int k=0;k<m;k++) cout<<s[k%i];
                    cout<<'\n';
                    return 0;
                }
                else if(s[i+j]<s[j]) {
                    i=i+j;
                    f=true;
                    break;
                }
            }
            if(!f) i+=i-1;
        }
    }
    for(int k=0;k<m;k++) cout<<s[k%n];
    cout<<'\n';
    return 0;
}