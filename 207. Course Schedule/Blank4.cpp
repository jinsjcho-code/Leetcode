// ===== 207. Course Schedule -- FINAL retry (zero hints) =====
//
// prerequisites[i] = [a, b]  ->  to take a, you must FIRST take b.
// Return true if all numCourses courses can be finished.
//
//   bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
//
// No hints this time. You know this. Go.
//
// (When you're done, also state Time / Space complexity below.)
//   Time:  O(N)
//   Space: O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // make an adjacent graph
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p:prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);  //b->a
            indegree[a]++;
        }

        // put the queue indegree which has 0
        
        queue<int> q;
        int counter=0;

        for (int i = 0 ; i<numCourses ; i++) {
            if (indegree[i] == 0) {
                q.push(i);        
            }
        }

        // BFS
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            counter++;

            for (int next:adj[cur]) {
                indegree[next]--;
                
                q.push(next);
            }
        }

        // cycle check
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

    vector<vector<int>> p9 = {{1,1}};
    cout << s.canFinish(2, p9) << endl;        // 0

    vector<vector<int>> p10 = {{1,0},{3,2}};
    cout << s.canFinish(4, p10) << endl;       // 1

    // bigger: 0->1->2->3->4, plus 5 independent, plus a cycle 6<->7
    vector<vector<int>> p11 = {{1,0},{2,1},{3,2},{4,3},{7,6},{6,7}};
    cout << s.canFinish(8, p11) << endl;       // 0

    // same but without the cycle
    vector<vector<int>> p12 = {{1,0},{2,1},{3,2},{4,3},{7,6}};
    cout << s.canFinish(8, p12) << endl;       // 1

    return 0;
}
