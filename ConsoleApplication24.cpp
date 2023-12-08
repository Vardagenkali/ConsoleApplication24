#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T Max(const vector<T>& arr) {
    if (arr.empty()) {
        cout << "Array is empty\n";
        return T();
    }

    T maxVal = arr[0];
    for (const T& val : arr) {
        if (val > maxVal) {
            maxVal = val;
        }
    }

    return maxVal;
}

template <typename T>
T Min(const vector<T>& arr) {
    if (arr.empty()) {
        cout<< "Array is empty\n";
        return T();
    }

    T minVal = arr[0];
    for (const T& val : arr) {
        if (val < minVal) {
            minVal = val;
        }
    }

    return minVal;
}

template <typename T>
void Sort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
int Search(const vector<T>& arr, const T& target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

template <typename T>
void replaceElement(vector<T>& arr, const T& oldValue, const T& newValue) {
    for (T& val : arr) {
        if (val == oldValue) {
            val = newValue;
        }
    }
}

int main() {
    vector<int> array = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

    cout << "Original Array: ";
    for (const auto& val : array) {
        cout << val << " ";
    }
    cout << "\n";

   cout << "Max Value: " << Max(array) << "\n";
   cout << "Min Value: " <<Min(array) << "\n";

    Sort(array);

    cout << "Sorted Array: ";
    for (const auto& val : array) {
        cout << val << " ";
    }
        cout << "\n";

    int target = 5;
    int index = Search(array, target);
    if (index != -1) {
        cout << "Element " << target << " found at index " << index << "\n";
    }
    else {
        cout << "Element " << target << " not found in the array.\n";
    }

    int oldValue = 5;
    int newValue = 99;
    replaceElement(array, oldValue, newValue);

    cout << "Array after replacing " << oldValue << " with " << newValue << ": ";
    for (const auto& val : array) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
