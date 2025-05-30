﻿#pragma once

#include "../MinDef.h"
#include "../Rtl/Process/Process.h"
#include "../Rtl/Process/EnvironmentBlock.h"

#pragma region TEB Fast Access (Without Pointer Reference)

/* Read TEB */

#if !defined(_WIN64)

__forceinline
unsigned
__int64
NtReadCurrentTebUlonglong(
    unsigned int Offset)
{
    ULARGE_INTEGER li;

    li.LowPart = NtReadCurrentTebUlong(Offset);
    li.HighPart = NtReadCurrentTebUlong(Offset + sizeof(ULONG));
    return li.QuadPart;
}

#endif

#define NtReadTebByte(m) NtReadCurrentTebByte(UFIELD_OFFSET(TEB, m))
#define NtReadTebUshort(m) NtReadCurrentTebUshort(UFIELD_OFFSET(TEB, m))
#define NtReadTebUlong(m) NtReadCurrentTebUlong(UFIELD_OFFSET(TEB, m))
#define NtReadTebUlonglong(m) NtReadCurrentTebUlonglong(UFIELD_OFFSET(TEB, m))
#define NtReadTebUlongPtr(m) NtReadCurrentTebUlongPtr(UFIELD_OFFSET(TEB, m))
#define NtReadTebPVOID(m) NtReadCurrentTebPVOID(UFIELD_OFFSET(TEB, m))

#define NtReadTeb(m) ((FIELD_TYPE(TEB, m))(\
    FIELD_SIZE(TEB, m) == sizeof(ULONGLONG) ? NtReadTebUlonglong(m) : (\
        FIELD_SIZE(TEB, m) == sizeof(ULONG) ? NtReadTebUlong(m) : (\
            FIELD_SIZE(TEB, m) == sizeof(USHORT) ? NtReadTebUshort(m) : (\
                FIELD_SIZE(TEB, m) == sizeof(UCHAR) ? NtReadTebByte(m) :\
                    ((ULONGLONG)(NtCurrentTeb()->m))\
            )\
        )\
    )\
))

/* Write TEB */

__forceinline
void
NtWriteCurrentTebByte(
    unsigned int Offset,
    unsigned char Value)
{
#if defined(_M_X64)
    __writegsbyte
#elif defined(_M_IX86)
    __writefsbyte
#elif defined(_M_ARM64) || defined(_M_ARM64EC)
    __writex18byte
#endif
        (Offset, Value);
}

__forceinline
void
NtWriteCurrentTebUshort(
    unsigned int Offset,
    unsigned short Value)
{
#if defined(_M_X64)
    __writegsword
#elif defined(_M_IX86)
    __writefsword
#elif defined(_M_ARM64) || defined(_M_ARM64EC)
    __writex18word
#endif
        (Offset, Value);
}

__forceinline
void
NtWriteCurrentTebUlong(
    unsigned int Offset,
    unsigned int Value
    )
{
#if defined(_M_X64)
    __writegsdword
#elif defined(_M_IX86)
    __writefsdword
#elif defined(_M_ARM64) || defined(_M_ARM64EC)
    __writex18dword
#endif
        (Offset, Value);
}

__forceinline
void
NtWriteCurrentTebUlonglong(
    unsigned int Offset,
    unsigned __int64 Value)
{
#if !defined(_WIN64)
    ULARGE_INTEGER li;

    li.QuadPart = Value;
    NtWriteCurrentTebUlong(Offset, li.LowPart);
    NtWriteCurrentTebUlong(Offset + sizeof(ULONG), li.HighPart);
#else
#if defined(_M_X64)
    __writegsqword
#elif defined(_M_IX86)
    __writefsqword
#elif defined(_M_ARM64) || defined(_M_ARM64EC)
    __writex18qword
#endif
        (Offset, Value);
#endif
}

#if defined(_WIN64)
#define NtWriteCurrentTebUlongPtr NtWriteCurrentTebUlonglong
#else
#define NtWriteCurrentTebUlongPtr NtWriteCurrentTebUlong
#endif

__forceinline
void
NtWriteCurrentTebPVOID(
    unsigned int Offset,
    void* Value)
{
    NtWriteCurrentTebUlongPtr(Offset, (ULONG_PTR)Value);
}

#define NtWriteTebByte(m, val) NtWriteCurrentTebByte(UFIELD_OFFSET(TEB, m), val)
#define NtWriteTebUshort(m, val) NtWriteCurrentTebUshort(UFIELD_OFFSET(TEB, m), val)
#define NtWriteTebUlong(m, val) NtWriteCurrentTebUlong(UFIELD_OFFSET(TEB, m), val)
#define NtWriteTebUlonglong(m, val) NtWriteCurrentTebUlonglong(UFIELD_OFFSET(TEB, m), val)
#define NtWriteTebUlongPtr(m, val) NtWriteCurrentTebUlongPtr(UFIELD_OFFSET(TEB, m), val)
#define NtWriteTebPVOID(m, val) NtWriteCurrentTebPVOID(UFIELD_OFFSET(TEB, m), val)

#define NtWriteTeb(m, val) (\
    FIELD_SIZE(TEB, m) == sizeof(ULONGLONG) ? NtWriteTebUlonglong(m, (ULONGLONG)(ULONG_PTR)(val)) : (\
        FIELD_SIZE(TEB, m) == sizeof(ULONG) ? NtWriteTebUlong(m, (ULONG)(ULONG_PTR)(val)) : (\
            FIELD_SIZE(TEB, m) == sizeof(USHORT) ? NtWriteTebUshort(m, (USHORT)(ULONG_PTR)(val)) : (\
                FIELD_SIZE(TEB, m) == sizeof(UCHAR) ? NtWriteTebByte(m, (UCHAR)(ULONG_PTR)(val)) :\
                    ((void)(NtCurrentTeb()->m = (val)))\
            )\
        )\
    )\
)

#pragma endregion

#pragma region Pseudo Handles

#define NtCurrentProcess() ((HANDLE)(LONG_PTR)-1)
#define ZwCurrentProcess() NtCurrentProcess()
#define NtCurrentThread() ((HANDLE)(LONG_PTR)-2)
#define ZwCurrentThread() NtCurrentThread()
#define NtCurrentSession() ((HANDLE)(LONG_PTR)-3)
#define ZwCurrentSession() NtCurrentSession()
#define NtCurrentProcessToken() ((HANDLE)(LONG_PTR)-4) // NtOpenProcessToken(NtCurrentProcess())
#define ZwCurrentProcessToken() NtCurrentProcessToken()
#define NtCurrentThreadToken() ((HANDLE)(LONG_PTR)-5) // NtOpenThreadToken(NtCurrentThread())
#define ZwCurrentThreadToken() NtCurrentThreadToken()
#define NtCurrentThreadEffectiveToken() ((HANDLE)(LONG_PTR)-6) // NtOpenThreadToken(NtCurrentThread()) + NtOpenProcessToken(NtCurrentProcess())
#define ZwCurrentThreadEffectiveToken() NtCurrentThreadEffectiveToken()

#define NtCurrentSilo() ((HANDLE)(LONG_PTR)-1)
#define ZwCurrentSilo() NtCurrentSilo()

#pragma endregion

#pragma region Current runtime information

#define NtCurrentPeb() ((PPEB)NtReadTeb(ProcessEnvironmentBlock))
#define NtCurrentProcessId() ((HANDLE)NtReadTeb(ClientId.UniqueProcess))
#define NtCurrentThreadId() ((HANDLE)NtReadTeb(ClientId.UniqueThread))
#define NtCurrentLogonId() (NtCurrentPeb()->LogonId)
#define NtGetNtdllBase() (CONTAINING_RECORD(NtCurrentPeb()->Ldr->InInitializationOrderModuleList.Flink, LDR_DATA_TABLE_ENTRY, InInitializationOrderLinks)->DllBase)
#define NtGetImageNtHeader() ((PIMAGE_NT_HEADERS)Add2Ptr(&__ImageBase, __ImageBase.e_lfanew))

#define RtlProcessHeap() (NtCurrentPeb()->ProcessHeap)

#pragma endregion

#pragma region Machine

#define CPU_CACHE_LINE_SIZE 64

#if defined(_M_IX86)

#define CONTEXT_PC Eip
#define MACHINE_TYPE IMAGE_FILE_MACHINE_I386

#elif defined(_M_X64)

#define CONTEXT_PC Rip
#define MACHINE_TYPE IMAGE_FILE_MACHINE_AMD64

#elif defined(_M_ARM64)

#define CONTEXT_PC Pc
#define MACHINE_TYPE IMAGE_FILE_MACHINE_ARM64

#endif

#pragma endregion
