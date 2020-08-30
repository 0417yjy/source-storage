#include "DynamicProgramming.h"

DynamicProgramming::DynamicProgramming(int size, std::function<void(int*, int)> fun) {
    // initialize member values
    this->size = size;
    this->calculatingFcn = fun;
    calculated_acc_idx = -1;
    arr = new int[size];
}

DynamicProgramming::DynamicProgramming(int size, std::function<void(int*, int)> fun, int *initializer, int init_size) {
    // initialize member values
    this->size = size;
    this->calculatingFcn = fun;
    calculated_acc_idx = -1;
    arr = new int[size];

    initialize(initializer, init_size);
}

void DynamicProgramming::initialize(int* initializer, int size) {
    if(size > this->size) {
        size = this->size;
    }

    for(int i=0;i<size;i++) {
        arr[i] = initializer[i];
    }

    calculated_acc_idx = size - 1;
}

int DynamicProgramming::get(int idx) {
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