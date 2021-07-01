#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int a;
    int b;
};
int main()
{
    int n;
    cin>>n;
    struct Node stu[n];
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>stu[i].a>>stu[i].b;
        v[i]=stu[i].a+stu[i].b;
    }
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
           if(v[i]==stu[j].a&&i!=j&&v[j]==stu[i].a)
           {
               cout<<"YE5"<<endl;
               return 0;
           }
        cout<<"N0"<<endl;
    return 0;
}