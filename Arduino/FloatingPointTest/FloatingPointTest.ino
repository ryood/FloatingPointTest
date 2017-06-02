#define LOOP_N  (100)

float buffer[LOOP_N];

void setup()
{
  char strBuffer[80];
  unsigned long start, end, elapse;

  Serial.begin(9600);
  Serial.print("\r\nFloating Point Test\r\n");
  sprintf(strBuffer, "LOOP_N\t%d\r\n", LOOP_N);
  Serial.print(strBuffer);
  Serial.print("op\tstart\tend\terapse\r\n");
  Serial.print("-------------------------------\r\n");

  // div
  start = micros();
  for (int i = 0; i < LOOP_N; i++) {
    buffer[i] = (float)i / LOOP_N;
  }
  end = micros();
  elapse = end - start;
  sprintf(strBuffer, "div\t%ld\t%ld\t%ld\r\n", start, end, elapse);
  Serial.print(strBuffer);

  // sinf
  start = micros();
  for (int i = 0; i < LOOP_N; i++) {
    buffer[i] = sinf((float)i / LOOP_N);
  }
  end = micros();
  elapse = end - start;
  sprintf(strBuffer, "sinf\t%ld\t%ld\t%ld\r\n", start, end, elapse);
  Serial.print(strBuffer);
  
  // cosf
  start = micros();
  for (int i = 0; i < LOOP_N; i++) {
    buffer[i] = cosf((float)i / LOOP_N);
  }
  end = micros();
  elapse = end - start;
  sprintf(strBuffer, "cosf\t%ld\t%ld\t%ld\r\n", start, end, elapse);
  Serial.print(strBuffer);

  // expf
  start = micros();
  for (int i = 0; i < LOOP_N; i++) {
    buffer[i] = expf((float)i / LOOP_N);
  }
  end = micros();
  elapse = end - start;
  sprintf(strBuffer, "expf\t%ld\t%ld\t%ld\r\n", start, end, elapse);
  Serial.print(strBuffer);

  // logf
  start = micros();
  for (int i = 0; i < LOOP_N; i++) {
    buffer[i] = logf((float)i / LOOP_N);
  }
  end = micros();
  elapse = end - start;
  sprintf(strBuffer, "logf\t%ld\t%ld\t%ld\r\n", start, end, elapse);
  Serial.print(strBuffer);
  
  // sqrtf
  start = micros();
  for (int i = 0; i < LOOP_N; i++) {
    buffer[i] = sqrtf((float)i / LOOP_N);
  }
  end = micros();
  elapse = end - start;
  sprintf(strBuffer, "sqrtf\t%ld\t%ld\t%ld\r\n", start, end, elapse);
  Serial.print(strBuffer);  

  Serial.print("\r\nEnd.\r\n");
}


void loop() {
  // put your main code here, to run repeatedly:

}
