//
// Created by mahidhar.ramesh on 12/31/2017.
//

#ifndef PROJECT_BINARYHEAP_H
#define PROJECT_BINARYHEAP_H

#include <vector>
#include <stdexcept>

template<class T>
class BinaryHeap {
private:
    std::vector<T> mItems;

    int getLeftChildIndex(int parentIndex) {
        return 2 * parentIndex + 1;
    }

    int getRightChildIndex(int parentIndex) {
        return 2 * parentIndex + 2;
    }

    int getParentIndex(int childIndex) {
        return (childIndex - 1)/2;
    }

    bool hasLeftChild(int index) {
        return getLeftChildIndex(index) < mItems.size();
    }

    bool hasRightChild(int index) {
        return getRightChildIndex(index) < mItems.size();
    }

    bool hasParent(int index) {
        return getParentIndex(index) >= 0;
    }

    T leftChild(int index) {
        return mItems[getLeftChildIndex(index)];
    }

    T rightChild(int index) {
        return mItems[getRightChildIndex(index)];
    }

    T parent(int index) {
        return mItems[getParentIndex(index)];
    }

    void swap(int indexOne, int indexTwo) {
        //std::swap(items[indexOne], items[indexTwo]);
        T temp = mItems[indexOne];
        mItems[indexOne] = mItems[indexTwo];
        mItems[indexTwo] = temp;
    }

public:

    BinaryHeap() {

    }

    T peek() throw(std::range_error) {
        if (mItems.size() == 0) {
            throw std::range_error("peek not allowed on empty heap");
        }
        return mItems[0];
    }

    T poll() throw(std::range_error) {
        if (mItems.size() == 0) {
            throw std::range_error("peek not allowed on empty heap");
        }

        T item = mItems[0];
        mItems[0] = mItems.back();
        mItems.pop_back();
        heapifyDown();
        return item;
    }

    void add(T item) {
        mItems.push_back(item);
        heapifyUp();
    }

    void heapifyUp() {
        int index = (int)mItems.size() - 1;
        while(hasParent(index) && parent(index) > mItems[index]) {
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }

    void heapifyDown() {
        int index = 0;
        while(hasLeftChild(index)) {
            int smallerChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
                smallerChildIndex = getRightChildIndex(index);
            }

            if (mItems[index] < mItems[smallerChildIndex]) {
                break;
            } else {
                swap(smallerChildIndex, index);
            }
            index = smallerChildIndex;
        }
    }
};

#endif //PROJECT_BINARYHEAP_H
