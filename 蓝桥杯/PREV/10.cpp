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
    int n,m;cin>>n>>m;
    priority_queue<int,VI,greater<int> > a,b;
    for(int i=3;i<=m;i+=2) a.push(i);
    int t=1,res=0;
    while(SZ(a)&&a.top()<m) {
        ++t;
        int d=a.top();
        if(d>n) ++res;
        a.pop();
        int tt=t;
        while(SZ(a)) {
            ++tt;
            if(tt%d) b.push(a.top());
            a.pop();
        }
        swap(a,b);
    }
    cout<<res<<'\n';
    return 0;
}