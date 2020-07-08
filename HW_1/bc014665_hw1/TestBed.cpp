#include "TestBed.h"
#include <ctime>

TestBed::TestBed(){

}

TestBed::~TestBed(){
    delete [] algorithm;
}
void TestBed::execute() {
    clock_t start = clock();
    cout << "Result: " << algorithm->select() << endl;
    clock_t end = clock();
    double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Duration(sec) :" << cpu_time << endl;
}

void TestBed::setAlgorithm(int type, int k){
    if(type == 1){
        algorithm = new AlgorithmSortAll(k);
    }
    else if(type == 2){
        algorithm = new AlgorithmSortK(k);
    }
    else{
        cout << "Please enter a valid number (1 or 2)";
    }
}
