/*
** EPITECH PROJECT, 2022
** antman
** File description:
** lzw utils
*/

#include "my_stdlib.h"
#include "my_str.h"

static const int CODES[] = {
    511, 1023, 2047, 4095, 8191, 16383, 32767,
};
static const int CODES_SIZE = sizeof(CODES) / sizeof(int);
static const unsigned int END_OF_FILE = 256;
static const int MAX_CODE_SIZE = 32767;

static int get_nb_of_bits(int code)
{
    int nb_bits = 9;

    for (int i = 0; i < CODES_SIZE; ++i) {
        if (code > CODES[i]) {
            nb_bits++;
        } else {
            break;
        }
    }

    return nb_bits;
}

static int reset_vars(
    int *avail_bits, unsigned int *pending_input, int *curr_code,
    size_t *buff_idx
)
{
    *avail_bits = 0;
    *pending_input = 0;
    *curr_code = 256;
    *buff_idx = 0;
    return 0;
}

static unsigned int shift_bitts(
    int **utils, unsigned int *pending_input, size_t *buff_idx, str_t *buff
)
{
    int *avail_bits = utils[0];
    int *nb_bits = utils[1];
    char c = 0;
    unsigned int data = 0;

    while (*avail_bits < *nb_bits) {
        if (*buff_idx >= buff->length)
            return END_OF_FILE;
        c = buff->data[(*buff_idx)++];
        *pending_input |= (c & 0xff) << *avail_bits;
        *avail_bits += 8;
    }
    data = *pending_input & ~(~0U << *nb_bits);
    *pending_input >>= *nb_bits;
    *avail_bits -= *nb_bits;
    return data;
}

int read_n_bits(str_t *buff, int reset)
{
    static int avail_bits = 0;
    static unsigned int pending_input = 0;
    static int curr_code = 256;
    static size_t buff_idx = 0;

    if (reset)
        return reset_vars(&avail_bits, &pending_input, &curr_code, &buff_idx);

    int nb_bits = get_nb_of_bits(curr_code);

    if (curr_code < MAX_CODE_SIZE)
        curr_code++;

    return shift_bitts(
        (int *[]){&avail_bits, &nb_bits}, &pending_input, &buff_idx, buff
    );
}
