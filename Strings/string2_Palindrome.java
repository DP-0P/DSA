public class string2_Palindrome {
    static boolean isPalindrome(String s){
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        if(sb.toString().equalsIgnoreCase(s))
        return true;
        else
        return false;
    }
}
