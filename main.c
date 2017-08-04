#include <stdio.h>
#include <memory.h>

void strip_ext(char *fname)
{
    char *end = fname + strlen(fname);

    while (end > fname && *end != '.') {
        --end;
    }

    if (end > fname) {
        *end = '\0';
    }
}

int main (int argc, char **argv){
    FILE *input_file;
    FILE *output_file;
    char *input = argv[1];
    char line[256];
    char output_name[100];

    strcat(output_name, input);
    strip_ext(output_name);
    strcat(output_name, ".csv");

    printf("output_file[%s]",output_name);


    input_file = fopen(input, "r");
    output_file = fopen(output_name, "w");

    if (input_file == 0)
    {
        //fopen returns 0, the NULL pointer, on failure
        perror("Cannot open input file\n");
        return(-1);
    }
    else
    {
        while (fgets(line, sizeof(line), input_file)) {
            /* note that fgets don't strip the terminating \n, checking its
               presence would allow to handle lines longer that sizeof(line) */
            //printf("%s", line);
            char *pos;
            if ((pos=strchr(line, '\n')) != NULL)
                *pos = ',';
            fputs(line, output_file);
        }
        //fputs("deplored", output_file);
        //fputs("utopia", output_file);


    }
    fclose(input_file);
    fclose(output_file);

    return 0;
}