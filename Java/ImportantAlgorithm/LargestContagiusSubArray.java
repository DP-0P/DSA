public class LargestContagiusSubArray {
    public static void main(String[] args) {
        int n[] = {-5,-4,-2,-6,-1};
        System.out.println(KadanesAlgo(n));
    }
    //not applicable if all the elements in the array are negative
    public static int KadanesAlgo(int n[]){
        int maxSum = 0;
        int currentSum = 0;

        for(int i = 0 ; i<n.length;++i){
            currentSum = currentSum + n[i];

            if(currentSum > maxSum)
            maxSum = currentSum;

            if(currentSum < 0)
            currentSum = 0;
        }
        return maxSum;
    }
}
