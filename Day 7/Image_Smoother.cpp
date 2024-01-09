class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        int n = img.size();

        vector<vector<int>> ans(n, vector<int> (img[0].size(), 0));

        for(int i=0; i<img.size(); i++){
            for(int j=0; j<img[i].size(); j++){
                long sum = 0;
                int elements = 0;
                for(int k=0; k<9; k++){
                    int row = i + dx[k];
                    int col = j + dy[k];
                    if(row >=0 && row <img.size() && col>=0 && col<img[i].size()){
                        sum += img[row][col];
                        elements++;
                    }
                }
                int m  = img[0].size();
                sum = sum/elements;
                ans[i][j] = sum;                
            }
        }
        return ans;
    }
};
