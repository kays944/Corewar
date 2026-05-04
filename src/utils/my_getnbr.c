/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** renvoi un string en chiffre
*/

int my_getnbr(char const *str)
{
    int NN = 0;
    int i = 0;
    int long final = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            NN++;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        if ((final * 10) + (str[i] - 48) > 2147483648 && NN % 2 != 0)
            return 0;
        if ((final * 10) + (str[i] - 48) > 2147483647 && NN % 2 == 0)
            return 0;
        final = (final * 10) + (str[i] - 48);
        i++;
    }
    if (NN % 2 != 0)
        final = -final;
    return (final);
}
