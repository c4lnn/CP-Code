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
string t,s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    for(int i=0;i<SZ(t);i++) {
        if(i<SZ(t)-1&&t[i]<='b'&&t[i+1]<='f') {
            for(int j=0;j<i;j++) cout<<t[j];
            int x=(t[i]-'a'+1)*10+(t[i+1]-'a'+1);
            cout<<(char)(x-1+'a');
            for(int j=i+2;j<SZ(t);j++) cout<<t[j];
            cout<<'\n';
            return 0;
        }
        else if(t[i]-'a'>=10&&t[i]-'a'!=19) {
            for(int j=0;j<i;j++) cout<<t[j];
            int x=t[i]-'a'+1;
            cout<<(char)(x/10-1+'a')<<(char)(x%10-1+'a');
            for(int j=i+1;j<SZ(t);j++) cout<<t[j];
            cout<<'\n';
            return 0;
        }

    }
    cout<<-1<<'\n';
    return 0;
}