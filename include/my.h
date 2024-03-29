/*
** EPITECH PROJECT, 2021
** cpoolday09 task02
** File description:
** libmy.a header
*/

#ifndef MY_H_
    #define MY_H_

    void my_putchar(char c);
    char *my_strstr(char *str, char const *to_find);
    int my_isneg(int nb);
    int my_strcmp(char const *s1, char const *s2);
    void my_put_nbr(int nb);
    void my_put_lnbr(long int nb);
    int my_strncmp(char const *s1, char const *s2, int n);
    void my_swap(int *a, int *b);
    char *my_strupcase(char *str);
    void my_putstr(char const *str);
    char *my_strlowcase(char *str);
    int my_strlen(char const *str);
    char *my_strcapitalize(char *str);
    int my_getnbr(char const *str);
    int my_str_isalpha(char const *str);
    void my_sort_int_array(int *tab, int size);
    int my_str_isnum(char const *str);
    int my_compute_power_rec(int nb, int power);
    int my_str_islower(char const *str);
    int my_compute_square_root(int nb);
    int my_str_isupper(char const *str);
    int my_is_prime(int nb);
    int my_str_isprintable(char const *str);
    int my_find_prime_sup(int nb);
    int my_showstr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    int my_showmem(char const *str, int size);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strcat(char *dest, char const *src);
    char *my_revstr(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    void *my_memset(int size, char *str);
    int my_put_error(char *str);
    void my_printf(char *str, ...);
    int my_get_base(char *number, char *base);
    char *my_strdup(char *src);
    char *my_strndup(char *src, int length);
    int my_arrlen(void **tab);
    void *my_null_error(char *str);
    int free_array(void **array);
    int show_array(char **array);

#endif
