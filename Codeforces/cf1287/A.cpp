#include<bits/stdc++.h>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    int T;cin>>T;
    int n;
    while(T--)
    {
        cin>>n;
        char t;
        int pre=0;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            cin>>t;
            if(t=='A') 
            {
                if(pre!=0) res=max(res,i-pre-1);
                pre=i;
            }
        }
        if(pre!=0) res=max(res,n-pre);
        cout<<res<<endl;
    }  
    return 0;
}