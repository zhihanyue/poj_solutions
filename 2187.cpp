#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
#define MAXN 50008
typedef pair<double,double> Point;
double cross(Point x,Point y) {
    return x.first*y.second-x.second*y.first;
}
Point operator-(Point x,Point y) {
    return Point(x.first-y.first,x.second-y.second);
}
double area2(Point x,Point y,Point z) {
    return fabs(cross(x-y,z-y));
}
double len2(Point x) {
    return x.first*x.first+x.second*x.second;
}
Point P[MAXN],TB[MAXN];


int main()
{
    int n;
    scanf("%d",&n);
    fromto(1,n,i) scanf("%lf%lf",&(P[i].first),&(P[i].second));
    sort(P+1,P+n+1);
    int k=0;
    for(int i=1;i<=n;++i) {
        for(;k>=2 && cross(TB[k]-TB[k-1],P[i]-TB[k])<=0;--k);
        TB[++k]=P[i];
    }
    for(int i=n-1,t=k;i>=1;--i) {
        for(;k>=t+1 && cross(TB[k]-TB[k-1],P[i]-TB[k])<=0;--k);
        TB[++k]=P[i];
    }
    //凸包免费赠送TB[k]这个哨兵哦~~ 
    --k;
    double ans=0.0;
    for(int i=1,j=2;i<=k;++i) {
        if(area2(TB[i],TB[i+1],TB[j+1])>area2(TB[i],TB[i+1],TB[j])) j=j%k+1;
        ans=max(ans,max(len2(TB[j]-TB[i]),len2(TB[j+1]-TB[i+1])));
    }
    printf("%.0lf\n",round(ans));
    return 0;
}
