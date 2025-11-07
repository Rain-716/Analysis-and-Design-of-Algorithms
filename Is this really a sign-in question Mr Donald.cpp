#include <bits/stdc++.h>
using namespace std;
void remove(map<int,int>& mp,int x)
{
    if (!--mp[x]){
        mp.erase(x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int m=n*(n-1)/2;
        vector<int> a(n+1),vecb(m);
        map<int,int> b;
        for (int& i : vecb){
            cin>>i;
            b[i]++;
        }
        int s12=vecb[0],s13=vecb[1];
        remove(b,s12);
        remove(b,s13);
        bool found=false;
        for (int j=2;j<m&&!found;j++){
            int s23=vecb[j];
            if ((s12+s13+s23)%2){
                continue;
            }
            long long s123=((long long)s12+s13+s23)/2;
            a[1]=s123-s23,a[2]=s123-s13,a[3]=s123-s12;
            if (a[1]<0||a[2]<0||a[3]<0){
                continue;
            }
            map<int,int> bb=b;
            remove(bb,s23);
            bool ok=true;
            for (int k=4;k<=n&&ok;k++){
                for (auto it=bb.begin();it!=bb.end();it++){
                    int s1k=it->first;
                    a[k]=s1k-a[1];
                    for (int i=1;i<k;i++){
                        if (bb.find(a[i]+a[k])==bb.end()){
                            ok=false;
                            break;
                        }
                    }
                    if (!ok){
                        continue;
                    }
                    for (int i=1;i<k;i++){
                        remove(bb,a[i]+a[k]);
                    }
                    break;
                }
            }
            if (bb.empty()){
                found=true;
                for (int i=1;i<=n;i++){
                    cout<<a[i]<<' ';
                }
                cout<<'\n';
                break;
            }
        }
    }
    return 0;
}