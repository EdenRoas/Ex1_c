#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#define square(x) x*x

int backwards(int num)
{
    int digit = (int)log10(num);
    if(num == 0)
        return 0;

    return ((num%10 * pow(10, digit)) + backwards(num/10));
}


int isPalindrome(int num)
{
    if(num == backwards(num))
    {
        return 1;
    }
    return 0;
}
int lenghNumber(int number)
{
    return floor(log10(abs(number))) + 1;
}

int isArmstrongR(int number, int nDigits, int sum)
{   
    if(lenghNumber(number) == 1)
    {
        return pow((number % 10), nDigits);
    }
    int tmp = pow((number % 10), nDigits);
    sum = tmp + isArmstrongR(number / 10, nDigits, sum);
    return sum;
}
int isArmstrong(int number)
{
    int nDigits = lenghNumber(number), sum = 0;
    sum = isArmstrongR(number, nDigits, sum);
    if(sum == number)
    {
        // printf("is Armstrong\n");
        return 1;

    }
    else
    {
       // printf("is not Armstrong\n");
        return 0;
    }
}

//  int main(){
//         int num = isArmstrong(9473);
//         //printf("%d\n",lenghNumber(407));
//         //int x = lenghNumber(372);
//         //printf("Factorial of %d is %d", num, isPalindrome(num));
//         return 0;
//     }



