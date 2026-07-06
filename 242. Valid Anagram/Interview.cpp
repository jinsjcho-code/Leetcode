// ===== Mock Interview (CoderPad style) =====
//
// Write everything yourself: #include, function, main, tests.
//
// (Problem stated verbally by the interviewer - see chat.)
//
// Start from a blank slate below:


// Goal: design the alphabet counter
// Basic Idea
// 1) Brute-force -> Time complexity: O(N^2)
// 2) Hash table

// rat vs. car
// r= 1, a=1, t=1,  // c = 1, a = 1, r=1

/*
I'll give you two strings, s and t. I want you to write a function that returns true if t is an anagram of s, and false otherwise.

An anagram is a word formed by rearranging the letters of another — using all the original letters exactly once.

Examples:

s = "anagram", t = "nagaram" → true
s = "rat", t = "car" → false
s = "a", t = "ab" → false


*/
#include <bits/stdc++.h>
using namespace std;

class two_strings {
public:
    bool two(string s, string t) {
        unordered_map<char, int> st;
        
        // size check
        if (s.size() != t.size()) return false;
        
        // save the counter for string s
        for (char c:s) {
            st[c] = st[c]+1;
        }

        // check the conter for string t
        for (char c:t) {
            if (st.find(c) != st.end()) { // check the present for c
                st[c] = st[c]-1; // count -1;

                if (st[c] < 0) return false; // more counter for string t
            }
            else { // not present for c
                return false;
            }
        }
    
    return true;
    }

};

int main() {
    two_strings ts;
    cout << ts.two("anagram", "nagaram") << endl;
    cout << ts.two("rat", "cat") << endl;
    cout << ts.two("a", "ab") << endl;
    cout << ts.two("aab", "abb") << endl;  // a:2 , b:1 vs. a:1 b:2

    return 0;
}