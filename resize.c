// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    float n = atof(argv[1]);

    if (n > 100 || n < 0)
    {
        printf("n must be a positive number less or equal then 100\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    fseek(inptr, -(sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER)), SEEK_CUR);

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bfo;
    fread(&bfo, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bio;
    fread(&bio, sizeof(BITMAPINFOHEADER), 1, inptr);

    int paddingNew;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    // determine padding for scanlines
    int padding = (4 - (bio.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    if (n != 1)
    {
        bi.biWidth = bi.biWidth * n;
        paddingNew = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
        bi.biHeight = bi.biHeight * n;
        bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + paddingNew) * abs(bi.biHeight);
        bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    }
    else
    {
        paddingNew = padding;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    if (n >= 1)
    {
        for (int i = 0, bioHeight = abs(bio.biHeight); i < bioHeight; i++)
        {
            // iterate over pixels in scanline
            for (int l = 0; l < n; l++)
            {
                for (int j = 0; j < bio.biWidth; j++)
                {
                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    for (int k = 0; k < n; k++)
                    {
                        // write RGB triple to outfile
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
                }

                // then add it back (to demonstrate how)
                for (int k = 0; k < paddingNew; k++)
                {
                    fputc(0x00, outptr);
                }

                if (l < (n - 1))
                {
                    int back = -bio.biWidth * sizeof(RGBTRIPLE);
                    fseek(inptr, back, SEEK_CUR);
                }
                else
                {

                    // skip over padding, if any
                    fseek(inptr, padding, SEEK_CUR);
                }
            }
        }
    }
    else
    {
        int p = ceil(1 / n);
        for (int i = 0, bioHeight = (abs(bio.biHeight) / p); i < bioHeight; i++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bio.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                if (j % p == 0)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // then add it back (to demonstrate how)
            for (int k = 0; k < paddingNew; k++)
            {
                fputc(0x00, outptr);
            }
            int forward = (bio.biWidth * sizeof(RGBTRIPLE) + (padding * 2)) * (p - 1);
            fseek(inptr, forward, SEEK_CUR);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}