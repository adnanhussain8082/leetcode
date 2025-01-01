class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int leftScore=0 , rightScore=0;
        //initial logic
        if((s[0]-'0')==0){
            leftScore=1;
        }

        for(int i=1;i<n;i++){
            if((s[i]-'0')==1){
                rightScore+=1;
            }
        }

        int maxi=leftScore+rightScore;
        int i=1;

        while(i<n-1){
            if((s[i]-'0')==0){
                leftScore+=1;
            }
            else if((s[i]-'0')==1){
                rightScore-=1;
            }

            maxi=max(maxi , leftScore+rightScore);

            i++;
        }
        return maxi;
    }
};