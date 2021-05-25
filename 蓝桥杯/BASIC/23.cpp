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
int main() {
    int n,a[30][30],count_1,count_2;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++) {
        count_1=0;
        count_2=0;
        for(int j=0;j<n;j++)
            if(a[i][j]==1)
                count_1++;
        if(count_1>n-count_1) {
            for(int j=0;j<n;j++)
                if(a[j][i]==1)
                    count_2++;
            if(count_2>n-count_2)
                printf("%d ",i+1);
        }
    }
    return 0;
}