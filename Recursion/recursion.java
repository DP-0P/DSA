//number of ways in n*m matrix
public class recursion {
    public static void main(String[] args) {
        System.out.println(ways(4,2));
    }
    public static int ways(int n, int m){
        if(n==1 || m==1)
        return 1;

        else
        return ways(n-1, m) + ways(n, m-1);
    }
}
