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
int cnt[30];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    char c;
    while(~scanf("%c",&c)) if(c>='a'&&c<='z') cnt[c-'a']++;
    int res=0;
    for(int i=0;i<26;i++) if(cnt[i]>cnt[res]) res=i;
    printf("%c\n",'a'+res);
    return 0;
}