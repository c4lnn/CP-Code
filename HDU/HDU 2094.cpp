#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string a,b;
    while(cin>>n&&n)
    {
        map<string,int>m;
        vector<int>edge[1000];
        int in[1000]={0};
        int t=1; 
        int sum=0;
        while(n--)
        {
            cin>>a>>b;
            if(!m[a])
                m[a]=t++;
            if(!m[b])
                m[b]=t++;
            edge[m[a]].push_back(m[b]);
            in[m[b]]++;
        }
        for(int i=1;i<t;i++)
            if(!in[i])
                sum++;
        if(sum==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
} 