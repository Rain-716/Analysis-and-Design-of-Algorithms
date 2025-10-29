#include <bits/stdc++.h>
using namespace std;
struct Doll
{
    int a,b,c,w,bi,ci;
    long long dp=0;
};
struct BIT2D
{
    int B;
    vector <vector<int>> outer;
    vector <vector<long long>> inner;
    BIT2D(int BB) : B(BB)
    {
        outer.assign(B+1,{});
        inner.assign(B+1,{});
    }
    void outerInit(int bi,int ci)
    {
        for (;bi<=B;bi+=bi&-bi){
            outer[bi].push_back(ci);
        }
    }
    void innerInit()
    {
        for (int i=1;i<=B;i++){
            auto& v=outer[i];
            sort(v.begin(),v.end());
            v.erase(unique(v.begin(),v.end()),v.end());
            inner[i].assign(v.size()+1,0);
        }
    }
    void Update(int bi,int ci,long long x)
    {
        for (;bi<=B;bi+=bi&-bi){
            auto& v=outer[bi];
            int pos=lower_bound(v.begin(),v.end(),ci)-v.begin()+1;
            for (;pos<inner[bi].size();pos+=pos&-pos){
                inner[bi][pos]=max(inner[bi][pos],x);
            }
        }
    }
    long long Query(int bi,int ci)
    {
        long long res=0;
        for (;bi>0;bi-=bi&-bi){
            auto& v=outer[bi];
            int pos=upper_bound(v.begin(),v.end(),ci)-v.begin();
            for (;pos>0;pos-=pos&-pos){
                res=max(inner[bi][pos],res);
            }
        }
        return res;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector <Doll> d(n);
    vector <int> Bi(n),Ci(n);
    for (Doll& dd : d){
        cin>>dd.a>>dd.b>>dd.c>>dd.w;
        Bi.push_back(dd.b);
        Ci.push_back(dd.c);
    }
    sort(Bi.begin(),Bi.end());
    Bi.erase(unique(Bi.begin(),Bi.end()),Bi.end());
    sort(Ci.begin(),Ci.end());
    Ci.erase(unique(Ci.begin(),Ci.end()),Ci.end());
    for (Doll& dd : d){
        dd.bi=lower_bound(Bi.begin(),Bi.end(),dd.b)-Bi.begin()+1;
        dd.ci=lower_bound(Ci.begin(),Ci.end(),dd.c)-Ci.begin()+1;
    }
    sort(d.begin(),d.end(),[](Doll& d1,Doll& d2)
    {
        if (d1.a!=d2.a){
            return d1.a<d2.a;
        }
        if (d1.b!=d2.b){
            return d1.b<d2.b;
        }
        if (d1.c!=d2.c){
            return d1.c<d2.c;
        }
        return d1.w<d2.w;
    });
    BIT2D bit2d(Bi.size());
    for (Doll& dd : d){
        bit2d.outerInit(dd.bi,dd.ci);
    }
    bit2d.innerInit();
    long long ans=0;
    for (int i=0;i<n;){
        int j;
        for (j=i;j<n&&d[j].a==d[i].a;j++){}
        for (int k=i;k<j;k++){
            d[k].dp=bit2d.Query(d[k].bi-1,d[k].ci-1)+d[k].w;
            ans=max(d[k].dp,ans);
        }
        for (int k=i;k<j;k++){
            bit2d.Update(d[k].bi,d[k].ci,d[k].dp);
        }
        i=j;
    }
    cout<<ans<<'\n';
    return 0;
}