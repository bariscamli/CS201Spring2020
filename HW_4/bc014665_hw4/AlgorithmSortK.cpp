#include "AlgorithmSortK.h"

using namespace std;

AlgorithmSortK::AlgorithmSortK(int k) : SelectionAlgorithm(k){

}

int AlgorithmSortK::select() {
    int *pNums = 0;
    int n;
    cin >> n;
    pNums = new int[k];


    for (int i = 0; i < k; i++) {
        pNums[i] = 0;
    }

    for (int i = 0; i < k; i++) {
        cin >> pNums[i];
    }

    int key;
    int j;
    for (int i = 1; i < k; i++){
        key = pNums[i];
        j = i;

        while (j > 0 && pNums[j-1] < key){
            pNums[j] = pNums[j-1];
            j = j - 1;
        }
        pNums[j] = key;
    }

    key = 0;
    int totalnumber = 0;

    int tempF;
    int tempS;

    while (totalnumber < n-k ){
        cin >> key;
        if(key > pNums[k-1] ){

            if(key > pNums[k-1] && key <= pNums[k-2]){
                pNums[k-1] = key;
            }

            else if(key >= pNums[0]){
                tempF = pNums[0];
                for (int i = 0; i < k-1 ; i++) {
                    tempS = pNums[i+1];
                    pNums[i+1] = tempF;
                    tempF = tempS;
                }
                pNums[0] = key;
            }

            else{
                for (int i = k - 3; i >= 0; i--) {
                    if (pNums[i] >= key) {
                        tempF = key;
                        for (int z = i+1; z < k ; z++) {
                            tempS = pNums[z];
                            pNums[z] = tempF;
                            tempF = tempS;
                        }
                        break;
                    }
                }
            }
        }
        totalnumber++;
    }
    int result = pNums[k-1];
    delete [] pNums;
    pNums = 0;
    return result;
}