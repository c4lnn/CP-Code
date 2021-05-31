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
// head
const int M[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check_leap(int x) {
    return x%100?x%4==0:x%400==0;
}
int get(char a,char b) {
    return (a-'0')*10+(b-'0');
}
bool check(int a,int b,int c) {
    if(b<1||b>12) return false;
    if(c==0) return false;
    if(check_leap(a>=60?1900+a:2000+a)&&b==2) return c<=29;
    return c<=M[b];
}
int main() {
    string s;cin>>s;
    int a=get(s[0],s[1]);
    int b=get(s[3],s[4]);
    int c=get(s[6],s[7]);
    vector<pair<int,PII> > res;
    if(check(a,b,c)) res.PB(MP(a,MP(b,c)));
    if(check(c,a,b)) res.PB(MP(c,MP(a,b)));
    if(check(c,b,a)) res.PB(MP(c,MP(b,a)));
    sort(ALL(res));
    res.resize(unique(ALL(res))-res.begin());
    for(int i=0;i<SZ(res);i++) {
        printf("%d-",res[i].FI>=60?1900+res[i].FI:2000+res[i].FI);
        printf("%02d-",res[i].SE.FI);
        printf("%02d\n",res[i].SE.SE);
    }
    return 0;
}