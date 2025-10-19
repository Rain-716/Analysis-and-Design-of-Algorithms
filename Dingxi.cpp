#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector <int> a(n+1,-1);
    while (k--){
        int x;
        cin>>x;
        a[x]=0;
    }
    a[0]=1;
    for (int i=1;i<=n;i++){
        if (a[i]){
            a[i]=0;
            if (i>=1){
                a[i]+=a[i-1];
            }
            if (i>=2){
                a[i]+=a[i-2];
            }
            if (i>=3){
                a[i]+=a[i-3];
            }
        }
    }
    cout<<a[n]<<'\n';
    return 0;
}