// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover n infile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    // open input file
    FILE *inptr = fopen(infile, "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    fseek(inptr, 0, SEEK_END);
    int filesize = ftell(inptr);
    fseek(inptr, 0, SEEK_SET);
    bool jpgActive = false;
    char *jpg;
    int jpg_num = 0;
    FILE *jpgNow = fopen("000.jpg", "w");
    string jpg_name = (char *) malloc(8);

    for (int i = 0; i < filesize; i = i + 512)
    {
        unsigned char buffer[512];
        fread(buffer, 1, 512, inptr);

        printf("%i\n", buffer[0]);
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            printf("Hi 1");
            //sprintf(string filename, );
            //validating name of file
            if (jpgActive)
            {
                fclose(jpgNow);
                sprintf(jpg_name, "%03i.jpg", jpg_num);
                jpgNow = fopen(jpg_name, "w");
            }
            jpgActive = true;
            jpg_num++;
            for (int j = 0; j < sizeof(buffer); j++)
            {
                fwrite(&buffer[j], 1, 1, jpgNow);
            }
            //buffer in funktion auseinander nehmen und in buffer schieben
        }
        else if (jpgActive)
        {
            for (int j = 0; j < sizeof(buffer); j++)
            {
                fwrite(&buffer[j], 1, 1, jpgNow);
            }
        }
    }

    fclose(jpgNow);
}
