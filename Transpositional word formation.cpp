#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int n=s.length(),m=0;
    vector<vector<int>> pos(26);
    for (int i=0;i<n;i++){
        int c=s[i]-'a';
        pos[c].push_back(i);
        m=max((int)pos[c].size(),m);
    }
    if (m>n/2){
        cout<<"impossible\n";
        return 0;
    }
    vector<int> order(n);
    int k=0;
    for (auto& i : pos){
        for (int& j : i){
            order[k++]=j;
        }
    }
    string t(n,' ');
    for (int i=0;i<n;i++){
        int from=order[i];
        int to=order[(i+m)%n];
        t[to]=s[from];
    }
    cout<<t<<'\n';
    return 0;
}