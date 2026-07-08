// ===== Day 1: 155. Min Stack =====
//
// Design a stack that supports push, pop, top, AND retrieving the
// minimum element -- ALL in O(1) time.
//
//   push(val)  : push val onto the stack
//   pop()      : remove the top element
//   top()      : return the top element
//   getMin()   : return the minimum element currently in the stack
//
// Example:
//   push(-2); push(0); push(-3);
//   getMin() -> -3
//   pop();
//   top()    -> 0
//   getMin() -> -2
//
// The tricky part: getMin() must be O(1). You can't scan the whole
// stack each time. HINT: keep a SECOND stack that tracks the minimum
// "so far" alongside the main stack. (Same idea as LRU: an extra
// structure that maintains info you need in O(1).)
//
// Design problem -> state -> MEMBER variables.

// Basic Idea: Stack, Sorted array for min?
//  

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:

    vector<int> st;
    vector<int> st_min;
    
    MinStack() {
        // TODO: (maybe nothing needed)
    }

    void push(int value) {
        // TODO
        st.push_back(value);

        if (st_min.empty()) st_min.push_back(value);
        else {
            if (st_min.back() <= value) {
                st_min.push_back(st_min.back());
            }
            else st_min.push_back(value);
        }
    }

    void pop() {
        // TODO
        st.pop_back();
        st_min.pop_back();
    }

    int top() {
        // TODO
        return st.back();
    }

    int getMin() {
        // TODO
        return st_min.back();
    }
};

int main() {
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << endl;   // -3
    s.pop();
    cout << s.top() << endl;      // 0
    cout << s.getMin() << endl;   // -2
    return 0;
}
