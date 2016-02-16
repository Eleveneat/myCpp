// 超时
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty())
            return -1;
        
        const size_t n = gas.size();
        
        for (int i = 0; i < n; i++) {
            int restGas = gas[i] - cost[i];
            if (restGas < 0) {
                continue;
            }
            for (int j = (i + 1) == n ? 0 : i + 1; j < n; j++) {
                if (j == i)
                    return 1;
                
                restGas += gas[j] - cost[j];

                if (restGas < 0)
                    break;

                if (j == n - 1)
                    j = 0;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty())
            return -1;
        
        int index = -1;
        int totalGas = 0;
        
        for (int i = 0, sum = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];
            
            if (sum < 0) {
                index = i;
                sum = 0;
            }
        }
        
        return totalGas < 0 ? -1 : index + 1;
    }
};
