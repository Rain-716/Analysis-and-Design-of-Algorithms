#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while (T--){
        int N,K;
        cin>>N>>K;
        vector <int> c(N);
        for (int& i : c){
            cin>>i;
        }
        sort(c.begin(),c.end());
        int l=0,r=N-1,cnt=0;
        while (l<r){
            r--;
            cnt++;
            if (c[l]+c[r+1]<=K){
                l++;
            }
        }
        if (l==r){
            cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}