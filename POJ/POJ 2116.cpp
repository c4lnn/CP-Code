#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
LL f[105];
string a,b,c;
string solve(int x) {
    if(!x) return "0";
    string res;
    bool st=false;
    for(int i=44;i>=0;i--) {
        if(x>=f[i]) x-=f[i],res+='1',st=true;
        else if(st) res+='0';
    }
    return res;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    f[0]=1,f[1]=2;
    for(int i=2;i<45;i++) f[i]=f[i-1]+f[i-2];
    LL res=0;
    while(cin>>a>>b) {
        LL x=0,y=0;
        for(int i=SZ(a)-1;i>=0;i--) if(a[i]=='1') x+=f[SZ(a)-1-i];
        for(int i=SZ(b)-1;i>=0;i--) if(b[i]=='1') y+=f[SZ(b)-1-i];
        a=solve(x);
        b=solve(y);
        c=solve(x+y);
        int mx=SZ(c);
        for(int i=0;i<mx-SZ(a)+2;i++) putchar(' ');
        cout<<a<<'\n';
        putchar('+');
        for(int i=0;i<mx-SZ(b)+1;i++) putchar(' ');
        cout<<b<<'\n';
        cout<<"  ";
        for(int i=0;i<mx;i++) putchar('-');
        cout<<"\n  "<<c<<"\n\n";
    }
    return 0;
}