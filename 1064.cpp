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
    double L=0,R=INT_MIN;
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;++i)
    {
        scanf("%lf",&len[i]);
        if(R<len[i])
            R=len[i];
    }
    R+=1;
    while(R-L>0.0001)
    {
        double M=L+(R-L)/2;
        if(check(M)<K)
            R=M;
        else L=M;
    }
    printf("%.2lf",floor(L*100)/100);
    return 0;
}
