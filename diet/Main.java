import java.util.*;
import java.io.*;

public class Main{
    static int n;
    static int a[] = new int[4];
    static int b[][] = new int[20][5];
    static boolean compare(int msk1, int msk2){
    	int p = 0, q = 0;
    	while(true){
    		while(p < 20 && ((msk1 >> p) % 2) == 0) p++;
    		while(q < 20 && ((msk2 >> q) % 2) == 0) q++;
    		if(q == 20) return false;
    		if(p == 20) return true;
    		if(p != q) return p < q;
    		p++;
    		q++;
    	}
    }
    public static void main(String[] args) throws IOException{
    	Scanner sc = new Scanner(System.in);
    	n = sc.nextInt();
    	for(int i = 0; i < 4; i++) a[i] = sc.nextInt();
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < 5; j++){
    			b[i][j] = sc.nextInt();
    		}
    	} 
    	int ans = 987654321;
    	int fn = 0;
    	for(int i = 0; i < (1<<n); i++){
    		int[] c = new int[5];
    		for(int j = 0; j < 5; j++) c[j] = 0;
    		for(int j = 0; j < n; j++){
    			if(((i >> j) & 1) == 1){
    				for(int k = 0; k < 5; k++) c[k] += b[j][k];
    			}
    		}
    		boolean good = true;
    		for(int j = 0; j < 4; j++){
    			if(a[j] > c[j]) good = false;
    		}
    		if(good){
    			if(ans > c[4]){
    				ans = c[4];
    				fn = i;
    			}
    			if(ans == c[4] && compare(i, fn)) fn = i;
    		}
    	}
    	if(ans > 10000000){
    		System.out.println("-1");
    	}
    	else{
	    	System.out.println(ans);
	    	boolean before = false;
	    	for(int i = 0; i < n; i++){
	    		if((fn >> i) % 2 == 1){
	    		    if(before) System.out.printf(" ");
	    		    System.out.printf("%d", i+1);
	    		    before = true;
	    		}
	    	}
    	}
    }
}
