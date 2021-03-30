#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

const int N=1e6+5;
const int P=13331;
char s[N];
ull h1[N],h2[N];
ull  p[N];

int main(){
    p[0]=1;
    for(int k=1;;k++){
        scanf("%s",s+1);
        if(strcmp(s+1,"END")==0) break;
        int len=strlen(s+1);
        int res=INT_MIN;
        for(int i=1;i<=len;i++){
            h1[i]=h1[i-1]*P+s[i]-'a'+1;
            p[i]=p[i-1]*P;
        }
        for(int i=len;i>=1;i--) h2[i]=h2[i+1]*P+s[i]-'a'+1;
        for(int i=1;i<=len;i++){
            int l=0,r=min(i,len-i+1);
            while(l<r){
                int mid=l+r+1>>1;
                if(h1[i]-h1[i-mid]*p[mid]==h2[i]-h2[i+mid]*p[mid]) l=mid;
                else r=mid-1;
           }
            res=max(res,2*l-1);
            l=0,r=min(i,len-i);
            while(l<r){
                int mid=l+r+1>>1;
                if(h1[i]-h1[i-mid]*p[mid]==h2[i+1]-h2[i+1+mid]*p[mid]) l=mid;
                else r=mid-1;
            }
            res=max(res,2*l);
        }
        printf("Case %d: %d\n",k,res);
    }
    return 0;
}