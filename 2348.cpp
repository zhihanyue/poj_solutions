#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    while(true) {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==0 && b==0) break;
        for(bool f=false;;f=!f) {
            if(a>b) swap(a,b);
            if(b-a>a || b%a==0) {
                printf(f?"Ollie wins\n":"Stan wins\n");
                break;
            }
            b-=a;
        }
    }
    return 0;
}
