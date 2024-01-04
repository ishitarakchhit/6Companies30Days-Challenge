class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();

        vector<vector<int>> height(n, vector<int> (m, -1));
        queue<pair<int,int>> q;
        
        //pushing all cells with value 1 and setting its height to 0 in the ans maze
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1){ //water cell
                    q.push({i, j});
                    height[i][j] = 0;
                }
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        //now take out lands until queue is empty
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //cout<<row<<" "<<col<<endl;
            for(int z = 0; z<4; z++){

                int nRow = row + dx[z];
                int nCol = col + dy[z];

                if(nRow<n && nRow>=0 && nCol>=0 && nCol<m && height[nRow][nCol] == -1){
                    q.push({nRow, nCol});
                    height[nRow][nCol] = height[row][col] +1;
                }
            }
        }

        return height;
        

    }
};
