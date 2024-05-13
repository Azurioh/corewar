/*
** EPITECH PROJECT, 2024
** instructions_list
** File description:
** Struct array for the read_instruction function
*/

#ifndef INSTRUCTIONS_LIST_H
    #define INSTRUCTIONS_LIST_H
    #include "robot.h"

typedef struct instructions_check_s {
    int id;
    void (*function)(robot_t *, char *);
} instructions_check_t;

const instructions_check_t INSTRUCTIONS_LIST[] = {
    { 0x01, NULL },
    { 0x02, NULL },
    { 0x03, NULL },
    { 0x04, NULL },
    { 0x05, NULL },
    { 0x06, NULL },
    { 0x07, NULL },
    { 0x08, NULL },
    { 0x09, NULL },
    { 0x0a, NULL },
    { 0x0b, NULL },
    { 0x0c, NULL },
    { 0x0d, NULL },
    { 0x0e, NULL },
    { 0x0f, NULL },
    { 0x10, NULL },
    { 0x00, NULL },
};

#endif
