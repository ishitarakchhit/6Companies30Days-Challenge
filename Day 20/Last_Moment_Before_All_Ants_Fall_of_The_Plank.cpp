// Intuition
// The time taken by any ant moving straight will be equal to the time taken by the ants that collide. So find the maximum time taken of all the ants before falling

// Approach
// Complexity
// Time complexity: O(n)
// Space complexity: O(1)
// Code
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time = 0;
        
        for(int i=0; i<left.size(); i++){
            int ant_Time = left[i]-0;
            time= max(time, ant_Time);
        }
        for(int i=0; i<right.size(); i++){
            int ant_Time = n-right[i];
            time = max(time, ant_Time);
        }
        return time;
        
    }
};
