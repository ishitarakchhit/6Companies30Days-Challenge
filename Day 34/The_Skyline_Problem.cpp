/*
Complexity
Time complexity: O(nlogn)
Space complexity: O(n + n)
Code
*/
class Solution {
public:
    void erase(multiset<int> &m, int num){
        multiset<int>::iterator it = m.find(num);
        m.erase(it); 
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //seperate all buildings in start point, heihgt and end point, height
        //mark all start points with negative sign
        int n= buildings.size();
        vector<vector<int>> points;

        //push all individual building points with marked starting and ending point using negative sign
        for(int i=0; i<n; i++){
            vector<int> point;
            point.push_back(buildings[i][0]);
            point.push_back((-1)*buildings[i][2]);
            points.push_back(point);
            point[0] = buildings[i][1];
            point[1] = buildings[i][2];
            points.push_back(point);
        }
        sort(points.begin(), points.end());
        
        vector<vector<int>> ans;
        multiset<int> m;       //map heap to take charge of maximum height out of active buildings
        m.insert(0);

        for(int i=0; i<points.size(); i++){
            if(points[i][1]<0){   //indicates that we need to add a new height since we are starting a new building
                multiset<int>::iterator it = m.end(); it--;
                if(abs(points[i][1])> *it){
                    vector<int> temp = {points[i][0], abs(points[i][1])};
                    ans.push_back(temp);
                }
                m.insert(abs(points[i][1]));
            }
            else{        //indicates that we are removing a height/building, so remove it from pq and push the current index and max height from heap to the ans array if index's height was higher than current max height
                erase(m, points[i][1]);
                multiset<int>::iterator it = m.end(); it--;
                
                if(points[i][1] > *it){
                    vector<int> temp = {points[i][0], *it};
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};
