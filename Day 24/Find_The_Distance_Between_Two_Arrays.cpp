/*
Intuition
we have to count the number of distance values

Approach
Intuitively run two loops to count such distance values

Complexity
Time complexity: O(n^2)
Space complexity: O(1)
Code
*/
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for(int i=0; i<arr1.size(); i++){
            bool flag = true;
            for(int j=0; j<arr2.size(); j++){
                if(abs(arr1[i]-arr2[j]) <= d){
                    flag = false;
                    break;
                }
            }
            if(flag == true) count++;
        }
        return count;
    }
};
