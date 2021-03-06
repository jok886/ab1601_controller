/******************************************************************************
Copyright (c) Airoha 2016 - All rights reserved

FILE NAME 
    airsync_auth.h
DESCRIPTION
NOTES
********************************************************************************/
#ifndef __AIRSYNC_AUTH_HH__
#define __AIRSYNC_AUTH_HH__

#include <time.h>
#include "crc32.h"
#include "aes_crypt.h"
#include "airsync_gatt.h"
#include "ble_gatt_server.h"
#include "airsync_typedef.h"

void airsync_auth(void);
void pack_auth_request(void);
void send_auth_req_packets(void);
void unpack_auth_response(void);
#endif