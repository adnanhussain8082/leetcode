class Solution {
private:
    bool canMake(int num , int target){
        if(target<0|| num<target) return false;

        if(num == target) return true;

        return canMake(num/10 , target - num%10) || canMake(num/100 , target - num%100) || canMake(num/1000 , target - num%1000);
    }
public:
    int punishmentNumber(int n) {
        int ans=0;

        for(int i=1;i<=n;i++){
            int num = i*i;
            if(canMake(num , i)){
                ans += num;
            }
        }
        return ans;
    }
};