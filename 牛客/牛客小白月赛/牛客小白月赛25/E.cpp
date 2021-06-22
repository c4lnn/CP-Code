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
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
char s[300005];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%s",s);
    stack<char> stk;
    for(int i=0;s[i];i++) {
        if(SZ(stk)&&stk.top()==s[i]) stk.pop();
        else stk.push(s[i]);
    }
    string res="";
    while(SZ(stk)) res+=stk.top(),stk.pop();
    reverse(ALL(res));
    if(res.length()==0) puts("0");
    else cout<<res<<'\n';
    return 0;
}