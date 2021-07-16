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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    if(n==0) cout<<'('<<'\n';
    else {
        int b=sqrt(n);
        int a=n/b;
        int c=n-a*b;
        for(int i=1;i<=a;i++) cout<<'(';
        for(int i=1;i<=b;i++) {
            cout<<')';
            if(b-i==c) cout<<'(';
        }
        cout<<'\n';
    }
    return 0;
}