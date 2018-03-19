/*package whatever //do not write package name here 
* Largest Fibonacci Subsequence https://practice.geeksforgeeks.org/problems/largest-fibonacci-subsequence/0
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int inputs = scan.nextInt();
	   int arraySize = 0 ;
			
		    for(int i = 0 ; i < inputs ; i++)
		{	 arraySize  = scan.nextInt();
		int[] inArray = new int[arraySize];
		for(int j = 0 ; j < arraySize ; j++)
		{
		    inArray[j] = scan.nextInt();
		}
		printFibonnaci(inArray);
		}
	}
	
	
	public static void printFibonnaci(int[] array)
	{
	    //  Case 1: Sort O (N logN)
	    // find fibonnaci upto highest value and store it in hashmap O(N)
	    // iterate and validate from HashMap O(N)
	    
	    Arrays.sort(array);
	    Set<Integer> map = getFiboMap(array[array.length-1]);
	    for(int i =0 ; i < array.length; i++)
	{
	    if(map.contains(array[i]))
	    {
	        System.out.print(array[i]+ " ");
	    }
	   
	}
  System.out.println(" ");
	}
	public static Set<Integer> getFiboMap(int largest)
	{
	    Set<Integer> op =  new HashSet<Integer>();
	    if(largest == 0)
	  {
	      op.add(0);
	  }else if(largest == 1)
	  {
	      op.add(0);
	      op.add(1);
	  }
	  else
	  {
	      int sum = 0 ; 
	      int n1 = 0;
	      int n2 = 1;
	      while(sum<largest)
	      {
	          sum = n1 + n2;
	          n1 = n2;
	          n2 =sum;
	          op.add(sum);
	      }
	      
	  }
	  return op;  
	}
}
