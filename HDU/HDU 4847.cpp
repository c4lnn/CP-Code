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
const int N=1e5+5;
string s;
int res;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(cin>>s) {
        int t=0;
        for(int i=0;i<SZ(s);i++) {
            if(t==0&&(s[i]=='d'||s[i]=='D')) t++;
            else if(t==1&&(s[i]=='o'||s[i]=='O')) t++;
            else if(t==2&&(s[i]=='g'||s[i]=='G')) t++;
            else if(t==3&&(s[i]=='e'||s[i]=='E')) t=0,res++;
            else t=0;
       }
    }
    printf("%d\n",res);
    return 0;
}