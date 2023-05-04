/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** pipe communicate
*/

#include "my_map.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "myrpg/components/defs.h"

static const int INIT_PIPE_MAP_SIZE = 100;

static map_t *get_pipe_map(void)
{
    static map_t *pipe_map = NULL;

    if (pipe_map == NULL)
        pipe_map = map_create(INIT_PIPE_MAP_SIZE);

    return pipe_map;
}

void pipe_write(str_t *key, int data)
{
    map_t *pipe_map = get_pipe_map();
    vec_int_t *pipe = map_get(pipe_map, key);

    if (pipe == NULL)
        pipe = vec_create(100, sizeof(int));

    vec_pushback(&pipe, &data);
    map_set(pipe_map, key, pipe);
}

int pipe_read(str_t *key)
{
    map_t *pipe_map = get_pipe_map();
    vec_int_t *pipe = map_get(pipe_map, key);

    if (pipe == NULL || pipe->size == 0)
        return -1;

    return VEC_LAST(pipe);
}

int pipe_pop(str_t *key)
{
    map_t *pipe_map = get_pipe_map();
    vec_int_t *pipe = map_get(pipe_map, key);

    if (pipe == NULL || pipe->size == 0)
        return -1;

    int value = VEC_LAST(pipe);
    vec_popback(pipe);
    return value;
}

void pipe_free(void)
{
    map_t *pipe_map = get_pipe_map();

    map_free(pipe_map, &free);
}
