#include <bits/stdc++.h>
using namespace std;
const vector <int> di={0,1,2,3,4};
const vector <int> dj={4,3,2,1,0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector <pair<int,int>> Q;
    int n,m,maxN=0,maxM=0;
    while (cin>>n>>m){
        Q.emplace_back(n,m);
        maxN=max(maxN,n);
        maxM=max(maxM,m);
    }
    int maxI=4*maxN,maxJ=4*maxM;
    vector <vector<double>> dp(maxI+1,vector<double>(maxJ+1,-1.0));
    for (int s=0;s<=maxI+maxJ;s+=4){
        int i_min=max(0,s-maxJ);
        int i_max=min(maxI,s);
        for (int i=i_min;i<=i_max;i++){
            int j=s-i;
            if (!j){
                dp[i][j]=0.0;
                continue;
            }
            if (!i){
                dp[i][j]=1.0;
                continue;
            }
            double res=0.0;
            int cnt=0;
            for (int k=0;k<5;k++){
                int ii=i-di[k];
                int jj=j-dj[k];
                if (ii>=0&&jj>=0){
                    res+=dp[ii][jj];
                    cnt++;
                }
            }
            dp[i][j]=res/cnt;
        }
    }
    cout<<fixed<<setprecision(6);
    for (auto& q : Q){
        cout<<dp[4*q.first][4*q.second]<<'\n';
    }
    return 0;
}