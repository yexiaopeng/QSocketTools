#include "../include/ntprocol.h"



uint NetHanderCheck(char *pdata, int size){
    return 0;
}





uint NetAnalysisCheck(char *pdata, int size, const char*SecurityData){
    return 0;
}




UINT16 NetCountCRC_16(char *pdata, int size){
    return 0;
}



NTNetProtocolPack* NetProtocolPackage(BYTE mprotocolType, const NTDeviceMark* pdeviceID, INT16 mpackID, BYTE mprotocolID, BYTE mver, DWORD mtime, WORD mlength,
        void *pdata, const char*SecurityData){

    NTNetProtocolPack protocolPack;
    return &protocolPack;
}


void sprintMark(char* strMark, NTDeviceMark* mark){

}



void sMarkprint(NTDeviceMark* mark,char* strMark){

}
