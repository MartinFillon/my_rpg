/*
** EPITECH PROJECT, 2022
** antman
** File description:
** lzw decoding
*/

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"

int read_n_bits(str_t *buff, int reset);

static const unsigned int END_OF_FILE = 256;
static const int CODE_MAX_SIZE = 32767;

static vec_str_t *init_dict(void)
{
    vec_str_t *dict = (vec_str_t *)vec_create(CODE_MAX_SIZE, sizeof(str_t *));

    my_memset(dict->data, 0, dict->capacity * dict->_elem_size);

    for (int i = 0; i <= 255; ++i) {
        dict->data[i] = str_create("");
        str_cadd(&dict->data[i], i);
    }

    return dict;
}

static void dict_free(vec_str_t *dict)
{
    for (size_t i = 0; i <= (size_t)CODE_MAX_SIZE; ++i)
        if (dict->data[i] != NULL)
            free(dict->data[i]);
    free(dict);
}

static void add_new_code_entry(
    vec_str_t *dict, int code, int *new_code, str_t *prev
)
{
    if (prev->length > 0 && *new_code <= CODE_MAX_SIZE) {
        if (dict->data[*new_code] == NULL)
            dict->data[*new_code] = str_create("");

        str_clear(&dict->data[*new_code]);
        str_sadd(&dict->data[*new_code], prev);
        str_cadd(&dict->data[*new_code], dict->data[code]->data[0]);
        (*new_code)++;
    }
}

static void add_new_entry(vec_str_t *dict, int code, str_t *prev)
{
    if (dict->data[code] == NULL) {
        dict->data[code] = str_create("");

        str_sadd(&dict->data[code], prev);
        str_cadd(&dict->data[code], prev->data[0]);
    }
}

str_t *decompress_string(str_t *compressed_str)
{
    read_n_bits(NULL, 1);
    vec_str_t *dict = init_dict();
    str_t *prev = str_create("");
    str_t *buffer = str_create("");
    int code = 0;
    int new_code = 257;

    while ((code = read_n_bits(compressed_str, 0)) != (int)END_OF_FILE) {
        if (code > CODE_MAX_SIZE)
            return buffer;
        add_new_entry(dict, code, prev);
        str_sadd(&buffer, dict->data[code]);
        add_new_code_entry(dict, code, &new_code, prev);
        str_sadd(str_clear(&prev), dict->data[code]);
    }
    dict_free(dict);
    free(prev);
    return buffer;
}
