#include <stdio.h>
struct Cmp
{
    float real;
    float imag;
};

typedef struct Cmp complex;

void displayComplex(complex *c);
void addComplex(complex *c1,complex *c2,complex *c3);
void subtractComplex(complex *c1,complex *c2,complex *c3);
void multiplyComplex(complex *c1,complex *c2,complex *c3);
void inputComplex(complex *c);
int main()
{
    complex c3,c1,c2;
    int ch;
    do{
        printf("\n 1.Display the Complex Number.\n 2.Add two Complex Numbers\n 3.Subtract two Complex Numbers.\n 4.Multiply two Complex Numbers\n Input 0 to the exit the menu.\n Enter your Choice: ");
        scanf(" %d",&ch);
        switch(ch)
        {
            case 1: printf(" Input the complex number(real+imaginary) to Display: ");
                    inputComplex(&c3);
                    displayComplex(&c3);
            break;
            case 2: printf(" Input the complex numbers to Add: ");
                    inputComplex(&c1);
                    inputComplex(&c2);
                    addComplex(&c1,&c2,&c3);
                    printf(" Sum is: ");
                    displayComplex(&c3);

            break;
            case 3: printf(" Input the complex numbers to Subtract: ");
                    inputComplex(&c1);
                    inputComplex(&c2);
                    subtractComplex(&c1,&c2,&c3);
                    printf(" Difference is: ");
                    displayComplex(&c3);

            break;
            case 4: printf(" Input the complex numbers to Multiply: ");
                    inputComplex(&c1);
                    inputComplex(&c2);
                    multiplyComplex(&c1,&c2,&c3);
                    printf(" Product is: ");
                    displayComplex(&c3);

            break;
            case 0 : break;
            default: printf(" Invalid Input!");
        }
        printf("\n End.Input 0 to exit or any other number to run the program again.   ");
        scanf("%d",&ch);
    }while(ch!=0);
    return 0;
}



void addComplex(complex *c1,complex *c2,complex *c3)
{
   c3->real=c1->real+c2->real;
   c3->imag=c1->imag+c2->imag;

}

void subtractComplex(complex *c1,complex *c2,complex *c3)
{
   c3->real=c1->real-c2->real;
   c3->imag=c1->imag-c2->imag;

}

void displayComplex(complex *c)
{
    if(c->imag<0)
        printf(" %.2f-i%.2f\n",c->real,0-c->imag);
    else
        printf(" %.2f+i%.2f\n",c->real,c->imag);
}

void multiplyComplex(complex *c1,complex *c2,complex *c3)
{

    c3->real=((c1->real)*(c2->real))-((c1->imag)*(c2->imag));
    c3->imag=((c1->real)*(c2->imag))+((c2->real)*(c1->imag));
}

void inputComplex(complex *c)
{
    scanf(" %f %f",&(c->real),&(c->imag));
}