import java.util.Arrays;

public class MajorityElement {
    public static void main(String[] args) {
        int n[] = { 5, 1, 1, 4, 1 };
        MooresVotingAlgo(n);
    }

    public static void UsingBruteAlgo(int n[]) {
        int count, max = n[0], maxCount = 0;
        for (int i = 0; i < n.length; ++i) {
            count = 0;
            for (int j = 0; j < n.length; ++j)

                if (n[i] == n[j])
                    count++;

            if (count > maxCount) {
                maxCount = count;
                max = n[i];
            }
        }
        if (maxCount > n.length / 2)
            System.out.println("Majority element is " + max + " .");
        else
            System.out.println("Majority element is not present !!!");
    }

    public static void UsingSorting(int n[]) {
        Arrays.sort(n);
        int temp = n[0], maxCount = 0, max = n[0], count = 0;
        for (int i = 0; i < n.length; i++) {

            if (n[i] == temp)
                count++;

            else {
                count = 0;
                temp = n[i];
            }

            if (count > maxCount) {
                maxCount = count;
                max = n[i];
            }
        }
        if (maxCount > n.length / 2)
            System.out.println("Majority element is " + max + " .");
        else
            System.out.println("Majority element is not present !!!");
    }

    public static void MooresVotingAlgo(int n[]) {
        int mayAns = n[0];
        int count = 0;

        for (int i = 0; i < n.length; i++) {

            if (n[i] == mayAns)
                count++;

            else
                count--;

            if (count == 0) {
                mayAns = n[i];
                count++;
            }
        }

        int finalCount = 0;

        for (int i = 0; i < n.length; i++)
            if (mayAns == n[i])
                finalCount++;

        if (finalCount > n.length / 2)
            System.out.println("Majority element is " + mayAns + " .");
        else
            System.out.println("Majority element is not present !!!");
    }
}
