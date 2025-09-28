#include <bits/stdc++.h>
using namespace std;
void printSet(set<int>& s)
{
    if (s.empty()){
        cout<<"{}\n";
        return;
    }
    bool first=true;
    for (int i : s){
        if (first){
            first=false;
            cout<<'{'<<i;
        }
        else {
            cout<<','<<i;
        }
    }
    cout<<"}\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int m,n,x;
    cin>>m>>n;
    set <int> A,B,C,D,E;
    for (int i=0;i<m;i++){
        cin>>x;
        A.insert(x);
    }
    for (int i=0;i<n;i++){
        cin>>x;
        B.insert(x);
        D.insert(x);
    }
    for (int i : A){
        D.insert(i);
        if (B.count(i)){
            C.insert(i);
        }
        else {
            E.insert(i);
        }
    }
    printSet(C);
    printSet(D);
    printSet(E);
    return 0;
}