// 超时
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());

        auto last = nums.end();
        for (auto a = nums.begin(); a < prev(last, 3); a++) {
            for (auto b = next(a); b < prev(last, 2); b++) {
                auto c = next(b);
                auto d = prev(last);
                while (c < d) {
                    if (*a + *b + *c + *d < target) {
                        c++;
                    } else if (*a + *b + *c + *d > target) {
                        d--;
                    } else {
                        result.push_back({*a, *b, *c, *d});
                        c++;
                        d--;
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};

// 超时，比上面的更慢
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());

        auto last = nums.end();
        for (auto a = nums.begin(); a < prev(last, 3); a = upper_bound(a, prev(last, 3), *a)) {
            for (auto b = next(a); b < prev(last, 2); b = upper_bound(b, prev(last, 2), *b)) {
                auto c = next(b);
                auto d = prev(last);
                while (c < d) {
                    if (*a + *b + *c + *d < target) {
                        c = upper_bound(c, d, *c);
                    } else if (*a + *b + *c + *d > target) {
                        d = prev(lower_bound(c, d, *d));
                    } else {
                        result.push_back({*a, *b, *c, *d});
                        c = upper_bound(c, d, *c);
                        d = prev(lower_bound(c, d, *d));
                    }
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());

        unordered_map<int, vector<pair<int, int> > > cache;
        for (size_t a = 0; a < nums.size(); a++) {
            for (size_t b = a + 1; b < nums.size(); b++) {
                cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
            }
        }

        for (size_t c = 0; c < nums.size(); c++) {
            for (size_t d = c + 1; d < nums.size(); d++) {
                const int key = target - nums[c] - nums[d];
                if (cache.find(key) == cache.end()) continue;

                const auto& vec = cache[key];
                for (size_t k = 0; k < vec.size(); k++) {
                    if (c <= vec[k].second) continue; // 有重叠

                    result.push_back( {nums[vec[k].first], nums[vec[k].second], nums[c], nums[d] });
                }
            }
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};

// 超时
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());

        unordered_map<int, vector<pair<int, int> > > cache;
        for (size_t a = 0; a < nums.size(); a++)
            for (size_t b = a + 1; b < nums.size(); b++)
                cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));

        for (auto i = cache.begin(); i != cache.end(); i++) {
            int key = target - i->first;
            if (cache.find(key) == cache.end()) continue;

            auto a = i->second.front().first;
            auto b = i->second.front().second;
            const auto& vec = cache[key];
            for (size_t k = 0; k < vec.size(); k++) {
                auto c = vec[k].first;
                auto d = vec[k].second;
                if (a != c && a != d && b != c && b != d) {
                    vector<int> tmp = {nums[a], nums[b], nums[c], nums[d]};
                    sort(tmp.begin(), tmp.end());
                    result.push_back(tmp);
                }
            }
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;        
    }
};
