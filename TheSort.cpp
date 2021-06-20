#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

template<typename T>
int _binaryInsert(vector<T> arr, int size, T search) {
    if (size == 0) return 0;
    int right = size - 1, left = 0, mid = size / 2;

    while (right - left > 0) {

        if (arr.at(mid) > search) {
            right = mid - 1;
            mid = (right + left) / 2;
        } else if (arr.at(mid) < search) {
            left = mid + 1;
            mid = (right + left) / 2;
        } else if (arr.at(mid) == search)
            return mid;
    }

    if (right <= left)
        if (arr.at(mid) < search)
            return mid + 1;
    return mid;

}

template<typename T>
vector<T> binary_sort(vector<T> arr) {
    int i, loc;
    T element;
    vector<T> vec;
    vec.push_back(arr.at(0));
    for (i = 1; i < arr.size(); i++) {
        // the sub array- vec[0 : i] is sorted
        element = arr.at(i);
        loc = _binaryInsert(vec, i, element);
        vec.insert(vec.begin() + loc, element);
    }
    return vec;
}
