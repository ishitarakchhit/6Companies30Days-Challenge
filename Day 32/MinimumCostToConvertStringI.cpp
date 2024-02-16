/*
Intuition
We have to find the shortest path from one character to another. One algorithm that can do this is shortest path algo, BFS.

Approach
Map all edges with their cost to convert from one char to other char. Now for every character call the BFS function to find the minimum cost to convert.
This will take up higher time complexity so we can initally store the shortest path for all characters which will take up a time of 26*(total edges). Then you can iterate over source string to convert it to target string and calculate the total cost.

Complexity
Time complexity: O(original.length() + 26*(original.length()) + source.length)
Space complexity: O(original.length() + 26 + 26*(original.length()))
Code
*/
class Solution {
public:

    //function to find the minimum cost for a given character to all the other characters
    vector<int> bfs(char org, unordered_map<char, vector<pair<char, int>>> &edges){
        queue<pair<char, int>> q;       //changed, cost
        q.push({org, 0});
        vector<int> cost(27, INT_MAX);
        
        cost[org-'a'] = 0;

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            if(edges.find(front.first)!= edges.end()){
                for(auto it: edges[front.first]){
                    int new_Cost = front.second + it.second;
                    if(cost[it.first-'a'] > new_Cost){
                        cost[it.first-'a'] = new_Cost;
                        q.push({it.first, new_Cost});
                    }
                }
            }
        }
        return cost;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> edges;  //source => vector{target, cost}

        //construct a graph with edges, weight 
        for(int i=0; i<original.size(); i++){
            if(original[i]!= changed[i]){
                edges[original[i]].push_back({changed[i], cost[i]});
            }
        }

        //now calculate the cost required to convert every integer to every other integer 26*26
        vector<vector<int>> total_Cost(27, vector<int> (27, INT_MAX));

        for(int i=0; i<27; i++){
            total_Cost[i] = bfs(i+'a', edges);            
        }

        long long ans=0;
        //calculate the total cost
        for(int i=0; i<source.length(); i++){
            int cost = total_Cost[source[i]-'a'][target[i]-'a'];
            if(cost == INT_MAX) return -1;
            ans += cost;
        }

        return ans;

    }
};
