#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <stack>

// ============================================== Valid Parentheses ==============================================
/*
* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* 
* An input string is valid if:
* 
* 1. Open brackets must be closed by the same type of brackets.
* 2. Open brackets must be closed in the correct order.
* 3. Every close bracket has a corresponding open bracket of the same type.
* 
* Example 1:
* Input: s = "()"
* Output: true
* 
* Example 2:
* Input: s = "()[]{}"
* Output: true
* 
* Example 3:
* Input: s = "(]"
* Output: false
*/
// ---------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    static bool isValid(std::string s)
    {
        if (s.empty() ) return false;

        std::stack<char> stack;

        for (char letter: s)
        {
            if (letter == '(' || letter == '[' || letter == '{')
                stack.push(letter);

            else if
                (
                    stack.empty() ||
                    (letter == ')' && stack.top() != '(') ||
                    (letter == ']' && stack.top() != '[') ||
                    (letter == '}' && stack.top() != '{')
                )
                return false;
            else
                stack.pop();
        }
        return stack.empty();
    }
};
// ---------------------------------------------------------------------------------------------------------------
int main()
{
    return 0;
}

