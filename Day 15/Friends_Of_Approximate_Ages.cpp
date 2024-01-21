// Intuition
// the ages are repeating which will create redundant visits so to eliminate this we will use unordered map.

// Approach
// we use unordered_map to map all frequencies and then run two loops to check for given conditions and calculate the requests

// Complexity
// Time complexity: O(n) to travel the array and O(120*120) for traversing the map two times
// Space complexity: O(120) to create the map and store the ages and their frequencies
// Code

class Solution {
public:
    bool check(int &x, int &y){
        //if(x == y) return false;
        if(y <= x/2 + 7) return false;
        if(y> x) return false;
        if(y > 100 && x<100) return false;
        return true;
    }

    int numFriendRequests(vector<int>& ages) {
        int request = 0;
        unordered_map<int,int> mp;  //age, frequency

        for(int i=0; i<ages.size(); i++){
            mp[ages[i]]++;
        }

        for(auto i=mp.begin(); i!=mp.end(); i++){
            for(auto j=mp.begin(); j!=mp.end(); j++){
                int x = i->first;
                int y = j->first;
                if(check(x, y)){
                    if(x==y){
                        request = request + (i->second)*(j->second-1);
                    }
                    else{
                    request = request + i->second*j->second;
                    }
                }
                
            }
        }
        return request;
    }
};


