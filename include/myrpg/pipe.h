/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** pipe communication
*/

#ifndef PIPE_
    #define PIPE_

    #include "my_str.h"


void pipe_write(str_t *, int data);

int pipe_read(str_t *);

int pipe_pop(str_t *);

void pipe_free(void);


#endif /* PIPE_ */
