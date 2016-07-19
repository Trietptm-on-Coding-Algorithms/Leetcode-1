



class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto ticket : tickets) {
            targets[ticket.first].insert(ticket.second);
        }

        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }

private:
    unordered_map<string, multiset<string>> targets;
    vector<string> route;

private:
    void visit(string airport) {
        while (!targets[airport].empty()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }

        route.push_back(airport);
    }
};