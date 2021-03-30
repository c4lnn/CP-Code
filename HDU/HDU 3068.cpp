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
const int N=2e5+5;
char s[N],t[N<<1];
int len[N<<1];
int manacher(const string &s) {
    int l=s.length(),k=0;
    t[0]='$';
    for(int i=0;i<l;i++) t[++k]='#',t[++k]=s[i];
    t[++k]='#';
    len[0]=0;
    int sum=0,id=0,mx=0;
    for(int i=1;i<=k;i++) {
        len[i]=i<mx?min(mx-i,len[2*id-i]):1;
        while(i-len[i]>=0&&i+len[i]<=k&&t[i-len[i]]==t[i+len[i]]) ++len[i];
        if(len[i]+i>mx) {
            mx=len[i]+i;
            id=i;
            sum=max(sum,len[i]); // 更新id回文串中点和mx回文串最右端
        }
    }
    return sum-1; // 返回最大回文串长度
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%s",&s)) {
        printf("%d\n",manacher(s));
    }
    return 0;
}