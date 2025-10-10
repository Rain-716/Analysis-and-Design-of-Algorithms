#include <bits/stdc++.h>
using namespace std;
struct Point
{
    double x,y;
};
vector <Point> p;
double dx2(int i,int j)
{
    double dx=p[i].x-p[j].x;
    return dx*dx;
}
double dy2(int i,int j)
{
    double dy=p[i].y-p[j].y;
    return dy*dy;
}
double dist2(int i,int j)
{
    return dx2(i,j)+dy2(i,j);
}
double DC(int l,int r)
{
    if (l>=r){
        return 1000.1;
    }
    if (r-l==1){
        return dist2(l,r);
    }
    int m=(l+r)>>1;
    double dl2=DC(l,m);
    double dr2=DC(m+1,r);
    double d2=min(dl2,dr2);
    vector <int> strip;
    int i=m,j=m+1;
    while (dx2(i,m)<d2&&i>=l){
        strip.push_back(i--);
    }
    while (dx2(j,m)<d2&&j<=r){
        strip.push_back(j++);
    }
    sort(strip.begin(),strip.end(),[](int i,int j)
    {
        return p[i].y<p[j].y;
    });
    for (int i=0;i<strip.size();i++){
        for (int j=i+1;j<strip.size();j++){
            if (dy2(strip[i],strip[j])>=d2){
                break;
            }
            d2=min(d2,dist2(strip[i],strip[j]));
        }
    }
    return d2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int N;
    while (cin>>N&&N){
        p.resize(N);
        for (Point& pnt : p){
            cin>>pnt.x>>pnt.y;
        }
        sort(p.begin(),p.end(),[](Point& p1,Point& p2)
        {
            if (p1.x!=p2.x){
                return p1.x<p2.x;
            }
            return p1.y<p2.y;
        });
        double d2=DC(0,N-1);
        cout<<fixed<<setprecision(2)<<sqrt(d2/4.0)<<'\n';
    }
    return 0;
}