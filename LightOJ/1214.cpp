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
string a;
LL b;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        cin>>a>>b;
        b=abs(b);
        LL t=0;
        for(int i=0;i<SZ(a);i++) {
            if(a[i]=='-') continue;
            t=t*10+a[i]-'0';
            t%=b;
        }
        cout<<"Case "<<cs<<": ";
        puts(t?"not divisible":"divisible");
    }
    return 0;
}