#include <iostream>
#include <vector>

// Helper function to generate subsets recursively
void generateSubsets(const std::vector<int>& nums, int index, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    // Base case: if we have processed all elements, store the subset
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }

    // Choice 1: Include the current element
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, result);

    // Choice 2: Exclude the current element (Backtrack)
    current.pop_back();
    generateSubsets(nums, index + 1, current, result);
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result;
    std::vector<int> current;

    generateSubsets(nums, 0, current, result);

    // Print all generated subsets
    for (const auto& subset : result) {
        std::cout << "[ ";
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}




///using bitmask


#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> getSubsetsBitmask(const std::vector<int>& nums) {
    int n = nums.size();
    int subsetCount = 1 << n; // 2^n subsets
    std::vector<std::vector<int>> result;

    // Iterate through all numbers from 0 to 2^n - 1
    for (int mask = 0; mask < subsetCount; ++mask) {
        std::vector<int> currentSubset;
        for (int i = 0; i < n; ++i) {
            // Check if the i-th bit is set to 1
            if (mask & (1 << i)) {
                currentSubset.push_back(nums[i]);
            }
        }
        result.push_back(currentSubset);
    }
    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result = getSubsetsBitmask(nums);

    for (const auto& subset : result) {
        std::cout << "[ ";
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}
