class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string , vector<string>> gr;
        unordered_map<string , int> indegree;

        for(int i=0;i<recipes.size();i++){
            for(auto& ing : ingredients[i]){
                gr[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;
        //push the elemets of supplies into it as they will have the indegree zero
        for(auto& it : supplies){
            q.push(it);
        }

        unordered_set<string> made;

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            for(auto& next : gr[curr]){
                if(--indegree[next]==0){
                    made.insert(next);
                    q.push(next);
                }
            }
        }

        vector<string> ans;

        for(auto& it : recipes){
            if(made.count(it)){
                ans.push_back(it);
            }
        }

        return ans;
    }
};