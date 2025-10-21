//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        size++;
        weightArr[size-1] = idx;
        data[size-1] = idx;
        upheap(size, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int root = data[0];
        data[0] = weightArr[size-1];
        size--;
        downheap(size, weightArr);
        return root;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        pos = size-1;
        while (data[pos] < data[(pos-1)/2]) {
            swap(data[pos], data[(pos-1)/2]);
            pos = (pos-1)/2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        pos = 0;
        while (data[pos] > data[2*pos+1] || data[pos] > data[2*pos+2]) {
            if (data[pos] > data[2*pos+1]) {
                swap(data[pos], data[2*pos+1]);
                pos = 2*pos+1;
            } else {
                swap(data[pos], data[2*pos+2]);
                pos = 2*pos+2;
            }
        }
    }
};

#endif