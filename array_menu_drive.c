#include <stdio.h>
#include<stdlib.h>
#define len 100

void Display(int *, int);
int CountOdd(int *,int);
int FindSmallest(int *, int );
void Reverse(int *, int );
void PrintFrequency(int *, int);
void Replace( int *, int , int ,int);
int SearchPrime(int *,int );

int main()
{
	int arr[len],i,n,ch,x,y,no,small,prime_pos;
	printf("\tEnter size of array: ");
	scanf("%d",&n);

	printf("\n\tEnter elements of the array: ");
	for(i=0;i<n;i++) 
    {
		scanf(" %d",&arr[i]);
	}

	do
	{
		printf("\n\t1. Display\n\t2. Count Odd\n\t3. Find Smallest\n\t4. Reverse\n\t5. Print Frequency\n\t6. Replace\n\t7. Search Prime\n\t8. EXIT \n\n");
		printf("\n\tEnter any choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				Display(&arr[0], n);
				break;
			case 2:
				no= CountOdd(&arr[0], n);
				printf("\tCount of odd elements: %d\n",no);
				break;
			case 3:
				small=FindSmallest(&arr[0], n);
				printf("\tSmallest element: %d\n",small);
				break;
			case 4:
				Reverse(&arr[0], n);
				Display(&arr[0], n);
				break;
			case 5:
				PrintFrequency(&arr[0], n);
				break;
			case 6:
				printf("\tEnter number to replace: ");
				scanf("%d",&x);
				printf("\tEnter the number to be replaced with previous input: ");
				scanf("%d",&y);
				Replace(&arr[0], n, x, y);
				Display(&arr[0], n);
				break;
			case 7:
				prime_pos=SearchPrime(&arr[0],n);
				if(prime_pos !=-1)
					printf("\tPosition of the prime number: %d \n",prime_pos);
				else
					printf("\t\tNO PRIME NUMBER.\n");
				break;
			case 8:
				break;
			default:
				printf("\n\tInvalid Input!Try again\n");
				break;
		}

	}while(ch!=8);

    return 0;
}

void Display(int *ptr, int a)
{
	int i;
	printf("\tArray formed: ");
	for(i=0;i<a;i++)
	{
		printf("\t%d\t",*(ptr+i));
	}
}

int CountOdd(int *ptr,int a)
{
	int i,c=0;
	for(i=0;i<a;i++)
	{
		if(*(ptr+i)%2==1)
			c++;

	}
	return c;
}

int FindSmallest(int *ptr, int a)
{
	int i,smallest=*ptr;
	for(i=0;i<a;i++)
	{
		if(*(ptr+i)< smallest)
			smallest=*(ptr+i);

	}
	return smallest;

}

void Reverse(int *ptr, int a)
{
	int i,temp;
	for(i=0;i<a/2;i++)
	{
		temp=*(ptr+i);
		*(ptr+i)=*(ptr+a-i-1);
		*(ptr+a-i-1)=temp;
	}
}

void PrintFrequency(int *ptr, int a)
{
	int i,c,j;
    int b[a];
	for(i=0; i<a; i++)
    {
        c=1;
        if(b[i]==1)
        	continue;

		for(j=i+1; j<=a; j++)
        {
           if((ptr+j)==(ptr+i))
            {
		       ++c;
		       b[j]=1;
		    }
	    }
	    printf("\tFrequency of %d is %d\n",*(ptr+i), c);
	}
}
void Replace( int *ptr, int a, int x,int y)
{
	int i;
	for(i=0;i<a;i++)
	{
		if(*(ptr+i)==x)
			*(ptr+i)=y;
	}

}
int SearchPrime(int *ptr,int a)
{
	int i,j,c;
	for(i=0;i<a;i++)
	{
		c=0;
		for(j=1;j<=*(ptr+i);j++)
		{
			if(*(ptr+i)%j==0)
				c++;
		}
		if(c==2)
			return i;
	}
	return -1;
}