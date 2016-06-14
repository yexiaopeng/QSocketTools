/*
 *  MHJMsgDecoder.h
 *
 *  Created on: 2016年6月14日
 *      Author: mhj-yxp
 */

#ifndef HEADER__NTMSGDECODER_H_
#define HEADER__NTMSGDECODER_H_
#include "./protocol/include/ntprotocol.h"
enum NTCheckReturnType {
    //校验错误
    NT_CHECK_RETURN_ERROR,
    //校验数据长度不足
    NT_CHECK_RETURN_MORE_DATA,
    //校验成功
    NT_CHECK_RETURN_SUCCESS
};

enum { eOK, eMoreData } ;

int MHJMsgDecoder(char *pusrdata, unsigned short length,NTNetProtocolPack** OutProtocol, const NTDeviceMark * deviceMark  , const char*SecurityData,void** pcache,unsigned short *pcachelength);


#endif /* HEADER__NTMSGDECODER_H_ */
