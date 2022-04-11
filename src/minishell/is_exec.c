/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** fis_exec
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

#include "my.h"
#include "minishell.h"

int is_exec(char *fp)
{
    struct stat *file = my_memset(sizeof(struct stat), NULL);

    if (stat(fp, file) == -1) {
        free(file);
        return 84;
    }
    if (file->st_mode & S_IXUSR && file->st_mode & S_IFREG) {
        free(file);
        return 1;
    }
    free(file);
    return 0;
}
