// DP 에 범용적으로 쓸 클래스, 코딩테스트용 한 파일에 전부 작성
#include <functional>

class DynamicProgramming {
  public:
    DynamicProgramming(int size, std::function<void(int*, int)> fun); // 기본 생성자
    DynamicProgramming(int size, std::function<void(int*, int)> fun, int *initializer, int init_size); // 이니셜라이저를 포함한 생성자
    void initialize(int* initializer, int size); // DP 배열의 초기화
    int get(int idx); // 특정 인덱스의 값을 가져오기
  private:
    ~DynamicProgramming(); // 소멸자
    std::function<void(int*, int)> calculatingFcn; // 배열에 값을 저장하는 규칙 함수
    int size; // 배열의 크기
    int calculated_acc_idx; // 0부터 계산이 완료된 인덱스
    int *arr; // 배열 포인터
};

/*
calculatingFcn은

void dp_function(int* arr, int idx) {
    arr[idx] = arr[idx - 1] + arr[idx - 2] + arr[idx - 3]; // DP 배열 계산 규칙
}

과 같은 형식으로 작성하면 됨
*/

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

DynamicProgramming::~DynamicProgramming() {
    delete[] arr;
}