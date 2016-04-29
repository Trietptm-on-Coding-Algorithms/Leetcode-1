class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int start = 0, end = s.size() - 1;
        
        while(start < end) {
            while (vowels.find(s[start]) == string::npos) {
                ++start;
            }
            
            while (vowels.find(s[end]) == string::npos) {
                --end;
            }
            
            if (start < end) {
                swap(s[start++], s[end--]);
            }        
        }
        
        return s;
    }
};