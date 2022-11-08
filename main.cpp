#include <cinttypes>
#include <iostream>

using namespace std;

#define TARGET 200

int64_t buff1[TARGET+1];
int64_t buff2[TARGET+1];

int main()
{

    int64_t *waysCurr = buff1;
    int64_t *waysPrev = buff2;
    int64_t *aux;

    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int ncoins = sizeof(coins)/sizeof(coins[0]);
    
    //Trivial solution if we just have coin 1
    for(int i = 0; i <= TARGET; i++){
        waysCurr[i] = 1;
    }

    //Bottom-up Dynamic programming
    for(int i = 1; i < ncoins; i++){
        aux = waysCurr; waysCurr = waysPrev; waysPrev = aux; //swap buffers
        int c = coins[i];
        int change = 0;
        while(change < c){
            waysCurr[change] = waysPrev[change];
            change++;
        }
        for(;change <= TARGET; change++){
            //waysCurr[change - c] is already computed when used
            waysCurr[change] = waysPrev[change] + waysCurr[change - c];
        }
        
    }

    cout << waysCurr[TARGET] << endl;
}