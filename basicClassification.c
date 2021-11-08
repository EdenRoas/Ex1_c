#include <stdio.h>
    int isPrime(int x){ 
        for (int i = 2; i < x; i++)
        {
         if ((x%i)==0){
              return 0;
                break;
         } }             
         return 1;
     }
    
    int Factorial(int x){
         if(x==0){
             return 1;
         }
         return x* Factorial(x-1);
     }
    
    int isStrong(int x){
        int num=x;
        int n=0,sumFac=0;
        while(x>0){
            sumFac +=Factorial(x%10);
            x=x/10;
        }
        if (sumFac==num){
                return 1;}
                return 0;
        
        }
     
    


