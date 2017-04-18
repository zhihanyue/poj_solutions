#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;

int N;
double len[10008];

int check(double x)
{
    int sum=0;
    for(int i=1;i<=N;++i)
        sum+=(int)(len[i]/x);
    return sum;
}

int main()
{
    int K;
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;++i)
        scanf("%lf",&len[i]);
    double L=0,R=1000000;
    for(int i=1;i<=1000;++i)
    {
        double M=L+(R-L)/2;
        if(check(M)<K)
            R=M;
        else L=M;
    }
/*  while(R-L>0.0001)
    {
        double M=L+(R-L)/2;
        if(check(M)<K)
            R=M;
        else L=M;
    }*/
    printf("%.2lf",floor(L*100)/100);
    return 0;
}
