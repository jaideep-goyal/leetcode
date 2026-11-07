class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // {weight, index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> free;

        // {finish time, weight, index}
        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>> busy;

        int n = servers.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
            free.push({servers[i], i});

        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            // Release servers that finished their tasks
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish, weight, idx] = busy.top();
                busy.pop();
                free.push({weight, idx});
            }

            // If no server is free, wait for the earliest one
            if (free.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [finish, weight, idx] = busy.top();
                    busy.pop();
                    free.push({weight, idx});
                }
            }

            // Assign task to the best available server
            auto [weight, idx] = free.top();
            free.pop();

            ans.push_back(idx);

            // Mark server as busy
            busy.push({time + tasks[i], weight, idx});
        }

        return ans;
    }
};