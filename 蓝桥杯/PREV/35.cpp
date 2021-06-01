#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
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
int n;
string s;
int solve(int &x) {
    int ret=0,cnt=0;
    while(x<n) {
        if(s[x]=='x') ++cnt;
        else if(s[x]=='|') ret=max(ret,cnt),cnt=0;
        else if(s[x]=='(') {
            if(x>=1&&s[x-1]=='|') ret=max(ret,solve(++x));
            else cnt+=solve(++x);
        }
        else if(s[x]==')') {
            ret=max(ret,cnt);
            while(s[x+1]=='x') ++x,++ret;
            return ret;
        }
        ++x;
    }
    return max(ret,cnt);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    n=SZ(s);
    int x=0;
    cout<<solve(x)<<'\n';
    return 0;
}