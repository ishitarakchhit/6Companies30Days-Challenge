class Solution {
public:
    int calc_Cost(int x1, int y1, int x2, int y2){
        return abs(x1-x2) + abs(y1-y2);
    }

    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int startx = start[0], 
            starty = start[1], 
            targetx = target[0], 
            targety = target[1];

        map<pair<int,int>,int> mp;
        //{index}=>cost

        priority_queue<pair<int,pair<int,int>>> pq; 
        //cost, {index}
        
        //map all end indices of paths with INT_MAX
        for(int i=0; i<specialRoads.size(); i++){
            int tx = specialRoads[i][2],
                ty = specialRoads[i][3];
            mp[{tx, ty}] = INT_MAX;
        }
        mp[{targetx, targety}] = INT_MAX;


        mp[{startx, starty}] = 0;         //starting index mapping
        pq.push({0, {startx, starty}});   //pushing the first element into the pq


        int ans = INT_MAX;
        while(!pq.empty()){
            int cost = pq.top().first;
            auto index = pq.top().second;
            pq.pop();

            if(index.first == targetx && index.second==targety){
                ans = cost;
                continue;
            }

            //pushing cost to reach target from current index
            int newCost = cost +calc_Cost(index.first, index.second, targetx, targety);
            if(newCost < mp[{targetx, targety}]){
                mp[{targetx, targety}] = newCost;
                pq.push({newCost, {targetx, targety}});
            }

            //now push all the special roads to the pq from current index
            for(int i=0; i<specialRoads.size(); i++){
                int sx = specialRoads[i][0],
                    sy = specialRoads[i][1],
                    tx = specialRoads[i][2],
                    ty = specialRoads[i][3],
                    subCost = specialRoads[i][4];
                
                if(tx == index.first && ty == index.second) continue;  
                //this will cause end to start to end

                else{
                    newCost = cost + 
                              calc_Cost(index.first, index.second, sx, sy) +
                              subCost;

                    int convCost = cost + calc_Cost(index.first, index.second, tx, ty);
                    int finalCost = min(newCost, convCost);
                    if(mp[{tx, ty}] > finalCost){
                        mp[{tx, ty}] = finalCost;
                        pq.push({finalCost, {tx, ty}});
                    }
                }
            }
        }
        return ans;
    }
};
