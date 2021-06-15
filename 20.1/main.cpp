#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

void QuickSort(int Tab[],int p,int k)
{
    int i=p , j=k , m=Tab[(p+k)/2];
    while (i<=j)
    {
        while (Tab[i]<m)i++;
        while (Tab[j]>m)j--;
        if(i<=j)
        {
            swap(Tab[i],Tab[j]);
            i++;j--;
        }
        if(p<j)QuickSort(Tab,p,j);
        if(i<k)QuickSort(Tab,i,k);
    }
}
void Draw(int Tab[],int N)
{
    for(int i =0;i<N;i++)
    {
        Tab[i]=rand()%100;
    }
}
void Show(int Tab[],int N)
{
    for(int i= 0 ; i <N;i++)
    {
        cout<<Tab[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    srand(time(NULL));
    const int N=10;
    int Tab[N]={};
    Draw(Tab,N);
    Show(Tab,N);
    QuickSort(Tab,0,9);
    Show(Tab,N);

    return 0;
}
