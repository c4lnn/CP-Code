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
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    int n;
    string s1,s2;
    while(tt--) {
        scanf("%d",&n);
        cin>>s1>>s2;
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++) {
            if(s1[i]>s2[i]) sum1++;
            else if(s1[i]<s2[i]) sum2++;
        }
        if(sum1>sum2) puts("RED");
        else if(sum1<sum2) puts("BLUE");
        else puts("EQUAL");
    }
    return 0;
}