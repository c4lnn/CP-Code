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
int cnt1[10],cnt2[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;cin>>a>>b;
    while(a%2==0) a/=2,++cnt1[2];
    while(a%3==0) a/=3,++cnt1[3];
    while(a%5==0) a/=5,++cnt1[5];
    while(b%2==0) b/=2,++cnt2[2];
    while(b%3==0) b/=3,++cnt2[3];
    while(b%5==0) b/=5,++cnt2[5];
    if(a!=b) cout<<-1<<'\n';
    else cout<<abs(cnt1[2]-cnt2[2])+abs(cnt1[3]-cnt2[3])+abs(cnt1[5]-cnt2[5])<<'\n';
    return 0;
}