// Challenge Definition:

// From a given matrix of 1's and 0's (where 1 - Water and 0 - land)
// Find the length of the water body by counting the 1's connected
// horizontally or vertically or both

#include "header.h"

static const int row = 5;
static const int col = 5;

void findConnectedComponents(int (*matrix)[col], std::vector<int> &components)
{
    //int *length_arr = new int;
    int count = 0;
    std::queue<Pos> open;
    std::vector<Pos> actions;
    actions.push_back(Pos(-1, 0));
    actions.push_back(Pos(1, 0));
    actions.push_back(Pos(0, -1));
    actions.push_back(Pos(0, 1));

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {

            if (matrix[i][j] == 1)
            {
                count++;
                matrix[i][j] = 0;
                open.push(Pos(i, j));
                while (open.size() != 0)
                {
                    Pos temp = open.front();
                    open.pop();
                    for (size_t n = 0; n < actions.size(); n++)
                    {
                        int r = temp.x + actions[n].x;
                        int c = temp.y + actions[n].y;
                        if (r >= 0 && r < row && c >= 0 && c < col)
                        {
                            if (matrix[r][c] == 1)
                            {
                                count++;
                                open.push(Pos(r, c));
                                matrix[r][c] = 0;
                            }
                        }
                    }
                }

                components.push_back(count);
                count = 0;
            }
        }
    }
}

int main()
{
    int matrix[row][col] = {{1, 0, 0, 1, 1},
                            {1, 0, 1, 1, 0},
                            {0, 0, 1, 1, 1},
                            {1, 0, 1, 1, 1},
                            {1, 0, 1, 1, 0}};

    std::vector<int> components;
    // actions.push_back(Pos(-1, 0));
    // actions.push_back(Pos(1, 0));
    // actions.push_back(Pos(0, 1));
    // actions.push_back(Pos(0, -1));

    findConnectedComponents(matrix, components);
    for (size_t i = 0; i < components.size(); i++)
    {
        std::cout << " " << components[i] << " ";
    }
}