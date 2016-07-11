class Twitter {
 private:
  struct Tweet {
    int time;
    int id;
    Tweet(int time, int id): time(time), id(id) {
      
    }
  };

  int time;
  unordered_map<int, vector<Tweet>> tweets;
  unordered_map<int, unordered_set<int>> following;
  
 public:
  Twitter():time(0) {
    
  }

  void postTweet(int userId, int tweetId) {
    tweets[userId].emplace_back(time++, tweetId);
  }

  vector<int> getNewsFeed(int userId) {
    vector<pair<Tweet*, Tweet*>> h;

    for (auto& u : following[userId]) {
      auto& t = tweets[u];
      if (!t.empty()) {
        h.emplace_back(t.data(), t.data() + t.size() - 1);
      }
    }

    auto& t = tweets[userId];
    if (!t.empty()) {
      h.emplace_back(t.data(), t.data() + t.size() - 1);
    }

    auto f = [](const pair<Tweet*, Tweet*>& x, const pair<Tweet*, Tweet*>& y) {
      return x.second->time < y.second->time;
    };

    make_heap(h.begin(), h.end(), f);

    const int n = 10;
    vector<int> result;

    for (int i = 0; i < n && !h.empty(); ++i) {
      pop_heap(h.begin(), h.end(), f);
      auto& top = h.back();
      result.push_back(top.second->id);

      if (top.first == top.second--) {
        h.pop_back();
      } else {
        push_heap(h.begin(), h.end(), f);
      }
    }

    return result;
  }

  void follow(int followerId, int followeeId) {
    if (followerId != followeeId) {
      following[followerId].insert(followeeId);
    }
  }

  void unfollow(int followerId, int followeeId) {
    following[followerId].erase(followeeId);
  } 
};
