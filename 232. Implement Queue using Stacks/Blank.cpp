// ===== Day 2: 232. Implement Queue using Stacks =====
//
// Implement a FIFO queue using ONLY two stacks.
//   push(x)  : add x to the back of the queue
//   pop()    : remove and return the front element
//   peek()   : return the front element (no remove)
//   empty()  : is the queue empty?
//
// The twist: a stack is LIFO (last in, first out), but a queue is
// FIFO (first in, first out). How do you get FIFO order from stacks?
//
// Example:
//   push(1); push(2);
//   peek() -> 1   (front is the FIRST one pushed)
//   pop()  -> 1
//   empty() -> false
//
// HINT: use TWO stacks -- an "input" stack and an "output" stack.
//   - push  -> always onto input
//   - pop/peek -> if output is empty, POUR input into output
//     (that reverses the order -> the oldest ends up on top of output)
//     then read from output's top.
//
// Design problem -> state -> MEMBER variables.

#include <bits/stdc++.h>
using namespace std;

class MyQueue {

    vector<int> st_input, st_output;
   
public:
    MyQueue() {
   
    }

    void push(int x) {
        st_input.push_back(x);
    }

    int pop() {
        int ans = peek();
        st_output.pop_back();

        return ans;
    }

    int peek() {
        if (st_output.empty()) {
            while (!st_input.empty()) {
                st_output.push_back(st_input.back());
                st_input.pop_back();
            }
        }

        int ans=st_output.back();
 
        return ans;
    }

    bool empty() {
        if (st_input.empty() && st_output.empty()) return true;

        return false;
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;   // 1
    cout << q.pop()  << endl;   // 1
    cout << q.empty() << endl;  // 0 (false)
    return 0;
}
