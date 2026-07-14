// ===== 207. Course Schedule -- retry #3 (minimal help) =====
//
// prerequisites[i] = [a, b]  ->  to take a, you must FIRST take b.
// Return true if all numCourses courses can be finished.
//
//   [[1,0]]        -> true
//   [[1,0],[0,1]]  -> false   (cycle)
//
//   bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
//
// ---------------------------------------------------------------
// The ONLY thing you should need:
//
//   "Run whatever is READY. Finishing it makes new things ready. Repeat.
//    If we run out of ready things but courses remain -> cycle."
//
// Everything else, derive it yourself:
//   - What does "ready" mean?  How do I know a course is ready?
//   - When I finish a course, who becomes ready?  How do I find them?
//   - What are the 4 steps, and which ones must FINISH before the next?
// ---------------------------------------------------------------
//
// FILL IN FIRST:
//   (1) State I need:
//       -> 여기는 뭘 채워야 함?
//
//   (2) What starts in the queue:
//       -> indeed is 0
//
//   (3) Cycle detection:
//       -> counter == numCourses
//   (4) Time: O(N)?? Space: O(N)??
// ---------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // make a adjacent
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p:prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a); // check the next one.

            indegree[a]++;
        }
    

        // check indegree
        queue<int> q;
        int counter=0;

        for (int i=0; i<numCourses ; i++) {
            if (indegree[i] ==0) {
                q.push(i);
            }
        }

        // Queue
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            //done
            counter++;

            for (int next : adj[cur]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                } 
            }
        }

        // check the cycle
        return counter==numCourses;
        

        
    }
};

int main() {
    Solution s;

    vector<vector<int>> p1 = {{1,0}};
    cout << s.canFinish(2, p1) << endl;        // 1

    vector<vector<int>> p2 = {{1,0},{0,1}};
    cout << s.canFinish(2, p2) << endl;        // 0

    vector<vector<int>> p3 = {};
    cout << s.canFinish(3, p3) << endl;        // 1

    vector<vector<int>> p4 = {{1,0},{2,1},{3,2}};
    cout << s.canFinish(4, p4) << endl;        // 1

    vector<vector<int>> p5 = {{1,0},{2,0},{3,1},{3,2}};
    cout << s.canFinish(4, p5) << endl;        // 1

    vector<vector<int>> p6 = {{2,1},{3,2},{1,3}};
    cout << s.canFinish(4, p6) << endl;        // 0

    vector<vector<int>> p7 = {{1,2},{2,1}};
    cout << s.canFinish(3, p7) << endl;        // 0

    vector<vector<int>> p8 = {{1,0},{2,1},{3,2},{4,3},{5,4}};
    cout << s.canFinish(6, p8) << endl;        // 1

    // self-loop: course 1 requires itself
    vector<vector<int>> p9 = {{1,1}};
    cout << s.canFinish(2, p9) << endl;        // 0

    // two independent chains
    vector<vector<int>> p10 = {{1,0},{3,2}};
    cout << s.canFinish(4, p10) << endl;       // 1

    return 0;
}
