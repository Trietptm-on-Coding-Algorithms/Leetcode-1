class Solution {
 public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> result;

    if (nums1.empty() || nums2.empty() || k <= 0) {
      return result;
    }

    auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
      return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);
    minHeap.emplace(0, 0);

    while (k-- > 0 && !minHeap.empty()) {
      auto idxPair = minHeap.top();
      minHeap.pop();
      result.emplace_back(nums1[idxPair.first], nums2[idxPair.second]);

      if (idxPair.first + 1 < nums1.size()) {
        minHeap.emplace(idxPair.first + 1, idxPair.second);
      }
      
      if (idxPair.first == 0 && idxPair.second + 1 < nums2.size()) {
        minHeap.emplace(idxPair.first, idxPair.second + 1);
      }
    }

    return result;
  }
};
