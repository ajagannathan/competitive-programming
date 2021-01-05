#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <utility>
//#include <vector>
//#include <array>

template <typename Tp, size_t S>
class Heap
{
private:
    Tp heap_array[S];
    typedef std::pair<Tp, size_t> data_pair;
    typedef const std::pair<Tp, size_t> const_data_pair;

public:
    Heap();

    const_data_pair& GetLeftChild(size_t index) const {
        data_pair data(heap_array[index * 2 + 1], index * 2 + 1);
        return data;
    }

    const_data_pair& GetRightChild(size_t index) const {
        std::pair<Tp, size_t> data(heap_array[index * 2 + 2], index * 2 + 2);
        return data;
    }

    const_data_pair& GetParent(size_t index) const {
        data_pair data(heap_array[(index - 1) / 2], (index - 1) / 2);
    }

    void push(const Tp& val) {
        //TODO
    }

    void pop(const Tp& val) {
        //TODO
    }

    constexpr size_t size() const { return S; }


    ~Heap();
};

#endif
