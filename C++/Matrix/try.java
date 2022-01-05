import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;


class Result {

    /*
     * Complete the 'decryptMessage' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING encryptedMessage as parameter.
     */

    public static String decryptMessage(String encryptedMessage) {
        String arr[] = encryptedMessage.split(" ");
        String req = "";
        
        for(int i=arr.length-1;i>=0;i--)
            req += arr[i]+" ";
        
        int a = 0;
        for(int i=0;i<req.length();i++){
            char test = req.charAt(i);
            if(Character.isDigit(test))
                a = test - '0';
                String rep= "";
                for(int j=0;j<a;j++)
                    rep+=req.charAt(i-1);
                String aa = test+"";
                req = req.replaceFirst(aa, rep);
        }
        
        return req;
    }

}
public class try {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String encryptedMessage = bufferedReader.readLine();

        String result = Result.decryptMessage(encryptedMessage);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
