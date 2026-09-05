class Solution {
private:
    long calculateTotalHours(vector<int>& piles, int& hourly , int& h){
        long totalHours=0;
        int n=piles.size();

        for(int i=0;i<n;i++){
            //explaination in notes
            //totalHours += ceil( double(piles[i])/double(hourly) ); this causes error as last test case not passed

            totalHours += (piles[i] + hourly - 1) / hourly; // Equivalent to ceil(pile / hourly)
            
            if (totalHours > h) { // Early exit if totalHours exceeds h
                return totalHours;
            }
        }
        return totalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = *max_element(piles.begin(),piles.end());
        int i=1;
        int j = maxElement;

        while(i<=j){
            int mid = i + (j-i)/2;
            int totalHours = calculateTotalHours(piles , mid , h);

            if(totalHours <= h){
                j=mid-1; // Try to find a smaller speed
            }
            else{
                i=mid+1; //increase speed
            }
        }
        return i;
    }
};