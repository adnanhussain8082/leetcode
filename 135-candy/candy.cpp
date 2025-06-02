class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=size(ratings);
        vector<int> candies(n , 1);

        if(n==1) return 1;

        //iterate from left to right starting from i=1
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1] && candies[i]<=candies[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }

        //iterate from right to left starting from i=n-2
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]){
                candies[i]=candies[i+1]+1;
            }
        }

        //iterate over the candies vector to get the total no of candies
        int totalcandies=0;
        for(auto i : candies){
            totalcandies+=i;
        }

        return totalcandies;
    }
};