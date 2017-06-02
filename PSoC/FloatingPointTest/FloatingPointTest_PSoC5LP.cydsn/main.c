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
	UART_1_Start();
    Counter_1_Start();

	UART_1_PutString("\r\nFloating Point Test\r\n");
    sprintf(strBuffer, "LOOP_N \t%d\r\n", LOOP_N);
    UART_1_PutString(strBuffer);
    UART_1_PutString("op\tstart\tend\telapse\r\n");
    UART_1_PutString("-------------------------------\r\n");

    // div
    startTime = Counter_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = (float)i / LOOP_N;
    }
    endTime = Counter_1_ReadCounter();
    elapse = startTime - endTime;
    sprintf(strBuffer, "div\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_1_PutString(strBuffer);
    
    // sinf
    startTime = Counter_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = sinf((float)i / LOOP_N);
    }
    endTime = Counter_1_ReadCounter();
    elapse = startTime - endTime;
    sprintf(strBuffer, "sinf\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_1_PutString(strBuffer);

    // cosf
    startTime = Counter_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = cosf((float)i / LOOP_N);
    }
    endTime = Counter_1_ReadCounter();
    elapse = startTime - endTime;
    sprintf(strBuffer, "cosf\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_1_PutString(strBuffer);
    
    // expf
    startTime = Counter_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = expf((float)i / LOOP_N);
    }
    endTime = Counter_1_ReadCounter();
    elapse = startTime - endTime;
    sprintf(strBuffer, "expf\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_1_PutString(strBuffer);

    // logf
    startTime = Counter_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = logf((float)i / LOOP_N);
    }
    endTime = Counter_1_ReadCounter();
    elapse = startTime - endTime;
    sprintf(strBuffer, "logf\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_1_PutString(strBuffer);
    
    // sqrtf
    startTime = Counter_1_ReadCounter();
    for (i = 0; i < LOOP_N; i++) {
        buffer[i] = sqrtf((float)i / LOOP_N);
    }
    endTime = Counter_1_ReadCounter();
    elapse = startTime - endTime;
    sprintf(strBuffer, "sqrtf\t%lu\t%lu\t%lu\r\n", startTime, endTime, elapse);
    UART_1_PutString(strBuffer);
    UART_1_PutString("\r\nEnd\r\n");
    
	for(;;)
	{
		/* Place your application code here. */
	}
}

/* [] END OF FILE */
