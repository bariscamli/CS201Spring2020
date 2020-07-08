//
// Created by baris on 4.04.2020.
//

#include "AlgorithmSortHeap.h"

using namespace std;

AlgorithmSortHeap::AlgorithmSortHeap(int k) : SelectionAlgorithm(k){

}

int AlgorithmSortHeap:: select() {
    int n;
    cin >> n;
    BinaryHeap *heap = new BinaryHeap(k);

    for (int i = 0; i < k; i++) {
        int number;
        cin >> number;
        heap->insert(number);
    }

    for (int i = 0; i < n-k; i++) {
        int number;
        cin >> number;
        if (heap->getMin() < number) {
            heap->deleteMin();
            heap->insert(number);
        }
    }
    return heap->getMin();
}