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
char a[4][4];
bool check() {
    for(int i=1;i<=3;i++) {
        int cnt1=0,cnt2=0;
        for(int j=1;j<=3;j++) {
            if(a[i][j]=='W') ++cnt1;
            else if(a[i][j]=='#') ++cnt2;
        }
        if(cnt1==2&&cnt2==1) return false;
    }
    for(int i=1;i<=3;i++) {
        int cnt1=0,cnt2=0;
        for(int j=1;j<=3;j++) {
            if(a[j][i]=='W') ++cnt1;
            else if(a[j][i]=='#') ++cnt2;
        }
        if(cnt1==2&&cnt2==1) return false;
    }
    int cnt1=0,cnt2=0;
    if(a[1][1]=='W') cnt1++;
    else if(a[1][1]=='#') cnt2++;
    if(a[2][2]=='W') cnt1++;
    else if(a[2][2]=='#') cnt2++;
    if(a[3][3]=='W') cnt1++;
    else if(a[3][3]=='#') cnt2++;
    if(cnt1==2&&cnt2==1) return false;
    cnt1=0,cnt2=0;
    if(a[1][3]=='W') cnt1++;
    else if(a[1][3]=='#') cnt2++;
    if(a[2][2]=='W') cnt1++;
    else if(a[2][2]=='#') cnt2++;
    if(a[3][1]=='W') cnt1++;
    else if(a[3][1]=='#') cnt2++;
    if(cnt1==2&&cnt2==1) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        for(int i=1;i<=3;i++) cin>>(a[i]+1);
        if(check()) cout<<"Bob"<<'\n';
        else {
            int tot=0;
            for(int i=1;i<=3;i++) {
                for(int j=1;j<=3;j++) if(a[i][j]=='W') {
                    a[i][j]='#';
                    ++tot;
                    if(!check()) --tot;
                    a[i][j]='W';
                }
            }
            cout<<(!tot?"Alice":"Emmm")<<'\n';
        }
    }
    return 0;
}