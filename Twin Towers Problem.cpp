#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,sum=0,csum=0;
    cin>>n;
    vector <int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector <int> d(sum+1,-1);
    d[0]=0;
    for (int i : a){
        vector <int> dd(d);
        for (int j=0;j<=csum;j++){
            if (d[j]==-1){
                continue;
            }
            dd[i+j]=max(dd[i+j],d[j]);
            if (i<=j){
                dd[j-i]=max(dd[j-i],d[j]+i);
            }
            else {
                dd[i-j]=max(dd[i-j],d[j]+j);
            }
        }
        d.swap(dd);
        csum+=i;
    }
    cout<<d[0]<<'\n';
    return 0;
}