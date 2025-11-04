#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,t;
    cin>>s>>t;
    s=min(s,t);
    int i=s.length()-1;
    while (i>=0&&s[i]=='Z'){
        i--;
    }
    if (i>=0){
        s[i]++;
    }
    while (++i<s.length()){
        s[i]='A';
    }
    cout<<s<<'\n';
    return 0;
}