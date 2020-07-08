#include "AlgorithmSortQuick.h"
using namespace std;
AlgorithmSortQuick :: AlgorithmSortQuick(int k) : SelectionAlgorithm(k){

}

int AlgorithmSortQuick :: select(){

    int N = 0;
    cin >> N;

    int *numbers = new int[N];

    for(int i = 0;i < N;i++){
        cin >> numbers[i];
    }

    int result = quickselect(numbers,0,N-1,k);

    delete [] numbers;
    return result;

}
int AlgorithmSortQuick :: quickselect(int *numbers, int left, int right, int k){

    if((right-left)<10 ){

        int key;
        int j;

        for (int i = left+1; i <=right; i++){
            key = numbers[i];
            j = i;

            while (j > left && numbers[j-1] <=  key){
                numbers[j] = numbers[j-1];
                j = j - 1;
            }
            numbers[j] = key;
        }

        return numbers[left + k - 1];
    }
    else{
        int center = (left + right) / 2;

        if(numbers[center] > numbers[left]) {
            swap(numbers[left], numbers[center]);
        }
        if(numbers[right] > numbers[left]) {
            swap(numbers[left], numbers[right]);
        }
        if(numbers[right] > numbers[center]) {
            swap(numbers[center], numbers[right]);
        }

        swap(numbers[center], numbers[right-1]);

        int pivot = numbers[right-1];

        int i = left;
        int j = right -1;

        for(;;)
        {
            while(numbers[++i] > pivot){}
            while(pivot > numbers[--j]){}
            if(i<j)
                swap(numbers[i],numbers[j]);
            else
                break;
        }

        swap(numbers[i],numbers[right-1]);

        if( k < (i-left +1))
            return quickselect(numbers,left,i-1,k);
        else if (k == (i-left+1))
            return pivot;
        else
            return quickselect(numbers,i+1,right,k-(i-left+1));
    }
}