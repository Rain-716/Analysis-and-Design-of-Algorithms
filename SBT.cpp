#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    while (cin>>n){
        int Min,Max;
        cin>>Min;
        Max=Min;
        for (int i=1;i<n;i++){
            int x;
            cin>>x;
            Min=min(x,Min);
            Max=max(x,Max);
        }
        if (Min>=10&&Max<=30&&Max-Min<=3){
            cout<<"Is SBT\n";
        }
        else {
            cout<<"Is not SBT\n";
        }
    }
    return 0;
}