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
// head
template<typename T>
bool read(T &t){
    static char ch;
    int f=1;
    while(ch!=EOF&&!isdigit(ch)) {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    if(ch==EOF) return false;
    for(t=0;isdigit(ch);ch=getchar()) t=t*10+ch-'0';
    t*=f;
    return true;
}
template<typename T>
void print(T t) {
    static int stk[70],top;
    if(t==0) {putchar('0');return;}
    if(t<0) {t=-t;putchar('-');}
    while(t) stk[++top]=t%10,t/=10;
    while(top) putchar(stk[top--]+'0');
}
PII a[25];
bool cmp(PII x,PII y) {
    return y.FI*x.SE-x.FI*y.SE+y.SE-x.SE>0;
}
int main() {
    int n;
    __int128 x;
    cin>>n;
    read(x);
    for(int i=1;i<=n;i++) cin>>a[i].FI>>a[i].SE;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) x=x*a[i].FI+a[i].SE;
    print(x);
    return 0;
}