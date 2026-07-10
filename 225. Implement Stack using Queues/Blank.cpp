// ===== Day 2 (extra): 225. Implement Stack using Queues =====
//
// Implement a LIFO stack using ONLY queue operations.
//   push(x)  : push x onto the stack
//   pop()    : remove and return the top (most recent) element
//   top()    : return the top element
//   empty()  : is it empty?
//
// A queue is FIFO (oldest comes out first). A stack is LIFO (newest
// comes out first). Opposite again -- how do we flip it?
//
// Example:
//   push(1); push(2);
//   top()  -> 2   (most recent)
//   pop()  -> 2
//   empty() -> false
//
// HINT (elegant one-queue trick):
//   On push(x): push x to the queue, THEN rotate -- move every element
//   that was already there to the back (pop front, push back), size-1
//   times. Now x sits at the FRONT, so front() = the newest = stack top.
//   Then pop()/top() just use the queue's front.
//
//   (Two queues also work; the one-queue rotate is cleaner.)
//
// queue tools:  q.push(x)  q.front()  q.pop()  q.size()  q.empty()

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        // TODO
    }

    void push(int x) {
        if (!q2.empty()) q2.push(x);   // q2가 활성이면 q2
        else q1.push(x);               // 아니면 q1 (둘 다 비어도 q1)
        
    }

    int pop() {
        // Check the empty queue
        if (q2.empty()) {
            // move queue to empty queue
            while (q1.size()>1) {
                q2.push(q1.front());
                q1.pop();
            }

            int ans = q1.front();
            q1.pop();

            return ans;
            
        }

        else {
            while (q2.size()>1) {
                q1.push(q2.front());
                q2.pop();
            }

            int ans = q2.front();
            q2.pop();

            return ans;
        }
    }

    int top() {
        if (q1.empty()) {
            return q2.back();
        }
        
        return q1.back();
    }

    bool empty() {
        if (q1.empty() && q2.empty()) return true;

        return false;
    }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.top()   << endl;  // 2
    cout << s.pop()   << endl;  // 2
    cout << s.empty() << endl;  // 0 (false)
    return 0;
}
