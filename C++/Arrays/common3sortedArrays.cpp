#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> final;

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            if (A[i] == B[j])
            {
                for (int k = 0; k < n3; k++)
                    if (A[i] == C[k])
                        final.push_back(A[i]);
            }

    auto end = final.end();
    for (auto it = final.begin(); it != end; ++it)
        end = remove(it + 1, end, *it);
    final.erase(end, final.end());

    return final;
}

int main()
{
    int a[] = {1, 5, 10, 20, 40, 80};
    int b[] = {6, 7, 20, 80, 100};
    int c[] = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> chal = commonElements(a, b, c, 6, 5, 8);

    for (int i = 0; i < chal.size(); i++)
        cout << chal.at(i) << " ";
}