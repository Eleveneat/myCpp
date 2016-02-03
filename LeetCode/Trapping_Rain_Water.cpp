class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int *max_left = new int[n]();
        int *max_right = new int [n]();
        
        for (int i = 1; i < n; i++) {
            max_left[i] = max(max_left[i - 1], height[i - 1]);
            max_right[n - 1 - i] = max(max_right[n - i], height[n - i]);
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int h = min(max_left[i], max_right[i]);
            if (h > height[i])
                sum += h - height[i];
        }
        
        delete [] max_left;
        delete [] max_right;
        return sum;
    }
}

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] > height[maxIndex])
                maxIndex = i;
        }
        
        int sum = 0;
        int peak = 0;
        for (int i = 0; i < maxIndex; i++) {
            if (height[i] > peak)
                peak = height[i];
            else
                sum += peak - height[i];
        }
        peak = 0;
        for (int i = n - 1; i > maxIndex; i--) {
            if (height[i] > peak)
                peak = height[i];
            else
                sum += peak - height[i];
        }
        
        return sum;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        stack<pair<int, int> > s;
        int water = 0;
        
        for (int i = 0; i < n; i++) {
            int h = 0;
            
            while (!s.empty()) {
                int bar = s.top().first;
                int pos = s.top().second;
                water += (min(bar, height[i]) - h) * (i - pos - 1);
                h = bar;
                
                if (height[i] < bar)
                    break;
                else
                    s.pop();
            }
            
            s.push(make_pair(height[i], i));
        }
        
        return water;
    }
};
