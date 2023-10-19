#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> first, std::vector<int> second) {
    std::vector<int> result;
    int temp1 = 0;
    int temp2 = 0;
    while (first.size() > 0 && second.size() > 0) {
        if (first[0] < second[0]) {
            result.push_back(first[0]);
            temp1++;
            if (first.size() == 1) {
                break;
            }
            first.erase(first.begin());
        } else {
            result.push_back(second[0]);
            temp2++;
            if (second.size() == 1) {
                break;
            }
            second.erase(second.begin());
        }
    }
    if (temp1 > temp2) {
        result.insert(result.end(), second.begin(), second.end());
    } else {
        result.insert(result.end(), first.begin(), first.end());
    }
    std::cout << "result is: ";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return result;
}

std::vector<int> mergeSort(std::vector<int> arr) {
    if (arr.size() > 1) {
        std::vector<int> arr1(arr.begin(), arr.begin() + arr.size() / 2);
        std::vector<int> arr2(arr.begin() + arr.size() / 2, arr.end());
        arr1 = mergeSort(arr1);
        arr2 = mergeSort(arr2);
        return merge(arr1, arr2);
    } else {
        return arr;
    }
}

int main() {
    std::vector<int> arr = {9, 1, 2, 4, 3, 2, 7, 9};
    std::vector<int> sortedArr = mergeSort(arr);
    std::cout << "task is - ";
    for (int i = 0; i < sortedArr.size(); i++) {
        std::cout << sortedArr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}