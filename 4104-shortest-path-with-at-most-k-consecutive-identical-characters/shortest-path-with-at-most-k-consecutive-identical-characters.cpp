#include <bits/stdc++.h>
using namespace std ;
class Solution
{
public:
    struct State {
        long long cost ;
        int node ;
        int streak ;

        bool operator>(const State &other) const {
            
            return cost > other.cost ;

        }
    };

    int shortestPath(int n, vector<vector<int>> &edges, string labels, int k)
    {

        vector<vector<pair<int, int>>> graph(n) ;

        for (auto &e : edges) {

            graph[e[0]].push_back({e[1], e[2]}) ;

        }

        const long long INF = 1e18 ;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF)) ;

        priority_queue<State, vector<State>, greater<State>> pq ;

        dist[0][1] = 0 ;
        pq.push({0, 0, 1}) ;

        while (!pq.empty()) {

            auto [cost, node, streak] = pq.top() ;

            pq.pop() ;

            if (cost != dist[node][streak]){
                
                continue ;
            }

            for (auto &[nextNode, weight] : graph[node]) {

                int nextStreak;

                if (labels[node] == labels[nextNode]) {

                    nextStreak = streak + 1 ;
                }
                else
                {
                    nextStreak = 1;
                }

                if (nextStreak > k) {

                    continue ;
                }

                long long newCost = cost + weight ;

                if (newCost < dist[nextNode][nextStreak]) {

                    dist[nextNode][nextStreak] = newCost ;

                    pq.push({newCost, nextNode, nextStreak}) ;

                }
            }
        }

        long long answer = INF ;

        for (int streak = 1; streak <= k; streak++) {

            answer = min(answer, dist[n - 1][streak]) ;
        }

        return answer == INF ? -1 : answer ;
    }
};