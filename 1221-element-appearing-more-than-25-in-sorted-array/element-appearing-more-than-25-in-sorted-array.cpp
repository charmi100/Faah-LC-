class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 1;
        int n = arr.size();
        if (count * 4 > n) {
            return arr[0];
        }
        for (int i = 1; i < n; i++){
        if(arr[i] == arr[i - 1]){
            count++;

            if(count * 4 > n){
            return arr[i];
        }
        }
        else{
            count = 1;
        }
        
        }
        return -1;
    
    }
};