import java.util.Arrays;
public class SelectionSort {
    public static void SelectionSort(int array[]){   
        for(int i=0;i<array.length-1;i++){
            int minIndex = i;
            for(int j=i+1;j<array.length;j++)
                if(array[j]<array[minIndex])
                minIndex = j;
            
            if(minIndex!=i){
              int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;  
            }    
        }
        System.out.println(Arrays.toString(array));
    }
}
// Best Case - O(n²) when array is already sorted
// Worst Case - O(n²) when array is sorted in descending order
// Average Case - O(n²)
// Space complexity - O(1)