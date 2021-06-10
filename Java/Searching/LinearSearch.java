public class LinearSearch {
    public static void LinearSearching(int array[], int search) {
        int index = -1;
        for (int i = 0; i < array.length; i++)
            if (array[i] == search)
                index = i;

        if (index < 0)
            System.out.println("Search element is not present in the array.");
            
        else
            System.out.println("Search element is present at index " + index);
    }
}

// Time Complexity -
// Best Case - O(1)
// Worst Case - O(n)
// Average Case - O(n/2)

// Space complexity - O(1)
