#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int Count = 0;

int partition(vector<int>& arr, int start, int end, int pivotIndex) {
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[end]);
    int i = start - 1;

    for (int j = start; j <end; j++) {
        Count++;
        if (arr[j]< pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i+1;
}
int chooseFirstPivot(int start, int end) {
    return start;
}
int chooseRandomPivot(int start, int end) {
    return start + rand() % (end - start + 1);
}
int chooseMiddlePivot(int start, int end) {
    return start + (end - start) / 2;
}
int chooseMedianPivot(vector<int>& arr, int start, int end) {
    int mid = start + (end - start)/ 2;
    int a = arr[start], b = arr[mid], c = arr[end];

    if ((a > b&& a < c) ||(a <b && a > c)) return start;
    else if ((b >a &&b < c)|| (b< a &&b >c)) return mid;
    else return end;
}
void quickSort(vector<int>& arr, int start, int end, int pivotType) {
    if (start >= end) {
        return;
    }
        int pivotIndex;
        switch (pivotType) {
            case 1: pivotIndex = chooseFirstPivot(start, end); break;
            case 2: pivotIndex = chooseRandomPivot(start, end); break;
            case 3: pivotIndex = chooseMiddlePivot(start, end); break;
            case 4: pivotIndex = chooseMedianPivot(arr, start, end); break;
            default: pivotIndex = chooseFirstPivot(start, end);
        }

        int pi = partition(arr, start, end, pivotIndex);
        quickSort(arr, start, pi - 1, pivotType);
        quickSort(arr, pi + 1, end, pivotType);
}
void testPivotApproach(vector<int> arr, int pivotType, string label) {
    Count = 0;
    quickSort(arr, 0, arr.size() - 1, pivotType);
    cout << label << " pivot: " << Count << " comparisons" << endl;
}
vector<int> generateSortedArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    return arr;
}
vector<int> generateReverseSortedArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = n - i;
    return arr;
}
vector<int> generateRandomArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = rand() % 100;
    return arr;
}
int main() {
    srand(time(0));
    int n = 10;

    vector<int> sortedArr = generateSortedArray(n);
    vector<int> reverseArr = generateReverseSortedArray(n);
    vector<int> randomArr = generateRandomArray(n);

    cout << "<---Sorted Array--->" << endl;
    testPivotApproach(sortedArr, 1, "First element");
    testPivotApproach(sortedArr, 2, "Random element");
    testPivotApproach(sortedArr, 3, "Middle element");
    testPivotApproach(sortedArr, 4, "Median-of-three");

    cout << "<---Reverse Sorted Array--->" << endl;
    testPivotApproach(reverseArr, 1, "First element");
    testPivotApproach(reverseArr, 2, "Random element");
    testPivotApproach(reverseArr, 3, "Middle element");
    testPivotApproach(reverseArr, 4, "Median-of-three");

    cout << "<---Random Array--->" << endl;
    testPivotApproach(randomArr, 1, "First element");
    testPivotApproach(randomArr, 2, "Random element");
    testPivotApproach(randomArr, 3, "Middle element");
    testPivotApproach(randomArr, 4, "Median-of-three");

    return 0;
}
// from analysis it is clear that median of three pivot is the best approach as it takes the least no. of comparisons in any case.
