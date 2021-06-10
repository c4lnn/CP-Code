#include<bits/stdc++.h>
using namespace std;
const int N=60;
char a[N],b[N];
int f[N][N][N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        cin>>a+1;
        cin>>b+1;
        int len_a=strlen(a+1),len_b=strlen(b+1);
        int res=1;
        for(int len1=0;len1<=len_a;len1++)
            for(int len2=0;len2<=len_b;len2++)
                for(int i=1;i+len1-1<=len_a;i++)
                    for(int k=1;k+len2-1<=len_b;k++) {
                        int j=i+len1-1,l=k+len2-1;
                        if(len1+len2<=1) f[i][j][k][l]=1;
                        else {
                            f[i][j][k][l]=0;
                            if(len1>1) f[i][j][k][l]|=(f[i+1][j-1][k][l]&&a[i]==a[j]);
                            if(len2>1) f[i][j][k][l]|=(f[i][j][k+1][l-1]&&b[k]==b[l]);
                            if(len1&&len2) {
                                f[i][j][k][l]|=(f[i+1][j][k][l-1]&&(a[i]==b[l]));
                                f[i][j][k][l]|=(f[i][j-1][k+1][l]&&(a[j]==b[k]));
                            }
                        }
                        if(f[i][j][k][l]) res=max(res,len1+len2);
                    }
        cout<<res<<endl;
    }
    return 0;
}