public class countAndSay {
    public static String say(String s){
        if(s.isEmpty())
            return "1";
        
        int i = 0;
        String t = "";
        while(i<s.length()){
            char c = s.charAt(i);
            int j = i+1;
            int count = 1;
            while(j<s.length() && c == s.charAt(j)){
                count++;
                j++;
            }
            String cnt = Integer.toString(count);
            t += cnt+c;
            i = j;
        }
        return t;
    }
    public static String countAndSay(int n){
        String s = "";
        for(int i=1;i<=n;i++)
            s = say(s);
        return s;
    }
    public static void main(String[] args) {
        System.out.println(countAndSay(4));
    }
}
