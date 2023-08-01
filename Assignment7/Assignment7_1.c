/* program  which is used to create shared Library and that Library should be loaded at runtime by the other program.
that library should contain function to perfrom the arithmatic operations like addition,Substraction,Division and Multiplication.

Author : Sudarshan darade
Date : 30/07/2023

*/

#include<stdio.h>
#include"Assignment7_1Header.h"

int Addition(int iNo1, int iNo2)
{
    int iAns = 0;

    iAns = iNo1 + iNo2;
    return iAns;
}

int Subtraction(int iNo1, int iNo2)
{
    int iAns = 0;

    iAns = iNo1 - iNo2;
    return iAns;
}

int Multiplication(int iNo1, int iNo2)
{
    int iAns = 1;

    iAns = iNo1 * iNo2;
    return iAns;
}

int Division(int iNo1, int iNo2)
{
    int iAns = 1;

    iAns = iNo1 / iNo2;
    return iAns;
}
