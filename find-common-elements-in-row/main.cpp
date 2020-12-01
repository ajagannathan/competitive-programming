//Given an M x N matrix find all common elements present in every row
//
// For eg.
//  { 7, 1, 3, 5, 3, 6 },
//	{ 2, 3, 6, 1, 1, 6 },
//	{ 6, 1, 7, 2, 1, 4 },
//	{ 6, 6, 7, 1, 3, 3 },
//	{ 5, 5, 6, 1, 5, 4 },
//	{ 3, 5, 6, 2, 7, 1 },
//	{ 4, 1, 4, 3, 6, 4 },
//	{ 4, 6, 1, 7, 4, 3 },
//
// Output : 1 and 6

#include "header.h"

void solution_1(int mat[][N])
{
    std::unordered_map<int, Node> lookUp;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int val = mat[i][j];

            if (lookUp.find(val) == lookUp.end())
            {
                lookUp[val] = {0, i};
            }
            else
            {
                if (lookUp[val].second != i)
                {
                    lookUp[val].first += 1;
                    lookUp[val].second = i;
                    if (lookUp[val].first == (M - 1))
                        std::cout << val << " ";
                }
            }
        }
    }
}

void solution_2(int mat[][N])
{
    std::unordered_map<int, int> map;
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            int val = mat[i][j];
            if (i == 0)
                map[val] = 1;
            if (i > 0 && map[val] == i)
            {
                map[val] += 1;
                if (map[val] == M - 1)
                    std::cout << val << " ";
            }
        }
    }
}
int main()
{
    int mat[M][N] = {
        {7, 1, 3, 5, 3, 6},
        {2, 3, 6, 1, 1, 6},
        {6, 1, 7, 3, 1, 4},
        {6, 6, 7, 1, 3, 3},
        {5, 3, 6, 1, 5, 4},
        {3, 5, 6, 2, 7, 1},
        {4, 1, 4, 3, 6, 4},
        {4, 6, 1, 7, 4, 3},
    };

    {
        Timer t;
        solution_1(mat);
    }

    std::cout << "\nEnd";
}