#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    for (int ti=0;ti<T;ti++){
        int n,m,k;
        cin>>n>>m>>k;
        vector <vector<int>> w(n+1,vector<int>(n+1,1e9+1));
        while (m--){
            int L,R,W;
            cin>>L>>R>>W;
            w[L][R]=min(W,w[L][R]);
        }
        for (int len=n;len>0;len--){
            for (int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                if (l>1){
                    w[l][r]=min(w[l-1][r],w[l][r]);
                }
                if (r<n){
                    w[l][r]=min(w[l][r+1],w[l][r]);
                }
            }
        }
        for (int len=1;len<=n;len++){
            for (int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                for (int m=l;m<r;m++){
                    w[l][r]=min(w[l][m]+w[m+1][r],w[l][r]);
                }
            }
        }
        vector <vector<int>> dp(n+1,vector<int>(n+1,1e9+1));
        dp[0][0]=0;
        for (int i=1;i<=n;i++){
            for (int j=0;j<=n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j]);
            }
            for (int h=1;h<=i;h++){
                int jr=i-h+1;
                for (int jl=0;jl<=n-jr;jl++){
                    dp[i][jl+jr]=min(dp[h-1][jl]+w[h][i],dp[i][jl+jr]);
                }
            }
        }
        int ans=1e9+1;
        for (int i=k;i<=n;i++){
            ans=min(dp[n][i],ans);
        }
        if (ans>1e9){
            ans=-1;
        }
        cout<<"case #"<<ti<<":\n"<<ans<<'\n';
    }
    return 0;
}