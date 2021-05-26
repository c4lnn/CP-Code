#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
map<string,int> sg;
int dfs(string s) {
    if(sg.count(s)) return sg[s];
    if(s.find("*OL")!=-1||s.find("L*L")!=-1||s.find("LO*")!=-1) return sg[s]=1;
    if(s.find('*')==-1) return sg[s]=0;
    int f=-1;
    for(int i=0;i<SZ(s);i++) if(s[i]=='*') {
        s[i]='L';
        int ret=dfs(s);
        if(ret==-1) {
            s[i]='*';
            return sg[s]=1;
        }
        else if(ret==0) f=0;
        s[i]='O';
        ret=dfs(s);
        if(ret==-1) {
            s[i]='*';
            return sg[s]=1;
        }
        else if(ret==0) f=0;
        s[i]='*';
    }
    return sg[s]=f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        sg.clear();
        string s;cin>>s;
        cout<<dfs(s)<<'\n';
    }
    return 0;
}