#include <iostream>
#include <string>

using namespace std;

const int N = 4;
const int CASH = 8;
const int DENOMINATIONS[4] = {1,2,4,5};
int LASTCASH[9][4];
int HMC[CASH+1];//HMC-How many coins

int HowManyCoins()
{
    HMC[0] = 0;
    for (int i = 1; i<=CASH ; i++) HMC[i] = CASH + 1 ;
    for (int i = 1 ; i<=CASH ;i++)
    {
        for(int j = 0 ; j <= N ; j++)
        {
            if(DENOMINATIONS[j]<=i)
               {
                   if(HMC[i-DENOMINATIONS[j]] + 1 <HMC[i])
                   {
                       HMC[i]=HMC[i-DENOMINATIONS[j]]+1;
                       for(int k =0 ; k<N ; k++)
                       {
                           LASTCASH[i][k]=LASTCASH[i-DENOMINATIONS[j]][k];
                       }
                       LASTCASH[i][j]++;
                   }
        }
    }
    }
    for(auto x: HMC)
        cout<<x<<" ";

    for (int i = 0 ; i <CASH +1;i++)
    {
        for(int j = 0 ; j<N;j++)
        {
            cout<<LASTCASH[i][j]<<" ";//table of coins
        }
        cout<<endl;
    }
    cout<<endl;
    return HMC[CASH];

}
int main()
{
    cout<<HowManyCoins();
    return 0;
}

