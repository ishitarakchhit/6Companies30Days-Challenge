class Solution {
public:
    
    void f(vector<vector<int>> &ans, vector<int> &temp, int i, int k, int n){
        if(n == 0){
            if(temp.size() == k)
                ans.push_back(temp);
            return;
        }
        else{
            for(int j=i; j<=9 && n-j >= 0; j++){
                temp.push_back(j);
                f(ans, temp, j+1, k, n-j);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        f(ans, temp, 1, k, n);

        return ans;
    }
};
