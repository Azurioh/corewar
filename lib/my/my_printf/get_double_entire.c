/*
** EPITECH PROJECT, 2023
** get_double_entire
** File description:
** Get the entire part of a double
*/

double get_double_entire(double nb)
{
    int divise = 100;
    double entire = 0;
    double nb_backup = nb;
    int calcul;

    if (nb < 0)
        nb *= -1;
    while (nb / divise == 0 && divise != 0) {
        divise /= 10;
    }
    while (divise > 0) {
        calcul = nb / divise;
        entire = entire * 10 + (calcul);
        nb -= calcul * divise;
        divise /= 10;
    }
    if (nb_backup < 0)
        entire *= -1;
    return entire;
}
