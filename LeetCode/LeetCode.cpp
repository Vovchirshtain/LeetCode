#include <stdio.h>
#include <vector>
#include <unordered_map>

// ============================================== Longest Common Prefix ==========================================
/*
* Write a function to find the longest common prefix string amongst an array of strings.
* 
* If there is no common prefix, return an empty string "".
* 
* Example 1:
* Input: strs = ["flower","flow","flight"]
* Output: "fl"
* 
* Example 2:
* Input: strs = ["dog","racecar","car"]
* Output: ""
* Explanation: There is no common prefix among the input strings.
*/
// ---------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs) 
    {
        if (strs.size() == 0) return "";

        std::string prefix = strs[0];
        for (unsigned int i = 1; i < strs.size(); i++)
        {
            while (strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty() ) return "";
            }
        }
        return prefix;
    }
};
// ---------------------------------------------------------------------------------------------------------------
int main()
{
    return 0;
}

