public class string1_Reverse {
    public static void main(String[] args) {
        reverse("Deepak");
        System.out.println(reverse("Deepak"));
    }

    static String reverse(String s) {
        StringBuilder sb = new StringBuilder(s);
        return sb.reverse().toString();
    }
}
