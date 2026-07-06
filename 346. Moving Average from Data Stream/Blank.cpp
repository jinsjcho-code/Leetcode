// ===== Practice (CoderPad style): 346. Moving Average =====
//
// CoderPad gives you nothing - write #include / main() yourself!
//
// [Problem]
//   Design a class that computes the moving average of the last 'size'
//   values from a stream of integers.
//     - MovingAverage(int size): window of fixed size
//     - double next(int val): add val, return average of the last <=size values
//
//   Example (size = 3):
//     next(1)  -> 1.0        window [1]
//     next(10) -> 5.5        window [1,10]
//     next(3)  -> 4.666...   window [1,10,3]
//     next(5)  -> 6.0        window [10,3,5]   (1 slid out)
//
// Idea: keep a queue of the window + a running sum.
//   - push val, add to sum
//   - if queue size > window: pop front, subtract it from sum
//   - return sum / queue.size()
//
// This is "state" -> use MEMBER variables (like LRU).
//
// queue tools:  q.push(x)  q.front()  q.pop()  q.size()  q.empty()
//
// Start from a blank slate below:

// Goal: 

#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
private:


public:
    int sz;
    list <int> items;
    double sum=0;

    MovingAverage(int size) {
        sz = size;
    }

    double next(int val) {
        
        
        items.push_back(val);
        
        if (items.size() > sz) {
            sum = (sum-items.front());
            items.pop_front();
            sum = sum+val;
            
            
        }

        else sum = sum+val;

        return sum/items.size();
    }

};


int main () {
    MovingAverage mv(3);
    cout << mv.next(1) << endl;
    cout << mv.next(10) << endl;
    cout << mv.next(3) << endl;
    cout << mv.next(5) << endl;

    return 0;
}