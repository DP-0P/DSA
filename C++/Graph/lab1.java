import java.util.*;
public class lab1 {
	public static void main(String args[])
	{
		Scanner sc  = new Scanner(System.in);
		int max=Integer.MIN_VALUE;
		int curr=0;
		int a[]= {-1,-6,-5,-7,-2};
		for (int i=0;i<a.length;i++)
		{
			curr=curr+a[i];
		
		if(curr>max)
		
			max=curr;
		
		if(curr<0)
			curr=0;
		}
		System.out.println("max"+" "+max);
	}
	
}