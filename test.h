#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <chrono>

typedef std::chrono::steady_clock high_res_clock;
typedef std::chrono::time_point<high_res_clock> high_res_time_point;
typedef std::chrono::duration<double> duration;

struct Pos
{
    int x, y;
    Pos()
    {
        x = 0;
        y = 0;
    }
    Pos(int a, int b)
    {
        x = a;
        y = b;
    }
    ~Pos() {}
};


struct Timer
{
private:
    high_res_time_point m_begin, m_end;
    duration m_d;

public:
    Timer() : m_begin(high_res_clock::now()) {}
    ~Timer()
    {
        m_end = high_res_clock::now();
        m_d = m_end - m_begin;
        std::cout << "Runtime : " << m_d.count() * 1000 << "\n";
    }
};

#endif //_HEADER_H