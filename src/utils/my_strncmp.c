/*
** EPITECH PROJECT, 2025
** strcmp
** File description:
** compar two strings
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int s1_value = 0;
    int s2_value = 0;

    while ((s1[i] || s2[i]) && i != n) {
        if (s1[i] != s2[i]) {
            s1_value = s1[i];
            s2_value = s2[i];
            break;
        }
        i++;
    }
    return (s1_value - s2_value);
}
