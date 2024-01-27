class Solution {
public:
    int calcGroups(vector<int> &seats){
        vector<bool> isReserved(11, 0);

        //mark the seats which are reserved
        for(int i=0; i<seats.size(); i++)
            isReserved[seats[i]] = 1;
        
        //cases

        int groups = 0;

        for(int i=2; i<=9 && i+3<=9; i++){
            if(!isReserved[i] && !isReserved[i+1] && !isReserved[i+2] && !isReserved[i+3]){
                groups++;
                i+=2;
            }
            i++;
        }
        return groups;
        

    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 0;
        int lastRow = 0;

        map<int,vector<int>> reserved;

        for(int i=0; i<reservedSeats.size(); i++){
            reserved[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }

        for(auto it: reserved){
            if(it.first != lastRow+1) ans += (it.first-lastRow-1)*2;
            //calculate the groups for the current row
            ans += calcGroups(it.second);
            lastRow = it.first;
        }

        if(lastRow !=n) ans += (n-lastRow)*2;
        return ans;
    }
};
