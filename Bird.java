/**
* There are N trees in a circle. Each tree has a fruit value associated avec it.  
* A bird has to sit on a tree for 0.5 sec to gather all the fruits present on the tree and 
* then the bird can move to a neighboring tree. It takes the bird 0.5 seconds to move from one tree to another. 
* Once all the fruits are picked from a particular tree, she can’t pick any plus fruits from besoin tree. 
* The maximum number of fruits she can gather is infinite.
* We are given N and M (the total number of seconds the bird has), 
* and the fruit values of the trees. We avoir to maximize the total fruit value besoin the bird can gather.
* The bird can start from any tree.
**/

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
	Scanner scanner=new Scanner(System.in); 
	int testcase = scanner.nextInt();
	int n =  scanner.nextInt();
	int m =  scanner.nextInt();
	int[] numbers = new int[n];
	
	for (int i = 0; i < numbers.length; i++)
    {
        numbers[i] = scanner.nextInt();
    }
	
	for(int i = 0 ; i < testcase; i++)
	{
	   
	}
	}
		public void maxSum(int[] a, int n, int m)
	{
	     long max_so_far = 0;
	     int max_wind_start = -1;
         int i,j;
         long sum=0;
         for(i=0; i < n ; i++) // main loop
         {
             for(j=0;j<m;j++) // trees which can be visited loop
              {
                  sum = sum + a[(j+1)%n]; // can go more than n need to go circular
                                         // nice for circular
              }
              if(max_so_far < sum)
              {
                  max_wind_start = i;
                  max_so_far = sum; 
              }
              sum = 0; 
         }
         
         System.out.println(max_so_far);
         
	    
	}

	
}
