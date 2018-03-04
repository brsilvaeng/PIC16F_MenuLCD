#ifndef TYPES_H
#define	TYPES_H

//#include <stdint.h>

#define null                (0)

typedef unsigned char       uint8;
typedef unsigned short int  uint16;
typedef unsigned long int   uint32;
typedef unsigned long long  uint64;

typedef signed char         int8;
typedef signed short int    int16;
typedef signed long int     int32;
typedef signed long long    int64;

typedef uint8               socket;

typedef union {
    uint8 val;
    struct {
        uint8 b0:1;
        uint8 b1:1;
        uint8 b2:1;
        uint8 b3:1;
        uint8 b4:1;
        uint8 b5:1;
        uint8 b6:1;
        uint8 b7:1;
    } bits;
} uint8_val, uint8_bits;


typedef union {
    uint16 val;
    uint8 v[2];
    struct {
        uint8 LB;
        uint8 HB;
    } byte;
    struct {
        uint8 b0:1;
        uint8 b1:1;
        uint8 b2:1;
        uint8 b3:1;
        uint8 b4:1;
        uint8 b5:1;
        uint8 b6:1;
        uint8 b7:1;
        uint8 b8:1;
        uint8 b9:1;
        uint8 b10:1;
        uint8 b11:1;
        uint8 b12:1;
        uint8 b13:1;
        uint8 b14:1;
        uint8 b15:1;
    } bits;
} uint16_val, uint16_bits;


typedef union {
    uint32 val;
    uint16 w[2];
    uint8  v[4];
    struct {
        uint16 LW;
        uint16 HW;
    } word;
    struct {
        uint8 LB;
        uint8 HB;
        uint8 UB;
        uint8 MB;
    } byte;
    struct {
        uint8 b0:1;
        uint8 b1:1;
        uint8 b2:1;
        uint8 b3:1;
        uint8 b4:1;
        uint8 b5:1;
        uint8 b6:1;
        uint8 b7:1;
        uint8 b8:1;
        uint8 b9:1;
        uint8 b10:1;
        uint8 b11:1;
        uint8 b12:1;
        uint8 b13:1;
        uint8 b14:1;
        uint8 b15:1;
        uint8 b16:1;
        uint8 b17:1;
        uint8 b18:1;
        uint8 b19:1;
        uint8 b20:1;
        uint8 b21:1;
        uint8 b22:1;
        uint8 b23:1;
        uint8 b24:1;
        uint8 b25:1;
        uint8 b26:1;
        uint8 b27:1;
        uint8 b28:1;
        uint8 b29:1;
        uint8 b30:1;
        uint8 b31:1;
    } bits;
} uint32_val, uint32_bits;

typedef union
{
    uint64 val;
    uint32 l[2];
    uint16 w[4];
    uint8 v[8];
    struct {
        uint32 LD;
        uint32 HD;
    } dword;
    struct {
        uint16 LW;
        uint16 HW;
        uint16 UW;
        uint16 MW;
    } word;
    struct {
        uint8 b0:1;
        uint8 b1:1;
        uint8 b2:1;
        uint8 b3:1;
        uint8 b4:1;
        uint8 b5:1;
        uint8 b6:1;
        uint8 b7:1;
        uint8 b8:1;
        uint8 b9:1;
        uint8 b10:1;
        uint8 b11:1;
        uint8 b12:1;
        uint8 b13:1;
        uint8 b14:1;
        uint8 b15:1;
        uint8 b16:1;
        uint8 b17:1;
        uint8 b18:1;
        uint8 b19:1;
        uint8 b20:1;
        uint8 b21:1;
        uint8 b22:1;
        uint8 b23:1;
        uint8 b24:1;
        uint8 b25:1;
        uint8 b26:1;
        uint8 b27:1;
        uint8 b28:1;
        uint8 b29:1;
        uint8 b30:1;
        uint8 b31:1;
        uint8 b32:1;
        uint8 b33:1;
        uint8 b34:1;
        uint8 b35:1;
        uint8 b36:1;
        uint8 b37:1;
        uint8 b38:1;
        uint8 b39:1;
        uint8 b40:1;
        uint8 b41:1;
        uint8 b42:1;
        uint8 b43:1;
        uint8 b44:1;
        uint8 b45:1;
        uint8 b46:1;
        uint8 b47:1;
        uint8 b48:1;
        uint8 b49:1;
        uint8 b50:1;
        uint8 b51:1;
        uint8 b52:1;
        uint8 b53:1;
        uint8 b54:1;
        uint8 b55:1;
        uint8 b56:1;
        uint8 b57:1;
        uint8 b58:1;
        uint8 b59:1;
        uint8 b60:1;
        uint8 b61:1;
        uint8 b62:1;
        uint8 b63:1;
    } bits;
} uint64_val, uint64_bits;

#endif

