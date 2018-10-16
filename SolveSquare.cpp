///@name SolveSquare
///@version 1
///@author Ivan Shargin, phystech
///@date 11.10.18
#include <stdio.h>
#include <math.h>

//======================================================
const int    INFINITE = -1,///< Substitute of infinity
             STRANGEnRoots = -2;///< Error code associated with invalid number of roots

//======================================================

/**
Gets coefficients of quadratic equation from console.
If it's format is invalid, give new chance to enter coefficients.
@param[out] a,b,c coefficients of quadratic equation a*X^2 + b*X + c = 0
*/
int GetCoefficients(double* a, double* b, double* c);

/**
Solve quadratic equation (a*X^2 + b*X + c = 0) if a!==0
or calls function SolveLinear if a==0.
@param[in] a,b,c  Coefficients of equation a*X^2 + b*X + c = 0
@param[out] x1,x2 Roots of equation
@return Number of roots
*/
int SolveSquare(double a, double b, double c, double* x1, double* x2);

/**
Solve linear equation.
@param[in] b,c Coefficients of linear equation b*X + c = 0
@param[out] x  Root of equation
@return Number of roots
*/
int SolveLinear(double b, double c, double* x);

//=====================================================
/**
@param[in] a,b,c Coefficients of quadratic equation a*x^2+b*x+c=0.
@param[out] x1,x2 First root, second root of equation. If there is only one root, program uses x1.
@param[in] nRoots Number of roots.
*/
int main()
{

    double a = NAN,b = NAN,c = NAN;
    double x1 = NAN,x2 = NAN;
    int    nRoots = STRANGEnRoots;

//.............................
    printf("#Square equation solver. version 1 by Ivanko Shargin\n\n");

    GetCoefficients(&a, &b, &c);

    nRoots=SolveSquare(a,b,c,&x1,&x2);

    switch (nRoots)
    {
    case 1:
        printf("One root in this equation x=%lg\n",x1);
        break;

    case 2:
        printf("first root  x1=%lg;\nsecond root x2=%lg\n",x1,x2);
        break;

    case 0:
        printf("No roots\n");
        break;

    case INFINITE:
        printf("Infinite number of roots\n");
        break;

    default:
        printf("Strange number of roots nRoots=%i in SolveSquare(%lg,%lg,%lg,&x1,&x2)\n",nRoots,a,b,c);
        return STRANGEnRoots;
    }

    return 0;
}

//======================================================


int GetCoefficients(double* a,double* b,double* c)
{
    for(;;)
    {
        printf("Enter coefficients(a*x^2+b*x+c=0) a,b,c and press <<enter>> :\n");

        if ( (scanf("%lg %lg %lg",a,b,c) ==  3) && (isfinite(*a)) && (isfinite(*b)) && (isfinite(*c)) ) break;

        scanf("%*[^\n]");

        printf("\nInvalid format of coefficients, try again. Ne durachitsya!\n");
    }
}


int SolveSquare(double a,double b,double c,double* x1,double* x2)
{
    if (a == 0) return SolveLinear(b,c,x1);

    double discriminant = b*b-4.0*a*c;

    if (discriminant>0)
    {
        double sqrtdis=sqrt(discriminant);
        *x1 = (-b+sqrtdis)/(2.0*a);
        *x2 = (-b-sqrtdis)/(2.0*a);
        return 2;
    }

    if (discriminant == 0)
    {
        *x1 = -b/(2.0*a);
        return 1;
    }

    if (discriminant<0) return 0;
}


int SolveLinear(double b,double c,double* x)
{
    if (b == 0)
        if (c == 0) return INFINITE;
        else
        return 0;

    {
        *x = -c/b;
        return 1;
    }
}
