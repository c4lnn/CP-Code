#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long s[50]={0,1};
    for(int i=2;i<50;i++)
        s[i]=s[i-1]+s[i-2];
    int N;
    int a,b;
    cin>>N;
    while(N--)
    {
        cin>>a>>b;
        if(a==1)
            cout<<s[b]<<endl;
        else
            cout<<s[b-a+1]<<endl;
    }
    return 0;
}