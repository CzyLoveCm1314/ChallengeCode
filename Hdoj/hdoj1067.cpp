#include<stdio.h>
#define OUT 1
#define IN 0

int strlenth(char ch[]);

int main()
{
	char ch[20];
	gets(ch);
	printf("%d\n", strlenth(ch));
	return 0;
}

int strlenth(char ch[])
{
	int i = 0, state, c;
	state = OUT;
	while ((c = getchar()) != 'EOF') {
		if (c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++i;
		}
		else
			++i;
	}
	return i;
}

