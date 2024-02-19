/*
Complexity
Time complexity: O(2^n *n)
Space complexity: O(n)
Code
  */

class Solution {
public:
    int modulo = 1e9 + 7;
    bool check(int it){
        for(int i=2; i<=30; i++){
            if(it%(i*i) == 0) return 0;
        }
        return 1;
    }
    int check(vector<int> &temp, unordered_map<int,int> &mp){
        if(temp.size()==0) return 0;
        long long product = 1;
        for(auto it: temp) product*= it;

        for(int i=2; i<=30; i++){
            if(product%(i*i) == 0) return 0;
        }
        
        long long ans = 1;
        for(auto it: temp){
            ans *= mp[it];
            ans= ans%modulo;
        }
        return ans;
    }

    long long helper(vector<int> &nums, vector<int> &temp, int i, unordered_map<int,int> &mp){
        if(i==nums.size()){
            long long ans = check(temp, mp);
            return ans;
        }

        if(temp.size()!=0 && check(temp, mp) == 0) return 0;

        //include the current number 
        temp.push_back(nums[i]);
        long long a = helper(nums, temp, i+1, mp)%modulo;
        temp.pop_back();

        //not pick
        long long b = helper(nums, temp, i+1, mp)%modulo;
        return (a+b)%modulo;
    }

    long long power(int a, int b){
        if(b ==0) return 1;
        long long p = power(a, b/2)%modulo;
        if(b%2 == 0) return (p*p)%modulo;
        else return (((p*p)%modulo)*a)%modulo;
    }

    int squareFreeSubsets(vector<int>& nums) {
        //first remove all square integers from the array
        unordered_map<int,int> mp;
        int count1 = 0;
        for(auto it: nums){
            if(check(it))
                mp[it]++;
        }
        vector<int> arr;
        for(auto it: mp){
            if(it.first!=1 && check(it.first))
                arr.push_back(it.first);
        }

        count1 = mp[1];
        vector<int> temp;
        long long ans = helper(arr, temp, 0, mp);

        //now handle all the one's since they will not impact the product, if present in any number of frequency
        long long subsets = ((long long)power(2,count1)-1)%modulo;
        ans = ((ans+ ans*subsets)%modulo + subsets)%modulo;
        return ans%modulo;
    }
};
