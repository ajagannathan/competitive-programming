// Find player path from source to destination of a matrix that satisfies a given contraints
// Given an N x N matrix of positive integers find path from first cell to the last cell of the matrix
// Constraints :
// The player can move exactly K steps where K is the value of that cell of the matrix.
// We can move from cell M[i][j] --> M[i + M[i][j]][j] or M[i - M[i][j]][j]
//                                   M[i][j + M[i][j]] or M[i][j - M[i][j]]
//
// For eg.
//  { 7, 1, 3, 5, 3, 6, 1, 1, 7, 5 },
//	{ 2, 3, 6, 1, 1, 6, 6, 6, 1, 2 },
//	{ 6, 1, 7, 2, 1, 4, 7, 6, 6, 2 },
//	{ 6, 6, 7, 1, 3, 3, 5, 1, 3, 4 },
//	{ 5, 5, 6, 1, 5, 4, 6, 1, 7, 4 },
//	{ 3, 5, 5, 2, 7, 5, 3, 4, 3, 6 },
//	{ 4, 1, 4, 3, 6, 4, 5, 3, 2, 6 },
//	{ 4, 4, 1, 7, 4, 3, 3, 1, 4, 2 },
//	{ 4, 4, 5, 1, 5, 2, 3, 5, 3, 5 },
//	{ 3, 6, 3, 5, 2, 2, 6, 4, 2, 1 }
//
// Output :(7,0) (3,0) (9,0) (6,0) (2,0) (8,0) (4,0) (4,5) (8,5)
//         (6,5) (2,5) (2,9) (4,9) (8,9) (3,9) (7,9) (9,9)

#include <iostream>
#include <vector>
struct Point
{
    int x, y;
    Point() : x(0), y(0) {}
    Point(int m, int n) : x(m), y(n) {}
    ~Point() {}
};
bool HasElement(std::vector<Point> &list, Point point)
{
    if (list.size() > 0)
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].x == point.x && list[i].y == point.y)
            {
                return true;
            }
        }
        return false;
    }
    else
        return false;
}
int main()
{
    const int N = 10;
    int Mat[N][N] = {
        {7, 1, 3, 5, 3, 6, 1, 1, 7, 5},
        {2, 3, 6, 1, 1, 6, 6, 6, 1, 2},
        {6, 1, 7, 2, 1, 4, 7, 6, 6, 2},
        {6, 6, 7, 1, 3, 3, 5, 1, 3, 4},
        {5, 5, 6, 1, 5, 4, 6, 1, 7, 4},
        {3, 5, 5, 2, 7, 5, 3, 4, 3, 6},
        {4, 1, 4, 3, 6, 4, 5, 3, 2, 6},
        {4, 4, 1, 7, 4, 3, 3, 1, 4, 2},
        {4, 4, 5, 1, 5, 2, 3, 5, 3, 5},
        {3, 6, 3, 5, 2, 2, 6, 4, 2, 1}};
    std::vector<Point> visited;
    int i, j, k;
    i = j = k = 0;

    while (i < (N - 1) || j < (N - 1))
    {
        k = Mat[i][j];
        if (k <= (N - 1))
        {
            if (i + k < N && HasElement(visited, Point(i + k, j)) == false)
            {
                i += k;
                visited.push_back(Point(i, j));
                std::cout << "(" << i << "," << j << ") ";
                continue;
            }
            else if (i - k < N && i - k > 0 && HasElement(visited, Point(i - k, j)) == false)
            {
                i -= k;
                visited.push_back(Point(i, j));
                std::cout << "(" << i << "," << j << ") ";
                continue;
            }
            if (j + k < N && HasElement(visited, Point(i, j + k)) == false)
            {
                j += k;
                visited.push_back(Point(i, j));
                std::cout << "(" << i << "," << j << ") ";
                continue;
            }
            else if (j - k < N && j - k > 0 && HasElement(visited, Point(i, j - k)) == false)
            {
                j -= k;
                visited.push_back(Point(i, j));
                std::cout << "(" << i << "," << j << ") ";
                continue;
            }
        }
    }
    std::cout << "\nEnd of path";
}