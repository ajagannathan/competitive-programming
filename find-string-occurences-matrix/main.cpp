// // Given a MxN matrix of characters, find all occurences of given string in the matrix.
// // We are allowed to search the string across the 8 neighbours of a given element.
// // Note that there should not be any cycles in the output path

// // For example. In the given matrix
// //         0    1    2    3    4
// // 	0	{ 'D', 'E', 'M', 'X', 'B' },
// // 	1	{ 'A', 'O', 'E', 'P', 'E' },
// // 	2	{ 'D', 'D', 'C', 'O', 'D' },
// // 	3	{ 'E', 'B', 'E', 'D', 'S' },
// // 	4	{ 'C', 'P', 'Y', 'E', 'N' }

// // For the string "CODE" below are all the occurences

// //     'C'(2, 2)'O'(1, 1)'D'(0, 0)'E'(0, 1)
// //     'C'(2, 2)'O'(1, 1)'D'(2, 0)'E'(3, 0)
// //     'C'(2, 2)'O'(1, 1)'D'(2, 1)'E'(1, 2)
// //     'C'(2, 2)'O'(1, 1)'D'(2, 1)'E'(3, 0)
// //     'C'(2, 2)'O'(1, 1)'D'(2, 1)'E'(3, 2)
// //     'C'(2, 2)'O'(2, 3)'D'(2, 4)'E'(1, 4)
// //     'C'(2, 2)'O'(2, 3)'D'(3, 3)'E'(3, 2)
// //     'C'(2, 2)'O'(2, 3)'D'(3, 3)'E'(4, 3)

#include "header.h"

static const int ROW = 5;
static const int COL = 5;

void findStringOccurences(char Mat[ROW][COL], const char *s)
{
    std::vector<Pos> neighbours2{Pos(-1, -1), Pos(-1, 0), Pos(-1, 1),
                                 Pos(0, -1), Pos(0, 1), Pos(1, -1),
                                 Pos(1, 0), Pos(1, 1)};
}

int main()
{
    // char matrix[ROW][COL] = {{'D', 'E', 'M', 'X', 'B'},
    //                          {'A', 'O', 'E', 'P', 'E'},
    //                          {'D', 'D', 'C', 'O', 'D'},
    //                          {'E', 'B', 'E', 'D', 'S'},
    //                          {'C', 'P', 'Y', 'E', 'N'}};

    // const char *s = "CODE";
    // findStringOccurences(matrix, s);

    Tree<char> tree;
    //TreeNode<char> *root = tree.getRootNode();
    tree.insertNode(tree.getRootNode(), 'C');
    tree.insertNode(tree.getRootNode(), 'O');
    tree.insertNode(tree.getRootNode(), 'O');
    tree.insertNode(tree.getRootNode()->branches[0], 'D');
}

//**********************************************
//                  Solution
//**********************************************
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include "header.h"
// using namespace std;

// // M x N matrix
// #define M 5
// #define N 5

// // stores cell coordinates of the matrix
// typedef pair<int, int> Node;

// // Below arrays details all 8 possible movements from a cell
// // (top, right, bottom, left and 4 diagonal moves)
// int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// // Function to check if it is possible to go to position next
// // from current position. The function returns false if next is
// // not a valid position or it is already visited
// bool isvalid(Node const &next, vector<Node> const &path)
// {
//     return (next.first >= 0) && (next.first < M) &&
//            (next.second >= 0) && (next.second < N) &&
//            (find(path.begin(), path.end(), next) == path.end());
// }

// // Function to print the complete path from source to destination
// void printPath(vector<Node> const &path, string word)
// {
//     int index = 0;
//     for (Node cell : path)
//     {
//         cout << "'" << word[index++] << "'";
//         cout << "(" << cell.first << ", " << cell.second << ") ";
//     }
//     cout << '\n';
// }

// // Notice that path vector is not passed by the reference (Why?)
// // Use Backtracking if vector is passed by reference
// void DFS(char mat[M][N], string word, Node const &next,
//          vector<Node> path, int index)
// {
//     int i = next.first;
//     int j = next.second;
//     int n = word.size();

//     // return if characters don't match
//     if (mat[i][j] != word[index])
//         return;

//     // include current cell in the path
//     path.push_back({i, j});

//     // if all words are matched, print the result and return
//     if (index == n - 1)
//     {
//         printPath(path, word);
//         return;
//     }

//     // check all 8 possible movements from current cell
//     // and recur for each valid movement
//     for (int k = 0; k < 8; ++k)
//     {
//         // calculate next position
//         Node next = {i + row[k], j + col[k]};

//         // check if it is possible to go to next position
//         // from current position
//         if (isvalid(next, path))
//             DFS(mat, word, next, path, index + 1);
//     }
// }

// int main()
// {
//     char mat[M][N] =
//         {
//             {'D', 'E', 'M', 'X', 'B'},
//             {'A', 'O', 'E', 'P', 'E'},
//             {'D', 'D', 'C', 'O', 'D'},
//             {'E', 'B', 'E', 'D', 'S'},
//             {'C', 'P', 'Y', 'E', 'N'}};

//     string word = "CODE";
//     vector<Node> path;

//     Timer t;
//     for (int i = 0; i < M; ++i)
//     {
//         for (int j = 0; j < N; ++j)
//         {
//             DFS(mat, word, make_pair(i, j), path, 0);
//         }
//     }

//         return 0;
// }