//Bluetooth Internet Speed Meter

int maxmbps = 900;
float readserial = 700;
int currentmbps = 700;
int maxvolt = 255;
static int meterpin = 9;
static int bufsiz = 8;

void setup() {
  TCCR1B = TCCR1B & 0b11111001;
  // setup pin for Meter
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  //set timeout to stop reading in milliseconds
  //Serial.setTimeout(1000);
  analogWrite(meterpin, 250);
}

void loop() {
  // check serial available
if (Serial.available() > 0) {

     //get serial data for speed
    readserial=serialreadvalue();
    currentmbps = (int) readserial;
//    if (Serial.read() == '\n') {

    // if Current Speed is greater than max speed, set meter to max
      if (currentmbps >= maxmbps) {
        analogWrite(meterpin, maxvolt);
        Serial.print("Code got to first IF statement");
        Serial.println();
        Serial.print("Current mbps: ");
        Serial.print(currentmbps);
        Serial.println();
      }
// otherwise, we need to set a non max voltage push scale voltage to meter
      if (currentmbps <= (maxmbps-5)) {
        // determine percentage of max speed and convert to percentage of max voltage range
        int voltagevalue = roundedDivision(currentmbps, maxmbps, maxvolt);
        analogWrite(meterpin, voltagevalue);
        Serial.print("Code got to second IF statement");
        Serial.println();
        Serial.print("Current mbps: ");
        Serial.print(currentmbps);
        Serial.println();
        Serial.print("Voltage Value: ");
        Serial.print(voltagevalue);
        Serial.println();
      }
//    }
  }
}

int serialreadvalue() {
  char buf[bufsiz];
  buf[0] = '\0';
  for (int i = 0; ; ) {
    if (Serial.available() <= 0) {
      delayMicroseconds(521);
    } else {
      buf[i] = Serial.read();
      if (buf[i] == '\r' || buf[i] == '\n' || buf[i] == '\0') {
        buf[i] = '\0';
        break;
      }
      (i < bufsiz-1) ? i++ : 0;
    }
  }
  return(atoi(buf));
}

int roundedDivision(int n, int d, int maxv)
{
  float r1 = (float)n / (float)d;
  float v1 = r1 * maxv;
  int r2 = n / d;
  int v2 = r2 * maxv;
  Serial.print("Calculated Float Voltge: ");
  Serial.print(v1);
  Serial.println();
  Serial.print("Calculated Int Voltge: ");
  Serial.print(v2);
  Serial.println();

  v1 -= v2;
  if(v1 >= 0.5)
     v2++;

  Serial.print("Rounded Int Voltge: ");
  Serial.print(v2);
  Serial.println();
  int v3 = (int) v1;
  v3 = v3+5;
  Serial.print("Cast Int Voltge: ");
  Serial.print(v3);
  Serial.println();
  return v3;
}
