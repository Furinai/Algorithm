class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (map.find(complement) != map.end())
            {
                int result[] = {map[complement], i};
                return vector<int>(result, result + 2);
            }
            map[nums[i]] = i;
        }
        return vector<int>{};
    }
};
