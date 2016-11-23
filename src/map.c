#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "map.h"

map_t *map_create() {;
	return calloc(1, sizeof(map_t));
}

void map_set(map_t *map, char *key, char *value) {
	map_node_t *node, *step;

	step = map->first;

	while(step != NULL) {
		if(strcmp(step->key, key) == 0) {
			free(step->value);
			step->value = strdup(value);
			return;
		}

		step = step->next;
	}

	node = calloc(1, sizeof(map_node_t));

	node->key = strdup(key);
	node->value = strdup(value);

	if(map->first == NULL) {
		map->first = node;
	} else {
		map_node_t *step = map->first;

		while(step->next != NULL) {
			step = step->next;
		}

		step->next = node;
	}
}

char *map_get(map_t *map, char *key) {
	map_node_t *step = map->first;

	while(step != NULL) {
		if(strcmp(step->key, key) == 0) {
			return step->value;
		}

		step = step->next;
	}

	return NULL;
}

void map_each(map_t *map, void (*func)(char *, char *)) {
	map_node_t *step = map->first;

	while(step != NULL) {
		func(step->key, step->value);
		step = step->next;
	}
}
