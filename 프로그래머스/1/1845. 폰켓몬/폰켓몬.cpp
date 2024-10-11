#include <iostream>
#include <vector>
#include <unordered_set>

int solution(std::vector<int> nums) {
    std::unordered_set<int> unique_nums;
    
    for (int num : nums) {
        unique_nums.insert(num);
    }
    
    int max_pick = nums.size() / 2;
    
    if (unique_nums.size() >= max_pick) {
        return max_pick;
    } else {
        return unique_nums.size();
    }
}

int main() {
    std::vector<int> nums1 = {3, 1, 2, 3};
    std::vector<int> nums2 = {3, 3, 3, 2, 2, 4};
    std::vector<int> nums3 = {3, 3, 3, 2, 2, 2};
    
    int result1 = solution(nums1);
    int result2 = solution(nums2);
    int result3 = solution(nums3);
    
    std::cout << "Result 1: " << result1 << std::endl; // 2
    std::cout << "Result 2: " << result2 << std::endl; // 3
    std::cout << "Result 3: " << result3 << std::endl; // 2
    
    return 0;
}
