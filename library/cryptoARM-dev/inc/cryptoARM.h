
#pragma once

#ifdef CRYPTOARM_EXPORTS  
#define CRYPTOARM_API __declspec(dllexport)   
#else  
#define CRYPTOARM_API __declspec(dllimport)   
#endif

//���~�X
#define DONGLE_SUCCESS             0x00000000 // �ާ@���\
#define DONGLE_NOT_FOUND           0xF0000001 // �������w���]��
#define DONGLE_INVALID_HANDLE      0xF0000002 // �L�Ī��y�`
#define DONGLE_INVALID_PARAMETER   0xF0000003 // �Ѽƿ��~
#define DONGLE_COMM_ERROR          0xF0000004 // �q�T���~
#define DONGLE_INSUFFICIENT_BUFFER 0xF0000005 // �w�İϪŶ�����
#define DONGLE_NOT_INITIALIZED     0xF0000006 // ���~�|����l�� (�Y�S�]�mPID)
#define DONGLE_ALREADY_INITIALIZED 0xF0000007 // ���~�w�g��l�� (�Y�w�]�mPID)
#define DONGLE_ADMINPIN_NOT_CHECK  0xF0000008 // �}�o�ӱK�X�S������
#define DONGLE_USERPIN_NOT_CHECK   0xF0000009 // �Τ�K�X�S������
#define DONGLE_INCORRECT_PIN       0xF000FF00 // �K�X�����T (��2����ܳѧE����)
#define DONGLE_PIN_BLOCKED         0xF000000A // PIN�X�w�ꦺ
#define DONGLE_ACCESS_DENIED       0xF000000B // �X�ݳQ�ڵ� 
#define DONGLE_FILE_EXIST          0xF000000E // ���w�s�b
#define DONGLE_FILE_NOT_FOUND      0xF000000F // �������w�����
#define DONGLE_READ_ERROR          0xF0000010 // Ū���ƾڿ��~
#define DONGLE_WRITE_ERROR         0xF0000011 // �g�J�ƾڿ��~
#define DONGLE_FILE_CREATE_ERROR   0xF0000012 // �Ыؤ����~
#define DONGLE_FILE_READ_ERROR     0xF0000013 // Ū�������~
#define DONGLE_FILE_WRITE_ERROR    0xF0000014 // �g�J�����~
#define DONGLE_FILE_DEL_ERROR      0xF0000015 // �R�������~
#define DONGLE_FAILED              0xF0000016 // �ާ@����
#define DONGLE_CLOCK_EXPIRE        0xF0000017 // �[�K��������
#define DONGLE_ERROR_UNKNOWN       0xFFFFFFFF // ���������~

#ifdef __cplusplus
extern "C" {
#endif

CRYPTOARM_API void cryptoARM_3DesEcbEncryptWithKeyValue(const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, unsigned char *keyValue);

CRYPTOARM_API void cryptoARM_3DesEcbDecryptWithKeyValue(const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, unsigned char *keyValue);

CRYPTOARM_API void cryptoARM_3DesCbcEncryptWithKeyValue(const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, unsigned char *keyValue, const unsigned char *iv);

CRYPTOARM_API void cryptoARM_3DesCbcDecryptWithKeyValue(const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, unsigned char *keyValue, const unsigned char *iv);

CRYPTOARM_API DWORD cryptoARM_3DesWriteKeyValue(unsigned int keyNo, unsigned char *keyValue, unsigned int keyLen);

CRYPTOARM_API DWORD cryptoARM_3DesEcbEncrypt(unsigned int keyNo, const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen);

CRYPTOARM_API DWORD cryptoARM_3DesEcbDecrypt(unsigned int keyNo, const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen);

CRYPTOARM_API DWORD cryptoARM_3DesCbcEncrypt(unsigned int keyNo, const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, const unsigned char *iv);

CRYPTOARM_API DWORD cryptoARM_3DesCbcDecrypt(unsigned int keyNo, const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, const unsigned char *iv);

#ifdef __cplusplus 
}
#endif