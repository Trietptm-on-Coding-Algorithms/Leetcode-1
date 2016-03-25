class Solution {
    bool isPal(string& s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        
        if (words.empty()) {
            return result;
        }

        unordered_map<string, int> table;
        for(int i = 0; i < words.size(); i++) {
            table[words[i]]=i;
        }
        
        vector<int> r(2);
        for(int i = 0; i < words.size(); i++) {
            string cur = words[i];
            string prefix = cur;
            string suffix = cur ;
            int K = words[i].size();
            
            for(int l = 0; l <= K; l++) {
                
                if(isPal(prefix, 0, l-1)) {
                    string tmp = cur.substr(l);
                    
                    if(!tmp.empty()) {
                        reverse(tmp.begin(), tmp.end());
                    }
                    
                    if(table.find(tmp) != table.end()) {
                        r[0] = table[tmp];
                        r[1] = i;
                        
                        if(r[0] != r[1] && 
                            cur.size() >= words[r[0]].size()) {
                                    result.push_back(r);
                            }
                     }
                }
                
                if(isPal(suffix, l, K-1)) {
                    string tmp = cur.substr(0,l); 
                    reverse(tmp.begin(), tmp.end()); 
                    
                    if(table.find(tmp) != table.end()) {
                        r[1] = table[tmp];
                        r[0] = i;
                        if(r[0] != r[1] && cur.size() > words[r[1]].size()) { 
                            result.push_back(r);
                        }
                    }
                }
            }
        }
        
        return result;
    }
};