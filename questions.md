# Questions

## What's `stdint.h`?

it defines differnt types of integers
## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

to find them more easy

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

8,32,32,16

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

66,77

## What's the difference between `bfSize` and `biSize`?

first is the size of the file, second size of structure

## What does it mean if `biHeight` is negative?

it's a top down bitmap

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

it could not open the picture, picture is missing 

## Why is the third argument to `fread` always `1` in our code?

because the header size is known and we want to get exactly 1 header

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

0

## What does `fseek` do?

it skips the padding

## What is `SEEK_CUR`?

TODO
