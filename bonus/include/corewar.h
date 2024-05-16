/*
** EPITECH PROJECT, 2024
** corewar.h
** File description:
** All include, struct and protos of the corewar project
*/

#ifndef COREWAR_H
    #define COREWAR_H
    #include "my.h"
    #include "op.h"
    #include "robot.h"

    #include <stdlib.h>
    #include <stddef.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdbool.h>

    #define READ_INDEX robot->read_index
    #define MEMORY corewar->memory

typedef struct memory_s {
    unsigned char memory;
    unsigned char *author;
} memory_t;

typedef struct corewar_s {
    memory_t *memory;
    robot_t **robots;
    robot_t *last_robot_alive;
    int carry;
    int nbr_cycle;
    int dump_nbr;
    int nbr_robots;
    int nbr_live;
    int is_dump;
} corewar_t;

corewar_t *init_corewar(void);
int corewar(int argc, char **argv);
int read_file(char *filepath, unsigned char **buff);
int parse_args(int argc, char **argv, corewar_t *corewar);
int my_str_isnum(char const *str);
int is_corfile(char *str);
int is_file_exist(char *filepath);
int fill_robots(char **argv, corewar_t *corewar);
char *read_coding_byte(int byte);

int manage_cycles(corewar_t *corewar);
void dump_memory(corewar_t *corewar);
void conv_hexa(unsigned int nb, char *str);

op_t get_operation_info(char *name);
void read_instruction(corewar_t *corewar, robot_t *robot);
int get_address(int index);
int get_address_value(memory_t *memory, int index);
int read_parameters_with_cbyte(memory_t *memory, char coding_byte,
    int read_index);
int get_movement_size_with_cbyte(char coding_byte);
char *place_robot_in_arena(corewar_t *corewar);

void live(corewar_t *corewar, robot_t *robot);
void add(corewar_t *corewar, robot_t *robot);
void sub(corewar_t *corewar, robot_t *robot);
void st_instruction(corewar_t *corewar, robot_t *robot);
void fork_instruction(corewar_t *corewar, robot_t *robot);
void lfork_instruction(corewar_t *corewar, robot_t *robot);
void ld_instruction(corewar_t *corewar, robot_t *robot);
void and_instruction(corewar_t *corewar, robot_t *robot);
void or_instruction(corewar_t *corewar, robot_t *robot);
void xor_instruction(corewar_t *corewar, robot_t *robot);
void lld_instruction(corewar_t *corewar, robot_t *robot);
void ldi_instruction(corewar_t *corewar, robot_t *robot);
void lldi_instruction(corewar_t *corewar, robot_t *robot);
void sti_instruction(corewar_t *corewar, robot_t *robot);
void aff(corewar_t *corewar, robot_t *robot);
void zjmp(corewar_t *corewar, robot_t *robot);

bool register_is_valid(int register_nb);
int convert_2bytes(memory_t *memory, int index);
int convert_4bytes(memory_t *memory, int index);
int convert_xbytes(memory_t *memory, int index, int nb_read);
int *convert_to_4bytes(int bitshift);
void register_to_memory(corewar_t *corewar, int index, int value,
    robot_t *robot);
#endif
