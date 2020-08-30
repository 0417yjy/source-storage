// DP 에 범용적으로 쓸 클래스
#include <functional>

class DynamicProgramming {
  public:
    DynamicProgramming(int size, std::function<void(int*, int)> fun);
    DynamicProgramming(int size, std::function<void(int*, int)> fun, int *initializer, int init_size);
    void initialize(int* initializer, int size);
    int get(int idx);
  private:
    std::function<void(int*, int)> calculatingFcn;
    int size;
    int calculated_acc_idx;
    int *arr;
};