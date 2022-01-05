import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class wordBreak {
    
    public static void wordBreak(int n,List<String> dict,String s,String res,List<String> ans){
        for(int i=1;i<=n;i++){
            String prefix = s.substring(0,i);

            if(dict.contains(prefix)){
                if(i==n){
                    res+=prefix;
                    ans.add(res);
                    return;
                }
                wordBreak(n-i, dict, s.substring(i, n), res+prefix+" ",ans);
            }
        }
    }
    public static void main(String[] args) {
        String s = "catsanddog";
        List<String> dict = new LinkedList<>(Arrays.asList("cats", "cat", "and", "sand", "dog"));
        List<String> res = new LinkedList<>();

        wordBreak(s.length(), dict, s, "", res);

        System.out.println(res.toString());
    }
}
// GFG accepted code
//  static List<String> wordBreak(int n, List<String> dict, String s)
//     {
//         List<String> ans = new ArrayList<>();
//         solve(dict,s,ans,"");
//         return ans;
//     }
//     static void solve(List<String> dict, String s, List<String> ans, String temp){
//         if(s.length() == 0){
//             ans.add(temp.substring(1));
//             return;
//         }
//         for(int i=1;i<=s.length();i++)
//             if(dict.contains(s.substring(0,i)))
//                 solve(dict,s.substring(i),ans,temp+ " " + s.substring(0,i));
//     }
