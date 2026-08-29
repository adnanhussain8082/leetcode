class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int start=0 , maxLen=0;

        unordered_map<int,int> mpp; //at most stores 3 elements so almost const

        for(int end=0;end<n;end++){
            mpp[fruits[end]]++;

            while(mpp.size() > 2){
                mpp[fruits[start]]--;
                if(mpp[fruits[start]]==0){
                    mpp.erase(fruits[start]);
                }
                start++;
            }

            maxLen=max(maxLen,end-start+1);
        }

        return maxLen;
    }
};