void reverse(int array[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}
