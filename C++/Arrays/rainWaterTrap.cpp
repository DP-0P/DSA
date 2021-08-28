#include <iostream>
using namespace std;

void trapWater(int array[], int size)
{

    int water = 0;
    for (int i = 0; i < size - 1; i++)
    {

        int lSide = array[i];
        for (int j = 0; j < i; j++)
            if (lSide < array[j])
                lSide = array[j];

        int rSide = array[i];
        for (int j = i + 1; j < size; j++)
            if (rSide < array[j])
                rSide = array[j];

        water += min(lSide, rSide) - array[i];
    }
    cout << water << endl;
}

int main()
{
    int array[] = {8, 8, 2, 4, 5, 5, 1};
    //output 7
    int var;
    // cout<<var;
    int size = sizeof(array) / sizeof(array[0]);
    trapWater(array, size);
}