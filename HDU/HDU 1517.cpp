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
const int N=10;
LL l0[N],r0[N],l1[N],r1[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    l0[0]=1,r0[0]=9,l1[0]=10,r1[0]=18;
    for(int i=1;;i++) {
        l0[i]=r1[i-1]+1,r0[i]=r1[i-1]*9;
        l1[i]=r0[i]+1,r1[i]=r0[i]*2;
        if(r1[i]>4294967295ll) break;
    }
    LL n;
    while(cin>>n) {
        for(int i=0;i<7;i++) {
            if(n>=l0[i]&&n<=r0[i]) {cout<<"Stan wins."<<'\n';break;}
            else if(n>=l1[i]&&n<=r1[i]) {cout<<"Ollie wins."<<'\n';break;}
        }
    }
    return 0;
}