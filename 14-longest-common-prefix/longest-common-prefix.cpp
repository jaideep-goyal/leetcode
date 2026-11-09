class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        //["flower","flow","flight"]
        //flight , flow , flower
        // f = flight
        // l = flower
        // f == f ans = f
        // l == l ans = fl
        // i == 0 break
        //ans return fl 

        sort(strs.begin(), strs.end());

        string first = strs[0];
        int n = strs.size();
        string last = strs[n - 1];
        string ans = "";

        for(int i = 0; i < min(first.size(),last.size()); i++) {

            if(first[i] != last[i]) break;

            ans += first[i];
        }


        return ans;
        
    }
};