#include "libft.h"

void update_if_superior(size_t *to_update, size_t candidate)
{
    printf("comparing degree: %zu to %zu\n", *to_update, candidate);
    if (*to_update < candidate)
        *to_update = candidate;
}