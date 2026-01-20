#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,a,b,hb=0;
    cin>>n>>m;
    vector <vector<pair<int,long long>>> adj(n+1);
    while (m--){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        if (w){
            hb=max(hb,63-__builtin_clzll(w));
        }
    }
    cin>>a>>b;
    auto bfs=[&](long long mask)->bool
    {
        vector <bool> vis(n+1,false);
        queue <int> q;
        q.push(a);
        vis[a]=true;
        while (!q.empty()){
            int u=q.front();
            q.pop();
            if (u==b){
                return true;
            }
            for (auto& [v,w] : adj[u]){
                if (!vis[v]&&((w&mask)==0LL)){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        return false;
    };
    if (!bfs(0LL)){
        cout<<-1<<'\n';
        return 0;
    }
    long long ans=0LL;
    for (int bit=hb;bit>=0;bit--){
        long long mask=ans|(1LL<<bit);
        if (bfs(mask)){
            ans=mask;
        }
    }
    cout<<(~ans&((1LL<<(hb+1))-1LL))<<'\n';
    return 0;
}