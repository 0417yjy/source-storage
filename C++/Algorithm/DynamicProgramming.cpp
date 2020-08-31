#include "DynamicProgramming.h"

DynamicProgramming::DynamicProgramming(int size, std::function<void(int*, int)> fun) {
    // initialize member values
    this->size = size;
    this->calculatingFcn = fun;
    arr = new int[size];
}

DynamicProgramming::DynamicProgramming(int size, std::function<void(int*, int)> fun, int *initializer, int init_size) {
    // initialize member values
    this->size = size;
    this->calculatingFcn = fun;
    arr = new int[size];

    initialize(initializer, init_size);
}

void DynamicProgramming::initialize(int* initializer, int size) {
    if(size > this->size) {
        size = this->size;
    }

    for(int i=0;i<size;i++) { // 주어진 배열만큼 초기화
        arr[i] = initializer[i];
    }

    for(int i=size;i<this->size;i++) { // 나머지는 -1로 채움
        arr[i] = -1;
    }
}

int DynamicProgramming::get(int idx) {
    if(idx >= size || idx < 0) {
        return -1;
    }

    if(arr[idx] != -1) {
        return arr[idx];
    }
    else {
        calculatingFcn(arr, idx);
        return arr[idx];    
    }
}

DynamicProgramming::~DynamicProgramming() {
    delete[] arr;
}

// ---------------------------------------------------------------------------------------------------------------------

DynamicProgrammingAcc::DynamicProgrammingAcc(int size, std::function<void(int*, int)> fun) : DynamicProgramming(size, fun) {
    calculated_acc_idx = -1;
}

DynamicProgrammingAcc::DynamicProgrammingAcc(int size, std::function<void(int*, int)> fun, int *initializer, int init_size) : DynamicProgramming(size, fun, initializer, init_size) {
    calculated_acc_idx = -1;
}

int DynamicProgrammingAcc::get(int idx) {
    if(idx >= size || idx < 0) {
        return -1;
    }
    if(idx <= calculated_acc_idx) {
        return arr[idx];
    }
    else {
        for(int i=calculated_acc_idx + 1;i<=idx;i++) {
            calculatingFcn(arr, i);
        }
        calculated_acc_idx = idx;
        return arr[idx];
    }
}