#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;cin>>s;
    VI cnt(26);
    for(int i=0;i<SZ(s);i++) cnt[s[i]-'a']++;
    int mx=0;
    for(int i=0;i<26;i++) if(cnt[i]>cnt[mx]) mx=i;
    cout<<(char)(mx+'a')<<'\n';
    cout<<cnt[mx]<<'\n';
    return 0;
}