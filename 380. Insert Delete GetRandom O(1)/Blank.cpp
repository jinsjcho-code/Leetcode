// ===== Blank retry (CoderPad style): RandomizedSet =====
//
// CoderPad는 #include / main()을 안 줌. 전부 직접 작성!
//
// [Problem] Design RandomizedSet — all operations AVERAGE O(1):
//   - bool insert(int val): insert if not present.
//                           true if inserted, false if already present.
//   - bool remove(int val): remove if present.
//                           true if removed, false if not present.
//   - int  getRandom():     return a random element, EQUAL probability.
//
// 진행 순서 (작게 짜고 자주 Run):
//   1) #include + using + 빈 class 골격 + main 의 hello -> Run
//   2) 멤버 변수 + 생성자 + insert        -> Run, 테스트 1~2
//   3) remove (swap-and-pop)              -> Run
//   4) getRandom                          -> Run
//
// 힌트가 필요하면 STL_Cheatsheet.md 참고 (정답 Interview.cpp 는 보지 말기!)
//
// 여기 아래부터 백지로 시작:

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:

    vector<int> num;
    unordered_map<int, int> table;

    // [Problem] Design RandomizedSet — all operations AVERAGE O(1):



public:
    RandomizedSet() {
        
    }

    //   - bool insert(int val): insert if not present.
    //                           true if inserted, false if already present.
    bool insert(int val) {
        if (table.find(val) != table.end()){ // exist
            return false;
        }

        // if not present the insert and return true
        table[val] = num.size();
        num.push_back(val);

        return true;    
    }

    
//   - bool remove(int val): remove if present.
//                           true if removed, false if not present.

    bool remove(int val) {
        // if not present return false
        if (table.find(val) == table.end()) return false;

        // exist
        // remove from the table
        
        // 1 - 2 - 3 - 4
        //    idx     last
        int idx = table[val];
        int last = num.back();
        num[idx] = last;
        table[last] = idx;

        num.pop_back();
        table.erase(val);
        
        return true;
    }

//   - int  getRandom():     return a random element, EQUAL probability.
    int getRandom() {
    
        return num[rand()%num.size()];
    }
};

int main() {
    RandomizedSet s;
    cout << s.insert(1) << endl;
    cout << s.insert(1) << endl;
    cout << s.remove(2) << endl;
    cout << s.remove(1) << endl;
    cout << s.remove(1) << endl;
    cout << s.insert(1) << endl;
    cout << s.insert(2) << endl;
    cout << s.insert(3) << endl;
    cout << s.insert(4) << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;



    return 0;
}
