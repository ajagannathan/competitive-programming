// Given an mxm matrix and a point of origin,
// calculate the probability that the point lies inside the matrix after n steps.
// The point is allowed to move up,down,left and right with an equal probability of 0.25

#include "header.h"

int main()
{
    std::queue<Position *> node;
    node.push(new Position(2, 3));
    node.push(new Position(4, 5));
    node.push(NULL);
    node.push(new Position(6, 7));
    node.push(new Position(1, 6));

    while (node.size() != 0)
    {
        Position *p = node.front();
        node.pop();
        if (p)
            std::cout << p->x << ", " << p->y << "\n";

        delete p;
        unsigned char b = 8;
        int a = 6;
        b = a;
    }
}