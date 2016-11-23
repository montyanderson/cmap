#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void handler(char *key, char *value) {
	printf("%s:%s\n", key, value);
}

int main() {
	map_t *m = map_create();

	map_set(m, "name", "Monty");
	map_set(m, "gender", "male");

	printf("%s %s\n", map_get(m, "name"), map_get(m, "gender"));

	map_each(m, handler);
}
