#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("Enter your string:");
	scanf("%s",str);
	int i,len = strlen(str);
	for( i=0; i<=len/2; i++)
	{
		if(str[i] != str[len-i-1])
		{
			printf("Not a Palindrome\n");
			break;
		}
	}
	if(i >= len/2)
		printf("Palindrome\n");
}
