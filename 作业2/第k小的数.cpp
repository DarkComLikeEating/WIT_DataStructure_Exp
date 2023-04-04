#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int quickselect(vector<int>& nums, int k) {
    if (nums.size() == 1) {
        return nums[0];
    }
    int pivot = nums[0];
    vector<int> left, right;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= pivot) {
            left.push_back(nums[i]);
        } else {
            right.push_back(nums[i]);
        }
    }
    if (k <= left.size()) {
        return quickselect(left, k);
    } else if (k == left.size() + 1) {
        return pivot;
    } else {
        return quickselect(right, k - left.size() - 1);
    }
}

int main() {
    vector<int> nums = {7, 5, 1, 9, 3};
    int k = 2;
    int kth_smallest = quickselect(nums, k);
    printf("第%d小的数是 %d\n", k, kth_smallest);
    return 0;
}
