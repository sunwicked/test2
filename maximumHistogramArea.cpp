/*----------MAXIMUM HISTOGRAM AREA----------------------------------------------->
 *
 *  1. Add to stack index  if current value is equal or bigger than top of stack
 *  2. Otherwise keep removing from stack till a number which is smaller or equal 
 *     than current is found
 *  3. Calculate Area everytime you remove 
 *        if(stack is empty)
 *            area = input[top] * i 
 *        else 
 *            area = input[top] * (i-stack[top]-1)
 *
 */
#include<iostream>
#include<stack>
 
int calculateArea(int hist[],int len){
    int maxArea=-1;
    int localTop=0;
    int area=-1;
    std::stack<int> index;
    int i ;
    for( i = 0; i < len;){        
        if(index.empty() || hist[index.top()]<= hist[i]){
            
            index.push(i++);
              
        } else { 
            int localTop=index.top();
            index.pop();
            if(index.empty()){
                area = hist[localTop] * i;        
            } else {
                area = hist[localTop] * (i - index.top()-1);
            }
            maxArea=std::max(area,maxArea);
         }
        
    }
    while(!index.empty()){
        int localTop=index.top();
        index.pop();
        if(index.empty()){
            area = hist[localTop] * i ;                    
        } else {
            area = hist[localTop] * (i - index.top()-1);
        }
        maxArea=std::max(area,maxArea);
    }
    return maxArea;
}

 int main(){
    int hist[] = {0,2,1,2,1,2};
    int len = sizeof(hist)/sizeof(hist[0]);
    std::cout<<" Max Area is : "<<calculateArea(hist,len)<<std::endl;
 }
