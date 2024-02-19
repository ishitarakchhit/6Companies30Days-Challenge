/*Approach
create a graph to map all the edges
generate all subtrees, use bitmask to save memory.
now inside the helper function decode the subtrees one by one and then call findMaxDist function to find the max distance for that subtree and also check if that subtree is valid or i.e. the path from one city to another should go though the cities within that subtree.
and find the max distance for that subtree and store the result in maxi variable
BFS function finds the minimum distance to reach from one node to other and if temp is marked -1, it means that we cannot push that node to our queue. In the end if temp contains any value equal to 10^6, it suggests that we were not able to visit that node and that particular subtree was invalid.
Complexity
Time complexity: 2^n
Space complexity: O(2^n)
Code
  */
class Solution {
public:
    //function to create adjacency list using given edges, this will be an undirected graph
    void createGraph(vector<vector<int>> &graph, vector<vector<int>> &edges){
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }
    
    //function to find the minimum distance to travel all the nodes from the current city
    vector<int> bfs(vector<vector<int>> &graph, int city, vector<int> &temp){
        int n = graph.size();
        temp[city] = 0;
        queue<pair<int,int>> q;       //city, distance
        q.push({city, 0});      

        while(!q.empty()){
            int newCity= q.front().first;
            int dist = q.front().second;
            q.pop();

            for(int i=0; i<graph[newCity].size(); i++){
                int travel = graph[newCity][i];
                if(temp[travel] > dist+1){
                    temp[travel] = dist+1;
                    q.push({travel, dist+1});
                }
                if(temp[travel] == -1) continue;
            }
        }
        return temp;
    }

    

    //function to generate all subtrees or subsets. This function uses mask integer to store all subtrees
    void generateSubtrees(int mask, vector<int> &subtrees, int ind, int n){
        if(ind > n){
            subtrees.push_back(mask);
            return;
        }
        generateSubtrees(mask|(1<<ind), subtrees, ind+1, n);
        generateSubtrees(mask, subtrees, ind+1, n);
    }


    //function to find the maximum distance to travel from one city to another within a subtree
    int findMaxDist(vector<vector<int>> &graph, vector<int> &subtree){
        int maxi = 0;

        for(int i=0; i<subtree.size(); i++){
            vector<int> temp(graph.size(), -1);
            for(int i=0; i<subtree.size(); i++){
                temp[subtree[i]] = 1e6;
            }
            vector<int> dist = bfs(graph, subtree[i], temp);
            for(int j=0; j<dist.size(); j++){
                if(dist[j] == 1e6) return 0;
                maxi = max(maxi, dist[j]);
            }
        }
        
        return maxi;
    }
    
//function to convert mask to a vector
    vector<int> decodeSubtree(int mask){
        vector<int> subtree;
        int i=0; 
        while(mask>0){
            if((mask&1) == 1){
                subtree.push_back(i);
            }
            mask = mask>>1;
            i++;
        }
        return subtree;
    }

    //function to count required subtrees
    void helper(vector<vector<int>> &graph, vector<int> &ans, vector<int> &subtrees, int n){
        //store maximum distance for every subtree in the end of the subset
        for(int i=0; i<subtrees.size(); i++){
            vector<int> subtree = decodeSubtree(subtrees[i]);
            if(subtree.size()<2) continue;
            int dist = findMaxDist(graph, subtree);
            if(dist>=1 && dist<=n) ans[dist-1]++;
        }
    }


    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n+1);
        vector<int> ans(n-1, 0);

        //create the graph using the given edges
        createGraph(graph, edges);

        //find all substrees of trees
        int mask = 0;
        vector<int> subtrees;
        generateSubtrees(mask, subtrees, 1, n);

        //function to find the final answer
        helper(graph, ans, subtrees, n);
        

        return ans;
    }
};
