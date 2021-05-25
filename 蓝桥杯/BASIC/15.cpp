#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,t;cin>>s>>t;
    if(SZ(s)!=SZ(t)) cout<<1<<'\n';
    else if(s==t) cout<<2<<'\n';
    else {
        bool f=true;
        for(int i=0;i<SZ(s);i++) {
            int t1,t2;
            if(s[i]>='A'&&s[i]<='Z') t1=s[i]-'A';
            else t1=s[i]-'a';
            if(t[i]>='A'&&t[i]<='Z') t2=t[i]-'A';
            else t2=t[i]-'a';
            if(t1!=t2) {f=false;break;}
        }
        cout<<(f?3:4)<<'\n';
    }
    return 0;
}