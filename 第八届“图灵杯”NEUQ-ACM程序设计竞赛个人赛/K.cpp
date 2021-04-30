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
//head
string s;
vector<char> a,b;
int main() {
    #ifdef DEBUG
        freopen("E:/OneDrive/IO/in.txt","r",stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    for(int i=0;i<32;i++) {
        if(isdigit(s[i])) b.PB(s[i]);
        else a.PB(s[i]);
    }
    for(int i=0;i<=3;i++) {
        for(int j=0;j<4;j++) {
            char c=a[4*i+j];
            int d=b[4*i+j]-'0';
            if(c>='A'&&c<='Z') {
                if(c-'A'+d>25) a[4*i+j]=c-'A'+d-26+'b';
                else a[4*i+j]=c+d;
            }
            else {
                if(c-'a'+d>25) a[4*i+j]=c-'a'+d-26+'B';
                else a[4*i+j]=c+d;
            }
        }
    }
    for(int i=0;i<=3;i++) {
        for(int j=3;~j;j--) {
            cout<<a[4*i+j];
        }
    }
    cout<<'\n';
    return 0;
}