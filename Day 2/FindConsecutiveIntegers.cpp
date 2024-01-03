class DataStream {
public:
    int value, k;
    int count = 0;
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if(num == value){
            count ++;
            if(count >= k) return true;
            else return false;
        }
        else{
            count = 0;
            return false;
        }
    }
};
