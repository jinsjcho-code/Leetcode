// ===== Blank retry #2 (CoderPad style): RandomizedSet =====
//
// CoderPad는 #include / main()을 안 줌. 전부 직접 작성!
// (Interview.cpp / Blank.cpp 보지 말기!)
//
// [Problem] Design RandomizedSet — all operations AVERAGE O(1):
//   - bool insert(int val): insert if not present.
//                           true if inserted, false if already present.
//   - bool remove(int val): remove if present.
//                           true if removed, false if not present.
//   - int  getRandom():     return a random element, EQUAL probability.
//
// 핵심 떠올리기:
//   - vector(값) + unordered_map(값 -> 인덱스)
//   - remove = swap-with-last + pop_back  (옮긴 값의 인덱스 갱신 잊지 말기!)
//   - getRandom = nums[rand() % nums.size()]
//
// 진행: 골격 Run -> insert Run -> remove Run -> getRandom Run
//
// 여기 아래부터 백지로 시작:


#include <bits/stdc++.h>
using namespace std;

// Problem: getRandom any number with same chance.
// Basic Idea: Hash table
// 
// unordered_map <int, int> table; -> can't get random number -> index.. 
// vector<int> items;


class RandomizedSet {
private:
    vector<int> items;
    unordered_map<int, int> table;

public:
    RandomizedSet () {

    }
    //insert if not present.
    //true if inserted, false if already present.

    bool insert(int val) {
        // if already present return false;

        if (table.find(val) != table.end()) return false;

        // if present, insered, return true
        table[val] = items.size(); // val = 4
        items.push_back(val); //  1-> 2-> 3-> val
        

        return true;
    }

//- bool remove(int val): remove if present.
//                           true if removed, false if not present.
    
    bool remove(int val) {
        // if nor present return false
        if (table.find(val) == table.end()) return false;
        
        // if present. removed , return ture
        //  1-> 2 (idx) -> 3-> 4 (last)
        //      o -> idx       x -> last
        
        // get the idx, last -> swap -> pop
        int idx = table[val];
        int last = items.back();

        // swap
        table[last] = idx;  
        items[idx] = last; // vector: 1 -> 4 -> 3-> 4

        //pop
        items.pop_back();
        table.erase(val);
        return true;
    }

    int getRandom() {
        
        return items[rand() % items.size()];
    }

};

int main () {
    RandomizedSet set;
    cout << "insert" << set.insert(1) << endl; // 1
    cout << "insert" << set.insert(2) << endl; // 1, 2
    cout << "insert" << set.insert(3) << endl; // 1, 2, 3
    cout << "insert" << set.insert(4) << endl; // 1, 2, 3
    cout << "insert" << set.insert(5) << endl; // 1, 2, 3
    cout << "insert" << set.insert(6) << endl; // 1, 2, 3
    cout << set.remove(2) << endl; // 1, 3
    cout << set.remove(2) << endl; // 1, 3
    cout << set.getRandom() << endl; // 1, 3
    cout << set.getRandom() << endl; // 1, 3
    cout << set.getRandom() << endl; // 1, 3
    return 0;
}
