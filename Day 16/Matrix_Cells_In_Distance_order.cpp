//map can also be used
//better apporach to sort with customization

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;   
        //distance, indices

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int distance = abs(rCenter-i) + abs(cCenter-j);
                pq.push({distance,{i,j}});
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto indices = pq.top().second;
            pq.pop();
            vector<int> temp;
            temp.push_back(indices.first);
            temp.push_back(indices.second);
            ans.push_back(temp);
        }

        return ans;
    }
};
