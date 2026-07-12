// ===== Day 6: 200. Number of Islands =====
//
// Given a 2D grid of '1' (land) and '0' (water), count the number of
// ISLANDS. An island is land connected horizontally or vertically
// (NOT diagonally). Assume the grid edges are all surrounded by water.
//
//   grid = [                       -> 1 island
//     ['1','1','1','1','0'],          (all the 1s are connected)
//     ['1','1','0','1','0'],
//     ['1','1','0','0','0'],
//     ['0','0','0','0','0'] ]
//
//   grid = [                       -> 3 islands
//     ['1','1','0','0','0'],
//     ['1','1','0','0','0'],
//     ['0','0','1','0','0'],
//     ['0','0','0','1','1'] ]
//
//   int numIslands(vector<vector<char>>& grid);
//
// ---------------------------------------------------------------
// THIS IS A GRAPH.  The grid IS the graph:
//   - each cell '1' = a node
//   - neighbors = up / down / left / right  (4 directions)
//
// THE KEY IDEA:
//   Walk every cell. When you find a '1' you haven't seen yet:
//       -> that's a NEW island, count++
//       -> then "flood" the whole island (DFS or BFS) so you don't
//          count its cells again.
//
// ⚠️ NEW vs TREES: a grid HAS cycles (you can walk in circles!)
//    So you MUST mark cells as visited, or you'll loop forever. 💥
//    Two ways to mark:
//      (a) a separate visited[][] array
//      (b) just overwrite the '1' with '0' as you visit it (sinking it)
//
// ---------------------------------------------------------------
// FILL IN FIRST:
//
//   (1) What does the flood/dfs helper RETURN?
//       -> connected
//
//   (2) Base case(s)?   (think: out of bounds? water? already visited?)
//       -> return if it's 0 or edge
//
//   (3) What does it do at each cell?
//       -> check the visited

// ---------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int counter;
    void islands(vector<vector<char>>& land, int x, int y) {
        
        // base case: check the edge
        if (x < 0 || y <0 || x >= land.size() || y >= land[0].size()) return; // check the edge. How can I check the edge? size???
      
        if (land[x][y]=='1') {
            land[x][y] = '0';
            islands(land, x-1, y); // east
            islands(land, x+1, y); // west
            islands(land, x, y+1); // south
            islands(land, x, y-1); // north
        }        
    }

    int numIslands(vector<vector<char>>& grid) {
        
        counter=0; // how many islands exist
        int x=grid.size();
        int y=grid[0].size();

        for (int i =0 ; i<x ; i++) {
            for (int j=0 ; j<y ; j++) {
                if (grid[i][j] == '1') {
                    islands(grid, i, j);
                    counter++;
                }
            }
        }
        
        return counter;
                
    }
};

int main() {
    Solution s;

    vector<vector<char>> g1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << s.numIslands(g1) << endl;   // 1

    vector<vector<char>> g2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << s.numIslands(g2) << endl;   // 3

    vector<vector<char>> g3 = {
        {'0','0','0'},
        {'0','0','0'}
    };
    cout << s.numIslands(g3) << endl;   // 0

    vector<vector<char>> g4 = {
        {'1'}
    };
    cout << s.numIslands(g4) << endl;   // 1

    // diagonal is NOT connected -> 2 islands
    vector<vector<char>> g5 = {
        {'1','0'},
        {'0','1'}
    };
    cout << s.numIslands(g5) << endl;   // 2

    return 0;
}
