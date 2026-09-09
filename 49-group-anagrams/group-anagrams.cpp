class Solution {
public:

    std::array<int,256> hash(string s){
        std::array<int,256> hash={0};
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> mpp;

        for(auto str : strs){
            string s = str;
            sort(s.begin(),s.end());
            mpp[s].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto i : mpp){
            ans.push_back(i.second);
        }
        return ans;


        //another method

        // map<std::array<int , 256> , vector<string>> mpp;

        // for(auto str : strs){
        //     mpp[hash(str)].push_back(str);
        // }

        // vector<vector<string>> ans;

        // for(auto i : mpp){
        //     ans.push_back(i.second);
        // }
        // return ans;



    }
};