#include<bits/stdc++.h>
using namespace std;
char s[100001]; 
map<char,int>mp;
char p[10][6][4]={ 
                    "QWE","QEW","WQE","WEQ","EQW","EWQ",
                    "WWW","WWW","WWW","WWW","WWW","WWW",
                    "WEE","WEE","EWE","EEW","EWE","EEW",
                    "QEE","QEE","EQE","EEQ","EQE","EEQ",
                    "QQE","QEQ","QQE","QEQ","EQQ","EQQ",
                    "EEE","EEE","EEE","EEE","EEE","EEE",
                    "QQW","QWQ","QQW","QWQ","WQQ","WQQ",
                    "QWW","QWW","WQW","WWQ","WQW","WWQ",
                    "QQQ","QQQ","QQQ","QQQ","QQQ","QQQ",
                    "WWE","WEW","WWE","WEW","EWW","EWW",
                  };
int dp[100001][6];
int cmp(int a,int b,int c,int d)
{
    if(!strcmp(p[a][b],p[c][d])) return 0;
    else if(p[a][b][1]==p[c][d][0]&&p[a][b][2]==p[c][d][1]) return 1;
    else if(p[a][b][2]==p[c][d][0]) return 2;
    return 3;
}
int main()
{
    mp['B']=0,mp['C']=1,mp['D']=2,mp['F']=3,mp['G']=4,mp['T']=5,mp['V']=6,mp['X']=7,mp['Y']=8,mp['Z']=9;    
    while(~scanf("%s",s))
    {
        for(int i=0;s[i];i++)
            for(int j=0;j<6;j++)
                dp[i][j]=(i+1)*3+i+1;
        for(int i=0;i<6;i++) dp[0][i]=3;
        for(int i=1;s[i];i++)
            for(int j=0;j<6;j++)
                for(int k=0;k<6;k++)
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+cmp(mp[s[i-1]],k,mp[s[i]],j));
        int minn=0x3f3f3f3f;
        for(int i=0;i<6;i++) minn=min(minn,dp[strlen(s)-1][i]); 
        printf("%d\n",minn+strlen(s));
    }    
    return 0;
}