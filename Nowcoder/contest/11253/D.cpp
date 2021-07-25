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
int check(int a1,int b1,int a2,int b2) {
    if(a1==2&&b1==8&&a2==2&&b2==8) return 0;
    if(a1==2&&b1==8) return 1;
    if(a2==2&&b2==8) return 2;
    if(a1==b1&&a2==b2) {
        if(a1>a2) return 1;
        if(a1<a2) return 2;
        return 0;
    }
    if(a1==b1) return 1;
    if(a2==b2) return 2;
    if((a1+b1)%10>(a2+b2)%10) return 1;
    if((a1+b1)%10<(a2+b2)%10) return 2;
    if((a1+b1)%10==(a2+b2)%10) {
        if(b1>b2) return 1;
        if(b1<b2) return 2;
        return 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int a1,b1,a2,b2;cin>>a1>>b1>>a2>>b2;
        if(a1>b1) swap(a1,b1);
        if(a2>b2) swap(a2,b2);
        int ret=check(a1,b1,a2,b2);
        if(ret==1) cout<<"first"<<'\n';
        else if(ret==2) cout<<"second"<<'\n';
        else cout<<"tie"<<'\n';
    }
    return 0;
}