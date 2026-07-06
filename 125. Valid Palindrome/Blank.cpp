// ===== Practice (CoderPad style): 125. Valid Palindrome =====
//
// CoderPad gives you nothing - write #include / main() yourself!
//
// [Problem]
//   A phrase is a palindrome if, after converting all uppercase letters
//   to lowercase and removing all non-alphanumeric characters, it reads
//   the same forward and backward.
//   Return true if s is a palindrome, false otherwise.
//
//   Examples:
//     "A man, a plan, a canal: Panama"  -> true   (amanaplanacanalpanama)
//     "race a car"                       -> false
//     " "                                -> true   (empty after cleaning)
//
//   bool isPalindrome(string s);
//
// Pattern: TWO POINTERS (left starts at 0, right at the end).
//   - skip characters that are NOT alphanumeric
//   - compare left vs right (lowercased); if they differ -> false
//   - move inward: left++, right--
//   - stop when left >= right  -> it's a palindrome
//
// Helpful: isalnum(c) -> is c a letter or digit?
//          tolower(c) -> lowercase version of c
//
// Steps: skeleton -> logic -> test
//
// Start from a blank slate below:

// Goal: check the palindrome
// Idea#1: check the front and back
// Structure: List
// Time: O(N/2), Space: O(N)

#include <bits/stdc++.h>
using namespace std;

class Valid_Palindrome {
private:
public:
    bool isPalindrome(string s) {
    list<char> items;

    for (char c: s) {
        if (isalnum(c)) {
            items.push_back(tolower(c));
        }
    }

    // check the front and back
    while (items.size() > 1) { // if size == 1 -> true
        if (items.front() == items.back()) {
            items.pop_front();
            items.pop_back();
        }
        else return false;
    }
    return true;

    }
};

int main() {
    Valid_Palindrome vp;
    cout << vp.isPalindrome("A man, a plan, a canal: Panama") << endl;  // 1
    cout << vp.isPalindrome("race a car") << endl;                       // 0
    cout << vp.isPalindrome(" ") << endl;                                // 1 (빈 문자열)
    return 0;
}