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
int n;
bool solve(string &s1,string &s2,string &s3,int a,int b,int c) {
    if(c-a+b>n) return cout<<"NO"<<'\n',false;
    for(int i=0;i<a;i++) s1+='a',s2+='a',s3+='a';
    for(int i=0;i<b-a;i++) s2+='b',s3+='b';
    for(int i=0;i<c-a;i++) s1+='c',s3+='c';
    while(SZ(s1)<n) s1+='d';
    while(SZ(s2)<n) s2+='e';
    while(SZ(s3)<n) s3+='f';
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c;cin>>a>>b>>c>>n;
    string s1="",s2="",s3="";
    bool ret=0;
    if(a<=b&&a<=c) {
        if(b<=c) ret=solve(s1,s2,s3,a,b,c);
        else ret=solve(s2,s1,s3,a,c,b);
    }
    else if(b<=a&&b<=c) {
        if(a<=c) ret=solve(s3,s2,s1,b,a,c);
        else ret=solve(s2,s3,s1,b,c,a);
    }
    else if(c<=a&&c<=b) {
        if(a<=b) ret=solve(s3,s1,s2,c,a,b);
        else ret=solve(s1,s3,s2,c,b,a);
    }
    if(ret) cout<<s1<<'\n'<<s2<<'\n'<<s3<<'\n';
    return 0;
}