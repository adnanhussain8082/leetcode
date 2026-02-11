class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        //boyer moore's voting algo
        
        //Boyer–Moore generalization: For elements occurring more than ⌊n/k⌋ times, 
        //there can be at most (k−1) such elements, so we keep (k−1) candidates 
        //and cancel counts like voting, then verify in a second pass.

        //very very important observation is note

        int n = v.size();
        int count1 = 0, count2 = 0;
        // int ele1 , ele2;//this line is causing problem

        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (count1 == 0 && v[i] != ele2) {
                count1 = 1;
                ele1 = v[i];
            } else if (count2 == 0 && v[i] != ele1) {
                count2 = 1;
                ele2 = v[i];
            } else if (v[i] == ele1)
                count1++;
            else if (v[i] == ele2)
                count2++;

            else {
                count1--, count2--;
            }
        }
        vector<int> nums;
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (ele1 == v[i])
                cnt1++;
            if (ele2 == v[i])
                cnt2++;
        }

        int mini = (int)(n / 3) + 1; // bcoz more than ⌊ n/3 ⌋ times.

        if (cnt1 >= mini)
            nums.push_back(ele1);
        if (cnt2 >= mini)
            nums.push_back(ele2);

        // sort(nums.begin(), nums.end());

        return nums;
    }
};