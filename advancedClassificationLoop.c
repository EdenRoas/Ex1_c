#include <math.h>
#include <stdio.h>
      int countDigit(int num){
        int count_digits=0;
        while(num>0){
          num=num/10;
          count_digits++;
        }
        return count_digits;
      }
      int isPalindrome(int num){
        int i,rev,sum=0;
        int originalnum=num;
        while(num>0)    
        {    
          rev=num%10;    
          sum=(sum*10)+rev;    
          num=num/10;    
          }    
          if(sum==originalnum){
            return 1;
            }
          return 0;
        }
        int isArmstrong(int z){
          int count= countDigit(z);
          int oldz=z,sum=0,digit;
          while (z>0){
            digit = z%10;
            sum=sum+(pow(digit , count));
            z=z/10;
          }
          if (oldz==sum){
              return 1;
          }
        return 0;

        }

      
   