#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,str[2011];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
    char ch;
    for(int i=0;i<n;i++)
    {
        getchar();
        ch=getchar();
        str[i]=ch-'A';
    }
    int pre=0,last=n-1,count=0;
    for(int i=0;i<n;i++)
    {
        if(str[pre]==str[last])
        {
        int pr=pre,la=last,flag=0;
        while(pr<=la)
        {
            if(str[pr]<str[la])
            {
            printf("%c",str[pre]+'A');
            count++;
            flag=1;
            pre++;    
            break;
            }
            else if(str[pr]>str[la])
            {
            printf("%c",str[last]+'A');
            count++;
            flag=1;
            last--;
            break;
            }
            pr++,la--;
        }
        if(!flag)
        {
            printf("%c",str[pre]+'A');
            count++;
            pre++;
        }
        }
        else if(str[pre]<str[last])
        {
        printf("%c",str[pre]+'A');
        count++;
        pre++;
        }
        else
        {
        printf("%c",str[last]+'A');
        count++;
        last--;    
        }
        if(count==80)
        {
        count=0;
        printf("\n");
        }
    }
    if(count)
        printf("\n");
    }
    return 0;
}
