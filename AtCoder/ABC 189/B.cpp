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
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int x;
    cin>>n>>x;
    x*=100;
    int res=0;
    int t=-1;
    for(int i=1;i<=n;i++) {
        int v,p;
        cin>>v>>p;
        res+=v*p;
        if(t==-1&&res>x) t=i;
    }
    cout<<t<<'\n';
    return 0;
}