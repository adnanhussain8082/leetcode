class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> count(10,0);

        //generate the frequency map of the given array
        for(auto& it : digits) count[it]++;

        //now start from 100 to 999 and get the each even num in this range
        
        for(int num=100;num<999;num+=2){

            vector<int> currCount(10,0); //to store the digits of curr num

            //get the digits of curr num

            int temp = num;

            while(temp>0){
                int digit = temp%10;
                currCount[digit]++;
                temp/=10;
            }

            //check whether this can be formed or not
            //note that we already tackled the "starting with zero" and
            // odd cases bcz our range 100-999 even nums only

            bool flag = true;
            for(int i=0;i<10;i++){
                if(count[i] < currCount[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(num);
            }
        }
        return ans;
    }
};