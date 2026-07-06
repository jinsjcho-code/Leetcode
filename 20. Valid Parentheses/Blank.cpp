// ===== Practice (CoderPad style): 20. Valid Parentheses =====
//
// CoderPad gives you nothing - write #include / main() yourself!
//
// [Problem]
//   Given a string s containing just the characters
//   '(', ')', '{', '}', '[' and ']',
//   determine if the input string is VALID.
//
//   Valid means:
//     1) Open brackets are closed by the SAME type of bracket.
//     2) Open brackets are closed in the CORRECT ORDER.
//     3) Every close bracket has a matching open bracket.
//
//   Examples:
//     "()"        -> true
//     "()[]{}"    -> true
//     "(]"        -> false
//     "([)]"      -> false   (wrong order!)
//     "{[]}"      -> true
//
//   bool isValid(string s);
//
// Steps: skeleton -> Run -> logic -> test
//
// Start from a blank slate below:

/*
Goal: Design Valid bracket options
Condition
1) Same type then true
() -> true
() [] {} -> true
(] -> false
([)] -> false : it needs a right order.

2) Basic Idea

 - ([{
 - }]) - true
 - 1. array + index
   + ([ -> ]
      o    check index + pair

 - 2. stack -> easily check the order : Time O(1), Space O(N)
 - ([  -> ] -> (
 
*/

#include <bits/stdc++.h>
using namespace std;

class ValidParentheses {
private:


public:
    bool isValid(string s) {
            // define vector or stack.
    vector<int> st;
        // empty check
       // if (s==nullptr) return false;   

        for (char c : s) {
            
            // otherwise
            if (c=='(' || c=='[' || c=='{') {
                st.push_back(c);
            }

            else if (c==')' || c== ']' || c=='}') {
                if (st.empty()) return false;

                if (c==')' && st.back()=='(') {
                    st.pop_back();
                }
                else if (c==']' && st.back()=='[') {
                    st.pop_back();
                }
                else if (c=='}' && st.back()=='{') {
                    st.pop_back();
                }
                else return false; // wrong order check
            }

            else return false;
        } 
        if (st.empty()) return true;
        return false;
        
    }





};

int main() {
    ValidParentheses v;
    cout << v.isValid("()") << endl;
    cout << v.isValid("[]") << endl;
    cout << v.isValid("{}") << endl;

    cout << v.isValid("()[]{}") << endl;
    cout << v.isValid("(]") << endl;
    cout << v.isValid("([)]") << endl;
    cout << v.isValid("{[]}") << endl;

    cout << v.isValid("(") << endl;
    

    return 0;
}