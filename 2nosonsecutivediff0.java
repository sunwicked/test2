/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/*package whatever //do not write package name here */
// consecutive two num diff 0 

class GFG {
	public static void main (String[] args) {
		//code
		int[] array = {2,2,1,-1,0,4,5,7,8};
		for(int i= 0 ; i < array.length-2;i++)
		{
		    if(Math.abs(array[i])-Math.abs(array[i+1])==0)
		    {
		        System.out.println("000");
		    }
		}
	}
}
