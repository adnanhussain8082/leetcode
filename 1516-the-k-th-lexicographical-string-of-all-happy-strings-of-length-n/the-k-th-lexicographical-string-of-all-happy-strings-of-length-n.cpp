class Solution {
public:
    //modifying the argument list to apply REC here only
    string getHappyString(int n, int& k , int p=0 , char lastChar='\0') {
        //base case
        if(p == n){
            --k;
            return "";
        }

        for(char ch='a';ch<='c';ch++){
            if(ch != lastChar){
                string result = getHappyString(n , k , p+1 , ch);

                if(k==0){
                    return ch + result;
                }
            }
        }
        return "";
    }
};