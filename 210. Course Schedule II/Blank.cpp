// ===== Day 7: 210. Course Schedule II  (207의 형제 -- 쉬워요!) =====
//
// Same setup as 207, but now RETURN THE ORDER, not just true/false.
//
//   prerequisites[i] = [a, b]  ->  to take a, you must FIRST take b.
//
//   numCourses=2, [[1,0]]        -> [0, 1]
//   numCourses=4, [[1,0],[2,0],[3,1],[3,2]]  -> [0,1,2,3]  (or [0,2,1,3])
//   numCourses=2, [[1,0],[0,1]]  -> []       (cycle -> impossible)
//
//   vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
//
// ---------------------------------------------------------------
// 💡 This IS 207. The order you POP things off the queue is already a
//    valid topological order -- you were just throwing it away!
//
//    207:  counter++;                 // count how many finished
//    210:  order.push_back(cur);      // ACTUALLY RECORD the order
//
//    Cycle check: if order.size() != numCourses -> return {}   (empty)
//
//    Note: MULTIPLE valid answers exist. Any order that respects the
//    dependencies is accepted. (Our tests below just check the size and
//    that the order is valid -- see the checker in main.)
// ---------------------------------------------------------------
//
// 🔧 Etched angle: this is the actual SCHEDULE -- the issue order for
//    a dependency graph of instructions.
//
// FILL IN:
//   (1) What changes from 207?  -> return the order
//   (2) Time / Space?           -> O(V+E), O(V+E)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Very similar with 207. but I need to return ORDER

        // Algorithm: topological order // Kahn's algorithm.

        // 1) Make a graph adj lists
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans = {};

        for (auto& p : prerequisites) {
            int a=p[0];
            int b=p[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        // 2) check the indegree is 0 and push the queue.
        queue<int> q; 
        for (int i=0; i<numCourses ; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // 3) BFS
        int counter=0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            counter++;
            ans.push_back(cur);

            for (int next:adj[cur]) {
                indegree[next]--;

                if (indegree[next]==0) {
                    q.push(next);
                }
            }
        }

        // 4) return the order        
        if (counter==numCourses) {
            return ans;
        }
        else return {};
    }
};

// ---- given: checks that an order is a VALID topological order ----
bool isValidOrder(int numCourses, vector<vector<int>>& prereq,
                  const vector<int>& order) {
    if ((int)order.size() != numCourses) return false;
    vector<int> pos(numCourses, -1);
    for (int i = 0; i < (int)order.size(); i++) {
        if (order[i] < 0 || order[i] >= numCourses) return false;
        if (pos[order[i]] != -1) return false;      // duplicate
        pos[order[i]] = i;
    }
    for (auto& p : prereq)
        if (pos[p[1]] > pos[p[0]]) return false;    // b must come before a
    return true;
}

int main() {
    Solution s;

    vector<vector<int>> p1 = {{1,0}};
    vector<int> o1 = s.findOrder(2, p1);
    cout << isValidOrder(2, p1, o1) << endl;        // 1 (valid order)

    vector<vector<int>> p2 = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> o2 = s.findOrder(4, p2);
    cout << isValidOrder(4, p2, o2) << endl;        // 1

    vector<vector<int>> p3 = {{1,0},{0,1}};
    vector<int> o3 = s.findOrder(2, p3);
    cout << o3.empty() << endl;                     // 1 (cycle -> empty)

    vector<vector<int>> p4 = {};
    vector<int> o4 = s.findOrder(3, p4);
    cout << isValidOrder(3, p4, o4) << endl;        // 1

    vector<vector<int>> p5 = {{1,0},{2,1},{3,2},{4,3},{5,4}};
    vector<int> o5 = s.findOrder(6, p5);
    cout << isValidOrder(6, p5, o5) << endl;        // 1

    vector<vector<int>> p6 = {{2,1},{3,2},{1,3}};
    vector<int> o6 = s.findOrder(4, p6);
    cout << o6.empty() << endl;                     // 1 (cycle)

    // print one order so you can see it
    cout << "--- one valid order for p2: ";
    for (int x : o2) cout << x << " ";
    cout << endl;

    return 0;
}
