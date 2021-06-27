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
    int mx=1;
    for(int i=1;i<n;i++) {
        if(s[i]>s[i%mx]) break;
        else if(s[i]<s[i%mx]) mx=i+1;
    }
    for(int i=0;i<m;i++) cout<<s[i%mx];
    cout<<'\n';
    return 0;
}