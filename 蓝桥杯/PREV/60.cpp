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
const int M[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
set<int> s1,s2;
void init() {
    for(int i=1;i<=12;i++) {
        int t=i%10*10+i/10;
        for(int j=1;j<=M[i];j++) if(j%10) {
            s1.insert(((j%10*10+j/10)*100+t)*10000+i*100+j);
        }
        if(i!=10) s2.insert(((i%10*10+i/10)*100+t)*10000+i*100+i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int x;cin>>x;
    cout<<*s1.upper_bound(x)<<'\n';
    cout<<*s2.upper_bound(x)<<'\n';
    return 0;
}