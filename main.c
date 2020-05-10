#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LDE {
	int		info;

	struct LDE 	*proximo;
	struct LDE	*anterior;
};

// declaração dos ponteiros de controle
struct no *inicio;
struct no *fim;

int main (void)
{
	printf ("%d\n", sizeof(struct LDE));
	return 0;
}
