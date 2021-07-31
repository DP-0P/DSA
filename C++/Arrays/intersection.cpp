#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void intersection(int arr1[], int l1, int arr2[], int l2)
{

    int arr3[l1 + l2];
    int k = 0;
    for (int i = 0; i < l1; i++)
        for (int j = 0; j < l2; j++)
            if (arr1[i] == arr2[j])
            {
                arr3[k] = arr1[i];
                k++;
            }

    int temp[k];
    int j = 0;
    for (int i = 0; i < k - 1; i++)
        if (arr3[i] != arr3[i + 1])
            temp[j++] = arr3[i];

    temp[j++] = arr3[k - 1];

    for (int i = 0; i < j; i++)
        arr3[i] = temp[i];

    for (int i = 0; i < j; i++)
        cout << arr3[i] << " ";
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> inter;
    for (int i = 0; i < nums1.size(); i++)
        for (int j = 0; j < nums2.size(); j++)
            if (nums1.at(i) == nums2.at(j))
                inter.push_back(nums1.at(i));

    auto end = inter.end();
    for (auto it = inter.begin(); it != end; ++it)
        end = remove(it + 1, end, *it);
    inter.erase(end, inter.end());

    return inter;
}

int main()
{

    int arr1[] = {1, 2, 4, 5, 6, 7};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int l1 = sizeof(arr1) / sizeof(arr1[0]);
    int l2 = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> vec1 = {1, 2, 4, 5, 6, 7};
    vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    intersection(arr1, l1, arr2, l2);

    cout << "\nAnother method" << endl;

    vector<int> final = intersection(vec1, vec2);
    for (int i = 0; i < final.size(); i++)
        cout << final.at(i) << " ";
}