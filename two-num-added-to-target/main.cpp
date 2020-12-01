// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

//     You may assume that each input would have exactly one solution,
//     and you may not use the same element twice.

//         Example :

//     Given nums = [ 2, 7, 11, 15 ],
//           target = 9,

//           Because nums[0] + nums[1] = 2 + 7 = 9,
//           return [ 0, 1 ].

#include "header.h"

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    bool matchFound = false;
    int match = -1;
    std::vector<int> indices;
    for (size_t i = 0; i < nums.size(); i++)
    {
        match = target - nums[i];
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] == match)
            {
                matchFound = true;
                indices.push_back(i);
                indices.push_back(j);
                break;
            }
        }
        if (matchFound)
        {
            break;
        }
    }
    return indices;
}

std::vector<int> twoSum_optimized(std::vector<int> &nums, int target)
{
    std::map<int, int> lookup;
    std::vector<int> indices;
    size_t input_size = nums.size();
    for (size_t i = 0; i < input_size; i++)
    {
        if (lookup.find(target - nums[i]) != lookup.end())
        {
            indices.push_back(i);
            indices.push_back(lookup[target - nums[i]]);
            return indices;
        }
        else
        {
            lookup[nums[i]] = i;
        }
    }
    return indices;
}

int main()
{
    std::cout << "***** Two sum problem ******\n";
    std::vector<int> input{2, 7, 15, 11, 17, 3};
    std::vector<int> indices;
    {
        Timer t;
        indices = twoSum_optimized(input, 20);
    }
    //std::vector<int> indices = twoSum(input, 26);
    // for (size_t i = 0; i < indices.size(); i++)
    // {
    //     std::cout << input[indices[i]] << " ";
    // }
    for (int k : indices)
    {
        std::cout << k << " ";
    }
}