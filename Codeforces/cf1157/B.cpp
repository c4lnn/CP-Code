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
    int n;cin>>n;
    string s;cin>>s;
    VI a(10);
    for(int i=1;i<=9;i++) cin>>a[i];
    bool f=false;
    for(int i=0;i<n;i++) {
        int t=s[i]-'0';
        if(!f&&a[t]<=t) continue;
        else if(a[t]>=t) f=true,s[i]=a[t]+'0';
        else if(f&&a[t]<t) break;
    }
    cout<<s<<'\n';
    return 0;
}