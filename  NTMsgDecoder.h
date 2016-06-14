/*
 *  MHJMsgDecoder.h
 *
 *  Created on: 2016年6月14日
 *      Author: mhj-yxp
 */

#ifndef HEADER__NTMSGDECODER_H_
#define HEADER__NTMSGDECODER_H_
#include "ntprotocol.h"


enum { eOK, eMoreData } ;

int MHJMsgDecoder(char *pusrdata, unsigned short length,NTNetProtocolPack** OutProtocol, const NTDeviceMark * deviceMark  , const char*SecurityData,void** pcache,unsigned short *pcachelength);


#endif /* HEADER__NTMSGDECODER_H_ */
