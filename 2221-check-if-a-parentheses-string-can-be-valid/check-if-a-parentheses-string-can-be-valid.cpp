class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n&1==1) return false; //odd length

        int balance=0 , flipped=0;

        //left to right
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                flipped++;
            }
            else if(s[i]=='('){
                balance++;
            }
            else{
                balance--;
            }

            if(balance+flipped < 0) return false;
        }
        if(balance > flipped) return false;

        //re-initialise
        balance=0 , flipped=0;

        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0'){
                flipped++;
            }
            else if(s[i]==')'){
                balance++;
            }
            else{
                balance--;
            }

            if(balance+flipped < 0) return false;
        }
        if(balance > flipped) return false;

        return true;
    }
};