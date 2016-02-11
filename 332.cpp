class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto ticket : tickets) {

        }

        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }

private:
    unordered_map<string, multiset<string>> targets;
    vector<string> route;

private:
    void visit(string airport) {

    }
};