#include <bits/stdc++.h>
using namespace std;
struct Elem
{
    int a,b,c,w,cnt=0;
    Elem(int aa,int bb,int cc,int ww) : a(aa),b(bb),c(cc),w(ww) {}
};
struct BIT
{
    int n;
    vector <int> t;
    void assign(int k)
    {
        n=k;
        t.assign(n+1,0);
    }
    void add(int x,int d)
    {
        for (;x<=n;x+=x&-x){
            t[x]+=d;
        }
    }
    int sum(int x)
    {
        int res=0;
        for (;x>0;x-=x&-x){
            res+=t[x];
        }
        return res;
    }
};
vector <Elem> a;
BIT bit;
bool cmp(int i,int j)
{
    if (a[i].b!=a[j].b){
        return a[i].b<a[j].b;
    }
    return a[i].c<a[j].c;
}
void CDQ(int l,int r)
{
    if (l==r){
        return;
    }
    int mid=(l+r)>>1;
    CDQ(l,mid);
    CDQ(mid+1,r);
    vector <int> L(mid-l+1),R(r-mid);
    for (int i=0;i<mid-l+1;i++){
        L[i]=i+l;
    }
    for (int i=0;i<r-mid;i++){
        R[i]=i+mid+1;
    }
    sort(L.begin(),L.end(),cmp);
    sort(R.begin(),R.end(),cmp);
    int i=0;
    for (int j=0;j<R.size();j++){
        while (i<L.size()&&a[L[i]].b<=a[R[j]].b){
            bit.add(a[L[i]].c,a[L[i]].w);
            i++;
        }
        a[R[j]].cnt+=bit.sum(a[R[j]].c);
    }
    for (int k=0;k<i;k++){
        bit.add(a[L[k]].c,-a[L[k]].w);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector <array<int,3>> t(n);
    for (auto& v : t){
        cin>>v[0]>>v[1]>>v[2];
    }
    sort(t.begin(),t.end(),[](auto& a1,auto& a2)
    {
        if (a1[0]!=a2[0]){
            return a1[0]<a2[0];
        }
        if (a1[1]!=a2[1]){
            return a1[1]<a2[1];
        }
        return a1[2]<a2[2];
    });
    for (int i=0;i<n;){
        int w=1;
        while (i+1<n&&t[i]==t[i+1]){
            i++;
            w++;
        }
        a.emplace_back(t[i][0],t[i][1],t[i][2],w);
        i++;
    }
    bit.assign(k);
    int m=a.size();
    CDQ(0,m-1);
    vector <int> ans(n,0);
    for (Elem& e : a){
        ans[e.cnt+e.w-1]+=e.w;
    }
    for (int& i : ans){
        cout<<i<<'\n';
    }
    return 0;
}