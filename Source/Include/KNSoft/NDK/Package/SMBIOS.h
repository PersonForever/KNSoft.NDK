﻿/*
 * KNSoft.NDK SMBIOS.h package, licensed under the MIT license.
 * Copyright (c) KNSoft.org (https://github.com/KNSoft). All rights reserved.
 *
 * SMBIOS Specification (https://www.dmtf.org/standards/smbios)
 *
 * V3.7.1 https://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.7.1.pdf
 */

#pragma once

#include <minwindef.h>

typedef unsigned __int64 QWORD, near* PQWORD, far* LPQWORD;

// MS-Spec: nonstandard extension used: zero-sized array in struct/union
#pragma warning(disable: 4200)

#pragma pack(push, 1)

typedef enum _SMBIOS_INFORMATION_TYPE
{
    SMBIOSBIOSInformation = 0,
    SMBIOSSystemInformation = 1,
    SMBIOSBaseboardInformation = 2,
    SMBIOSSystemEnclosureOrChassis = 3,
    SMBIOSProcessorInformation = 4,
    SMBIOSMemoryControllerInformation = 5, /* Obsolete */
    SMBIOSMemoryModuleInformation = 6, /* Obsolete */
    SMBIOSCacheInformation = 7,
    SMBIOSPortConnectorInformation = 8,
    SMBIOSSystemSlots = 9,
    SMBIOSOnBoardDevicesInformation = 10, /* Obsolete */
    SMBIOSOEMStrings = 11,
    SMBIOSSystemConfigurationOptions = 12,
    SMBIOSBIOSLanguageInformation = 13,
    SMBIOSGroupAssociations = 14,
    SMBIOSSystemEventLog = 15,
    SMBIOSPhysicalMemoryArray = 16,
    SMBIOSMemoryDevice = 17,
    SMBIOS32BitMemoryErrorInformation = 18,
    SMBIOSMemoryArrayMappedAddress = 19,
    SMBIOSMemoryDeviceMappedAddress = 20,
    SMBIOSBuiltinPointingDevice = 21,
    SMBIOSPortableBattery = 22,
    SMBIOSSystemReset = 23,
    SMBIOSHardwareSecurity = 24,
    SMBIOSSystemPowerControls = 25,
    SMBIOSVoltageProbe = 26,
    SMBIOSCoolingDevice = 27,
    SMBIOSTemperatureProbe = 28,
    SMBIOSElectricalCurrentProbe = 29,
    SMBIOSOutOfBandRemoteAccess = 30,
    SMBIOSBootIntegrityServicesEntryPoint = 31,
    SMBIOSSystemBootInformation = 32,
    SMBIOS64BitMemoryErrorInformation = 33,
    SMBIOSManagementDevice = 34,
    SMBIOSManagementDeviceComponent = 35,
    SMBIOSManagementDeviceThresholdData = 36,
    SMBIOSMemoryChannel = 37,
    SMBIOSIPMIDeviceInformation = 38,
    SMBIOSSystemPowerSupply = 39,
    SMBIOSAdditionalInformation = 40,
    SMBIOSOnboardDevicesExtendedInformation = 41,
    SMBIOSManagementControllerHostInterface = 42,
    SMBIOSTPMDevice = 43,
    SMBIOSProcessorAdditionalInformation = 44,
    SMBIOSFirmwareInventoryInformation = 45,
    SMBIOSStringProperty = 46,
    SMBIOSInactive = 126,
    SMBIOSEndOfTable = 127
} SMBIOS_INFORMATION_TYPE, *PSMBIOS_INFORMATION_TYPE;

/* aka RawSMBIOSData */
typedef struct _SMBIOS_RAWDATA
{
    BYTE Used20CallingMethod;
    BYTE SMBIOSMajorVersion;
    BYTE SMBIOSMinorVersion;
    BYTE DmiRevision;
    DWORD Length;
    _Field_size_bytes_(Length) BYTE SMBIOSTableData[]; // PSMBIOS_TABLE_HEADER
} SMBIOS_RAWDATA, *PSMBIOS_RAWDATA;

typedef struct _SMBIOS_TABLE_HEADER
{
    BYTE Type;
    BYTE Length;
    WORD Handle;
} SMBIOS_TABLE_HEADER, *PSMBIOS_TABLE_HEADER;
C_ASSERT(sizeof(SMBIOS_TABLE_HEADER) == 4);

typedef struct _SMBIOS_TABLE
{
    SMBIOS_TABLE_HEADER Header;
    union
    {
        struct
        {
            BYTE Vendor;
            BYTE Version;
            WORD StartingAddressSegment;
            BYTE ReleaseDate;
            BYTE ROMSize;
            union
            {
                QWORD Characteristics;
                struct
                {
                    QWORD Reserved0 : 1;                    /* 00 Reserved */
                    QWORD Reserved1 : 1;                    /* 01 Reserved */
                    QWORD Unknown0 : 1;                     /* 02 Unknown */
                    QWORD CharacteristicsNotSupported : 1;  /* 03 BIOS Characteristics are not supported */
                    QWORD ISA : 1;                          /* 04 ISA is supported */
                    QWORD MCA : 1;                          /* 05 MCA is supported */
                    QWORD EISA : 1;                         /* 06 EISA is supported */
                    QWORD PCI : 1;                          /* 07 PCI is supported */
                    QWORD PCCard : 1;                       /* 08 PC card (PCMCIA) is supported */
                    QWORD PNP : 1;                          /* 09 Plug and Play is supported */
                    QWORD APM : 1;                          /* 10 APM is supported */
                    QWORD Upgradeable : 1;                  /* 11 BIOS is upgradeable (Flash) */
                    QWORD ShadowingIsAllowed : 1;           /* 12 BIOS shadowing is allowed */
                    QWORD VL_VESA : 1;                      /* 13 VL-VESA is supported */
                    QWORD ESCD : 1;                         /* 14 ESCD support is available */
                    QWORD BootFromCD : 1;                   /* 15 Boot from CD is supported */
                    QWORD SelectableBoot : 1;               /* 16 Selectable boot is supported */
                    QWORD ROMIsSocketed : 1;                /* 17 BIOS ROM is socketed (e.g., PLCC or SOP socket) */
                    QWORD BootFromPCCard : 1;               /* 18 Boot from PC card (PCMCIA) is supported */
                    QWORD EDDSpecification : 1;             /* 19 EDD specification is supported */
                    QWORD FloppyForNEC9800_1Dot2MB : 1;     /* 20 Int 13h — Japanese floppy for NEC 9800 1.2 MB (3.5”, 1K bytes/sector, 360 RPM) is supported */
                    QWORD FloppyForToshiba_1Dot2MB : 1;     /* 21 Int 13h — Japanese floppy for Toshiba 1.2 MB (3.5”, 360 RPM) is supported */
                    QWORD Floppy_5Dot25Inch_360KB : 1;      /* 22 Int 13h — 5.25” / 360 KB floppy services are supported */
                    QWORD Floppy_5Dot25Inch_1Dot2MB : 1;    /* 23 Int 13h — 5.25” / 1.2 MB floppy services are supported */
                    QWORD Floppy_3Dot5Inch_720KB : 1;       /* 24 Int 13h — 3.5” / 720 KB floppy services are supported */
                    QWORD Floppy_3Dot5Inch_2Dot88MB : 1;    /* 25 Int 13h — 3.5” / 2.88 MB floppy services are supported */
                    QWORD PrintScreenService : 1;           /* 26 Int 5h, print screen service is supported */
                    QWORD _8042KeyboardServices : 1;        /* 27 Int 9h, 8042 keyboard services are supported */
                    QWORD SerialServices : 1;               /* 28 Int 14h, serial services are supported */
                    QWORD PrinterServices : 1;              /* 29 Int 17h, printer services are supported */
                    QWORD CGA_Mono_VideoServices : 1;       /* 30 Int 10h, CGA/Mono Video Services are supported */
                    QWORD NEC_PC98 : 1;                     /* 31 NEC PC-98 */
                    QWORD ReservedForBIOSVendor : 16;       /* 32:47 Reserved for BIOS vendor */
                    QWORD ReservedForSystemVendor : 16;     /* 48:63 Reserved for system vendor */
                };
            };
            union
            {
                BYTE CharacteristicsExtensionBytes[2];
                struct
                {
                    struct
                    {
                        BYTE ACPI : 1;                  /* 00 ACPI is supported */
                        BYTE USBLegacy : 1;             /* 01 USB Legacy is supported */
                        BYTE AGP : 1;                   /* 02 AGP is supported */
                        BYTE I2OBoot : 1;               /* 03 I2O boot is supported */
                        BYTE LS120_SuperDiskBoot : 1;   /* 04 LS-120 SuperDisk boot is supported */
                        BYTE ATAPI_ZIP_DriveBoot : 1;   /* 05 ATAPI ZIP drive boot is supported */
                        BYTE _1394Boot : 1;             /* 06 1394 boot is supported */
                        BYTE SmartBattery : 1;          /* 07 Smart battery is supported */
                    };
                    struct
                    {
                        BYTE BIOSBootSpecification : 1;                     /* 00 BIOS Boot Specification is supported */
                        BYTE FunctionKeyInitiatedNetworkServiceBoot : 1;    /* 01 Function key-initiated network service boot is supported */
                        BYTE EnableTargetedContentDistribution : 1;         /* 02 Enable targeted content distribution */
                        BYTE UEFISpecification : 1;                         /* 03 UEFI Specification is supported */
                        BYTE VirtualMachine : 1;                            /* 04 SMBIOS table describes a virtual machine */
                        BYTE ManufacturingMode : 1;                         /* 05 Manufacturing mode is supported */
                        BYTE ManufacturingModeEnabled : 1;                  /* 06 Manufacturing mode is enabled */
                        BYTE Reserved : 1;                                  /* 07 Reserved */
                    };
                };
            };
            BYTE MajorRelease;
            BYTE MinorRelease;
            BYTE ECFirmwareMajorRelease;
            BYTE ECFirmwareMinorRelease;
            union
            {
                WORD ExtendedROMSize;
                struct
                {
                    WORD Size : 14; /* 00:13 Size */
#define SMBIOS_BIOS_EXTENDEDROMSIZE_UNIT_MB 00b
#define SMBIOS_BIOS_EXTENDEDROMSIZE_UNIT_GB 01b
                    WORD Unit : 2;  /* 14:15 Unit, SMBIOS_BIOS_EXTENDEDROMSIZE_UNIT_* */
                };
            };
        } TYPE_0_BIOS_INFO;
        struct
        {
            BYTE Manufacturer;
            BYTE ProductName;
            BYTE Version;
            BYTE SerialNumber;
            BYTE UUID[16];
#define SMBIOS_SYSTEM_WAKEUPTYPE_RESERVED           ((BYTE)00h)
#define SMBIOS_SYSTEM_WAKEUPTYPE_OTHER              ((BYTE)01h)
#define SMBIOS_SYSTEM_WAKEUPTYPE_UNKNOW             ((BYTE)02h)
#define SMBIOS_SYSTEM_WAKEUPTYPE_APM_TIMER          ((BYTE)03h)
#define SMBIOS_SYSTEM_WAKEUPTYPE_MODEM_RING         ((BYTE)04h)
#define SMBIOS_SYSTEM_WAKEUPTYPE_LAN_REMOTE         ((BYTE)05h)
#define SMBIOS_SYSTEM_WAKEUPTYPE_POWER_SWITCH       ((BYTE)06h)
#define SMBIOS_SYSTEM_WAKEUPTYPE_PCI_PME            ((BYTE)07h)
#define SMBIOS_SYSTEM_WAKEUPTYPE_AC_POWER_RESTORED  ((BYTE)08h)
            BYTE WakeUpType; /* SMBIOS_SYSTEM_WAKEUPTYPE_* */
            BYTE SKUNumber;
            BYTE Famliy;
        } TYPE_1_SYSTEM_INFO;
        struct
        {
            BYTE Manufacturer;
            BYTE Product;
            BYTE Version;
            BYTE SerialNumber;
            BYTE AssetTag;
            union
            {
                BYTE FeatureFlags;
                struct
                {
                    BYTE HostingBoard : 1;      /* 00 The board is a hosting board (for example, a motherboard) */
                    BYTE RequiresAuxiliary : 1; /* 01 The board requires at least one daughter board or auxiliary card to function properly */
                    BYTE Removable : 1;         /* 02 The board is removable */
                    BYTE Replaceable : 1;       /* 03 The board is replaceable */
                    BYTE HotSwappable : 1;      /* 04 The board is s hot swappable */
                    BYTE Reserved : 3;          /* 05:07 Reserved for future definition by this specification */
                };
            };
            BYTE LocationInChassis;
            WORD ChassisHandle;
#define SMBIOS_BASEBOARD_TYPE_UNKNOWN                   ((BYTE)01h)
#define SMBIOS_BASEBOARD_TYPE_OTHER                     ((BYTE)02h)
#define SMBIOS_BASEBOARD_TYPE_SERVER_BLADE              ((BYTE)03h)
#define SMBIOS_BASEBOARD_TYPE_CONNECTIVITY_SWITCH       ((BYTE)04h)
#define SMBIOS_BASEBOARD_TYPE_SYSTEM_MANAGEMENT_MODULE  ((BYTE)05h)
#define SMBIOS_BASEBOARD_TYPE_PROCESSOR_MODULE          ((BYTE)06h)
#define SMBIOS_BASEBOARD_TYPE_IO_MODULE                 ((BYTE)07h)
#define SMBIOS_BASEBOARD_TYPE_MEMORY_MODULE             ((BYTE)08h)
#define SMBIOS_BASEBOARD_TYPE_DAUGHTER_BOARD            ((BYTE)09h)
#define SMBIOS_BASEBOARD_TYPE_MOTHERBOARD               ((BYTE)0Ah)
#define SMBIOS_BASEBOARD_TYPE_PROCESSOR_MEMORY_MODULE   ((BYTE)0Bh)
#define SMBIOS_BASEBOARD_TYPE_PROCESSOR_IO_MODULE       ((BYTE)0Ch)
#define SMBIOS_BASEBOARD_TYPE_INTERCONNECT_BOARD        ((BYTE)0Dh)
            BYTE BoardType; /* SMBIOS_BASEBOARD_TYPE_*/
            BYTE NumberOfContainedObjectHandles;
            _Field_size_(NumberOfContainedObjectHandles) WORD ContainedObjectHandles[];
        } TYPE_2_BASEBOARD_INFO;
        struct
        {
            BYTE Manufacturer;
            union
            {
                BYTE Type;
                struct
                {
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_OTHER                   ((BYTE)01h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_UNKNOWN                 ((BYTE)02h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_DESKTOP                 ((BYTE)03h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_LOW_PROFILE_DESKTOP     ((BYTE)04h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_PIZZA_BOX               ((BYTE)05h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_MINI_TOWER              ((BYTE)06h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_TOWER                   ((BYTE)07h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_PORTABLE                ((BYTE)08h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_LAPTOP                  ((BYTE)09h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_NOTEBOOK                ((BYTE)0Ah)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_HAND_HELD               ((BYTE)0Bh)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_DOCKING_STATION         ((BYTE)0Ch)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_ALL_IN_ONE              ((BYTE)0Dh)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_SUB_NOTEBOOK            ((BYTE)0Eh)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_SPACE_SAVING            ((BYTE)0Fh)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_LUNCH_BOX               ((BYTE)10h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_MAIN_SERVER_CHASSIS     ((BYTE)11h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_EXPANSION_CHASSIS       ((BYTE)12h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_SUB_CHASSIS             ((BYTE)13h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_BUS_EXPANSION_CHASSIS   ((BYTE)14h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_PERIPHERAL_CHASSIS      ((BYTE)15h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_RAID_CHASSIS            ((BYTE)16h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_RACK_MOUNT_CHASSIS      ((BYTE)17h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_SEALED_CASE_PC          ((BYTE)18h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_MULTI_SYSTEM_CHASSIS    ((BYTE)19h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_COMPACT_PCI             ((BYTE)1Ah)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_ADVANCED_TCA            ((BYTE)1Bh)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_BLADE                   ((BYTE)1Ch)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_BLADE_ENCLOSURE         ((BYTE)1Dh)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_TABLET                  ((BYTE)1Eh)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_CONVERTIBLE             ((BYTE)1Fh)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_DETACHABLE              ((BYTE)20h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_IOT_GATEWAY             ((BYTE)21h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_EMBEDDED_PC             ((BYTE)22h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_MINI_PC                 ((BYTE)23h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_STICK_PC                ((BYTE)24h)
                    BYTE Value : 7;         /* SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_TYPE_* */
                    BYTE ChassisLock : 1;   /* Chassis lock is present */
                };
            };
            BYTE Version;
            BYTE SerialNumber;
            BYTE AssetTagNumber;
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_STATE_OTHER              ((BYTE)01h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_STATE_UNKNOWN            ((BYTE)02h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_STATE_SAFE               ((BYTE)03h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_STATE_WARNING            ((BYTE)04h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_STATE_CRITICAL           ((BYTE)05h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_STATE_NON_RECOVERABLE    ((BYTE)06h)
            BYTE BootUpState;       /* SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_STATE_* */
            BYTE PowerSupplyState;  /* SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_STATE_* */
            BYTE ThermalState;      /* SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_STATE_* */
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_SECURITY_STATE_OTHER                         ((BYTE)01h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_SECURITY_STATE_UNKNOWN                       ((BYTE)02h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_SECURITY_STATE_NONE                          ((BYTE)03h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_SECURITY_STATE_EXTERNAL_INTERFACE_LOCKED_OUT ((BYTE)04h)
#define SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_SECURITY_STATE_EXTERNAL_INTERFACE_ENABLED    ((BYTE)05h)
            BYTE SecurityStatus;    /* SMBIOS_SYSTEM_ENCLOSURE_OR_CHASSIS_SECURITY_STATE_* */
            DWORD OEMDefined;
            BYTE Height;
            BYTE NumberOfPowerCords;
            BYTE ContainedElementCount;
            BYTE ContainedElementRecordLength;
            _Field_size_bytes_(ContainedElementCount * ContainedElementRecordLength) BYTE ContainedElements[];
            /* BYTE SKUNumber; */
        } TYPE_3_SYSTEM_ENCLOSURE_OR_CHASSIS;
        struct
        {
            BYTE SocketDesignation;
#define SMBIOS_PROCESSOR_TYPE_OTHER             ((BYTE)01h)
#define SMBIOS_PROCESSOR_TYPE_UNKNOWN           ((BYTE)02h)
#define SMBIOS_PROCESSOR_TYPE_CENTRAL_PROCESSOR ((BYTE)03h)
#define SMBIOS_PROCESSOR_TYPE_MATH_PROCESSOR    ((BYTE)04h)
#define SMBIOS_PROCESSOR_TYPE_DSP_PROCESSOR     ((BYTE)05h)
#define SMBIOS_PROCESSOR_TYPE_VIDEO_PROCESSOR   ((BYTE)06h)
            BYTE Type;  /* SMBIOS_PROCESSOR_TYPE_* */
            BYTE Family;
            BYTE Manufacturer;
            QWORD ID;
            BYTE Version;
            union
            {
                BYTE Voltage;
                struct
                {
                    BYTE Voltage5V : 1;
                    BYTE Voltage3Dot3V : 1;
                    BYTE Voltage2Dot9V : 1;
                    BYTE Reserved0 : 1;
                    BYTE Reserved1 : 3;
                    BYTE LegacyMode : 1;            /* Should be 0 */
                };
                struct
                {
                    BYTE VoltageTimes10 : 7;
                    BYTE NotLegacyModeVoltage : 1;  /* Should be 1 */
                };
            };
            WORD ExternalClock;
            WORD MaxSpeed;
            WORD CurrentSpeed;
            union
            {
                BYTE Status;
                struct
                {
#define SMBIOS_PROCESSOR_CPU_STATUS_UNKNOWN             0h
#define SMBIOS_PROCESSOR_CPU_STATUS_ENABLED             1h
#define SMBIOS_PROCESSOR_CPU_STATUS_DISABLED_BY_USER    2h
#define SMBIOS_PROCESSOR_CPU_STATUS_DISABLED_BY_BIOS    3h
#define SMBIOS_PROCESSOR_CPU_STATUS_IDLE                4h
#define SMBIOS_PROCESSOR_CPU_STATUS_OTHER               7h
                    BYTE CPUStatus : 3; /* SMBIOS_PROCESSOR_CPU_STATUS_* */
                    BYTE Reserved2 : 3;
                    BYTE CPUSocketPopulated : 1;
                    BYTE Reserved3 : 1;
                };
            };
#define SMBIOS_PROCESSOR_UPGRADE_OTHER                  ((BYTE)01h)
#define SMBIOS_PROCESSOR_UPGRADE_UNKNOWN                ((BYTE)02h)
#define SMBIOS_PROCESSOR_UPGRADE_DAUGHTER_BOARD         ((BYTE)03h)
#define SMBIOS_PROCESSOR_UPGRADE_ZIF_SOCKET             ((BYTE)04h)
#define SMBIOS_PROCESSOR_UPGRADE_REPLACEABLE_PIGGY_BACK ((BYTE)05h)
#define SMBIOS_PROCESSOR_UPGRADE_NONE                   ((BYTE)06h)
#define SMBIOS_PROCESSOR_UPGRADE_LIF_SOCKET             ((BYTE)07h)
#define SMBIOS_PROCESSOR_UPGRADE_SLOT_1                 ((BYTE)08h)
#define SMBIOS_PROCESSOR_UPGRADE_SLOT_2                 ((BYTE)09h)
#define SMBIOS_PROCESSOR_UPGRADE_370_PIN_SOCKET         ((BYTE)0Ah)
#define SMBIOS_PROCESSOR_UPGRADE_SLOT_A                 ((BYTE)0Bh)
#define SMBIOS_PROCESSOR_UPGRADE_SLOT_M                 ((BYTE)0Ch)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_423             ((BYTE)0Dh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_A               ((BYTE)0Eh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_478             ((BYTE)0Fh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_754             ((BYTE)10h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_940             ((BYTE)11h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_939             ((BYTE)12h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_mPGA604         ((BYTE)13h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA771          ((BYTE)14h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA775          ((BYTE)15h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_S1              ((BYTE)16h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_AM2             ((BYTE)17h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_F               ((BYTE)18h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA1366         ((BYTE)19h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_G34             ((BYTE)1Ah)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_AM3             ((BYTE)1Bh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_C32             ((BYTE)1Ch)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA1156         ((BYTE)1Dh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA1567         ((BYTE)1Eh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_PGA988A         ((BYTE)1Fh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1288         ((BYTE)20h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_rPGA988B        ((BYTE)21h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1023         ((BYTE)22h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1224         ((BYTE)23h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA1155         ((BYTE)24h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA1356         ((BYTE)25h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA2011         ((BYTE)26h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_FS1             ((BYTE)27h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_FS2             ((BYTE)28h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_FM1             ((BYTE)29h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_FM2             ((BYTE)2Ah)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA2011_3       ((BYTE)2Bh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA1356_3       ((BYTE)2Ch)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA1150         ((BYTE)2Dh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1168         ((BYTE)2Eh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1234         ((BYTE)2Fh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1364         ((BYTE)30h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_AM4             ((BYTE)31h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA1151         ((BYTE)32h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1356         ((BYTE)33h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1440         ((BYTE)34h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1515         ((BYTE)35h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA3647_1       ((BYTE)36h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_SP3             ((BYTE)37h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_SP3r2           ((BYTE)38h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA2066         ((BYTE)39h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1392         ((BYTE)3Ah)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1510         ((BYTE)3Bh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1528         ((BYTE)3Ch)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA4189         ((BYTE)3Dh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA1200         ((BYTE)3Eh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA4677         ((BYTE)3Fh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA1700         ((BYTE)40h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1744         ((BYTE)41h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1781         ((BYTE)42h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1211         ((BYTE)43h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA2422         ((BYTE)44h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA1211         ((BYTE)45h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA2422         ((BYTE)46h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA5773         ((BYTE)47h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA5773         ((BYTE)48h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_AM5             ((BYTE)49h)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_SP5             ((BYTE)4Ah)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_SP6             ((BYTE)4Bh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA883          ((BYTE)4Ch)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA1190         ((BYTE)4Dh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_BGA4129         ((BYTE)4Eh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA4710         ((BYTE)4Fh)
#define SMBIOS_PROCESSOR_UPGRADE_SOCKET_LGA7529         ((BYTE)50h)
            BYTE Upgrade; /* SMBIOS_PROCESSOR_UPGRADE_* */
            WORD L1CacheHandle;
            WORD L2CacheHandle;
            WORD L3CacheHandle;
            BYTE SerialNumber;
            BYTE AssetTag;
            BYTE PartNumber;
            BYTE CoreCount;
            BYTE CoreEnabled;
            BYTE ThreadCount;
            union
            {
                WORD Characteristics;
                struct
                {
                    WORD Reserved4 : 1;
                    WORD Unknown : 1;
                    WORD _64BitCapable : 1;
                    WORD MultiCore : 1;
                    WORD HardwareThread : 1;
                    WORD ExecuteProtection : 1;
                    WORD EnhancedVirtualization : 1;
                    WORD PowerPerformanceControl : 1;
                    WORD _128BitCapable : 1;
                    WORD Arm64SoCID : 1;
                    WORD Reserved5 : 6;
                };
            };
            WORD Famliy2;
            WORD CoreCount2;
            WORD CoreEnabled2;
            WORD ThreadCount2;
            WORD ThreadEnabled;
        } TYPE_4_PROCESSOR_INFO;
        struct
        {
            BYTE SocketDesignation;
            union
            {
                WORD CacheConfiguration;
                struct
                {
                    WORD CacheLevel : 3;
                    WORD CacheSocketed : 1;
                    WORD Reserved0 : 1;
#define SMBIOS_CACHE_LOCATION_INTERNAL    00b
#define SMBIOS_CACHE_LOCATION_EXTERNAL    01b
#define SMBIOS_CACHE_LOCATION_RESERVED    10b
#define SMBIOS_CACHE_LOCATION_UNKNOWN     11b
                    WORD Location : 2;          /* SMBIOS_CACHE_LOCATION_* */
                    WORD Enabled : 1;
#define SMBIOS_CACHE_OPERATIONAL_MODE_WRITE_THROUGH                 00b
#define SMBIOS_CACHE_OPERATIONAL_MODE_WRITE_BACK                    01b
#define SMBIOS_CACHE_OPERATIONAL_MODE_VARIES_WITH_MEMORY_ADDRESS    10b
#define SMBIOS_CACHE_OPERATIONAL_MODE_UNKNOWN                       11b
                    WORD OperationalMode : 2;   /* SMBIOS_CACHE_OPERATIONAL_MODE_* */
                    WORD Reserved1 : 6;
                };
            };
            union
            {
                WORD MaximumCacheSize;
                struct
                {
                    WORD MaxSizeInGranularity : 15;
                    WORD MaxSizeGranularity : 1;
                };
            };
            union
            {
                WORD InstalledSize;
                struct
                {
                    WORD InstalledSizeInGranularity : 15;
                    WORD InstalledSizeGranularity : 1;
                };
            };
            typedef struct _SMBIOS_CACHE_SRAM_TYPE
            {
                WORD Other : 1;
                WORD Unknown : 1;
                WORD NonBurst : 1;
                WORD Burst : 1;
                WORD PipelineBurst : 1;
                WORD Synchronous : 1;
                WORD Asynchronous : 1;
                WORD Reserved : 9;
            } SMBIOS_CACHE_SRAM_TYPE, *PSMBIOS_CACHE_SRAM_TYPE;
            C_ASSERT(sizeof(SMBIOS_CACHE_SRAM_TYPE) == sizeof(WORD));
            SMBIOS_CACHE_SRAM_TYPE SupportedSRAMType;
            SMBIOS_CACHE_SRAM_TYPE CurrentSRAMType;
            BYTE CacheSpeed;
#define SMBIOS_CACHE_ERROR_CORRECTION_TYPE_OTHER            ((BYTE)01h)
#define SMBIOS_CACHE_ERROR_CORRECTION_TYPE_UNKNOWN          ((BYTE)02h)
#define SMBIOS_CACHE_ERROR_CORRECTION_TYPE_NONE             ((BYTE)03h)
#define SMBIOS_CACHE_ERROR_CORRECTION_TYPE_PARITY           ((BYTE)04h)
#define SMBIOS_CACHE_ERROR_CORRECTION_TYPE_SINGLE_BIT_ECC   ((BYTE)05h)
#define SMBIOS_CACHE_ERROR_CORRECTION_TYPE_MULTI_BIT_ECC    ((BYTE)06h)
            BYTE ErrorCorrectionType;   /* SMBIOS_CACHE_ERROR_CORRECTION_TYPE_* */
#define SMBIOS_CACHE_SYSTEM_CACHE_TYPE_OTHER        ((BYTE)01h)
#define SMBIOS_CACHE_SYSTEM_CACHE_TYPE_UNKNOWN      ((BYTE)02h)
#define SMBIOS_CACHE_SYSTEM_CACHE_TYPE_INSTRUCTION  ((BYTE)03h)
#define SMBIOS_CACHE_SYSTEM_CACHE_TYPE_DATA         ((BYTE)04h)
#define SMBIOS_CACHE_SYSTEM_CACHE_TYPE_UNIFIED      ((BYTE)05h)
            BYTE SystemCacheType;       /* SMBIOS_CACHE_SYSTEM_CACHE_TYPE_* */
#define SMBIOS_CACHE_ASSOCIATIVITY_OTHER                    ((BYTE)01h)
#define SMBIOS_CACHE_ASSOCIATIVITY_UNKNOWN                  ((BYTE)02h)
#define SMBIOS_CACHE_ASSOCIATIVITY_DIRECT_MAPPED            ((BYTE)03h)
#define SMBIOS_CACHE_ASSOCIATIVITY_2_WAY_SET_ASSOCIATIVE    ((BYTE)04h)
#define SMBIOS_CACHE_ASSOCIATIVITY_4_WAY_SET_ASSOCIATIVE    ((BYTE)05h)
#define SMBIOS_CACHE_ASSOCIATIVITY_FULL_ASSOCIATIVE         ((BYTE)06h)
#define SMBIOS_CACHE_ASSOCIATIVITY_8_WAY_SET_ASSOCIATIVE    ((BYTE)07h)
#define SMBIOS_CACHE_ASSOCIATIVITY_16_WAY_SET_ASSOCIATIVE   ((BYTE)08h)
#define SMBIOS_CACHE_ASSOCIATIVITY_12_WAY_SET_ASSOCIATIVE   ((BYTE)09h)
#define SMBIOS_CACHE_ASSOCIATIVITY_24_WAY_SET_ASSOCIATIVE   ((BYTE)0Ah)
#define SMBIOS_CACHE_ASSOCIATIVITY_32_WAY_SET_ASSOCIATIVE   ((BYTE)0Bh)
#define SMBIOS_CACHE_ASSOCIATIVITY_48_WAY_SET_ASSOCIATIVE   ((BYTE)0Ch)
#define SMBIOS_CACHE_ASSOCIATIVITY_64_WAY_SET_ASSOCIATIVE   ((BYTE)0Dh)
#define SMBIOS_CACHE_ASSOCIATIVITY_20_WAY_SET_ASSOCIATIVE   ((BYTE)0Eh)
            BYTE Associativity;         /* SMBIOS_CACHE_ASSOCIATIVITY_* */
            union
            {
                DWORD MaximumCacheSize2;
                struct
                {
                    DWORD MaxSizeInGranularity2 : 31;
                    DWORD MaxSizeGranularity2 : 1;
                };
            };
            union
            {
                DWORD InstalledCacheSize2;
                struct
                {
                    DWORD InstalledCacheSizeInGranularity2 : 31;
                    DWORD InstalledCacheSizeGranularity2 : 1;
                };
            };
        } TYPE_7_CACHE_INFO;
        struct
        {
            BYTE InternalReferenceDesignator;
#define SMBIOS_PORT_CONNECTOR_TYPE_NONE                             ((BYTE)00h)
#define SMBIOS_PORT_CONNECTOR_TYPE_CENTRONICS                       ((BYTE)01h)
#define SMBIOS_PORT_CONNECTOR_TYPE_MINI_CENTRONICS                  ((BYTE)02h)
#define SMBIOS_PORT_CONNECTOR_TYPE_MINI_PROPRIETARY                 ((BYTE)03h)
#define SMBIOS_PORT_CONNECTOR_TYPE_DB_25_PIN_MALE                   ((BYTE)04h)
#define SMBIOS_PORT_CONNECTOR_TYPE_DB_25_PIN_FEMALE                 ((BYTE)05h)
#define SMBIOS_PORT_CONNECTOR_TYPE_DB_15_PIN_MALE                   ((BYTE)06h)
#define SMBIOS_PORT_CONNECTOR_TYPE_DB_15_PIN_FEMALE                 ((BYTE)07h)
#define SMBIOS_PORT_CONNECTOR_TYPE_DB_9_PIN_MALE                    ((BYTE)08h)
#define SMBIOS_PORT_CONNECTOR_TYPE_DB_9_PIN_FEMALE                  ((BYTE)09h)
#define SMBIOS_PORT_CONNECTOR_TYPE_RJ_11                            ((BYTE)0Ah)
#define SMBIOS_PORT_CONNECTOR_TYPE_RJ_45                            ((BYTE)0Bh)
#define SMBIOS_PORT_CONNECTOR_TYPE_50_PIN_MINISCSI                  ((BYTE)0Ch)
#define SMBIOS_PORT_CONNECTOR_TYPE_MINI_DIN                         ((BYTE)0Dh)
#define SMBIOS_PORT_CONNECTOR_TYPE_MICRO_DIN                        ((BYTE)0Eh)
#define SMBIOS_PORT_CONNECTOR_TYPE_PS_2                             ((BYTE)0Fh)
#define SMBIOS_PORT_CONNECTOR_TYPE_INFRARED                         ((BYTE)10h)
#define SMBIOS_PORT_CONNECTOR_TYPE_HP_HIL                           ((BYTE)11h)
#define SMBIOS_PORT_CONNECTOR_TYPE_ACCESS_BUS                       ((BYTE)12h)
#define SMBIOS_PORT_CONNECTOR_TYPE_SSA_SCSI                         ((BYTE)13h)
#define SMBIOS_PORT_CONNECTOR_TYPE_CIRCULAR_DIN_8_MALE              ((BYTE)14h)
#define SMBIOS_PORT_CONNECTOR_TYPE_CIRCULAR_DIN_8_FEMALE            ((BYTE)15h)
#define SMBIOS_PORT_CONNECTOR_TYPE_ON_BOARD_IDE                     ((BYTE)16h)
#define SMBIOS_PORT_CONNECTOR_TYPE_ON_BOARD_FLOPPY                  ((BYTE)17h)
#define SMBIOS_PORT_CONNECTOR_TYPE_9_PIN_DUAL_INLINE                ((BYTE)18h)
#define SMBIOS_PORT_CONNECTOR_TYPE_25_PIN_DUAL_INLINE               ((BYTE)19h)
#define SMBIOS_PORT_CONNECTOR_TYPE_50_PIN_DUAL_INLINE               ((BYTE)1Ah)
#define SMBIOS_PORT_CONNECTOR_TYPE_68_PIN_DUAL_INLINE               ((BYTE)1Bh)
#define SMBIOS_PORT_CONNECTOR_TYPE_ON_BOARD_SOUND_INPUT_FROM_CD_ROM ((BYTE)1Ch)
#define SMBIOS_PORT_CONNECTOR_TYPE_MINI_CENTRONICS_TYPE_14          ((BYTE)1Dh)
#define SMBIOS_PORT_CONNECTOR_TYPE_MINI_CENTRONICS_TYPE_26          ((BYTE)1Eh)
#define SMBIOS_PORT_CONNECTOR_TYPE_MINI_JACK                        ((BYTE)1Fh)
#define SMBIOS_PORT_CONNECTOR_TYPE_BNC                              ((BYTE)20h)
#define SMBIOS_PORT_CONNECTOR_TYPE_1394                             ((BYTE)21h)
#define SMBIOS_PORT_CONNECTOR_TYPE_SAS_SATA_PLUG_RECEPTACLE         ((BYTE)22h)
#define SMBIOS_PORT_CONNECTOR_TYPE_USB_TYPE_C_RECEPTACLE            ((BYTE)23h)
#define SMBIOS_PORT_CONNECTOR_TYPE_PC_98                            ((BYTE)A0h)
#define SMBIOS_PORT_CONNECTOR_TYPE_PC_98HIRESO                      ((BYTE)A1h)
#define SMBIOS_PORT_CONNECTOR_TYPE_PC_H98                           ((BYTE)A2h)
#define SMBIOS_PORT_CONNECTOR_TYPE_PC_98NOTE                        ((BYTE)A3h)
#define SMBIOS_PORT_CONNECTOR_TYPE_PC_98FULL                        ((BYTE)A4h)
#define SMBIOS_PORT_CONNECTOR_TYPE_OTHER                            ((BYTE)FFh)
            BYTE InternalConnectorType; /* SMBIOS_PORT_CONNECTOR_TYPE_* */
            BYTE ExternalReferenceDesignator;
            BYTE ExternalConnectorType; /* SMBIOS_PORT_CONNECTOR_TYPE_* */
#define SMBIOS_PORT_TYPE_NONE                           ((BYTE)00h)
#define SMBIOS_PORT_TYPE_PARALLEL_PORT_XT_AT_COMPATIBLE ((BYTE)01h)
#define SMBIOS_PORT_TYPE_PARALLEL_PORT_PS_2             ((BYTE)02h)
#define SMBIOS_PORT_TYPE_PARALLEL_PORT_ECP              ((BYTE)03h)
#define SMBIOS_PORT_TYPE_PARALLEL_PORT_EPP              ((BYTE)04h)
#define SMBIOS_PORT_TYPE_PARALLEL_PORT_ECP_EPP          ((BYTE)05h)
#define SMBIOS_PORT_TYPE_SERIAL_PORT_XT_AT_COMPATIBLE   ((BYTE)06h)
#define SMBIOS_PORT_TYPE_SERIAL_PORT_16450_COMPATIBLE   ((BYTE)07h)
#define SMBIOS_PORT_TYPE_SERIAL_PORT_16550_COMPATIBLE   ((BYTE)08h)
#define SMBIOS_PORT_TYPE_SERIAL_PORT_16550A_COMPATIBLE  ((BYTE)09h)
#define SMBIOS_PORT_TYPE_SCSI_PORT                      ((BYTE)0Ah)
#define SMBIOS_PORT_TYPE_MIDI_PORT                      ((BYTE)0Bh)
#define SMBIOS_PORT_TYPE_JOY_STICK_PORT                 ((BYTE)0Ch)
#define SMBIOS_PORT_TYPE_KEYBOARD_PORT                  ((BYTE)0Dh)
#define SMBIOS_PORT_TYPE_MOUSE_PORT                     ((BYTE)0Eh)
#define SMBIOS_PORT_TYPE_SSA_SCSI                       ((BYTE)0Fh)
#define SMBIOS_PORT_TYPE_USB                            ((BYTE)10h)
#define SMBIOS_PORT_TYPE_FIRE_WIRE                      ((BYTE)11h)
#define SMBIOS_PORT_TYPE_PCMCIA_TYPE_1                  ((BYTE)12h)
#define SMBIOS_PORT_TYPE_PCMCIA_TYPE_2                  ((BYTE)13h)
#define SMBIOS_PORT_TYPE_PCMCIA_TYPE_3                  ((BYTE)14h)
#define SMBIOS_PORT_TYPE_CARD_BUS                       ((BYTE)15h)
#define SMBIOS_PORT_TYPE_ACCESS_BUS_PORT                ((BYTE)16h)
#define SMBIOS_PORT_TYPE_SCSI_2                         ((BYTE)17h)
#define SMBIOS_PORT_TYPE_SCSI_WIDE                      ((BYTE)18h)
#define SMBIOS_PORT_TYPE_PC_98                          ((BYTE)19h)
#define SMBIOS_PORT_TYPE_PC_98_Hireso                   ((BYTE)1Ah)
#define SMBIOS_PORT_TYPE_PC_H98                         ((BYTE)1Bh)
#define SMBIOS_PORT_TYPE_VIDEO_PORT                     ((BYTE)1Ch)
#define SMBIOS_PORT_TYPE_AUDIO_PORT                     ((BYTE)1Dh)
#define SMBIOS_PORT_TYPE_MODEM_PORT                     ((BYTE)1Eh)
#define SMBIOS_PORT_TYPE_NETWORK_PORT                   ((BYTE)1Fh)
#define SMBIOS_PORT_TYPE_SATA                           ((BYTE)20h)
#define SMBIOS_PORT_TYPE_SAS                            ((BYTE)21h)
#define SMBIOS_PORT_TYPE_MFDP                           ((BYTE)22h)
#define SMBIOS_PORT_TYPE_THUNDERBOLT                    ((BYTE)23h)
#define SMBIOS_PORT_TYPE_8251_COMPATIBLE                ((BYTE)A0h)
#define SMBIOS_PORT_TYPE_8251_FIFO_COMPATIBLE           ((BYTE)A1h)
#define SMBIOS_PORT_TYPE_OTHER                          ((BYTE)FFh)
            BYTE PortType; /* SMBIOS_PORT_TYPE_* */
        } TYPE_8_PORT_CONNECTOR_INFO;
        struct
        {
            BYTE Designation;
#define SMBIOS_SYSTEM_SLOTS_TYPE_OTHER                                  ((BYTE)01h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_UNKNOWN                                ((BYTE)02h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_ISA                                    ((BYTE)03h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_MCA                                    ((BYTE)04h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_EISA                                   ((BYTE)05h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI                                    ((BYTE)06h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PC_CARD                                ((BYTE)07h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_VL_VESA                                ((BYTE)08h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PROPRIETARY                            ((BYTE)09h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PROCESSOR_CARD_SLOT                    ((BYTE)0Ah)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PROPRIETARY_MEMORY_CARD_SLOT           ((BYTE)0Bh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_IO_RISER_CARD_SLOT                     ((BYTE)0Ch)
#define SMBIOS_SYSTEM_SLOTS_TYPE_NUBUS                                  ((BYTE)0Dh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_66MHZ_CAPABLE                      ((BYTE)0Eh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_AGP                                    ((BYTE)0Fh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_AGP_2X                                 ((BYTE)10h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_AGP_4X                                 ((BYTE)11h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_X                                  ((BYTE)12h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_AGP_8X                                 ((BYTE)13h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_M2_SOCKET_1_DP                         ((BYTE)14h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_M2_SOCKET_1_SD                         ((BYTE)15h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_M2_SOCKET_2                            ((BYTE)16h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_M2_SOCKET_3                            ((BYTE)17h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_M2_SOCKET_MXM_TYPE_I                   ((BYTE)18h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_M2_SOCKET_MXM_TYPE_II                  ((BYTE)19h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_M2_SOCKET_MXM_TYPE_III_STANDARD        ((BYTE)1Ah)
#define SMBIOS_SYSTEM_SLOTS_TYPE_M2_SOCKET_MXM_TYPE_III_HE              ((BYTE)1Bh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_M2_SOCKET_MXM_TYPE_IV                  ((BYTE)1Ch)
#define SMBIOS_SYSTEM_SLOTS_TYPE_M2_SOCKET_MXM_3_TYPE_A                 ((BYTE)1Dh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_M2_SOCKET_MXM_3_TYPE_B                 ((BYTE)1Eh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_2_SFF_8639             ((BYTE)1Fh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_3_SFF_8639             ((BYTE)20h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_MINI_52_PIN_WITH_BOTTOM_SIDE_KEEP_OUTS     ((BYTE)21h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_MINI_52_PIN_WITHOUT_BOTTOM_SIDE_KEEP_OUTS  ((BYTE)22h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_MINI_76_PIN                ((BYTE)23h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_4_SFF_8639             ((BYTE)24h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_5_SFF_8639             ((BYTE)25h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_OCP_NIC_3_SFF                          ((BYTE)26h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_OCP_NIC_3_LFF                          ((BYTE)27h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_OCP_NIC_PRIOR_TO_3                     ((BYTE)28h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_CXL_FLEXBUS_1                          ((BYTE)30h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PC_98_C20                              ((BYTE)A0h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PC_98_C24                              ((BYTE)A1h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PC_98_E                                ((BYTE)A2h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PC_98_LOCAL_BUS                        ((BYTE)A3h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PC_98_CARD                             ((BYTE)A4h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS                            ((BYTE)A5h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_X1                         ((BYTE)A6h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_X2                         ((BYTE)A7h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_X4                         ((BYTE)A8h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_X8                         ((BYTE)A9h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_X16                        ((BYTE)AAh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_2                      ((BYTE)ABh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_2_X1                   ((BYTE)ACh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_2_X2                   ((BYTE)ADh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_2_X4                   ((BYTE)AEh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_2_X8                   ((BYTE)AFh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_2_X16                  ((BYTE)B0h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_3                      ((BYTE)B1h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_3_X1                   ((BYTE)B2h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_3_X2                   ((BYTE)B3h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_3_X4                   ((BYTE)B4h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_3_X8                   ((BYTE)B5h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_3_X16                  ((BYTE)B6h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_4                      ((BYTE)B8h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_4_X1                   ((BYTE)B9h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_4_X2                   ((BYTE)BAh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_4_X4                   ((BYTE)BBh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_4_X8                   ((BYTE)BCh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_4_X16                  ((BYTE)BDh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_5                      ((BYTE)BEh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_5_X1                   ((BYTE)BFh)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_5_X2                   ((BYTE)C0h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_5_X4                   ((BYTE)C1h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_5_X8                   ((BYTE)C2h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_5_X16                  ((BYTE)C3h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_PCI_EXPRESS_GEN_6_AND_BEYOND           ((BYTE)C4h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_EDSFF_E1S_E1L                          ((BYTE)C5h)
#define SMBIOS_SYSTEM_SLOTS_TYPE_EDSFF_E3S_E3L                          ((BYTE)C6h)
            BYTE Type;              /* SMBIOS_SYSTEM_SLOTS_TYPE_* */
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_OTHER        ((BYTE)01h)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_UNKNOWN      ((BYTE)02h)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_8_BIT        ((BYTE)03h)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_16_BIT       ((BYTE)04h)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_32_BIT       ((BYTE)05h)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_64_BIT       ((BYTE)06h)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_128_BIT      ((BYTE)07h)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_1X           ((BYTE)08h)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_2X           ((BYTE)09h)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_4X           ((BYTE)0Ah)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_8X           ((BYTE)0Bh)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_12X          ((BYTE)0Ch)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_16X          ((BYTE)0Dh)
#define SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_32X          ((BYTE)0Eh)
            BYTE SlotDataBusWidth;  /* SMBIOS_SYSTEM_SLOTS_DATA_BUS_WIDTH_* */
#define SMBIOS_SYSTEM_SLOTS_CURRENT_USAGE_OTHER         ((BYTE)01h)
#define SMBIOS_SYSTEM_SLOTS_CURRENT_USAGE_UNKNOWN       ((BYTE)02h)
#define SMBIOS_SYSTEM_SLOTS_CURRENT_USAGE_AVAILABLE     ((BYTE)03h)
#define SMBIOS_SYSTEM_SLOTS_CURRENT_USAGE_IN_USE        ((BYTE)04h)
#define SMBIOS_SYSTEM_SLOTS_CURRENT_USAGE_UNAVAILABLE   ((BYTE)05h)
            BYTE CurrentUsage;      /* SMBIOS_SYSTEM_SLOTS_CURRENT_USAGE_* */
#define SMBIOS_SYSTEM_SLOTS_LENGTH_OTHER                        ((BYTE)01h)
#define SMBIOS_SYSTEM_SLOTS_LENGTH_UNKNOWN                      ((BYTE)02h)
#define SMBIOS_SYSTEM_SLOTS_LENGTH_SHORT                        ((BYTE)03h)
#define SMBIOS_SYSTEM_SLOTS_LENGTH_LONG                         ((BYTE)04h)
#define SMBIOS_SYSTEM_SLOTS_LENGTH_2DOT5_INCH_DRIVE_FORM_FACTOR ((BYTE)05h)
#define SMBIOS_SYSTEM_SLOTS_LENGTH_3DOT5_INCH_DRIVE_FORM_FACTOR ((BYTE)06h)
            BYTE Length;            /* SMBIOS_SYSTEM_SLOTS_LENGTH_* */
            WORD ID;
            union
            {
                BYTE Characteristics1;
                struct
                {
                    BYTE CharacteristicsUnknown : 1;
                    BYTE Provides5Dot0Volts : 1;
                    BYTE Provides3Dot3Volts : 1;
                    BYTE OpeningSharedWithAnother : 1;
                    BYTE PCCardSupportsPCCard16 : 1;
                    BYTE PCCardSupportsCardBus : 1;
                    BYTE PCCardSupportsZoomVideo : 1;
                    BYTE PCCardSupportsModemRingResume : 1;
                };
            };
            union
            {
                BYTE Characteristics2;
                struct
                {
                    BYTE PCISupportsPMESignal : 1;
                    BYTE SupportsHotPlugDevices : 1;
                    BYTE PCISupportsSMBusSignal : 1;
                    BYTE PCIeSupportsBifurcation : 1;
                    BYTE SupportsAsyncOrSurpriseRemoval : 1;
                    BYTE FlexbusCXL1Capable : 1;
                    BYTE FlexbusCXL2Capable : 1;
                    BYTE FlexbusCXL3Capable : 1;
                };
            };
            WORD SegmentGroupNumber;
            BYTE BusNumber;
            union
            {
                BYTE DeviceFunctionNumber;
                struct
                {
                    BYTE FunctionNumber : 3;
                    BYTE DeviceNumber : 5;
                };
            };
            BYTE DataBusWidth;
            BYTE PeerGroupingCount;
            _Field_size_bytes_(5 * PeerGroupingCount) BYTE PeerGroups[];
            /* BYTE Information; */
            /* BYTE PhysicalWidth; */
            /* WORD Pitch; */
            /* BYTE Height; */
        } TYPE_9_SYSTEM_SLOTS;
        struct
        {
#define SMBIOS_ONBOARD_DEVICES_TYPE_OTHER           ((BYTE)01h)
#define SMBIOS_ONBOARD_DEVICES_TYPE_UNKNOWN         ((BYTE)02h)
#define SMBIOS_ONBOARD_DEVICES_TYPE_VIDEO           ((BYTE)03h)
#define SMBIOS_ONBOARD_DEVICES_TYPE_SCSI_CONTROLLER ((BYTE)04h)
#define SMBIOS_ONBOARD_DEVICES_TYPE_ETHERNET        ((BYTE)05h)
#define SMBIOS_ONBOARD_DEVICES_TYPE_TOKEN_RING      ((BYTE)06h)
#define SMBIOS_ONBOARD_DEVICES_TYPE_SOUND           ((BYTE)07h)
#define SMBIOS_ONBOARD_DEVICES_TYPE_PATA_CONTROLLER ((BYTE)08h)
#define SMBIOS_ONBOARD_DEVICES_TYPE_SATA_CONTROLLER ((BYTE)09h)
#define SMBIOS_ONBOARD_DEVICES_TYPE_SAS_CONTROLLER  ((BYTE)0Ah)
            _Field_size_((Header.Length - sizeof(Header)) / 2) BYTE Type[]; /* SMBIOS_ONBOARD_DEVICES_TYPE_* */
            /* _Field_size_((Header.Length - sizeof(Header)) / 2) BYTE DescriptionString[]; */
        } TYPE_10_OBSOLETE_ON_BOARD_DEVICES_INFO;
        struct
        {
            BYTE Count;
        } TYPE_11_OEM_STRINGS;
        struct
        {
            BYTE Count;
        } TYPE_12_SYSTEM_CONFIGURATION_OPTIONS;
        struct
        {
            BYTE InstallableLanguages;
            union
            {
                BYTE Flags;
                struct
                {
                    BYTE AbbreviatedFormat : 1;
                    BYTE Reserved0 : 7;
                };
            };
            BYTE Reserved1[15];
            BYTE CurrentLanguage;
        } TYPE_13_BIOS_LANGUAGE_INFO;
        struct
        {
            BYTE GroupName;
            BYTE ItemType1;
            WORD ItemHandle1;
            /* ItemType2, ItemHandle2, ..., ItemTypeN, ItemHandleN */
        } TYPE_14_GROUP_ASSOCIATIONS;
        struct
        {
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_OTHER                         ((BYTE)01h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_UNKNOWN                       ((BYTE)02h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_SYSTEM_BOARD_OR_MOTHERBOARD   ((BYTE)03h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_ISA_ADD_ON_CARD               ((BYTE)04h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_EISA_ADD_ON_CARD              ((BYTE)05h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_PCI_ADD_ON_CARD               ((BYTE)06h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_MCA_ADD_ON_CARD               ((BYTE)07h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_PCMCIA_ADD_ON_CARD            ((BYTE)08h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_PROPRIETARY_ADD_ON_CARD       ((BYTE)09h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_NUBUS                         ((BYTE)0Ah)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_PC_98_C20_ADD_ON_CARD         ((BYTE)A0h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_PC_98_C24_ADD_ON_CARD         ((BYTE)A1h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_PC_98_E_ADD_ON_CARD           ((BYTE)A2h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_PC_98_LOCAL_BUS_ADD_ON_CARD   ((BYTE)A3h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_CXL_ADD_ON_CARD               ((BYTE)A4h)
            BYTE Location;          /* SMBIOS_PHYSICAL_MEMORY_ARRAY_LOCATION_* */
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_USE_OTHER              ((BYTE)01h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_USE_UNKNOWN            ((BYTE)02h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_USE_SYSTEM_MEMORY      ((BYTE)03h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_USE_VIDEO_MEMORY       ((BYTE)04h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_USE_FLASH_MEMORY       ((BYTE)05h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_USE_NON_VOLATILE_RAM   ((BYTE)06h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_USE_CACHE_MEMORY       ((BYTE)07h)
            BYTE Use;               /* SMBIOS_PHYSICAL_MEMORY_ARRAY_USE_* */
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_ERROR_CORRECTION_TYPE_OTHER            ((BYTE)01h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_ERROR_CORRECTION_TYPE_UNKNOWN          ((BYTE)02h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_ERROR_CORRECTION_TYPE_NONE             ((BYTE)03h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_ERROR_CORRECTION_TYPE_PARITY           ((BYTE)04h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_ERROR_CORRECTION_TYPE_SINGLE_BIT_ECC   ((BYTE)05h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_ERROR_CORRECTION_TYPE_MULTI_BIT_ECC    ((BYTE)06h)
#define SMBIOS_PHYSICAL_MEMORY_ARRAY_ERROR_CORRECTION_TYPE_CRC              ((BYTE)07h)
            BYTE ErrorCorrection;   /* SMBIOS_PHYSICAL_MEMORY_ARRAY_ERROR_CORRECTION_TYPE_* */
            DWORD MaximumCapacity;
            WORD ErrorInformationHandle;
            WORD NumberOfMemoryDevices;
            QWORD ExtendedMaximumCapacity;
        } TYPE_16_PHYSICAL_MEMORY_ARRAY;
        struct
        {
            WORD PhysicalMemoryArrayHandle;
            WORD ErrorInformationHandle;
            WORD TotalWidth;
            WORD DataWidth;
            WORD Size;
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_OTHER              ((BYTE)01h)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_UNKNOWN            ((BYTE)02h)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_SIMM               ((BYTE)03h)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_SIP                ((BYTE)04h)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_CHIP               ((BYTE)05h)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_DIP                ((BYTE)06h)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_ZIP                ((BYTE)07h)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_PROPRIETARY_CARD   ((BYTE)08h)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_DIMM               ((BYTE)09h)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_TSOP               ((BYTE)0Ah)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_ROW_OF_CHIPS       ((BYTE)0Bh)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_RIMM               ((BYTE)0Ch)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_SODIMM             ((BYTE)0Dh)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_SRIMM              ((BYTE)0Eh)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_FB_DIMM            ((BYTE)0Fh)
#define SMBIOS_MEMORY_DEVICE_FORM_FACTOR_DIE                ((BYTE)10h)
            BYTE FormFactor;    /* SMBIOS_MEMORY_DEVICE_FORM_FACTOR_* */
            BYTE DeviceSet;
            BYTE DeviceLocator;
            BYTE BankLocator;
#define SMBIOS_MEMORY_DEVICE_TYPE_OTHER                         ((BYTE)01h)
#define SMBIOS_MEMORY_DEVICE_TYPE_UNKNOWN                       ((BYTE)02h)
#define SMBIOS_MEMORY_DEVICE_TYPE_DRAM                          ((BYTE)03h)
#define SMBIOS_MEMORY_DEVICE_TYPE_EDRAM                         ((BYTE)04h)
#define SMBIOS_MEMORY_DEVICE_TYPE_VRAM                          ((BYTE)05h)
#define SMBIOS_MEMORY_DEVICE_TYPE_SRAM                          ((BYTE)06h)
#define SMBIOS_MEMORY_DEVICE_TYPE_RAM                           ((BYTE)07h)
#define SMBIOS_MEMORY_DEVICE_TYPE_ROM                           ((BYTE)08h)
#define SMBIOS_MEMORY_DEVICE_TYPE_FLASH                         ((BYTE)09h)
#define SMBIOS_MEMORY_DEVICE_TYPE_EEPROM                        ((BYTE)0Ah)
#define SMBIOS_MEMORY_DEVICE_TYPE_FEPROM                        ((BYTE)0Bh)
#define SMBIOS_MEMORY_DEVICE_TYPE_EPROM                         ((BYTE)0Ch)
#define SMBIOS_MEMORY_DEVICE_TYPE_CDRAM                         ((BYTE)0Dh)
#define SMBIOS_MEMORY_DEVICE_TYPE_3DRAM                         ((BYTE)0Eh)
#define SMBIOS_MEMORY_DEVICE_TYPE_SDRAM                         ((BYTE)0Fh)
#define SMBIOS_MEMORY_DEVICE_TYPE_SGRAM                         ((BYTE)10h)
#define SMBIOS_MEMORY_DEVICE_TYPE_RDRAM                         ((BYTE)11h)
#define SMBIOS_MEMORY_DEVICE_TYPE_DDR                           ((BYTE)12h)
#define SMBIOS_MEMORY_DEVICE_TYPE_DDR2                          ((BYTE)13h)
#define SMBIOS_MEMORY_DEVICE_TYPE_DDR2_FB_DIMM                  ((BYTE)14h)
#define SMBIOS_MEMORY_DEVICE_TYPE_DDR3                          ((BYTE)18h)
#define SMBIOS_MEMORY_DEVICE_TYPE_FBD2                          ((BYTE)19h)
#define SMBIOS_MEMORY_DEVICE_TYPE_DDR4                          ((BYTE)1Ah)
#define SMBIOS_MEMORY_DEVICE_TYPE_LPDDR                         ((BYTE)1Bh)
#define SMBIOS_MEMORY_DEVICE_TYPE_LPDDR2                        ((BYTE)1Ch)
#define SMBIOS_MEMORY_DEVICE_TYPE_LPDDR3                        ((BYTE)1Dh)
#define SMBIOS_MEMORY_DEVICE_TYPE_LPDDR4                        ((BYTE)1Eh)
#define SMBIOS_MEMORY_DEVICE_TYPE_LOGICAL_NON_VOLATILE_DEVICE   ((BYTE)1Fh)
#define SMBIOS_MEMORY_DEVICE_TYPE_HBM                           ((BYTE)20h)
#define SMBIOS_MEMORY_DEVICE_TYPE_HBM2                          ((BYTE)21h)
#define SMBIOS_MEMORY_DEVICE_TYPE_DDR5                          ((BYTE)22h)
#define SMBIOS_MEMORY_DEVICE_TYPE_LPDDR5                        ((BYTE)23h)
#define SMBIOS_MEMORY_DEVICE_TYPE_HBM3                          ((BYTE)24h)
            BYTE Type;          /* SMBIOS_MEMORY_DEVICE_TYPE_* */
            union
            {
                WORD TypeDetail;
                struct
                {
                    WORD Reserved0 : 1;
                    WORD TypeOther : 1;
                    WORD TypeUnknow : 1;
                    WORD FastPaged : 1;
                    WORD StaticColumn : 1;
                    WORD PseudoStatic : 1;
                    WORD RAMBUS : 1;
                    WORD Synchronous : 1;
                    WORD CMOS : 1;
                    WORD EDO : 1;
                    WORD WindowDRAM : 1;
                    WORD CacheDRAM : 1;
                    WORD NonVolatile : 1;
                    WORD Registered : 1;
                    WORD Unbuffered : 1;
                    WORD LRDIMM : 1;
                };
            };
            WORD Speed;
            BYTE Manufacturer;
            BYTE SerialNumber;
            BYTE AssetTag;
            BYTE PartNumber;
            union
            {
                BYTE Attributes;
                struct
                {
                    BYTE Rank : 4;
                    BYTE Reserved1 : 4;
                };
            };
            DWORD ExtendedSize;
            WORD ConfiguredMemorySpeed;
            WORD MinimumVoltage;
            WORD MaximumVoltage;
            WORD ConfiguredVoltage;
#define SMBIOS_MEMORY_DEVICE_TECHNOLOGY_OTHER                           ((BYTE)01h)
#define SMBIOS_MEMORY_DEVICE_TECHNOLOGY_UNKNOWN                         ((BYTE)02h)
#define SMBIOS_MEMORY_DEVICE_TECHNOLOGY_DRAM                            ((BYTE)03h)
#define SMBIOS_MEMORY_DEVICE_TECHNOLOGY_NVDIMM_N                        ((BYTE)04h)
#define SMBIOS_MEMORY_DEVICE_TECHNOLOGY_NVDIMM_F                        ((BYTE)05h)
#define SMBIOS_MEMORY_DEVICE_TECHNOLOGY_NVDIMM_P                        ((BYTE)06h)
#define SMBIOS_MEMORY_DEVICE_TECHNOLOGY_INTEL_OPTANE_PERSISTENT_MEMORY  ((BYTE)07h)
            BYTE Technology;    /* SMBIOS_MEMORY_DEVICE_TECHNOLOGY_* */
            union
            {
                WORD OperatingModeCapability;
                struct
                {
                    WORD Reserved2 : 1;
                    WORD OperatingModeCapabilityOther : 1;
                    WORD OperatingModeCapabilityUnknown : 1;
                    WORD VolatileMemory : 1;
                    WORD ByteAccessiblePersistentMemory : 1;
                    WORD BlockAccessiblePersistentMemory : 1;
                    WORD Reserved3 : 10;
                };
            };
            BYTE FirmwareVersion;
            WORD ModuleManufacturerID;
            WORD ModuleProductID;
            WORD SubsystemControllerManufacturerID;
            QWORD NonVolatileSize;
            QWORD VolatileSize;
            QWORD CacheSize;
            QWORD LogicalSize;
            DWORD ExtendedSpeed;
            DWORD ExtendedConfiguredSpeed;
            WORD PMIC0ManufacturerID;
            WORD PMIC0RevisionNumber;
            WORD RCDManufacturerID;
            WORD RCDRevisionNumber;
        } TYPE_17_MEMORY_DEVICE;
        struct
        {
            DWORD StartingAddress;
            DWORD EndingAddress;
            WORD Handle;
            BYTE PartitionWidth;
            QWORD ExtendedStartingAddress;
            QWORD ExtendedEndingAddress;
        } TYPE_19_MEMORY_ARRAY_MAPPED_ADDRESS;
        struct
        {
            DWORD StartingAddress;
            DWORD EndingAddress;
            WORD Handle;
            WORD MemoryArrayMappedAddressHandle;
            BYTE PartitionRowPosition;
            BYTE InterleavePosition;
            BYTE InterleavedDataDepth;
            QWORD ExtendedStartingAddress;
            QWORD ExtendedEndingAddress;
        } TYPE_20_MEMORY_DEVICE_MAPPED_ADDRESS;
        struct
        {
            union
            {
                BYTE Capabilities;
                struct
                {
                    BYTE Status : 1;
#define SMBIOS_SYSTEM_RESET_BOOT_OPTION_RESERVED            00b
#define SMBIOS_SYSTEM_RESET_BOOT_OPTION_OPERATING_SYSTEM    01b
#define SMBIOS_SYSTEM_RESET_BOOT_OPTION_SYSTEM_UTILITIES    10b
#define SMBIOS_SYSTEM_RESET_BOOT_OPTION_DO_NOT_REBOOT       11b
                    BYTE BootOption : 2;        /* SMBIOS_SYSTEM_RESET_BOOT_OPTION_* */
                    BYTE BootOptionOnLimit : 2; /* SMBIOS_SYSTEM_RESET_BOOT_OPTION_* */
                    BYTE SystemContainsAWatchdogTimer : 1;
                    BYTE Reserved : 2;
                };
            };
            WORD ResetCount;
            WORD ResetLimit;
            WORD TimerInterval;
            WORD Timeout;
        } TYPE_23_SYSTEM_RESET;
        struct
        {
            union
            {
                BYTE Settings;
#define SMBIOS_HARDWARE_SECURITY_SETTINGS_STATUS_DISABLED           00b
#define SMBIOS_HARDWARE_SECURITY_SETTINGS_STATUS_ENABLED            01b
#define SMBIOS_HARDWARE_SECURITY_SETTINGS_STATUS_NOT_IMPLEMENTED    10b
#define SMBIOS_HARDWARE_SECURITY_SETTINGS_STATUS_UNKNOWN            11b
                struct
                {
                    /* SMBIOS_HARDWARE_SECURITY_SETTINGS_STATUS_* */
                    BYTE FrontPanelResetStatus : 2;
                    BYTE AdministratorPasswordStatus : 2;
                    BYTE KeyboardPasswordStatus : 2;
                    BYTE PowerOnPasswordStatus : 2;
                }; 
            };
        } TYPE_24_HARDWARE_SECURITY;
        struct
        {
            BYTE NextScheduledPowerOnMonth;
            BYTE NextScheduledPowerOnDayOfMonth;
            BYTE NextScheduledPowerOnHour;
            BYTE NextScheduledPowerOnMinute;
            BYTE NextScheduledPowerOnSecond;
        } TYPE_25_SYSTEM_POWER_CONTROLS;
        struct
        {
            BYTE Description;
            union
            {
                BYTE LocationAndStatus;
                struct
                {
#define SMBIOS_VOLTAGE_PROBE_LOCATION_OTHER                     00001b
#define SMBIOS_VOLTAGE_PROBE_LOCATION_UNKNOWN                   00010b
#define SMBIOS_VOLTAGE_PROBE_LOCATION_PROCESSOR                 00011b
#define SMBIOS_VOLTAGE_PROBE_LOCATION_DISK                      00100b
#define SMBIOS_VOLTAGE_PROBE_LOCATION_PERIPHERAL_BAY            00101b
#define SMBIOS_VOLTAGE_PROBE_LOCATION_SYSTEM_MANAGEMENT_MODULE  00110b
#define SMBIOS_VOLTAGE_PROBE_LOCATION_MOTHERBOARD               00111b
#define SMBIOS_VOLTAGE_PROBE_LOCATION_MEMORY_MODULE             01000b
#define SMBIOS_VOLTAGE_PROBE_LOCATION_PROCESSOR_MODULE          01001b
#define SMBIOS_VOLTAGE_PROBE_LOCATION_POWER_UNIT                01010b
#define SMBIOS_VOLTAGE_PROBE_LOCATION_ADD_IN_CARD               01011b
                    BYTE Location : 5;  /* SMBIOS_VOLTAGE_PROBE_LOCATION_* */
#define SMBIOS_VOLTAGE_PROBE_STATUS_OTHER           001b
#define SMBIOS_VOLTAGE_PROBE_STATUS_UNKNOWN         010b
#define SMBIOS_VOLTAGE_PROBE_STATUS_OK              011b
#define SMBIOS_VOLTAGE_PROBE_STATUS_NON_CRITICAL    100b
#define SMBIOS_VOLTAGE_PROBE_STATUS_CRITICAL        101b
#define SMBIOS_VOLTAGE_PROBE_STATUS_NON_RECOVERABLE 110b
                    BYTE Status : 3;    /* SMBIOS_VOLTAGE_PROBE_STATUS_* */
                };
            };
        } TYPE_26_VOLTAGE_PROBE;
        struct
        {
            WORD TemperatureProbeHandle;
            union
            {
                BYTE DeviceTypeAndStatus;
                struct
                {
#define SMBIOS_COOLING_DEVICE_TYPE_FAN                      00011b
#define SMBIOS_COOLING_DEVICE_TYPE_CENTRIFUGAL_BLOWER       00100b
#define SMBIOS_COOLING_DEVICE_TYPE_CHIP_FAN                 00101b
#define SMBIOS_COOLING_DEVICE_TYPE_CABINET_FAN              00110b
#define SMBIOS_COOLING_DEVICE_TYPE_POWER_SUPPLY_FAN         00111b
#define SMBIOS_COOLING_DEVICE_TYPE_HEAT_PIPE                01000b
#define SMBIOS_COOLING_DEVICE_TYPE_INTEGRATED_REFRIGERATION 01001b
#define SMBIOS_COOLING_DEVICE_TYPE_ACTIVE_COOLING           10000b
#define SMBIOS_COOLING_DEVICE_TYPE_PASSIVE_COOLING          10001b
                    BYTE Type : 5;      /* SMBIOS_COOLING_DEVICE_TYPE_* */
#define SMBIOS_COOLING_DEVICE_STATUS_OTHER              001b
#define SMBIOS_COOLING_DEVICE_STATUS_UNKNOWN            010b
#define SMBIOS_COOLING_DEVICE_STATUS_OK                 011b
#define SMBIOS_COOLING_DEVICE_STATUS_NON_CRITICAL       100b
#define SMBIOS_COOLING_DEVICE_STATUS_CRITICAL           101b
#define SMBIOS_COOLING_DEVICE_STATUS_NON_RECOVERABLE    110b
                    BYTE Status : 3;    /* SMBIOS_COOLING_DEVICE_STATUS_* */
                };
            };
            BYTE CoolingUnitGroup;
            DWORD OEMDefined;
            WORD NominalSpeed;
            BYTE Description;
        } TYPE_27_COOLING_DEVICE;
        struct
        {
            BYTE Description;
            union
            {
                BYTE LocationAndStatus;
                struct
                {
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_OTHER                     00001b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_UNKNOWN                   00010b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_PROCESSOR                 00011b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_DISK                      00100b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_PERIPHERAL_BAY            00101b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_SYSTEM_MANAGEMENT_MODULE  00110b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_MOTHERBOARD               00111b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_MEMORY_MODULE             01000b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_PROCESSOR_MODULE          01001b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_POWER_UNIT                01010b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_ADD_IN_CARD               01011b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_FRONT_PANEL_BOARD         01100b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_BACK_PANEL_BOARD          01101b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_POWER_SYSTEM_BOARD        01110b
#define SMBIOS_TEMPERATURE_PROBE_LOCATION_DRIVE_BACK_PLANE          01111b
                    BYTE Location : 5;  /* SMBIOS_TEMPERATURE_PROBE_LOCATION_* */
#define SMBIOS_TEMPERATURE_PROBE_STATUS_OTHER           001b
#define SMBIOS_TEMPERATURE_PROBE_STATUS_UNKNOWN         010b
#define SMBIOS_TEMPERATURE_PROBE_STATUS_OK              011b
#define SMBIOS_TEMPERATURE_PROBE_STATUS_NON_CRITICAL    100b
#define SMBIOS_TEMPERATURE_PROBE_STATUS_CRITICAL        101b
#define SMBIOS_TEMPERATURE_PROBE_STATUS_NON_RECOVERABLE 110b
                    BYTE Status : 3;    /* SMBIOS_TEMPERATURE_PROBE_STATUS_* */
                };
            };
            WORD MaximumValue;
            WORD MinimumValue;
            WORD Resolution;
            WORD Tolerance;
            WORD Accuracy;
            DWORD OEMDefined;
            WORD NominalValue;
        } TYPE_28_TEMPERATURE_PROBE;
        struct
        {
            BYTE Description;
            union
            {
                BYTE LocationAndStatus;
                struct
                {
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_OTHER                      00001b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_UNKNOWN                    00010b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_PROCESSOR                  00011b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_DISK                       00100b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_PERIPHERAL_BAY             00101b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_SYSTEM_MANAGEMENT_MODULE   00110b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_MOTHERBOARD                00111b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_MEMORY_MODULE              01000b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_PROCESSOR_MODULE           01001b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_POWER_UNIT                 01010b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_ADD_IN_CARD                01011b
                    BYTE Location : 5;  /* SMBIOS_ELECTRICAL_CURRENT_PROBE_LOCATION_* */
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_STATUS_OTHER            001b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_STATUS_UNKNOWN          010b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_STATUS_OK               011b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_STATUS_NON_CRITICAL     100b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_STATUS_CRITICAL         101b
#define SMBIOS_ELECTRICAL_CURRENT_PROBE_STATUS_NON_RECOVERABLE  110b
                    BYTE Status : 3;    /* SMBIOS_ELECTRICAL_CURRENT_PROBE_STATUS_* */
                };
            };
            WORD MaximumValue;
            WORD MinimumValue;
            WORD Resolution;
            WORD Tolerance;
            WORD Accuracy;
            DWORD OEMDefined;
            WORD NominalValue;
        } TYPE_29_ELECTRICAL_CURRENT_PROBE;
        struct
        {
            BYTE ManufacturerName;
            union
            {
                BYTE Connections;
                struct
                {
                    BYTE InboundConnectionEnabled : 1;
                    BYTE OutboundConnectionEnabled : 1;
                    BYTE Reserved : 6;
                };
            };
        } TYPE_30_OUT_OF_BAND_REMOTE_ACCESS;
        struct
        {
            BYTE Reserved[6];
            BYTE BootStatus[10];
        } TYPE_32_SYSTEM_BOOT_INFORMATION;
        struct
        {
            BYTE Description;
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_OTHER                         ((BYTE)01h)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_UNKNOWN                       ((BYTE)02h)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_NATIONAL_SEMICONDUCTOR_LM75   ((BYTE)03h)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_NATIONAL_SEMICONDUCTOR_LM78   ((BYTE)04h)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_NATIONAL_SEMICONDUCTOR_LM79   ((BYTE)05h)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_NATIONAL_SEMICONDUCTOR_LM80   ((BYTE)06h)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_NATIONAL_SEMICONDUCTOR_LM81   ((BYTE)07h)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_ANALOG_DEVICES_ADM9240        ((BYTE)08h)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_DALLAS_SEMICONDUCTOR_DS1780   ((BYTE)09h)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_MAXIM_1617                    ((BYTE)0Ah)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_GENESYS_GL518SM               ((BYTE)0Bh)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_WINBOND_W83781D               ((BYTE)0Ch)
#define SMBIOS_MANAGEMENT_DEVICE_TYPE_HOLTEK_HT82H791               ((BYTE)0Dh)
            BYTE Type;          /* SMBIOS_MANAGEMENT_DEVICE_TYPE_* */
            DWORD Address;
#define SMBIOS_MANAGEMENT_DEVICE_ADDRESS_TYPE_OTHER     ((BYTE)01h)
#define SMBIOS_MANAGEMENT_DEVICE_ADDRESS_TYPE_UNKNOWN   ((BYTE)02h)
#define SMBIOS_MANAGEMENT_DEVICE_ADDRESS_TYPE_IO_PORT   ((BYTE)03h)
#define SMBIOS_MANAGEMENT_DEVICE_ADDRESS_TYPE_MEMORY    ((BYTE)04h)
#define SMBIOS_MANAGEMENT_DEVICE_ADDRESS_TYPE_SMBUS     ((BYTE)05h)
            BYTE AddressType;   /* SMBIOS_MANAGEMENT_DEVICE_ADDRESS_TYPE_* */
        } TYPE_34_MANAGEMENT_DEVICE;
        struct
        {
            BYTE Description;
            WORD ManagementDeviceHandle;
            WORD ComponentHandle;
            WORD ThresholdHandle;
        } TYPE_35_MANAGEMENT_DEVICE_COMPONENT;
        struct
        {
            BYTE PowerUnitGroup;
            BYTE Location;
            BYTE DeviceName;
            BYTE Manufacturer;
            BYTE SerialNumber;
            BYTE AssetTagNumber;
            BYTE ModelPartNumber;
            BYTE RevisionLevel;
            WORD MaxPowerCapacity;
            union
            {
                WORD Characteristics;
                struct
                {
                    WORD HotReplaceable : 1;
                    WORD Present : 1;
                    WORD UnpluggedFromTheWall : 1;
#define SMBIOS_SYSTEM_POWER_SUPPLY_INPUT_VOLTAGE_RANGE_SWITCHING_OTHER          0001b
#define SMBIOS_SYSTEM_POWER_SUPPLY_INPUT_VOLTAGE_RANGE_SWITCHING_UNKNOWN        0010b
#define SMBIOS_SYSTEM_POWER_SUPPLY_INPUT_VOLTAGE_RANGE_SWITCHING_MANUAL         0011b
#define SMBIOS_SYSTEM_POWER_SUPPLY_INPUT_VOLTAGE_RANGE_SWITCHING_AUTO_SWITCH    0100b
#define SMBIOS_SYSTEM_POWER_SUPPLY_INPUT_VOLTAGE_RANGE_SWITCHING_WIDE_RANGE     0101b
#define SMBIOS_SYSTEM_POWER_SUPPLY_INPUT_VOLTAGE_RANGE_SWITCHING_NOT_APPLICABLE 0110b
                    WORD DMTFInputVoltageRangeSwitching : 4;    /* SMBIOS_SYSTEM_POWER_SUPPLY_INPUT_VOLTAGE_RANGE_SWITCHING_* */
#define SMBIOS_SYSTEM_POWER_SUPPLY_STATUS_OTHER         001b
#define SMBIOS_SYSTEM_POWER_SUPPLY_STATUS_UNKNOWN       010b
#define SMBIOS_SYSTEM_POWER_SUPPLY_STATUS_OK            011b
#define SMBIOS_SYSTEM_POWER_SUPPLY_STATUS_NON_CRITICAL  100b
#define SMBIOS_SYSTEM_POWER_SUPPLY_STATUS_CRITICAL      101b
                    WORD Status : 3;                            /* SMBIOS_SYSTEM_POWER_SUPPLY_STATUS_* */
#define SMBIOS_SYSTEM_POWER_SUPPLY_TYPE_OTHER       0001b  
#define SMBIOS_SYSTEM_POWER_SUPPLY_TYPE_UNKNOWN     0010b  
#define SMBIOS_SYSTEM_POWER_SUPPLY_TYPE_LINEAR      0011b  
#define SMBIOS_SYSTEM_POWER_SUPPLY_TYPE_SWITCHING   0100b  
#define SMBIOS_SYSTEM_POWER_SUPPLY_TYPE_BATTERY     0101b  
#define SMBIOS_SYSTEM_POWER_SUPPLY_TYPE_UPS         0110b  
#define SMBIOS_SYSTEM_POWER_SUPPLY_TYPE_CONVERTER   0111b  
#define SMBIOS_SYSTEM_POWER_SUPPLY_TYPE_REGULATOR   1000b  
                    WORD DMTFPowerSupplyType : 4;               /* SMBIOS_SYSTEM_POWER_SUPPLY_TYPE_* */
                    WORD Reserved : 2;
                };
            };
        } TYPE_39_SYSTEM_POWER_SUPPLY;
        struct
        {
            BYTE ReferenceDesignation;
            union
            {
                BYTE Type;
                struct
                {
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_OTHER              ((BYTE)01h)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_UNKNOWN            ((BYTE)02h)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_VIDEO              ((BYTE)03h)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_SCSI_CONTROLLER    ((BYTE)04h)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_ETHERNET           ((BYTE)05h)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_TOKEN_RING         ((BYTE)06h)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_SOUND              ((BYTE)07h)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_PATA_CONTROLLER    ((BYTE)08h)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_SATA_CONTROLLER    ((BYTE)09h)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_SAS_CONTROLLER     ((BYTE)0Ah)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_WIRELESS_LAN       ((BYTE)0Bh)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_BLUETOOTH          ((BYTE)0Ch)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_WWAN               ((BYTE)0Dh)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_EMMC               ((BYTE)0Eh)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_NVME_CONTROLLER    ((BYTE)0Fh)
#define SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_UFS_CONTROLLER     ((BYTE)10h)
                    BYTE TypeOfDevice : 7; /* SMBIOS_ONBOARD_DEVICES_EXTENDED_TYPE_* */
                    BYTE Status : 1;
                };
            };
            BYTE TypeInstance;
            WORD SegmentGroupNumber;
            BYTE BusNumber;
            union
            {
                BYTE DeviceFunctionNumber;
                struct
                {
                    BYTE FunctionNumber : 3;
                    BYTE DeviceNumber : 5;
                };
            };
        } TYPE_41_ONBOARD_DEVICES_EXTENDED_INFORMATION;
        struct
        {
            BYTE VendorID[4];
            BYTE MajorSpecVersion;
            BYTE MinorSpecVersion;
            DWORD FirmwareVersion1;
            DWORD FirmwareVersion2;
            BYTE Description;
            union
            {
                QWORD Characteristics;
                struct
                {
                    QWORD Reserved0 : 1;
                    QWORD Reserved1 : 1;
                    QWORD NotSupported : 1;
                    QWORD FamilyConfigurableViaFirmwareUpdate : 1;
                    QWORD FamilyConfigurableViaPlatformSoftwareSupport : 1;
                    QWORD FamilyConfigurableViaOEMProprietaryMechanism : 1;
                    QWORD Reserved2 : 58;
                };
            };
            DWORD OEMDefined;
        } TYPE_43_TPM_DEVICE;
        struct
        {
            WORD ReferencedHandle;
            BYTE ProcessorSpecificBlock[];
        } TYPE_44_PROCESSOR_ADDITIONAL_INFO;
        struct
        {
            BYTE ComponentName;
            BYTE Version;
#define SMBIOS_FIRMWARE_INVENTORY_VERSION_FORMAT_FREE_FORM      ((BYTE)00h)
#define SMBIOS_FIRMWARE_INVENTORY_VERSION_FORMAT_MAJOR_MINOR    ((BYTE)01h)
#define SMBIOS_FIRMWARE_INVENTORY_VERSION_FORMAT_HEX_STRING_32  ((BYTE)02h)
#define SMBIOS_FIRMWARE_INVENTORY_VERSION_FORMAT_HEX_STRING_64  ((BYTE)03h)
            BYTE VersionFormat; /* SMBIOS_FIRMWARE_INVENTORY_VERSION_FORMAT_* */
            BYTE ID;
#define SMBIOS_FIRMWARE_INVENTORY_ID_FORMAT_FREE_FORM   ((BYTE)00h)
#define SMBIOS_FIRMWARE_INVENTORY_ID_FORMAT_UEFI_GUID   ((BYTE)01h)
            BYTE IDFormat;  /* SMBIOS_FIRMWARE_INVENTORY_ID_FORMAT_* */
            BYTE ReleaseDate;
            BYTE Manufacturer;
            BYTE LowestSupportedFirmwareVersion;    /* SMBIOS_FIRMWARE_INVENTORY_VERSION_FORMAT_* */
            QWORD ImageSize;
            union
            {
                WORD Characteristics;
                struct
                {
                    WORD Updatable : 1;
                    WORD WriteProtect : 1;
                    WORD Reserved : 14;
                };
            };
#define SMBIOS_FIRMWARE_INVENTORY_STATE_OTHER               ((BYTE)01h)
#define SMBIOS_FIRMWARE_INVENTORY_STATE_UNKNOWN             ((BYTE)02h)
#define SMBIOS_FIRMWARE_INVENTORY_STATE_DISABLED            ((BYTE)03h)
#define SMBIOS_FIRMWARE_INVENTORY_STATE_ENABLED             ((BYTE)04h)
#define SMBIOS_FIRMWARE_INVENTORY_STATE_ABSENT              ((BYTE)05h)
#define SMBIOS_FIRMWARE_INVENTORY_STATE_STANDBY_OFFLINE     ((BYTE)06h)
#define SMBIOS_FIRMWARE_INVENTORY_STATE_STANDBY_SPARE       ((BYTE)07h)
#define SMBIOS_FIRMWARE_INVENTORY_STATE_UNAVAILABLE_OFFLINE ((BYTE)08h)
            BYTE State; /* SMBIOS_FIRMWARE_INVENTORY_STATE_* */
            BYTE NumberOfAssociatedComponents;
            _Field_size_(NumberOfAssociatedComponents) WORD AssociatedComponentHandles[];
        } TYPE_45_FIRMWARE_INVENTORY_INFO;
    };
} SMBIOS_TABLE, *PSMBIOS_TABLE;

#pragma pack(pop)

#pragma warning(default: 4200)
