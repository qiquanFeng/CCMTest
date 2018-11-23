/// V1.1.1.3

/////////////////////////////////////////////////////////////////////////////


#ifndef _COTPTOOLDLLDEFINE_H_
#define _COTPTOOLDLLDEFINE_H_


/////////////////////////////////////////////////////////////////////////////


#include <Windows.h>


/////////////////////////////////////////////////////////////////////////////


/// Define OTP TOOL export macro
#ifdef OTP_TOOL_EXPORTS

#define OTP_TOOL_API __declspec(dllexport)

#elif defined(OTP_TOOL_IMPORTS)

#define OTP_TOOL_API __declspec(dllimport)

#else

#define OTP_TOOL_API

#endif


/////////////////////////////////////////////////////////////////////////////


/// OTP: Return result
struct TOtpResult
{
    /// Return result enumeration
    enum E
    {
        /// Success
        Success = 0,

        /// Fail
        Fail,

        /// File name parameter is invalid
        FileNameInvalid,

        /// File Buffer parameter is invalid
        FileBufferInvalid,

        /// ADB path not exist
        AdbPathNotExist,

        /// Phone index not exist
        PhoneIndexNotExist,

        /// Serial number parameter is invalid
        SerialNumberInvalid,

        /// Serial number has be used on other connected phone
        SerialNumberUsed,

        /// Connect failed
        ConnectFailed,

        /// Not connected state
        NotConnected,

        /// Read main info failed
        ReadMainInfoFailed,

        /// The current phone version id is different from other connected phone
        VersionIdDifferent,

        /// Version ID parameter is invalid
        VersionIdInvalid,

        /// Key-Value list parameter is invalid
        KeyValueListInvalid,

        /// Image is invalid
        ImageIsEmpty,

        /// Image parameter is invalid
        ImageInvalid,

        /// Read image parameter is invalid
        ReadImageInvalid,

        /// Open image parameter is invalid
        OpenImageInvalid,

        /// Display image parameter is invalid
        DisplayImageInvalid,

        /// Setting parameter is invalid
        SettingInvalid,

        /// Register parameter is invalid
        RegisterInvalid,

        /// Calibration buffer parameter is invalid
        CalibrationBufferInvalid,

        /// Calibrate only RAW/MIPI_RAW image
        CalibrateOnlyRawImage,

        /// Get calibration length failed
        GetCalibrationLengthFailed,

        /// Analyzing BLC error
        AnalyzingBlcError,

        /// Image file not exist
        ImageFileNotExist,

        /// Open image file failed
        OpenImageFileFailed,

        /// Image file size is error
        ImageFileSizeError,

        /// Extend command parameter is invalid
        ExtendCommandInvalid,

        /// Extend buffer parameter is invalid
        ExtendBufferInvalid,

        /// Not started preview
        NotStartedPreview,

        /// AF starting state: need get continue
        AfStarting,

        /// RGB parameter is invalid
        RgbInvalid,

        /// Stat only on RAW/MIPI_RAW image
        StatOnlyOnRawImage
    };
};


/////////////////////////////////////////////////////////////////////////////


/// OTP: Buffer
typedef struct TOtpBuffer
{
    /// Data Length: byte
    UINT uLength;

    /// Data
    PCHAR pData;
}*TOtpBufferPtr;


/////////////////////////////////////////////////////////////////////////////


/// OTP: Max serial number length, byte
#define OTP_MAX_SERIAL_NUMBER_LENGTH                            16

/// OTP: Max phone count
#define OTP_MAX_PHONE_COUNT                                     8


/// OTP: Phone
typedef struct TOtpPhone
{
    /// Serial number
    WCHAR strSerialNumber[OTP_MAX_SERIAL_NUMBER_LENGTH + 1];
}*TOtpPhonePtr;


/// OTP: Phone list
typedef struct TOtpPhoneList
{
    /// Phone count
    UINT uCount;

    /// Phone list
    TOtpPhone stList[OTP_MAX_PHONE_COUNT];
}*TOtpPhoneListPtr;


/////////////////////////////////////////////////////////////////////////////


/// OTP: Max key length, byte
#define OTP_MAX_KEY_LENGTH                                      16

/// OTP: Max Key-Value count
#define OTP_MAX_KEY_VALUE_COUNT                                 16


/// OTP: Key-Value type
struct TOtpKeyValueType
{   
public:

    /// Key-Value type enumeration
    enum E
    {
        /// Capture image format
        CaptureImageFormat = 0,

        /// Capture image size
        CaptureImageSize,

        /// Image Zoom
        ImageZoom,

        /// AE
        Ae,

        /// AF Mode
        AfMode
    };
};


/// OTP: Key-Value
typedef struct TOtpKeyValue
{
    /// Key
    WCHAR strKey[OTP_MAX_KEY_LENGTH + 1];

    /// Value
    INT nValue;
}*TOtpKeyValuePtr;


/// OTP: Key-Value list
typedef struct TOtpKeyValueList
{
    /// Key-Value type
    TOtpKeyValueType::E eType;

    /// Key-Value count
    UINT uCount;

    /// Default value index: 0 ~ (uCount - 1)
    UINT uDefaultIndex;

    /// Key-Value list
    TOtpKeyValue stList[OTP_MAX_KEY_VALUE_COUNT];
}*TOtpKeyValueListPtr;


/////////////////////////////////////////////////////////////////////////////


/// OTP: Image
typedef struct TOtpImage
{
    /// Width
    UINT uWidth;

    /// Height
    UINT uHeight;

    /// Source image
    TOtpBuffer stSourceImage;

    /// RGB image
    TOtpBuffer stRgbImage;
}*TOtpImagePtr;


/// OTP: Read image
typedef struct TOtpReadImage
{
    /// TRUE=Preview, FALSE=Capture/File
    BOOL bIsPreview;

    /// Format index, reference TOtpKeyValueType::CaptureImageFormat, and it is valid on Capture
    UINT uFormatIndex;

    /// Size index, reference TOtpKeyValueType::CaptureImageSize, and it is valid on Capture
    UINT uSizeIndex;

    /// TRUE=Convert To RGB, FALSE=Don't convert To RGB
    BOOL bConvertToRgb;

    /// Width
    UINT uWidth;

    /// Height
    UINT uHeight;
}*TOtpReadImagePtr;


/// OTP: Open image
typedef struct TOtpOpenImage
{
    /// Image file name
    WCHAR strFileName[MAX_PATH + 1];

    /// Width
    UINT uWidth;

    /// Height
    UINT uHeight;

    /// Endian: TRUE=Big Endian; FALSE=Little Endian
    BOOL bBigOrLittleEndian;

    /// TRUE=Convert To RGB, FALSE=Don't convert To RGB
    BOOL bConvertToRgb;

    /// Source image
    TOtpBuffer stSourceImage;

    /// RGB image
    TOtpBuffer stRgbImage;
}*TOtpOpenImagePtr;


/// OTP: Display image
typedef struct TOtpDisplayImage
{
    /// TRUE=Preview, FALSE=Capture/File
    BOOL bIsPreview;

    /// Zoom index, reference TOtpKeyValueType::ImageZoom, and it is valid on Capture/File
    UINT uZoomIndex;

    /// Paint DC: CDC *
    PVOID pPaintDC;
}*TOtpDisplayImagePtr;


/////////////////////////////////////////////////////////////////////////////


/// OTP: Custom display image
typedef struct TOtpCustomDisplayImage
{
    /// TRUE=Preview, FALSE=Capture/File
    BOOL bIsPreview;

    /// Display width
    UINT uDisplayWidth;

    /// Display height
    UINT uDisplayHeight;

    /// Paint DC: CDC *
    PVOID pPaintDC;
}*TOtpCustomDisplayImagePtr;


/////////////////////////////////////////////////////////////////////////////


/// OTP: Paint image event parameter
typedef struct TOtpOnPaintImageParameter
{ 
    /// Width
    UINT uWidth;

    /// Height
    UINT uHeight;

    /// RGB image
    TOtpBuffer stRgbImage;

    /// Memory DC: CDC *
    PVOID pMemoryDC;
}*TOtpOnPaintImageParameterPtr;


/// OTP: Paint image event
/// @param stOnPaintImageParameter - Paint image event parameter
/// @return TRUE=Success; FALSE=Fail
typedef BOOL (*OtpOnPaintImage)(TOtpOnPaintImageParameter &stOnPaintImageParameter);


/////////////////////////////////////////////////////////////////////////////


/// OTP: Max setting reserved count
#define OTP_MAX_SETTING_RESERVED_COUNT                          128


/// OTP: Setting parameter
typedef struct TOtpSetting
{
    /// Shutter: us, 0xFFFFFFFF is invalid, others is valid
    UINT uShutterUs;

    /// Gain: 0 ~ 1023
    UINT uGain;

    /// Frame Rate: frame, 0 ~ 1023
    UINT uFrameRate;

    /// EV: 0 ~ 256
    UINT uEv;

    /// AE: Lock=0, Unlock=1
    UINT uAe;

    /// AF MODE: AF=0, MF=1, CAF=2
    UINT uAfMode;

    /// AF Position: 0 ~ 1023
    UINT uAfPosition;

    /// Check Sum
    UINT uCheckSum;

    /// Reserved count
    UINT uReservedCount;

    /// Reserved: For extend
    UINT uReserveds[OTP_MAX_SETTING_RESERVED_COUNT];
}*TOtpSettingPtr;


/////////////////////////////////////////////////////////////////////////////


/// OTP: Max register count
#define OTP_MAX_REGISTER_COUNT                                  1024


/// OTP: Register type
struct TOtpRegisterType
{   
public:

    /// Register type enumeration
    enum E
    {
        /// Actuator I2C
        ActuatorI2c = 0,

        /// Sensor I2C
        SensorI2c
    };
};


/// OTP: Register
typedef struct TOtpRegister
{
    /// Register type
    TOtpRegisterType::E eType;

    /// Start address
    UINT uStartAddress;

    /// Register count
    UINT uCount;

    /// Register list
    UINT uRegisterList[OTP_MAX_REGISTER_COUNT];
}*TOtpRegisterPtr;


/////////////////////////////////////////////////////////////////////////////


/// OTP: Min extend command
#define OTP_MIN_EXTEND_COMMAND                                  0x10000000

/// OTP: Max extend command
#define OTP_MAX_EXTEND_COMMAND                                  0xFFFFFFFF


/////////////////////////////////////////////////////////////////////////////


/// OTP: RGB
typedef struct TOtpRgb
{
    /// R
    USHORT uR;

    /// G
    USHORT uG;

    /// B
    USHORT uB;
}*TOtpRgbPtr;


/////////////////////////////////////////////////////////////////////////////


/// OTP: Get OTP tool version
/// @return OTP tool version, empty string is failed, otherwise success
extern "C" OTP_TOOL_API CONST WCHAR * OtpGetToolVersion(VOID);
typedef CONST WCHAR * (* FuncOtpGetToolVersion)(VOID);


/// OTP: Free buffer by OtpTool.dll created
/// @param pBuffer - [IN][OUT] Data buffer, pBuffer->pData be created by OtpTool.dll
///                  [IN] pBuffer->uLength/pBuffer->pData
///                  [OUT] pBuffer->uLength/pBuffer->pData
extern "C" OTP_TOOL_API VOID OtpFreeBuffer(TOtpBufferPtr pBuffer);
typedef VOID (* FuncOtpFreeBuffer)(TOtpBufferPtr pBuffer);


/// OTP: Read data from file
/// @param strFileName - [IN] File name, not empty string
/// @param pFileBuffer - [OUT] File data buffer, pFileBuffer->pData be created by OtpTool.dll and need call OtpFreeBuffer to free
/// @return Return result, reference TOtpResult::Success/Fail/FileNameInvalid/FileBufferInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpOpenFile(CONST WCHAR * strFileName, TOtpBufferPtr pFileBuffer);
typedef TOtpResult::E (* FuncOtpOpenFile)(CONST WCHAR * strFileName, TOtpBufferPtr pFileBuffer);


/// OTP: Save data to file
/// @param strFileName - [IN] File name, not empty string
/// @param pFileBuffer - [IN] File data buffer
/// @return Return result, reference TOtpResult::Success/Fail/FileNameInvalid/FileBufferInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpSaveFile(CONST WCHAR * strFileName, CONST TOtpBufferPtr pFileBuffer);
typedef TOtpResult::E (* FuncOtpSaveFile)(CONST WCHAR * strFileName, CONST TOtpBufferPtr pFileBuffer);


/// OTP: Get ADB path
/// @return ADB path, empty string is failed, otherwise success
extern "C" OTP_TOOL_API CONST WCHAR * OtpGetAdbPath(VOID);
typedef CONST WCHAR * (* FuncOtpGetAdbPath)(VOID);


/// OTP: Set ADB path
/// @param strAdbPath - [IN] ADB path, not empty string
/// @return Return result, reference TOtpResult::Success/Fail/AdbPathNotExist
extern "C" OTP_TOOL_API TOtpResult::E OtpSetAdbPath(CONST WCHAR * strAdbPath);
typedef TOtpResult::E (* FuncOtpSetAdbPath)(CONST WCHAR * strAdbPath);


/// OTP: Get phone list
/// @return Phone list, TOtpPhoneList.uCount=0 is failed, otherwise success
extern "C" OTP_TOOL_API TOtpPhoneList OtpGetPhoneList(VOID);
typedef TOtpPhoneList (* FuncOtpGetPhoneList)(VOID);


/// OTP: Initialize all OTP instances
/// @param uPhoneCount - [IN] Phone count, mix value is 1, max value is OTP_MAX_PHONE_COUNT
/// @return The initialized phone count, 0 is failed, otherwise success
extern "C" OTP_TOOL_API UINT OtpInitialize(UINT uPhoneCount);
typedef UINT (* FuncOtpInitialize)(UINT uPhoneCount);


/// OTP: Dispose all OTP instances
extern "C" OTP_TOOL_API VOID OtpDispose(VOID);
typedef VOID (* FuncOtpDispose)(VOID);


/// OTP: Reboot Adb while online mode
/// @param strSerialNumber - [IN] Serial number, not empty string
extern "C" OTP_TOOL_API VOID OtpRebootAdb(CONST WCHAR * strSerialNumber);
typedef VOID (* FuncOtpRebootAdb)(CONST WCHAR * strSerialNumber);


/// OTP: Connect to phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param strSerialNumber - [IN] Serial number, not empty string
/// @return Return result, reference TOtpResult::Success/PhoneIndexNotExist/SerialNumberInvalid/SerialNumberUsed/ConnectFailed/ReadMainInfoFailed/VersionIdDifferent
extern "C" OTP_TOOL_API TOtpResult::E OtpConnect(UINT uPhoneIndex, CONST WCHAR * strSerialNumber);
typedef TOtpResult::E (* FuncOtpConnect)(UINT uPhoneIndex, CONST WCHAR * strSerialNumber);


/// OTP: Disconnect to phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/PhoneIndexNotExist
extern "C" OTP_TOOL_API TOtpResult::E OtpDisconnect(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpDisconnect)(UINT uPhoneIndex);


/// OTP: Is connected phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpIsConnected(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpIsConnected)(UINT uPhoneIndex);


/// OTP: Is testdcam active
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpIsTestdcamActive(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpIsTestdcamActive)(UINT uPhoneIndex);


/// OTP: Read main info
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/PhoneIndexNotExist/NotConnected/ReadMainInfoFailed/VersionIdDifferent
extern "C" OTP_TOOL_API TOtpResult::E OtpReadMainInfo(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpReadMainInfo)(UINT uPhoneIndex);


/// OTP: Get version id form phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pVersionId - [OUT] Version ID, not null, return the version ID value
/// @return Return result, reference TOtpResult::Success/PhoneIndexNotExist/NotConnected/VersionIdInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpGetVersionId(UINT uPhoneIndex, PUINT pVersionId);
typedef TOtpResult::E (* FuncOtpGetVersionId)(UINT uPhoneIndex, PUINT pVersionId);


/// OTP: Get Key-Value form phone or config file
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pKeyValueList - [IN][OUT] Key-Value list, not null
///                        [IN] pKeyValueList->eType
///                        [OUT] pKeyValueList->uCount/pKeyValueList->uDefaultIndex/pKeyValueList->stList
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/KeyValueListInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpGetKeyValueList(UINT uPhoneIndex, TOtpKeyValueListPtr pKeyValueList);
typedef TOtpResult::E (* FuncOtpGetKeyValueList)(UINT uPhoneIndex, TOtpKeyValueListPtr pKeyValueList);


/// OTP: Modify serial number, create a new seiral number, write it into phone, put it into returned strNewSerialNumber.
///      If all phones's serial number are different, then not use the function
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param strNewSerialNumber - [OUT] Serial number, not null, min length is (OTP_MAX_SERIAL_NUMBER_LENGTH + 1), return the serial number
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/SerialNumberInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpModifySerialNumber(UINT uPhoneIndex, PWCHAR strNewSerialNumber);
typedef TOtpResult::E (* FuncOtpModifySerialNumber)(UINT uPhoneIndex, PWCHAR strNewSerialNumber);


/// OTP: Start preview on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param uImageWidth - [IN] The width of preview image
/// @param uImageHeight - [IN] The height of preview image
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpStartPreview(UINT uPhoneIndex, UINT uImageWidth, UINT uImageHeight);
typedef TOtpResult::E (* FuncOtpStartPreview)(UINT uPhoneIndex, UINT uImageWidth, UINT uImageHeight);


/// OTP: Stop preview on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpStopPreview(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpStopPreview)(UINT uPhoneIndex);


/// OTP: Is started preview on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpIsStartedPreview(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpIsStartedPreview)(UINT uPhoneIndex);


/// OTP: Get image data form image
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pImage - [OUT] Image, not null
/// @return Return result, reference TOtpResult::Success/PhoneIndexNotExist/ImageInvalid/ImageIsEmpty
extern "C" OTP_TOOL_API TOtpResult::E OtpGetImageData(UINT uPhoneIndex, TOtpImagePtr pImage);
typedef TOtpResult::E (* FuncOtpGetImageData)(UINT uPhoneIndex, TOtpImagePtr pImage);


/// OTP: Read image form phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pReadImage - [IN][OUT] Read image, not null
///                     [IN] pReadImage->bIsPreview/pReadImage->uFormatIndex/pReadImage->uSizeIndex/pReadImage->bConvertToRgb
///                     [OUT] pReadImage->uWidth/pReadImage->uHeight
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/NotStartedPreview/ReadImageInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpReadImage(UINT uPhoneIndex, TOtpReadImagePtr pReadImage);
typedef TOtpResult::E (* FuncOtpReadImage)(UINT uPhoneIndex, TOtpReadImagePtr pReadImage);


/// OTP: Open image form file
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pOpenImage - [IN][OUT] Open Image, not null
///                     [IN] pOpenImage->strFileName/pOpenImage->uWidth/pOpenImage->uHeight/pOpenImage->bBigOrLittleEndian/pOpenImage->bConvertToRgb
///                     [OUT] pOpenImage->stSourceImage/pOpenImage->stRgbImage
/// @return Return result, reference TOtpResult::Success/PhoneIndexNotExist/OpenImageInvalid/OpenImageFileFailed
extern "C" OTP_TOOL_API TOtpResult::E OtpOpenImage(UINT uPhoneIndex, TOtpOpenImagePtr pOpenImage);
typedef TOtpResult::E (* FuncOtpOpenImage)(UINT uPhoneIndex, TOtpOpenImagePtr pOpenImage);


/// OTP: Show image on the Paint DC
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pDisplayImage - [IN] Display image, not null
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/DisplayImageInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpDisplayImage(UINT uPhoneIndex, CONST TOtpDisplayImagePtr pDisplayImage);
typedef TOtpResult::E (* FuncOtpDisplayImage)(UINT uPhoneIndex, CONST TOtpDisplayImagePtr pDisplayImage);


/// OTP: Show image on the Paint DC by custom
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pDisplayImage - [IN] Display image, not null
/// @param pOnPaintImage - [IN] Paint image event, null=event invalid, not null=event valid
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/DisplayImageInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpCustomDisplayImage(UINT uPhoneIndex, CONST TOtpCustomDisplayImagePtr pDisplayImage, OtpOnPaintImage pOnPaintImage);
typedef TOtpResult::E (* FuncOtpCustomDisplayImage)(UINT uPhoneIndex, CONST TOtpCustomDisplayImagePtr pDisplayImage, OtpOnPaintImage pOnPaintImage);


/// OTP: Select reload on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpSelectReload(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpSelectReload)(UINT uPhoneIndex);


/// OTP: Unselect reload on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpUnselectReload(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpUnselectReload)(UINT uPhoneIndex);


/// OTP: Camera on on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpCameraOn(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpCameraOn)(UINT uPhoneIndex);


/// OTP: Camera off on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpCameraOff(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpCameraOff)(UINT uPhoneIndex);


/// OTP: Start 3A on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpStart3A(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpStart3A)(UINT uPhoneIndex);


/// OTP: Stop 3A on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpStop3A(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpStop3A)(UINT uPhoneIndex);


/// OTP: Start AWB on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpStartAwb(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpStartAwb)(UINT uPhoneIndex);


/// OTP: Stop AWB on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpStopAwb(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpStopAwb)(UINT uPhoneIndex);


/// OTP: Start AF on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpStartAf(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpStartAf)(UINT uPhoneIndex);


/// OTP: Get AF state
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/AfStarting
extern "C" OTP_TOOL_API TOtpResult::E OtpGetAfState(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpGetAfState)(UINT uPhoneIndex);


/// OTP: Start LSC on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpStartLsc(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpStartLsc)(UINT uPhoneIndex);


/// OTP: Stop LSC on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpStopLsc(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpStopLsc)(UINT uPhoneIndex);


/// OTP: Read setting parameter form phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pSetting - [OUT] Setting parameter, not null, return the setting parameter value
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/SettingInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpReadSetting(UINT uPhoneIndex, TOtpSettingPtr pSetting);
typedef TOtpResult::E (* FuncOtpReadSetting)(UINT uPhoneIndex, TOtpSettingPtr pSetting);


/// OTP: Write setting parameter into phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pSetting - [IN] Setting parameter, not null
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/SettingInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpWriteSetting(UINT uPhoneIndex, CONST TOtpSettingPtr pSetting);
typedef TOtpResult::E (* FuncOtpWriteSetting)(UINT uPhoneIndex, CONST TOtpSettingPtr pSetting);


/// OTP: Read register parameter form phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pRegister - [IN][OUT] Register parameter, not null, return the register parameter value
///                    [IN] pRegister->eType/pRegister->uStartAddress/pRegister->uCount
///                    [OUT] pRegister->uStartAddress/pRegister->uCount/pRegister->uRegisterList
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/RegisterInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpReadRegister(UINT uPhoneIndex, TOtpRegisterPtr pRegister);
typedef TOtpResult::E (* FuncOtpReadRegister)(UINT uPhoneIndex, TOtpRegisterPtr pRegister);


/// OTP: Write register parameter into phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pRegister - [IN] Register parameter, not null
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/RegisterInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpWriteRegister(UINT uPhoneIndex, CONST TOtpRegisterPtr pRegister);
typedef TOtpResult::E (* FuncOtpWriteRegister)(UINT uPhoneIndex, CONST TOtpRegisterPtr pRegister);


/// OTP: Calibrate OTP
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pCalibrationBuffer - [OUT] Calibration data buffer, not null, pCalibrationBuffer->pData be created by OtpTool.dll and need call OtpFreeBuffer to free
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/CalibrationBufferInvalid/ImageIsEmpty/CalibrateOnlyRawImage/GetCalibrationLengthFailed/AnalyzingBlcError
extern "C" OTP_TOOL_API TOtpResult::E OtpCalibrateOtp(UINT uPhoneIndex, TOtpBufferPtr pCalibrationBuffer);
typedef TOtpResult::E (* FuncOtpCalibrateOtp)(UINT uPhoneIndex, TOtpBufferPtr pCalibrationBuffer);


/// OTP: Read calibrated OTP partial parameter form phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param uAddressOffset - [IN] The offset based address
/// @param uReadLength - [IN] The readed data length ready
/// @param pCalibrationBuffer - [OUT] Calibration data buffer, not null, pCalibrationBuffer->pData be created by OtpTool.dll and need call OtpFreeBuffer to free
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/CalibrationBufferInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpReadCalibratedOtpPart(UINT uPhoneIndex, UINT uAddressOffset, UINT uReadLength, TOtpBufferPtr pCalibrationBuffer);
typedef TOtpResult::E (* FuncOtpReadCalibratedOtpPart)(UINT uPhoneIndex, UINT uAddressOffset, UINT uReadLength, TOtpBufferPtr pCalibrationBuffer);


/// OTP: Write calibrated OTP partial parameter into phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param uAddressOffset - [IN] The offset based address
/// @param pCalibrationBuffer - [IN] Calibration data buffer, not null
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/CalibrationBufferInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpWriteCalibratedOtpPart(UINT uPhoneIndex, UINT uAddressOffset, CONST TOtpBufferPtr pCalibrationBuffer);
typedef TOtpResult::E (* FuncOtpWriteCalibratedOtpPart)(UINT uPhoneIndex, UINT uAddressOffset, CONST TOtpBufferPtr pCalibrationBuffer);


/// OTP: Read calibrated OTP parameter form phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pCalibrationBuffer - [OUT] Calibration data buffer, not null, pCalibrationBuffer->pData be created by OtpTool.dll and need call OtpFreeBuffer to free
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/CalibrationBufferInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpReadCalibratedOtp(UINT uPhoneIndex, TOtpBufferPtr pCalibrationBuffer);
typedef TOtpResult::E (* FuncOtpReadCalibratedOtp)(UINT uPhoneIndex, TOtpBufferPtr pCalibrationBuffer);


/// OTP: Write calibrated OTP parameter into phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pCalibrationBuffer - [IN] Calibration data buffer, not null
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/CalibrationBufferInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpWriteCalibratedOtp(UINT uPhoneIndex, CONST TOtpBufferPtr pCalibrationBuffer);
typedef TOtpResult::E (* FuncOtpWriteCalibratedOtp)(UINT uPhoneIndex, CONST TOtpBufferPtr pCalibrationBuffer);


/// OTP: Calibrate GOLDEN
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pCalibrationBuffer - [OUT] Calibration data buffer, not null, pCalibrationBuffer->pData be created by OtpTool.dll and need call OtpFreeBuffer to free
/// @param pErrorImageFileNameBuffer - [OUT] Error image file name buffer, not null, pErrorImageFileNameBuffer->pData be created by OtpTool.dll and need call OtpFreeBuffer to free
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/CalibrationBufferInvalid/ImageFileNotExist/OpenImageFileFailed/ImageFileSizeError/CalibrateOnlyRawImage/GetCalibrationLengthFailed/AnalyzingBlcError
extern "C" OTP_TOOL_API TOtpResult::E OtpCalibrateGolden(UINT uPhoneIndex, TOtpBufferPtr pCalibrationBuffer, TOtpBufferPtr pErrorImageFileNameBuffer);
typedef TOtpResult::E (* FuncOtpCalibrateGolden)(UINT uPhoneIndex, TOtpBufferPtr pCalibrationBuffer, TOtpBufferPtr pErrorImageFileNameBuffer);


/// OTP: Erase eFlash on phone
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected
extern "C" OTP_TOOL_API TOtpResult::E OtpEraseEFlash(UINT uPhoneIndex);
typedef TOtpResult::E (* FuncOtpEraseEFlash)(UINT uPhoneIndex);


/// OTP: Execute command for extend
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param uExtendCommand - [IN] Extend command, OTP_MIN_EXTEND_COMMAND ~ OTP_MAX_EXTEND_COMMAND
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/ExtendCommandInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpExecuteExtendCommand(UINT uPhoneIndex, UINT uExtendCommand);
typedef TOtpResult::E (* FuncOtpExecuteExtendCommand)(UINT uPhoneIndex, UINT uExtendCommand);


/// OTP: Read data form phone for extend
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param uExtendCommand - [IN] Extend command, OTP_MIN_EXTEND_COMMAND ~ OTP_MAX_EXTEND_COMMAND
/// @param pExtendBuffer - [OUT] Extend data buffer, not null, pDataBuffer->pData be created by OtpTool.dll and need call OtpFreeBuffer to free
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/ExtendCommandInvalid/ExtendBufferInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpReadExtendData(UINT uPhoneIndex, UINT uExtendCommand, TOtpBufferPtr pExtendBuffer);
typedef TOtpResult::E (* FuncOtpReadExtendData)(UINT uPhoneIndex, UINT uExtendCommand, TOtpBufferPtr pExtendBuffer);


/// OTP: Write data into phone for extend
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param uExtendCommand - [IN] Extend command, OTP_MIN_EXTEND_COMMAND ~ OTP_MAX_EXTEND_COMMAND
/// @param pExtendBuffer - [IN] Extend data buffer, not null, execute command only when pExtendBuffer is null, otherwise write extend data
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/ExtendCommandInvalid/ExtendBufferInvalid
extern "C" OTP_TOOL_API TOtpResult::E OtpWriteExtendData(UINT uPhoneIndex, UINT uExtendCommand, CONST TOtpBufferPtr pExtendBuffer);
typedef TOtpResult::E (* FuncOtpWriteExtendData)(UINT uPhoneIndex, UINT uExtendCommand, CONST TOtpBufferPtr pExtendBuffer);


/// OTP: Read stat RGB data form phone, and OtpReadImage must be called before calling OtpReadStatRgb
/// @param uPhoneIndex - [IN] Phone index, 0 ~ (The Initialized phone count - 1)
/// @param pRgb - [OUT] RGB parameter, not null, return the RGB parameter value
/// @return Return result, reference TOtpResult::Success/Fail/PhoneIndexNotExist/NotConnected/RgbInvalid/ImageIsEmpty/StatOnlyOnRawImage
extern "C" OTP_TOOL_API TOtpResult::E OtpReadStatRgb(UINT uPhoneIndex, TOtpRgbPtr pRgb);
typedef TOtpResult::E (* FuncOtpReadStatRgb)(UINT uPhoneIndex, TOtpRgbPtr pRgb);


/////////////////////////////////////////////////////////////////////////////


#endif

