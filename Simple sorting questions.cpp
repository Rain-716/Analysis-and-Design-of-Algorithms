#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    vector <long long> c(n+1);
    for (int i=1;i<=n;i++){
        long long a;
        cin>>a;
        c[i]=a-(long long)i*(i+1)/2;
    }
    sort(c.begin()+1,c.end());
    long long b0=c[(n+1)/2],sum=0;
    for (int i=1;i<=n;i++){
        sum+=abs(c[i]-b0);
    }
    cout<<sum<<'\n';
    return 0;
}