class Solution
{
    public:
        int maxFreqSum(string s)
        {
            int freq[26], maxvowel = 0, maxconso = 0;
            for (char c: s)
            {
                int i = c - 'a';
                freq[i]++;
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                {
                    maxvowel = max(maxvowel, freq[i]);
                }
                else
                {
                    maxconso = max(maxconso, freq[i]);
                }
            }
            return maxvowel + maxconso;
        }
};