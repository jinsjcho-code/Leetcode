// ===== 225. Implement Stack using Queues -- ONE queue version =====
//
// The trick: keep ONE queue. On push(x), rotate so the newest element
// ends up at the FRONT. Then pop()/top() just read the front.
//
//   push(1): q = [1]
//   push(2): q.push(2) -> [1,2], then rotate size-1 = 1 time:
//            move front(1) to back -> [2,1]   (2 is now at front!)
//   top()  -> q.front() = 2
//   pop()  -> front is 2, remove it
//
// Rotate = "pop front, push back" repeated (size-1) times.
// IMPORTANT: save the count BEFORE the loop (size changes as you go).

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {

    }

    void push(int x) {
        // TODO: push x, then rotate (size-1) times so x is at the front
        q.push(x);

        int n=q.size();
        for (int i=0 ; i<n-1 ; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        // TODO: front is the top; save it, pop, return it
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        // TODO: return the front
        return q.front();
    }

    bool empty() {
        // TODO
        if (q.empty()) return true;
        return false;
    }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top()   << endl;  // 3
    cout << s.pop()   << endl;  // 3
    cout << s.top()   << endl;  // 2
    cout << s.empty() << endl;  // 0
    return 0;
}
