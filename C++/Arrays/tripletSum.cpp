#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool tripletSum(vector<int> array, int sum)
{
    for (int i = 0; i < array.size(); i++)
    {
        int currentSum = sum - array.at(i);
        unordered_set<int> sett;
        for (int j = i + 1; j < array.size(); j++)
        {
            if (sett.find(currentSum - array.at(j)) != sett.end())
                return 1;

            sett.insert(array.at(j));
        }
    }
    return 0;
}

int main()
{
    vector<int> array = {557, 217, 627, 358, 527, 358, 338, 272, 870, 362, 897, 23, 618, 113, 718, 697, 586, 42, 424, 130, 230, 566, 560, 933};
    cout<<tripletSum(array,986);
}