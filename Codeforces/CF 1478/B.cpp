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
//head
bool check1(int x,int d) {
    while(x) {
        if(x%10==d) return true;
        x/=10;
    }
    return false;
}
bool check2(int x,int d) {
    for(int i=1;i<=10;i++) if(i*d<=x&&i*d%10==x%10) return true;
    int f=0;
    if(x%10<d) f=1;
    if(x/10-f-d>=0) return true;
    return false;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int q,d;
        cin>>q>>d;
        for(int i=1;i<=q;i++) {
            int x;
            cin>>x;
            if(check1(x,d)) cout<<"YES"<<'\n';
            else cout<<(check2(x,d)?"YES":"NO")<<'\n';
        }
    }
    return 0;
}