#ifndef NTPROCOL_H
#define NTPROCOL_H

#include <netinet/in.h>
#include <stdio.h>

#include "c_type.h"

#pragma pack(push)
#pragma pack(1)

/*
*  device Mark
*/
typedef struct _NTDeviceMark {
    BYTE idSecurity1;
    uint32_t deviceID;
    BYTE deviceType;
    BYTE deviceFlag;
    BYTE idSecurity2;
} NTDeviceMark;


/*
 * Net Variable length data packet
 */
typedef struct _NTNetProtocolPack{
    char packHander[5];        //pack hander "$SONE"
    BYTE protocolType;         //protocol Type
    NTDeviceMark deviceMark;  //device Mark
    UINT16 packID;             //pack id
    BYTE protocolID;           //protocl ID
    BYTE protocolVer;          //protocol ver
    DWORD timeStamp;           //timeStamp GTM + 8
    WORD  dataLength;          //data length
    WORD  handerCRC;           //hander crc
    WORD  data;                 //data   if dataLength=0  data is crcdata
                                 //  if dataLength !=0 crc16 is end of data
}NTNetProtocolPack;


typedef struct _IPPORTADDRESS {
    in_addr_t ip;
    UINT16 prot;
} IPPORTADDRESS;

#pragma pack(pop)


enum NTCheckReturnType {
    //check error
    NT_CHECK_RETURN_ERROR,
    //data size is not enough
    NT_CHECK_RETURN_MORE_DATA,
    //check success
    NT_CHECK_RETURN_SUCCESS
};


/****************************************
  @Function Name:
  @Function Description:
  @Input Parameter:
  @Output Parameter
  @Return Value:
  @Calls:
  @Calls By:
  --------------------------------------
  @Author :
  @Date:
  @Ver:
  @Other:
****************************************/
uint NetHanderCheck(char *pdata, int size);




/****************************************
  @Function Name:
  @Function Description:
  @Input Parameter:
  @Output Parameter
  @Return Value:
  @Calls:
  @Calls By:
  --------------------------------------
  @Author :
  @Date:
  @Ver:
  @Other:
****************************************/
uint NetAnalysisCheck(char *pdata, int size, const char*SecurityData);


/****************************************
  @Function Name:
  @Function Description:
  @Input Parameter:
  @Output Parameter
  @Return Value:
  @Calls:
  @Calls By:
  --------------------------------------
  @Author :
  @Date:
  @Ver:
  @Other:
****************************************/
UINT16 NetCountCRC_16(char *pdata, int size);


/****************************************
  @Function Name:
  @Function Description:
  @Input Parameter:
  @Output Parameter
  @Return Value:
  @Calls:
  @Calls By:
  --------------------------------------
  @Author :
  @Date:
  @Ver:
  @Other:
****************************************/
NTNetProtocolPack* NetProtocolPackage(BYTE mprotocolType, const NTDeviceMark* pdeviceID, INT16 mpackID, BYTE mprotocolID, BYTE mver, DWORD mtime, WORD mlength,
        void *pdata, const char*SecurityData);

/****************************************
  @Function Name:
  @Function Description:
  @Input Parameter:
  @Output Parameter
  @Return Value:
  @Calls:
  @Calls By:
  --------------------------------------
  @Author :
  @Date:
  @Ver:
  @Other:
****************************************/
void sprintMark(char* strMark, NTDeviceMark* mark);


/****************************************
  @Function Name:
  @Function Description:
  @Input Parameter:
  @Output Parameter
  @Return Value:
  @Calls:
  @Calls By:
  --------------------------------------
  @Author :
  @Date:
  @Ver:
  @Other:
****************************************/
void sMarkprint(NTDeviceMark* mark,char* strMark);



























#endif // NTPROCOL_H
