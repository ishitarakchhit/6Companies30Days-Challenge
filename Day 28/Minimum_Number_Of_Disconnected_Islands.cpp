Intuition
To convert any connected island to disconnected island, seperating one single island from the group can result in two seperate islands or disconnected islands
eg. 1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
can be converted to
1 0 1 1
0 1 1 1
1 1 1 1
1 1 1 1
first grid has one island where as second grid has tow islands.
Therefore, we can conclude to convert connected to disconnected island we atmost require 2 days

Approach
First, check if the grid already contains disconnected islands or no islands, if yes then return 0.
Secondly, traverse the entire grid and start converting land to water one by one and simultaneously check if it results in disconnected component or not. If yes, then return 1.
Else in the end return 2.
Complexity
Time complexity: O(nmn*m)
Space complexity: O(n*m) for bfs traversal
Code
class Solution {
public:

    //function to count the number of islands
    void bfs(vector<vector<int>> &grid, int i, int j){
        queue<pair<int,int>> q;
        q.push({i, j});
        grid[i][j] = 0;

        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty()){
            auto top = q.front();
            int row = top.first;
            int col = top.second;
            q.pop();
            //now push all its adjacent land into the queue
            for(int d =0; d<4; d++){
                int nrow = row + dx[d];
                int ncol = col + dy[d];
                if(nrow<grid.size() && nrow>=0 && ncol>=0 && ncol<grid[0].size()){
                    if(grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 0;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        
    }

    //function to check if the grid only has 1,0 island or more
    bool check(vector<vector<int>> grid){
        int n =0;     //count of number of islands

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    n++;
                    bfs(grid, i, j);
                }
            }
        }

        if(n == 0 || n>1) return true;
        else return false;
    }

    int minDays(vector<vector<int>>& grid) {

        if(check(grid)) return 0;

        for(int i=0; i<grid.size() ;i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] =0;
                    if(check(grid)) return 1;
                    else grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
