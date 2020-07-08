#include "AlgorithmSortAll.h"
using namespace std;
AlgorithmSortAll::AlgorithmSortAll(int k) : SelectionAlgorithm(k){

}

int AlgorithmSortAll::select() {
    int *pNums = 0;
    int n;
    cin >> n;
    pNums = new int[n];

    for(int i=0;i<n;i++){
        pNums[i] = 0;
    }

    for(int i=0;i<n;i++){
        cin >> pNums[i];
    }

    int key;
    int j;
    for (int i = 1; i < n; i++){
        key = pNums[i];
        j = i;

        while (j > 0 && pNums[j-1] < key){
            pNums[j] = pNums[j-1];
            j = j - 1;
        }
        pNums[j] = key;
    }

    int result = pNums[k-1];
    delete [] pNums;
    pNums = 0;
    return result;
}
