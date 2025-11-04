#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin>>n){
        vector <int> c(n+1);
        for (int i=1;i<=n;i++){
            cin>>c[i];
        }
        vector <int> mainCnt(n+1,0),cnt(n+1,0);
        for (int i=1;i<=n;i++){
            fill(cnt.begin(),cnt.end(),0);
            int bestColor=0,bestCnt=0;
            for (int j=i;j<=n;j++){
                cnt[c[j]]++;
                if (cnt[c[j]]>bestCnt||(cnt[c[j]]==bestCnt&&c[j]<bestColor)){
                    bestColor=c[j];
                    bestCnt=cnt[c[j]];
                }
                mainCnt[bestColor]++;
            }
        }
        for (int i=1;i<n;i++){
            cout<<mainCnt[i]<<' ';
        }
        cout<<mainCnt[n]<<'\n';
    }
    return 0;
}