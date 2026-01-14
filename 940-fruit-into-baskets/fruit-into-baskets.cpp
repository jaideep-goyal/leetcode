class Solution
{
    public:
        int totalFruit(vector<int> &fruits)
        {
            unordered_map<int, int> count;
            int l = 0, total = 0, res = 0;

            for (int r = 0; r < fruits.size(); r++)
            {
                count[fruits[r]]++;
                total++;

                while (count.size() > 2)
                {
                    int f = fruits[l];
                    count[f]--;
                    total--;
                    if (count[f] == 0)
                    {
                        count.erase(f);
                    }
                    l++;
                }
                res = max(res, total);
            }
            return res;
        }
};