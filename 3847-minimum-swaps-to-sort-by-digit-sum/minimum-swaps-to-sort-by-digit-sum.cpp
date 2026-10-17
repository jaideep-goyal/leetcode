class Solution {
public:
    // Sum of digits
    int sum(int n) 
    {
        int s = 0 ;

        while (n > 0) 
        {
            s += n % 10 ;
            n /= 10 ;
        }

        return s ;
    }

    int minSwaps(vector<int>& nums1) {
        vector<int> nums2 = nums1 ;

        // Sort by digit sum, then by value
        sort(nums2.begin(), nums2.end(), [this](int a, int b) 
        {
            if (sum(a) == sum(b)) 
            {
                return a < b ;
            }

            return sum(a) < sum(b) ;
        }) ;

        // Store the target index of each element
        unordered_map<int, int> mp ;

        for (int i = 0 ; i < nums2.size() ; i++) 
        {
            mp[nums2[i]] = i ;
        }

        int ans = 0 ;

        // Put each element at its correct position
        for (int i = 0 ; i < nums1.size() ; i++) 
        {
            while (nums1[i] != nums2[i]) 
            {
                int j = mp[nums1[i]] ;
                swap(nums1[i], nums1[j]) ;
                ans++ ;
            }
        }

        return ans ;
    }
} ;