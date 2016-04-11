#pragma once		
#ifdef _WINKRNL
#include <ntifs.h>
#include <devioctl.h>
#else
#include <winioctl.h>
#endif
#include "CipherOpts.h"

typedef struct
{
	GUID DiskId;
	ECipherAlgo Algorithm;
	union
	{
		XorCipherOptions Xor;
		Aes128CipherOptions Aes128;
		Gost89CipherOptions Gost89;
		UCHAR Reserved[0x100];
	} Opts;
} EVhdVirtualDiskCipherConfigRequest;

typedef struct
{
	GUID DiskId;
} EVhdVirtualDiskCipherInfoRequest;

typedef struct
{
	GUID DiskId;
	ECipherAlgo Algorithm;
} EVhdVirtualDiskCipherInfoResponse;

typedef struct _LOG_SETTINGS {
    ULONG32 LogLevel;
    ULONG32 LogCategories;
    ULONG32 MaxFileSize;
    ULONG32 MaxKeptRotatedFiles;

    UINT8 Reserved[32];
} LOG_SETTINGS;

C_ASSERT(sizeof(LOG_SETTINGS) == 48);

#define IOCTL_VIRTUAL_DISK_SET_CIPHER		CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x2001, METHOD_IN_DIRECT, FILE_WRITE_ACCESS)	
#define IOCTL_VIRTUAL_DISK_GET_CIPHER		CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x2002, METHOD_OUT_DIRECT, FILE_READ_ACCESS)	
#define IOCTL_VIRTUAL_DISK_SET_LOGGER       CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x2003, METHOD_IN_DIRECT, FILE_WRITE_ACCESS)
#define IOCTL_VIRTUAL_DISK_GET_LOGGER       CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x2004, METHOD_OUT_DIRECT, FILE_READ_ACCESS)
