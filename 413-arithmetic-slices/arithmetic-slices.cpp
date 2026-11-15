class Solution {
public:
    bool is_a(vector<int>& window) {
        if(window.size() < 3) return false;
        int d = window[1] - window[0];
        for(int i = 2; i < window.size(); i++) {
            int newd = window[i] - window[i -1];
            if(newd != d) return false;
        }
        return true;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {

        int diff = 0;
        int l = 0;
        int ans = 0;
        vector<int> window;
        for(int r = 0; r < nums.size(); r++) {

            // while(window.size() < 3){
            //     window.push_back(nums[r]);
            // }
            // while(!is_a(window)) window.erase(window.begin());

            // if(r - l + 1 >= 3) ans++;
            window.push_back(nums[r]);

            while (window.size() >= 3 && !is_a(window)) {
                window.erase(window.begin());
                l++;
            }

            if (window.size() >= 3) {
                ans += window.size() - 2;
            }      
            
        }

        return ans;
        
    }
};