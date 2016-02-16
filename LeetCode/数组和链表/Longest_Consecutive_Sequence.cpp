class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> maps;
        for (auto a : nums)
            maps[a] = false;
            
        int maxLen = 0;
        for (auto a : nums) {
            if (maps[a]) continue;
            
            maps[a] = true;
            int l = 1;
            
            for (int j = a + 1; maps.find(j) != maps.end(); j++) {
                maps[j] = true;
                l++;
            }
            
            for (int j = a - 1; maps.find(j) != maps.end(); j--) {
                maps[j] = true;
                l++;
            }
            
            maxLen = max(maxLen, l);
        }
        
        return maxLen;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int size = nums.size();
        int l = 1;
        for (int i = 0; i < size; i++) {
            if (map.find(nums[i]) != map.end()) continue;
            
            map[nums[i]] = 1;
            if (map.find(nums[i] - 1) != map.end()) {
                l = max(l, mergeCluster(map, nums[i] - 1, nums[i]));
            }
            if (map.find(nums[i] + 1) != map.end()) {
                l = max(l, mergeCluster(map, nums[i], nums[i] + 1));
            }
        }
        return size == 0 ? 0 : l;
    }
    
private:
    int mergeCluster(unordered_map<int, int>& map, int left, int right) {
        int upper = right + map[right] - 1;
        int lower = left - map[left] + 1;
        int length = upper - lower + 1;
        map[upper] = length;
        map[lower] = length;
        return length;
    }
};

// Longest Consecutive Sequence
class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    int r = 0;
    unordered_set<int> s;
    for (auto i: num)
      s.insert(i);
    for (auto i: num) {
      int j = i, k = i+1;
      while (s.count(j-1)) s.erase(j--);
      while (s.count(k)) s.erase(k++);
      r = max(r, k-j);
    }
    return r;
  }
};
