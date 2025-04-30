class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;

        for(auto& it : nums){

            //1st method---simpe to_string() function 
            // int numLen = to_string(it).length();
            // if((numLen & 1) == 0) count++;

            //2nd method---use logical reasoning
            // if((it>9 && it<100) || (it>999 && it<10000) || it==100000){
            //     count++;
            // } 

            //3rd method---use logbase10 to get ActualDigits-1 then add +1
            int digits = (int)log10(it)+1;
            if((digits&1)==0) count++;

        }

        return count;
    }
};