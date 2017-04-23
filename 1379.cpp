#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime> 
#include <climits>
#include <algorithm>
using namespace std;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
#define MAXN 1008
#define MAXDIS 15000
#define EPS 1e-5
#define INF 1e20
#define PI 3.1415926535
#define CNTP 30
#define CNTC 30
typedef pair<double,double> Point;
Point P[MAXN]; 
int n,mx,my;

double myrand(double L,double R) {
    return L+(R-L)*rand()/RAND_MAX;
}
double pow2(double x){return x*x;}
double mindist(Point x) {
    double dist=INF;
    fromto(1,n,i) dist=min(dist,sqrt(pow2(x.first-P[i].first)+pow2(x.second-P[i].second)));
    return dist;
}
Point solve()
{
    static Point Sta[CNTP+1];static double D[CNTP+1];
    fromto(1,CNTP,i){Sta[i]=Point(myrand(0,mx),myrand(0,my));D[i]=mindist(Sta[i]);}
    
    double T=MAXDIS;
    while(T>=EPS) {
        fromto(1,CNTP,i) fromto(1,CNTC,kkk) {
            double jiao=myrand(0,10*PI);
            Point newp(Sta[i].first+T*cos(jiao),Sta[i].second+T*sin(jiao));
            if(newp.first<0 || newp.first>mx || newp.second<0 || newp.second>my) continue;
            double newval=mindist(newp),delta=newval-D[i];
            if(delta>0){D[i]=newval;Sta[i]=newp;}
            //if(delta>0 || myrand(0,1)<=exp(delta/T)){D[i]=newval;Sta[i]=newp;}
        }
        T*=0.8;
    }
    int maxi=1;
    fromto(1,CNTP,i) if(D[maxi]<D[i]) maxi=i;
    return Sta[maxi];
}

int main()
{
    srand(time(0));
    int case_cnt;
    scanf("%d",&case_cnt);
    while(case_cnt--) {
        scanf("%d%d%d",&mx,&my,&n);
        fromto(1,n,i) scanf("%lf%lf",&P[i].first,&P[i].second);
        Point ans=solve();
        printf("The safest point is (%.1lf, %.1lf).\n",ans.first,ans.second);
    }
    return 0;
}
