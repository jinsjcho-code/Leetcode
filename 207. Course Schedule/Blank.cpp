// ===== Day 7: 207. Course Schedule  ⭐⭐ (Etched 핵심!) =====
//
// You must take numCourses courses, labeled 0 .. numCourses-1.
// prerequisites[i] = [a, b] means: to take course a, you must FIRST take b.
//                                  (b -> a,  "b must come before a")
//
// Return true if you can finish ALL courses.
//
//   numCourses=2, prereq=[[1,0]]         -> true    (take 0, then 1)
//   numCourses=2, prereq=[[1,0],[0,1]]   -> false   (0 needs 1, 1 needs 0 --
//                                                    a CYCLE! deadlock)
//
//   bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
//
// ---------------------------------------------------------------
// 🔧 HARDWARE ANGLE (say this in the interview!):
//   "This is exactly how a scheduler resolves instruction dependencies
//    in a pipeline -- you can't execute an op until its inputs are ready.
//    A cycle means a deadlock: nothing can ever be scheduled."
//   Same idea: build systems (make), dataflow graphs, netlist ordering.
// ---------------------------------------------------------------
//
// THE QUESTION REALLY IS:  "does this dependency graph have a CYCLE?"
//   - no cycle  -> a valid order exists -> true
//   - cycle     -> impossible          -> false
//
// ---------------------------------------------------------------
// APPROACH: KAHN'S ALGORITHM (BFS) -- the "scheduler" way. Very intuitive:
//
//   1) Build the graph:
//        adj[b] = list of courses that depend on b
//        indegree[a] = how many prereqs course a is still waiting on
//
//   2) Put every course with indegree == 0 into a queue.
//        (these have no prereqs -- they're READY to run right now)
//
//   3) While the queue isn't empty:
//        - pop a course, mark it "done" (count++)
//        - for each course that depended on it: indegree--
//          if that course's indegree hits 0 -> it's now READY -> push it
//
//   4) If count == numCourses -> everything got scheduled -> true
//      Otherwise some courses never became ready -> they're stuck in a
//      cycle -> false
//
//   "Run whatever is ready. Completing it makes new things ready. Repeat."
//   That IS a scheduler.
// ---------------------------------------------------------------
//
// FILL IN FIRST:
//   (1) What state do I need?         -> 
//   (2) What goes in the queue first? -> 
//   (3) How do I detect the cycle?    -> rabit and turtle?
// ---------------------------------------------------------------
//
// Tools:
//   vector<vector<int>> adj(numCourses);      // adjacency list
//   vector<int> indegree(numCourses, 0);
//   queue<int> q;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // APPROACH: KAHN'S ALGORITHM (BFS) -- the "scheduler" way. Very intuitive:
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& p : prerequisites) {
            int a=p[0];
            int b=p[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        // puhs in the queue if indegree is 0
        queue<int> q;
        for (int i=0 ; i<numCourses ; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            count++;

            for (int next: adj[cur]) {
                indegree[next]--;
                if (indegree[next] ==0)
                    q.push(next);
            }
        }

        return count==numCourses;
    }
};

int main() {
    Solution s;

    // 0 -> 1     (take 0, then 1)
    vector<vector<int>> p1 = {{1,0}};
    cout << s.canFinish(2, p1) << endl;        // 1 (true)

    // 0 -> 1 -> 0   CYCLE
    vector<vector<int>> p2 = {{1,0},{0,1}};
    cout << s.canFinish(2, p2) << endl;        // 0 (false)

    // no prerequisites at all
    vector<vector<int>> p3 = {};
    cout << s.canFinish(3, p3) << endl;        // 1

    // 0 -> 1 -> 2 -> 3   (a chain)
    vector<vector<int>> p4 = {{1,0},{2,1},{3,2}};
    cout << s.canFinish(4, p4) << endl;        // 1

    // diamond: 0 -> 1, 0 -> 2, 1 -> 3, 2 -> 3   (no cycle)
    vector<vector<int>> p5 = {{1,0},{2,0},{3,1},{3,2}};
    cout << s.canFinish(4, p5) << endl;        // 1

    // cycle hidden deeper: 1->2->3->1
    vector<vector<int>> p6 = {{2,1},{3,2},{1,3}};
    cout << s.canFinish(4, p6) << endl;        // 0

    return 0;
}
