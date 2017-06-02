/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include <math.h>

#define LOOP_N  (100)

float buffer[LOOP_N];

int main()
{
    char strBuffer[80];
    uint32 startTime, endTime, elapse;
    int i;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    Timer_1_Start();
    
    UART_UartPutString("\r\nFloating Point Test\r\n");
    
    sprintf(strBuffer, "LOOP_N \t%d\r\n", LOOP_N);
    UART_UartPutString(strBuffer);
    UART_UartPutString("op\tstart\tend\telapse\r\n");
    UART_UartPutString("-------------------------------\r\n");
    
    // div
    Timer_1_WriteCounter(0);
    startTime = Timer_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = (float)i / LOOP_N;
    }
    endTime = Timer_1_ReadCounter();
    elapse = endTime - startTime;
    sprintf(strBuffer, "div\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_UartPutString(strBuffer);
    
    // sinf
    Timer_1_WriteCounter(0);
    startTime = Timer_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = sinf((float)i / LOOP_N);
    }
    endTime = Timer_1_ReadCounter();
    elapse = endTime - startTime;
    sprintf(strBuffer, "sinf\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_UartPutString(strBuffer);

    // cosf
    Timer_1_WriteCounter(0);
    startTime = Timer_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = cosf((float)i / LOOP_N);
    }
    endTime = Timer_1_ReadCounter();
    elapse = endTime - startTime;
    sprintf(strBuffer, "cosf\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_UartPutString(strBuffer);

    // expf
    Timer_1_WriteCounter(0);
    startTime = Timer_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = expf((float)i / LOOP_N);
    }
    endTime = Timer_1_ReadCounter();
    elapse = endTime - startTime;
    sprintf(strBuffer, "expf\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_UartPutString(strBuffer);
    
    // logf
    Timer_1_WriteCounter(0);
    startTime = Timer_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = logf((float)i / LOOP_N);
    }
    endTime = Timer_1_ReadCounter();
    elapse = endTime - startTime;
    sprintf(strBuffer, "logf\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_UartPutString(strBuffer);
    
    // sqrtf
    Timer_1_WriteCounter(0);
    startTime = Timer_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = sqrtf((float)i / LOOP_N);
    }
    endTime = Timer_1_ReadCounter();
    elapse = endTime - startTime;
    sprintf(strBuffer, "sqrtf\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_UartPutString(strBuffer);
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
