#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
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
const int N=1e5+5;
struct R {
    string name;
    int a,sum;
    int straight;
    PII four_of_a_king;
    PII full_house;
    PII three_of_a_king;
    tuple<int,int,int> two_pair;
    PII pair;
    bool operator < (const R &T) const {
        if(a>T.a) return true;
        if(a<T.a) return false;
        if(a==7) return name<T.name;
        if(a==6) return straight>T.straight||straight==T.straight&&name<T.name;
        if(a==5) return four_of_a_king.FI>T.four_of_a_king.FI||four_of_a_king.FI==T.four_of_a_king.FI&&four_of_a_king.SE>T.four_of_a_king.SE||four_of_a_king.FI==T.four_of_a_king.FI&&four_of_a_king.SE==T.four_of_a_king.SE&&name<T.name;
        if(a==4) return full_house.FI>T.full_house.FI||full_house.FI==T.full_house.FI&&full_house.SE>T.full_house.SE||full_house.FI==T.full_house.FI&&full_house.SE==T.full_house.SE&&name<T.name;
        if(a==3) return three_of_a_king.FI>T.three_of_a_king.FI||three_of_a_king.FI==T.three_of_a_king.FI&&three_of_a_king.SE>T.three_of_a_king.SE||three_of_a_king.FI==T.three_of_a_king.FI&&three_of_a_king.SE==T.three_of_a_king.SE&&name<T.name;
        if(a==2) {
            if(get<0>(two_pair)>get<0>(T.two_pair)) return true;
            if(get<0>(two_pair)<get<0>(T.two_pair)) return false;
            if(get<1>(two_pair)>get<1>(T.two_pair)) return true;
            if(get<1>(two_pair)<get<1>(T.two_pair)) return false;
            if(get<2>(two_pair)>get<2>(T.two_pair)) return true;
            if(get<2>(two_pair)<get<2>(T.two_pair)) return false;
            return name<T.name;
        }
        if(a==1) return pair.FI>T.pair.FI||pair.FI==T.pair.FI&&pair.SE>T.pair.SE||pair.FI==T.pair.FI&&pair.SE==T.pair.SE&&name<T.name;
        return sum>T.sum||sum==T.sum&&name<T.name;
    }
}b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>b[i].name;
        string s;cin>>s;
        VI a;
        for(int j=0;j<SZ(s);j++) {
            if(s[j]=='1'&&s[j+1]=='0') a.PB(10),++j;
            else if(s[j]=='A') a.PB(1);
            else if(s[j]=='J') a.PB(11);
            else if(s[j]=='Q') a.PB(12);
            else if(s[j]=='K') a.PB(13);
            else a.PB(s[j]-'0');
        }
        sort(ALL(a));
        for(int j=0;j<5;j++) b[i].sum+=a[j];
        if(a[0]==1&&a[1]==10&&a[2]==11&&a[3]==12&&a[4]==13) b[i].a=7;
        else if(a[1]-a[0]==1&&a[2]-a[1]==1&&a[3]-a[2]==1&&a[4]-a[3]==1) {
            b[i].a=6;
            b[i].straight=a[4];
        }
        else if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]) {
            b[i].a=5;
            b[i].four_of_a_king=MP(a[0],a[4]);
        }
        else if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]) {
            b[i].a=5;
            b[i].four_of_a_king=MP(a[1],a[0]);
        }
        else if(a[0]==a[1]&&a[1]==a[2]&&a[3]==a[4]) {
            b[i].a=4;
            b[i].full_house=MP(a[0],a[3]);
        }
        else if(a[0]==a[1]&&a[2]==a[3]&&a[3]==a[4]) {
            b[i].a=4;
            b[i].full_house=MP(a[2],a[0]);
        }
        else if(a[0]==a[1]&&a[1]==a[2]||a[1]==a[2]&&a[2]==a[3]||a[2]==a[3]&&a[3]==a[4]) {
            b[i].a=3;
            b[i].three_of_a_king=MP(a[2],b[i].sum-a[2]*3);
        }
        else if(a[0]==a[1]&&a[2]==a[3]) {
            b[i].a=2;
            b[i].two_pair=make_tuple(a[2],a[0],a[4]);
        }
        else if(a[0]==a[1]&&a[3]==a[4]) {
            b[i].a=2;
            b[i].two_pair=make_tuple(a[3],a[0],a[2]);
        }
        else if(a[1]==a[2]&&a[3]==a[4]) {
            b[i].a=2;
            b[i].two_pair=make_tuple(a[3],a[1],a[0]);
        }
        else if(a[0]==a[1]||a[1]==a[2]) {
            b[i].a=1;
            b[i].pair=MP(a[1],b[i].sum-a[1]*2);
        }
        else if(a[2]==a[3]||a[3]==a[4]) {
            b[i].a=1;
            b[i].pair=MP(a[3],b[i].sum-a[3]*2);
        }
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++) cout<<b[i].name<<'\n';
    return 0;
}