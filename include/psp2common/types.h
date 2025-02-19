/**
 * \kernelgroup{SceTypes}
 * \usage{psp2common/types.h}
 */

#ifndef _PSP2_COMMON_TYPES_H_
#define _PSP2_COMMON_TYPES_H_

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SCE types */
typedef int8_t SceChar8;
typedef uint8_t SceUChar8;

typedef int8_t SceInt8;
typedef uint8_t SceUInt8;

typedef int16_t SceShort16;
typedef uint16_t SceUShort16;

typedef int16_t  SceInt16;
typedef uint16_t  SceUInt16;

typedef int32_t SceInt32;
typedef uint32_t SceUInt32;

typedef int32_t SceInt;
typedef uint32_t SceUInt;

typedef int64_t SceInt64;
typedef uint64_t SceUInt64;

typedef int64_t SceLong64;
typedef uint64_t SceULong64;

typedef unsigned int SceSize;
typedef int SceSSize;

typedef int SceBool;
enum {
	SCE_FALSE,
	SCE_TRUE
};

typedef float SceFloat;
typedef float SceFloat32;

typedef double SceDouble;
typedef double SceDouble64;

typedef signed char SceSByte;
typedef signed char SceSByte8;

typedef unsigned char SceByte;
typedef unsigned char SceByte8;

typedef uint16_t SceWChar16;
typedef uint32_t SceWChar32;

typedef void SceVoid;
typedef void *ScePVoid;

typedef int SceIntPtr;
typedef unsigned int SceUIntPtr;
typedef SceUIntPtr SceUIntVAddr;

typedef int SceMode;         //!< Mode for I/O functions
typedef SceInt64 SceOff;     //!< Offset type

typedef int SceUID;          //!< UIDs are used to describe many different kernel objects.
typedef int ScePID;          //!< Process ID
typedef unsigned int SceNID; //!< Library/Function NID

typedef char* SceName;       //!< Names are used to describe object names

/** 64-bit system clock type. */
typedef SceUInt64 SceKernelSysClock;


#define SCE_KERNEL_PROCESS_ID_SELF 0  //!< Current running process ID is always 0
#define SCE_UID_NAMELEN            31 //!< Maximum length for kernel object names


/* PSP2 Specific types */
typedef struct SceIVector2 {
    SceInt x;
    SceInt y;
} SceIVector2;

typedef struct SceFVector2 {
    SceFloat x;
    SceFloat y;
} SceFVector2;

typedef struct SceIVector3 {
    SceInt x;
    SceInt y;
    SceInt z;
} SceIVector3;

typedef struct SceFVector3 {
    SceFloat x;
    SceFloat y;
    SceFloat z;
} SceFVector3;

typedef struct SceIVector4 {
    SceInt x;
    SceInt y;
    SceInt z;
    SceInt w;
} SceIVector4;

typedef struct SceFVector4 {
    SceFloat x;
    SceFloat y;
    SceFloat z;
    SceFloat w;
} SceFVector4;

typedef struct SceIMatrix2 {
    SceIVector2 x;
    SceIVector2 y;
} SceIMatrix2;

typedef struct SceFMatrix2 {
    SceFVector2 x;
    SceFVector2 y;
} SceFMatrix2;

typedef struct SceIMatrix3 {
    SceIVector3 x;
    SceIVector3 y;
    SceIVector3 z;
} SceIMatrix3;

typedef struct SceFMatrix3 {
    SceFVector3 x;
    SceFVector3 y;
    SceFVector3 z;
} SceFMatrix3;

typedef struct SceIMatrix4 {
    SceIVector4 x;
    SceIVector4 y;
    SceIVector4 z;
    SceIVector4 w;
} SceIMatrix4;

typedef struct SceFMatrix4 {
    SceFVector4 x;
    SceFVector4 y;
    SceFVector4 z;
    SceFVector4 w;
} SceFMatrix4;

typedef struct SceFQuaternion {
    SceFloat x;
    SceFloat y;
    SceFloat z;
    SceFloat w;
} SceFQuaternion;

typedef struct SceFColor {
    SceFloat r;
    SceFloat g;
    SceFloat b;
    SceFloat a;
} SceFColor;

typedef struct SceFPlane {
    SceFloat a;
    SceFloat b;
    SceFloat c;
    SceFloat d;
} SceFPlane;

typedef struct SceDateTime {
    unsigned short year;
    unsigned short month;
    unsigned short day;
    unsigned short hour;
    unsigned short minute;
    unsigned short second;
    unsigned int microsecond;
} SceDateTime;


#ifdef __cplusplus
}
#endif

#endif /* _PSP2_COMMON_TYPES_H_ */
