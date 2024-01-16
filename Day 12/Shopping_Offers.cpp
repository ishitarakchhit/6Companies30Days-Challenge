class Solution {
public:

    int helper(int n, vector<int> &price, vector<vector<int>>& special, vector<int> &needs){
        if( n == special.size()){
            //now include the remmaining boxes
            int total = 0;
            for(int i=0; i<price.size(); i++)   
                total += needs[i] * price[i];
            return total;
        }

        //now include the current special price
        int size = needs.size();
        
        //check if current special can be included or not
        vector<int> needs2 = needs;
        bool flag = true;
        for(int i=0; i<size; i++){
            if(needs2[i] < special[n][i]){
                flag = false;
                break;
            }
        }

        //if current special price can be included
        if(flag == true)
        for(int i=0; i<size; i++){
            needs2[i]-= special[n][i];
        }

        int totalCostLeft = 1e9;
        int totalCostLeft2 = 1e9;
        if(flag == true){
            
            totalCostLeft2 = special[n][size] + helper(n, price, special, needs2);
        }

        
        //excluding the current special price
        //backtrack
        needs2 = needs;
        int totalCostRight = helper(n+1, price, special, needs2);
        
         return min(min(totalCostLeft, totalCostLeft2), totalCostRight);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
         map<vector<int>, int> mp;           //vector, cost

        int n = price.size();
        //to remove the duplicate offers and keep the one with minimum price
        for(int i=0; i<special.size(); i++){
            auto temp = special[i];
            temp.pop_back();
            
            if(mp.find(temp) != mp.end()){
                mp[temp] = min(mp[temp], special[i][n]);
            }
            else{
                mp[temp] = special[i][n];
            }
        }

        //now insert these elements into the special matrix
        special.clear();

        for(auto it: mp){
            auto temp = it.first;
            temp.push_back(it.second);
            special.push_back(temp);
        }


        return helper(0, price, special, needs);
    }
};
