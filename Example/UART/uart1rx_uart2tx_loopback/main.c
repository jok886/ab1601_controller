/******************************************************************************
Copyright (c) Airoha 2016 - All rights reserved

FILE NAME 
    main.c
DESCRIPTION
NOTES
********************************************************************************/
/*!
      \page Example_UART_uart1rx_uart2tx_loopback "Example/UART/uart1rx_uart2tx_loopback"
      \code {.c}
*/
#include "ab1600.h"
#include <stdio.h>
#include "drv_uart.h"
#include <stdlib.h>
#include <string.h>
#include "ab_uart.h"
#include "drv_pinmux.h"

static void uart1_rx_data_ind(uint16_t len)
{
    uint8_t buf[50];
    uint16_t rlen;
    
    while(rlen = AB_UART_Read(uart1_ins, buf, 50))
    {
        AB_UART_Write(uart2_ins, buf, rlen);
        printf("send %d bytes\n", rlen); //this is to uart1
    }
}

const Ab_UartParam  uart1_param_3M = {3000000L, 380, uart1_rx_data_ind, UART_FORMAT_WORD_LENGTH_8_BIT | UART_FORMAT_STOP_1_BIT};
const Ab_UartParam  uart2_param_3M_noRx = {3000000L, 380, NULL, UART_FORMAT_WORD_LENGTH_8_BIT | UART_FORMAT_STOP_1_BIT};

void main()
{    
    /*print output port*/
    Ab_printf_init(uart1_ins);

    /*set uart 2pin mux*/
    DRV_PinMux_GrpSet(UART2_PIN_MASK3, PIN_UART2);
    

    AB_UART_Open(uart1_ins, (Ab_UartParam*)&uart1_param_3M);
    AB_UART_Open(uart2_ins, (Ab_UartParam*)&uart2_param_3M_noRx);
    
    while (1);
}
/*!
      \endcode
*/


