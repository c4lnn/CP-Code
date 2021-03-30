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
int f[50];
map<int,bool> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    f[1]=1,f[2]=1;
    for(int i=3;i<=46;i++) f[i]=f[i-1]+f[i-2],mp[f[i]]=true;
    int n;
    while(cin>>n) {
        if(!n) break;
        cout<<(mp.count(n)?"Second win":"First win")<<'\n';
    }
    return 0;
}