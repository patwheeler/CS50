# Questions

## What's `stdint.h`?
A header file that provides a set of typedefs which define exact-width integer types.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?
These are all typedefs; they help keep programs running the same across varying system architectures.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?
BYTE contains 1 byte (unsigned 8 bits)
DWORD contains 4 bytes (unsigned 32 bits)
LONG contains 4 bytes (signed 32 bits)
WORD contains 2 bytes (unsigned 16 bits)

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."
The first two bytes of any BMP file must be 0x42 and 0x4D, or 'BM'. 

## What's the difference between `bfSize` and `biSize`?
'bfSize' is the size of the entire image and the headers, whereas 'biSize' is the size required by the structure (aka the size of 'BITMAPFILEHEADER') and will always be 40 bytes. 

## What does it mean if `biHeight` is negative?
A negative 'biHeight' indicates the bitmap is a top-down DIB( device-independent bitmap) and its origin lies in the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?
'biBitCount'

## Why might `fopen` return `NULL` in `copy.c`?
It's possible fopen will return 'NULL' in 'copy.c' if there was an error opening the file. 

## Why is the third argument to `fread` always `1` in our code?
The third argument in 'fread' will always be 1 because that's how many elements we are reading (i.e. 1 picture).

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?
int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
int padding = (4 - (3 * 3 % 4)) % 4
int padding = (4 - 1) % 4
int padding = 3 % 4
int padding = 3;

## What does `fseek` do?
'fseek' is used to move the file pointer position to a given location. 

## What is `SEEK_CUR`?
'SEEK_CUR' indicates that the offset is realtive to the current file position. 
