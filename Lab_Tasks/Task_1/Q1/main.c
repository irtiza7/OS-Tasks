#include <stdio.h>
#include <stdlib.h>

int isAlphabet(char ch)
{
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
    {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    FILE *input_file;
    FILE *output_file;
    char ch;

    // Opening/Creating the input and out files, and setting the file pointers to these files.
    input_file = fopen(argv[1], "r");
    output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL)
    {
        printf("File Error | Program Aborting\n");
    }
    else
    {
        // Read each character from input.txt and save it in the output.txt file if its not an alphabet.
        while ((ch = fgetc(input_file)) != EOF)
        {
            if (!(isAlphabet(ch)))
            {
                fputc(ch, output_file);
            }
        }
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}