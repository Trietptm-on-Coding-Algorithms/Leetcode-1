class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }

    bool tables[s1.length() + 1][s2.length() + 2];

    for (int r = 0; r < s1.length() + 1; ++r) {
      for (int c = 0; c < s2.length() + 1; ++c) {
        if (r == 0 && c == 0) {
          table[r][c] = true;
        } else if (r == 0) {
          table[r][c] = (table[r][c-1] && s2[c-1] == s3[r+c-1]);
        } else if (c == 0) {
          table[r][c] = (table[r-1][c] && s1[r-1] == s3[r+c-1];
        } else {
            table[r][c] = (table[r-1][c] && s1[r-1] == s3[r+c-1]) || (table[r][c-1] && s2[c-1] == s3[r+c-1])
        }
      }
    }

      return table[s1.length()][s2.length()];
  }
};
