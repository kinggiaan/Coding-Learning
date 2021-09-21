#include <iostream>
void sortedSquares(int* nums, int size) {
    for (int i = 0; i < size; i++) {
        nums[i] = nums[i] * nums[i];
    }
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (nums[i] > nums[j]) {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;

            }
        }

    }
}
int main() {
    int a[5] = { 4,1,2,5,2 };
    sortedSquares(a, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << " ";
    }
}