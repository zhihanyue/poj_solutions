#include <iostream>
using namespace std;

char a[2008],b[2008];
int main()
{
    int N;
    cin >> N;
    for(int i=1;i<=N;++i)
        cin >> a[i];
    int L=1,R=N;
    for(int i=1;i<=N;++i)
    {
        bool isL=false;
        for(int j=0;j<=R-L;++j)
        {
            if(a[L+j]<a[R-j])
            {
                isL=true;
                break;
            }
            else if(a[L+j]>a[R-j])
            {
                isL=false;
                break;
            }
        }
        if(isL)
            b[i]=a[L++];
        else b[i]=a[R--];
    }
    cout << b+1 << endl;
    return 0;
}
