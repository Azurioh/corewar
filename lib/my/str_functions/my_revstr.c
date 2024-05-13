/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** reverse a string
*/
int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void swap(char *a, char *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

char *my_revstr(char *str)
{
    int mid;
    int i = 0;
    int j = my_strlen2(str) - 1;

    mid = my_strlen2(str) / 2;
    while (i < mid) {
        swap(&str[i], &str[j]);
        i++;
        j--;
    }
    return (str);
}
