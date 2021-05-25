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
    int n;cin>>n;
    int sum=0,mn=0x3f3f3f3f,mx=0xc0c0c0c0;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        sum+=x;
        mn=min(mn,x);
        mx=max(mx,x);
    }
    cout<<mx<<'\n';
    cout<<mn<<'\n';
    cout<<sum<<'\n';
    return 0;
}