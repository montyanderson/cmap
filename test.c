#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main() {
	map_t *m = map_create();

	map_set(m, "name", "Monty");
	map_set(m, "gender", "male");

	char *name = map_get(m, "name");
	char *gender = map_get(m, "gender");

	printf("%s %s\n", name, gender);

	free(name);
	free(gender);
}
