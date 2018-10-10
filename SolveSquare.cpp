#include <stdio.h>
#include <math.h>


//=====================================================
const int    INFINITE=-1,//infinite number of roots(nRoots)
             STRANGEnRoots=-2;
const char

//======================================================
int SolveSquare(double a,double b,double c,double* x1,double* x2);
int SolveLinear(double b,double c,double* x);//function for a=0

//=====================================================
int main()
{
  int    nRoots=STRANGEnRoots;//number of roots
  double x1=NAN,x2=NAN;//first root and second root(if there is one root program uses x1)
  double a=NAN,b=NAN,c=NAN;//coefficients of square equation a*x^2+b*x+c=0
//.............................
  printf("#Square equation solver. version 1.1(c) by Ivanko Shargin\n");
  printf("Enter coefficients(a*x^2+b*x+c=0) a,b,c:\n");
  scanf("%lg %lg %lg",&a,&b,&c);

  nRoots=SolveSquare(a,b,c,&x1,&x2);

  switch (nRoots)
  {
    case 1:        printf("One root in this equation x=%lg\n",x1);break;

    case 2:        printf("first root x1=%lg; second root x2=%lg\n",x1,x2);break;

    case 0:        printf("No roots\n");break;

    case INFINITE:       printf("Infinite number of roots\n");break;

    default:       printf("Strange number of roots nRoots=%i in SolveSquare(%lg,%lg,%lg,&x1,&x2)\n",nRoots,a,b,c);
                   return STRANGEnRoots;
  }

  return 0;
}

//======================================================
int SolveSquare(double a,double b,double c,double* x1,double* x2)
{
  if (a==0) return SolveLinear(b,c,x1);

  double discriminant=b*b-4.0*a*c;

  if (discriminant>0)
  {
    double sqrtdis=sqrt(discriminant);
           *x1=(-b+sqrtdis)/(2.0*a);
           *x2=(-b-sqrtdis)/(2.0*a);
           return 2;
  }

  if (discriminant==0)
  {
           *x1=-b/(2.0*a);
           return 1;
  }

  if (discriminant<0) return 0;
}

int SolveLinear(double b,double c,double* x)
{
  if ((b==0) && (c==0))  return INFINITE;
  if ((b==0) && !(c==0)) return 0;

  {
    *x=-c/b;
    return 1;
  }
}
# SolveSquare
