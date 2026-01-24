class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        int odd=0;
        int even=INT_MAX;
        for (int i = 0; i < s.size(); i++) {

            mp[s[i]]++;
        }
        for (auto it : mp) {
            if (it.second % 2 == 0) {
                if(it.second<even){
                    even=it.second;
                }

            }

            else {
                if(it.second>odd){
                    odd=it.second;
                }
            }
        }
        return odd-even;
    }
};