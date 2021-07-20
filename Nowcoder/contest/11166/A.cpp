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
bool sg[5005][5005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<1360*2;i+=2) sg[a[i]][a[i+1]]=true;
    int T;cin>>T;
    while(T--) {
        int n,m;cin>>n>>m;
        if(n>m) swap(n,m);
        cout<<(!sg[n][m]?"Alice":"Bob")<<'\n';
    }
    return 0;
}