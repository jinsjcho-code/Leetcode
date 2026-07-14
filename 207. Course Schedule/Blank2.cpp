// ===== 207. Course Schedule -- retry (minimal hints) =====
//
// prerequisites[i] = [a, b]  means: to take a, you must FIRST take b.
//                            i.e.  b  ->  a
// Return true if all numCourses courses can be finished.
//
//   numCourses=2, [[1,0]]        -> true
//   numCourses=2, [[1,0],[0,1]]  -> false   (cycle = deadlock)
//
//   bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
//
// 🔧 Say it out loud: "This is a scheduler resolving instruction
//    dependencies. A cycle means deadlock — nothing can ever run."
//
// ---------------------------------------------------------------
// FILL IN FIRST (don't peek at Blank.cpp!):
//
//   (1) What state do I need?
//       -> What is meaning state?? I don't get meaning in english.
//
//   (2) What goes into the queue first?  (what can run right now?)
//       -> I can run when indeed is 0
//
//   (3) How do I know there's a cycle?
//       -> check the counter and number of couses. if it's not same, then it's cycle.
// ---------------------------------------------------------------
//
// Remember the ONE-LINE intuition:
//   "Run whatever is ready. Finishing it makes new things ready. Repeat.
//    If we run out of ready things but courses remain -> cycle."
//
// ⚠️ Reminder: vectors you index into must be sized up front:
//      vector<vector<int>> adj(numCourses);
//      vector<int> indegree(numCourses, 0);

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Idea: Khan's algorithm
        // Pros:    Cons: 
        // Time: O(N)? / Space: O(N)?

        // 1) define adj graph
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            int a=p[0];
            int b=p[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        // 2) Khan's algorithm
        
        queue<int> q;

        int counter=0;

        for (int i = 0 ; i<numCourses;i++) {
            
            // check the indegree
            // push the queue which has 0 in indegree

            if (indegree[i] == 0) {
                q.push(i);
            }

        }
            // BFS? // 이게 왜 BFS지?
            while (!q.empty()) {
                // fetch from queue
                int cur = q.front();
                q.pop();

                // Done
                counter++;

                for (int next:adj[cur]) {
                    indegree[next]--;

                    if (indegree[next]==0) {
                    q.push(next); 
                    }

                }
            }
            
           
            
        
        
        if (counter==numCourses) return true;
        else return false;   

    }
};

int main() {
    Solution s;

    vector<vector<int>> p1 = {{1,0}};
    cout << s.canFinish(2, p1) << endl;        // 1

    vector<vector<int>> p2 = {{1,0},{0,1}};
    cout << s.canFinish(2, p2) << endl;        // 0  (cycle)

    vector<vector<int>> p3 = {};
    cout << s.canFinish(3, p3) << endl;        // 1  (no prereqs)

    vector<vector<int>> p4 = {{1,0},{2,1},{3,2}};
    cout << s.canFinish(4, p4) << endl;        // 1  (chain)

    vector<vector<int>> p5 = {{1,0},{2,0},{3,1},{3,2}};
    cout << s.canFinish(4, p5) << endl;        // 1  (diamond)

    vector<vector<int>> p6 = {{2,1},{3,2},{1,3}};
    cout << s.canFinish(4, p6) << endl;        // 0  (cycle 1->2->3->1)

    // one isolated course + a cycle elsewhere
    vector<vector<int>> p7 = {{1,2},{2,1}};
    cout << s.canFinish(3, p7) << endl;        // 0  (0 is free, but 1<->2 cycle)

    // long chain, no cycle
    vector<vector<int>> p8 = {{1,0},{2,1},{3,2},{4,3},{5,4}};
    cout << s.canFinish(6, p8) << endl;        // 1

    return 0;
}
