/*
** EPITECH PROJECT, 2024
** instructions_list
** File description:
** Struct array for the read_instruction function
*/

#ifndef INSTRUCTIONS_LIST_H
    #define INSTRUCTIONS_LIST_H
    #include "corewar.h"

typedef struct instructions_check_s {
    int id;
    void (*function)(corewar_t *, robot_t *);
} instructions_check_t;

const instructions_check_t INSTRUCTIONS_LIST[] = {
    { 0x01, &live },
    { 0x02, NULL },
    { 0x03, &st_instruction },
    { 0x04, &add },
    { 0x05, &sub },
    { 0x06, &and_instruction },
    { 0x07, &or_instruction },
    { 0x08, &xor_instruction },
    { 0x09, NULL },
    { 0x0a, NULL },
    { 0x0b, NULL },
    { 0x0c, &fork_instruction },
    { 0x0d, NULL },
    { 0x0e, NULL },
    { 0x0f, NULL },
    { 0x10, NULL },
    { 0x00, NULL },
};

#endif
