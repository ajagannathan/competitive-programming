#include <iostream>
#include <numeric>

// Function to check if all subsets are filled or not
bool checkSum(int sumLeft[], int k)
{
    int r = true;
    for (int i = 0; i < k; i++)
    {
        if (sumLeft[i] != 0)
            r = false;
    }

    return r;
}

// Helper function for solving k partition problem
// It return true if there exists k subsets with given sum
bool subsetSum(int S[], int n, int sumLeft[], int A[], int k)
{
    // return true if subset is found
    if (checkSum(sumLeft, k))
        return true;

    // base case: no items left
    if (n < 0)
        return false;

    bool res = false;

    // consider current item S[n] and explore all possibilities
    // using backtracking
    for (int i = 0; i < k; i++)
    {
        if (!res && (sumLeft[i] - S[n]) >= 0)
        {
            // mark current element subset
            A[n] = i + 1;

            // add current item to i'th subset
            sumLeft[i] = sumLeft[i] - S[n];

            // recur for remaining items
            res = subsetSum(S, n - 1, sumLeft, A, k);

            // backtrack - remove current item from i'th subset
            sumLeft[i] = sumLeft[i] + S[n];
        }
    }

    // return true if we get solution
    return res;
}

// Function for solving k-partition problem. It prints the subsets if
// set S[0..n-1] can be divided into k subsets with equal sum
void partition(int S[], int n, int k)
{
    // base case
    if (n < k)
    {
        std::cout << "k-Partition of set S is not Possible";
        return;
    }

    // get sum of all elements in the set
    int sum = std::accumulate(S, S + n, 0);

    int A[n], sumLeft[k];

    // create an array of size k for each subset and initialize it
    // by their expected sum i.e. sum/k
    for (int i = 0; i < k; i++)
        sumLeft[i] = sum / k;

    // return true if sum is divisible by k and the set S can
    // be divided into k subsets with equal sum
    bool res = !(sum % k) && subsetSum(S, n - 1, sumLeft, A, k);

    if (!res)
    {
        std::cout << "k-Partition of set S is not Possible";
        return;
    }

    // print all k-partitions
    for (int i = 0; i < k; i++)
    {
        std::cout << "Partition " << i << " is: ";
        for (int j = 0; j < n; j++)
            if (A[j] == i + 1)
                std::cout << S[j] << " ";
        std::cout << std::endl;
    }
}

// main function for k-partition problem
int main()
{
    // Input: set of integers
    int S[] = {7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4};

    // number of items in S
    int n = sizeof(S) / sizeof(S[0]);
    int k = 5;

    partition(S, n, k);

    return 0;
}

// #include <iostream>
// #include <unordered_map>

// typedef std::unordered_map<int, int>::iterator IntMapIntItr;

// // void MakePartition(std::unordered_map<int, int> &arr_map, int sum)
// // {
// //     while (sum > 0)
// //     {
// //         if (arr_map.find(sum) == arr_map.end())
// //         {
// //             std::unordered_map<int, int>::iterator it;
// //             for (it = arr_map.begin(); it != arr_map.end(); it++)
// //             {
// //                 if (it->first > sum)
// //                     continue;
// //                 if (it->second == 0)
// //                 {
// //                     arr_map.erase(it->first);
// //                     continue;
// //                 }
// //                 else
// //                 {
// //                     std::cout << it->first << " ";
// //                     sum -= it->first;
// //                     it->second -= 1;
// //                     break;
// //                 }
// //             }
// //         }
// //         else if (arr_map[sum] != 0)
// //         {
// //             std::cout << sum << " ";
// //             arr_map[sum] -= 1;
// //             sum -= sum;
// //         }
// //         else
// //         {
// //             arr_map.erase(sum);
// //         }
// //     }
// // }

// void MakePartition(std::unordered_map<int, int> &arr_map, int sum)
// {
//     int r_sum = 0;
//     while (r_sum < sum)
//     {
//         int diff = sum - r_sum;
//         if (arr_map.find(diff) != arr_map.end() && arr_map.find(diff)->second > 0)
//         {

//             r_sum += diff;
//             std::cout << diff;
//             arr_map[diff] -= 1;
//             if (arr_map[diff] == 0)
//                 arr_map.erase(diff);
//         }
//         else
//         {
//             IntMapIntItr it = arr_map.begin();
//             while (it != arr_map.end())
//             {
//                 if (it->second > 0 && (r_sum + it->first) <= sum)
//                 {
//                     r_sum += it->first;
//                     it->second--;
//                     std::cout << it->first;
//                     if (it->second == 0)
//                         arr_map.erase(it->first);
//                     break;
//                 }
//                 else
//                 {
//                     it++;
//                     continue;
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     int arr[12] = {7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4};
//     int arr_size = sizeof(arr) / sizeof(arr[0]);
//     int partitions = 5;
//     int arr_sum = 0;
//     std::unordered_map<int, int> arr_map;
//     int max_element = INT32_MIN;

//     for (size_t i = 0; i < arr_size; i++)
//     {
//         arr_sum += arr[i];
//         arr_map[arr[i]] += 1;
//         if (arr[i] > max_element)
//             max_element = arr[i];
//     }

//     if (arr_sum % partitions > 0 || arr_sum / partitions < max_element)
//         std::cout << "Equal sum partitions could not be made\n";

//     else
//     {
//         for (size_t i = 0; i < partitions; i++)
//         {
//             std::cout << "**** Set " << i + 1 << " ****\n";
//             MakePartition(arr_map, arr_sum / partitions);
//         }
//     }
// }