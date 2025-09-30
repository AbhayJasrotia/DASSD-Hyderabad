#include <stdio.h>
typedef struct complex{
    float real;
    float img;
}complex;
complex addcomplexnumbers(complex s1,complex s2)
{
    complex res;
    res.real=s1.real+s2.real;
    res.img=s1.img+s2.img;
    return res;
}
complex subtractcomplexnumbers(complex s1,complex s2)
{
    complex res;
    res.real=s1.real-s2.real;
    res.img=s1.img-s2.img;
    return res;
}
int main()
{
    complex s1,s2,sum,diff;
    printf("Enter the real and imaginary aprt of the first complex number\n");
    scanf("%f %f",&s1.real,&s1.img);
    printf("Enter the real and imaginary part of the second complex numbera\n");
    scanf("%f %f",&s2.real,&s2.img);
     
    sum=addcomplexnumbers(s1,s2);
    diff=subtractcomplexnumbers(s1,s2);
    printf("Sum of complex number is=%.2f+%.2f=%2.f\n",sum.real,sum.img,sum.real+sum.img);
    printf("Difference of complex numbers is=%.2f-%.2f=%.2f\n",diff.real,diff.img,diff.real-diff.img);

    
    return 0;

    
}