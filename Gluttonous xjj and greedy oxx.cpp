#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector <int> a(n+1),idx(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        idx[i]=i;
    }
    sort(idx.begin()+1,idx.end(),[&](int x,int y)
    {
        return a[x]>a[y];
    });
    vector <int> S,T;
    long long s=0,t=0;
    for (int i=1;i<=n;i++){
        int id=idx[i];
        if (s<=t){
            S.push_back(id);
            s+=a[id];
        }
        else {
            T.push_back(id);
            t+=a[id];
        }
    }
    cout<<"Yes\n";
    vector <int>& res=(s<=t) ? S : T;
    cout<<res.size()<<'\n';
    for (int& i : res){
        cout<<i<<' ';
    }
    cout<<'\n';
    return 0;
}