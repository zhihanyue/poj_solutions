#include <cstdio>
using namespace std;

int main()
{
    while(true) {
        int n;
        scanf("%d",&n);
        if(n==0) break;
        printf(n<=2?"Alice\n":"Bob\n");
    }
    
    return 0;
}
