//
// Created by Mahidhar Rajala on 8/20/17.
//


#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>


template<class T>
const T& max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

template<class T>
T sum(const T& a, const T& b)
{
    return a + b;
}

template<class T>
const T& min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

template <typename T>
class SegmentTree {
    const std::vector<T>& mInput;
    const std::function<T(T, T)> mFunc;
    std::vector<T> mSegmentTree;

public:
    SegmentTree(const std::vector<T>& input, const std::function<T(T, T)> func) : mInput(input), mFunc(func), mSegmentTree(input.size() * 4) {
        build(0, 0, mInput.size()-1);
    }

    T query(unsigned long i, unsigned long j) {
        return query(0, 0, mInput.size()-1, i, j);
    }

    void printInput() {
        std::for_each(mInput.begin(), mInput.end(), [](auto item) { std::cout << item << " ";});
        std::cout << std::endl;
    }

    void printSegmentTree() {
        std::cout << "size:" << mSegmentTree.size() << std::endl;
        std::for_each(mSegmentTree.begin(), mSegmentTree.end(), [](auto item) { std::cout << item << " ";});
        std::cout << std::endl;
    }

private:

    void build(unsigned long treeIndex, unsigned long low, unsigned long high) {
        if (low == high) {
            mSegmentTree[treeIndex] = mInput[low];
            return;
        }
        unsigned long  mid = low + (high - low)/2;
        build(2 * treeIndex + 1, low, mid);
        build(2 * treeIndex + 2, mid + 1, high);
        mSegmentTree[treeIndex] = mFunc(mSegmentTree[2 * treeIndex + 1], mSegmentTree[2 * treeIndex + 2]);
    }

    T query(unsigned long treeIndex, unsigned long low, unsigned long high, unsigned long i, unsigned long j) {
        if (low > j || high < i)
            return 0;

        if (i <= low && j >= high)
            return mSegmentTree[treeIndex];

        unsigned long mid = low + (high - low)/2;

        if (i > mid) {
            return query(2 * treeIndex + 2, mid + 1, high, i, j);
        } else if (j <= mid) {
            return query(2 * treeIndex + 1, low, mid, i, j);
        } else {
            T lq = query(2 * treeIndex + 1, low, mid, i, mid);
            T rq = query(2 * treeIndex + 2, mid + 1, high, mid + 1, j);
            return mFunc(lq, rq);
        }
    }

};

int main(int argc, char* argv[]) {
    std::vector<int> items = { 18, 17, 13, 19, 15, 11, 20, 12, 33, 25 };
    std::function<int(int, int)> f = sum<int>;
    SegmentTree<int> st(items, f);
    st.printInput();
    st.printSegmentTree();
    unsigned long i = 4;
    unsigned long j = 6;
    std::cout << "Max[" << i << ":" << j << "]" << st.query(i, j) << std::endl;
}