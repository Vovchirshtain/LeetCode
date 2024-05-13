#include <stdio.h>
#include <vector>
#include <unordered_map>

// ============================================== Two Sum ========================================================
/*
* Given an array of integers numsand an integer target, return indices of the two numbers such that they add up to target.
* 
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
* 
* You can return the answer in any order.
* 
* Example 1:
* Input: nums = [2,7,11,15], target = 9
* Output: [0,1]
* Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
* 
* Example 2:
* Input: nums = [3,2,4], target = 6
* Output: [1,2]
* 
* Example 3:
* Input: nums = [3,3], target = 6
* Output: [0,1]
*/
// ---------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) 
    {
        int diff;
        unsigned int i;
        std::unordered_map<int, int>::iterator it;
        std::unordered_map<int, int> hash_t;

        for (i = 0; i < nums.size(); i++)
        {
            diff = target - nums[i];
            it = hash_t.find(diff);

            if (it != hash_t.end() ) return {hash_t[diff], (int)i};
            else hash_t[nums[i]] = i;
        }

        return {};
    }
};
// ---------------------------------------------------------------------------------------------------------------
int main()
{
    std::vector<int> nums = {1, 2, 3, 4};
    int target = 3;

    Solution solution;
    std::vector<int> output = solution.twoSum(nums, target);

    printf("output: ");
    for (int digit: output)
        printf("%i ", digit);
    printf("\n");
    return 0;
}

