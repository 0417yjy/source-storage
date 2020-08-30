// DP 에 범용적으로 쓸 클래스, 코딩테스트용 한 파일에 전부 작성
#include <functional>

class DynamicProgramming {
  public:
    DynamicProgramming(int size, std::function<void(int*, int)> fun);
    void initialize(int* initializer, int size);
    int get(int idx);
  private:
    std::function<void(int*, int)> calculatingFcn;
    int size;
    int calculated_acc_idx;
    int *arr;
};

DynamicProgramming::DynamicProgramming(int size, std::function<void(int*, int)> fun) {
    // initialize member values
    this->size = size;
    this->calculatingFcn = fun;
    calculated_acc_idx = -1;
    arr = new int[size];
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