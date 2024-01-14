class Solution {
public:
    vector<int> bfs(vector<vector<pair<int, int>>> &adj, vector<int> &dist, int i) {
    queue<pair<int, int>> q;
    q.push({i, 0});

    while (!q.empty()) {
        auto city = q.front().first;
        auto distance = q.front().second;
        q.pop();

        for (auto &x : adj[city]) {
            if (x.second + distance < dist[x.first]) {
                q.push({x.first, x.second + distance});
                dist[x.first] = x.second + distance; // Update distance
            }
        }
    }
    return dist;
}

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int city = INT_MAX, ans = 0;;

        //create the adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0; i<edges.size(); i++){
            int edge = edges[i][0];
            int nei = edges[i][1];        
            int dist = edges[i][2];
            adj[edge].emplace_back(nei, dist);
            adj[nei].emplace_back(edge, dist);
        } 

        //now for every city find the neighbouring cities approach: BFS
        for(int i=0; i<n; i++){
            //create a vector to map distance of all cities from current city
            vector<int> dist(n, INT_MAX);
            dist[i]=0;   

            dist = bfs(adj, dist, i);

            int cityCount = 0;
            for(int j=0; j<n; j++){
                if(dist[j] <= distanceThreshold)
                    cityCount++;
            }
            //cout<<cityCount<<" "<<city<<endl;
            if(cityCount <= city){
                city = cityCount;
                ans = i;
            }
                
        }

        return ans;

    }
};
