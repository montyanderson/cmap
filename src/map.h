#include <stdbool.h>

typedef struct map_node_s {
	char *key;
	char *value;
	struct map_node_s *next;
} map_node_t;

typedef struct {
	map_node_t *first;
} map_t;

map_t *map_create();
void map_set(map_t *map, char *key, char *value);
char *map_get(map_t *map, char *key);
