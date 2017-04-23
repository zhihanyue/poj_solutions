#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime> 
using namespace std;
#define N 1008
#define CNTP 30
#define CNTC 30
#define EPS 1e-8
#define INF 1e20
#define MAXDIS 15000
#define PI 3.1415926
struct POINT {
    double x, y, d;
    POINT() {}
    POINT(double _x, double _y): x(_x), y(_y) {}
} p[N], rp[CNTP];
double myrand(double L,double R) {
    return L+(R-L)*rand()/RAND_MAX;
}
int x, y, n;
double dis(POINT a) {
    double ret=INF;
    for (int i=0; i<n; i++)
        ret=min(ret,sqrt((a.x-p[i].x)*(a.x-p[i].x) + (a.y-p[i].y)*(a.y-p[i].y)));
    return ret;
}

POINT solve() {
    for (int i=0; i<CNTP; i++) {
        rp[i]= POINT(myrand(0,x),myrand(0,y));
        rp[i].d = dis(rp[i]);
    }
    double T=MAXDIS;
    while (T>=EPS) {
        for (int i=0; i<CNTP; i++) {
            for (int k=0; k<CNTC; k++) {
                double jiao=myrand(0,10*PI);
                POINT t(rp[i].x+T*cos(jiao),rp[i].y+T*sin(jiao));
                t.d = dis(t);
                if (0<=t.x && t.x<=x && 0<=t.y && t.y<=y)
                    if (t.d > rp[i].d) rp[i] = t;
            }
        }
        T *= 0.8;
    }
    int k = 0;
    for (int i=1; i<CNTP; i++)
        if (rp[k].d < rp[i].d) k = i;
    return rp[k];
}

int main() {
    srand(time(0));
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d%d", &x, &y, &n);
        for (int i=0; i<n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        POINT ans=solve();
        printf("The safest point is (%.1lf, %.1lf).\n",ans.x,ans.y);
    }
    return 0;
}
