//Josephus problem
public class recursion4 {
    public static void main(String[] args) {
        System.out.println(Josephus(5, 3));
    }
    public static int Josephus(int n, int k) {
        if (n == 1)
            return 0;

        else
            return (Josephus(n - 1, k) + k) % n;
    }
}