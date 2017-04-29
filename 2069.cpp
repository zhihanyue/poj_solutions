#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
#define MAXN 38
#define EPS 1e-8
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
struct Point {
    double x,y,z;
} P[MAXN],S;

double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

double solve(int n)
{
    S.x=S.y=S.z=0;
    double delta=100,ans=1e8;
    while(delta>=EPS) {
        int maxi=1;
        fromto(1,n,i) if(dist(S,P[maxi])<dist(S,P[i])) maxi=i;
        double dis=dist(S,P[maxi]);
        ans=min(ans,dis);
        S.x+=(P[maxi].x-S.x)/dis*delta;
        S.y+=(P[maxi].y-S.y)/dis*delta;
        S.z+=(P[maxi].z-S.z)/dis*delta;
        delta*=0.99;
    }
    return ans;
}

int main()
{
    while(true) {
        int n;
        scanf("%d",&n);
        if(n==0) break;
        fromto(1,n,i) scanf("%lf%lf%lf",&P[i].x,&P[i].y,&P[i].z);
        printf("%.5lf\n",solve(n));
    }
    return 0;
}
