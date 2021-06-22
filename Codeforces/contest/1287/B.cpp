#include<bits/stdc++.h>

using namespace std;

const int N=1505;
const int SET='S'+'E'+'T';

int n,k;
string s[N];
map<string,int>m;
int ans;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>s[i],m[s[i]]++;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            string t="";
            for(int p=0;p<k;p++)
            {
                if(s[i][p]==s[j][p]) t+=s[i][p];
                else t+=SET-s[i][p]-s[j][p];
            }
            ans+=m.count(t);
        }
    cout<<ans/3<<endl;
    return 0;
}