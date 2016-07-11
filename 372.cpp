class Solution {
 public:
  int superPow(int a, vector<int>& b) {
    if (b.empty())
      return 1;
    
    int lastDigit = b.back();
    b.pop_back();
    
    return help(superPow(a, b), 10) * help(a, lastDigit) % base;
  }

 private:
  int help(int a, int k) {
    a %= base;

    int result = 1;
    for (int i = 0; i < k; ++i) {
      result = (result * a) % base;
    }

    return result;
  }
  
  const int base = 1337;
};
