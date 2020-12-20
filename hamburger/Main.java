import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        sc.nextLine();
        String S = sc.nextLine(); 
        int j = 0, ans = 0;
        for(int i=0; i<N; i++){
            if(S.charAt(i)=='H') continue;
            for(j=Math.max(j,i-K); j<=Math.min(N-1,i+K); j++){
                if(S.charAt(j)=='P') continue;
                ans++;
                j++;
                break;
            }
        }
        System.out.println(ans);
    }
}