class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        //key -> sorted string
        // value -> list of anagrams

        unordered_map<string,vector<string>> mp;

        for(string w : strs) {

            //make a copy
            string key = w;

            //sort the copy
            sort(key.begin(), key.end());

            //strore
            mp[key].push_back(w);


        }

        vector<vector<string>> ans;

        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
        
    }
};