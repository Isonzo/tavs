#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LENGTH 4096
#define MAX_FILES 128
typedef struct
{
    char* path;
    char* name;
}file_t;

int cmpr_file(const void* a, const void* b)
{
    file_t file_a = *(file_t*)a;
    file_t file_b = *(file_t*)b;

    if (strcmp(file_a.name, "main.c"))
            return 1;
    if (strcmp(file_b.name, "main.c"))
            return -1;

    return strcmp(file_a.name, file_b.name);
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <file1> <file2> ...\n", argv[0]);
        return 2;
    }

    if (argc >= MAX_FILES)
    {
        fprintf(stderr, "Too many files! Current set limit: %d\n", MAX_FILES);
    }

    char command[MAX_CMD_LENGTH] = { 0 };
    strcpy(command, "nvim -c \"");

    file_t files[MAX_FILES];


    for (int i = 0; i < argc - 1; ++i)
    {
        // Seperate out file names and make them not have prepending '/'
        char* dir = argv[i + 1];
        char* name = NULL;
        if ((name = strrchr(argv[i + 1], '/')))
            name = name + 1;
        else
            name = argv[i + 1];

        files[i] = (file_t) { dir, name };
    }

    qsort(files, argc - 1, sizeof(file_t), cmpr_file);

    file_t prev = files[0];
    for (int i = 1; i < argc - 1; ++i)
    {
        char* extension_prev = strrchr(prev.name, '.');
        char* extension = strrchr(files[i].name, '.');

        char* compare_prev = NULL;
        char* compare = NULL;

        if (!extension_prev)
            compare_prev = extension_prev;

        if (!extension)
            compare = extension;

        int length_prev = extension_prev - prev.name;
        int length = extension - files[i].name;

        if (strncmp(prev.name, files[i].name, length_prev < length ? length_prev : length))
        {
            strcat(command, "tabe ");
            strcat(command, prev.path);
            strcat(command, "|");
            prev = files[i];
            continue;
        }

        strcat(command, "tabe ");
        strcat(command, prev.path);
        strcat(command, "|");
        strcat(command, "vsplit ");
        strcat(command, files[i].path);
        strcat(command, "|");

        prev = files[++i];
    }

    strcat(command, "tabfirst|tabclose\"");
    system(command);
    return 0;
}
