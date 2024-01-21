class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //find the cost differences for each index
        int n = s.length();
        vector<int> cost(n);

        for(int i=0; i<n; i++){
            cost[i] = abs(s[i]-t[i]);
        }
        
        //the task has now converted to finding the maximum length subarray having maximum sum as maxCost

        //now calculate the prefix sum of these indices
        for(int i=1; i<n; i++){
            cost[i] = cost[i] + cost[i-1];
        }
        cout<<"here";
        //now use the sliding window approach to find the maximum length
        int maxLength = 0;
        int start = -1, end = -1;
        int sum= 0;

        while(end+1<n && start+1<n){
            end++;
            int newSum = cost[end];
            if(start!=-1)
            newSum -=cost[start];
            if(newSum<=maxCost){
                maxLength = max(maxLength, end-start);
                sum = newSum;
            }
            else{
                while(start<=end && newSum >maxCost){
                    start ++;
                    newSum = cost[end]-cost[start];
                }
                if(newSum <= maxCost){
                    maxLength = max(maxLength, end-start);
                    sum = newSum;
                }
            }
        }   

        return maxLength;     

    }
};
