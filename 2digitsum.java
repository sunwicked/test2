/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		
		int [] input = {-25,-10,-7,-4,-3,2,4,8,10};
		
Arrays.sort(input);

 for(int i = 0; i < input.length; i ++)
 {
 int  target = input[i];
 int  l = 0;
 int r = input.length-1;
  while(l<r)
  {
  
  int total = input[l]+input[r]-target;
  if(total == 0)
  {
  	System.out.println(target);
  	System.out.println(input[l]);
  	System.out.println(input[r]);
  	
  break;
  }
  else if(total < 0 )
  {
  l++;
  }
  else{
  r--;}
  }
  
 }
	}
}
