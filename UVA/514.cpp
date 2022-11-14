#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    while(cin>>n&&n)
    {

        int a[n];
        while(cin>>a[0])
        {
            if(a[0]==0)
            {
                cout<<endl;
                break;
            }
            else
            {
                for(int i=1;i<n;i++)
                    cin>>a[i];
                    stack<int>s;
                    int t=0;
                    for(int i=1;i<=n;i++)
                    {
                        s.push(i);
                        while(s.top()==a[t])
                        {
                            s.pop();
                            t++;
                            if(s.empty()) break;
                        }
                    }
                    if(s.empty())
                        cout<<"Yes\n";
                    else
                        cout<<"No\n";
            }
        }
    }
    return 0;
}