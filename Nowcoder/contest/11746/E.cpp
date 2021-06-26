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
    #ifdef DEBUG
        freopen("E:/OneDrive/IO/in.txt","r",stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int n,x;
        cin>>n>>x;
        int a=x-1,b=n-x;
        //cout<<a<<" "<<b<<'\n';
        if(a>b) swap(a,b);
        int t=(b-a)*(1+sqrt(5))/2;
        cout<<(t!=a?"yo xi no forever!":"ma la se mi no.1!")<<'\n';
    }
    return 0;
}