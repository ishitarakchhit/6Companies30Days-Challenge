class Solution {
public:
    string itos(int x){
        if ( x== 0) return "0";
        string temp  =  "";
        int num = x;
        while(x){
            char rem = x%10 + '0';
            x/=10;
            temp.push_back(rem);
        }
        
        reverse(temp.begin(), temp.end());
        return temp;
    }

    string getHint(string secret, string guess) {
        int x = 0;
        int y = 0;

        unordered_map<int, int> mp;      //scret string num mapped to its frequency

        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]){
                x ++;
                secret[i] = guess[i] = '#';
            }
            else{
                if(mp.find(secret[i]) != mp.end()){
                    mp[secret[i]] ++;
                }
                else{
                    mp[secret[i]] = 1;
                }
            }
        }


        //now count the numbers which are present in guess
        for(int i=0; i<secret.size(); i++){
            if(guess[i]!= '#'){
                if(mp[guess[i]] >=1){
                    y++;
                    mp[guess[i]]--;
                }
            }
        }

        string ans = "";
        ans.append(itos(x));
        ans +='A';
        ans.append(itos(y));
        ans +='B';
        return ans;
    }
};
