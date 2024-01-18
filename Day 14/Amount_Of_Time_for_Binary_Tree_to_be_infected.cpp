class Solution {
    unordered_map<int, vector<int>> mp;          //node value, its edges
public:
    void createGraph(TreeNode* &root, int start){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            //push its left and right node
            if(node->left){
                mp[node->val].push_back((node->left)->val);
                mp[node->left->val].push_back(node->val);
                q.push(node->left); 
            }
            if(node->right){
                mp[node->val].push_back(node->right->val);
                mp[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }
    }

    int helper(int start){
        queue<pair<int,int>> q;     //node, time in which it got infectecd
        unordered_map<int,bool> visited;        //node, whether this node has been visited or not

        for(auto it: mp){
            visited[it.first] = false;
        }

        q.push({start, 0});
        visited[start] = true;
        
        int minTime = 0;

        while(!q.empty()){
            auto [node, time] = q.front();
            q.pop();

            for(auto nodes: mp[node]){
                if(visited[nodes] == false){
                    q.push({nodes, time+1});
                    minTime = time+1;
                    visited[nodes] = true;
                }
            }
        }

        return minTime;

    }

    int amountOfTime(TreeNode* root, int start) {
        //to create an adjacency list out of the binary tree
        //we are using an unordered_map becuase the values of nodes are not defined under n
        createGraph(root, start);

        //to find the minimum time for all nodes to get infected
        return helper(start);

    }
};
