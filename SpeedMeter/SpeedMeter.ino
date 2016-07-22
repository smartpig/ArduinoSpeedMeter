//Bluetooth Internet Speed Meter

int meterpin = 24;
int maxmbps = 75;

void setup() {
  // put your setup code here, to run once:
  // setup pin for Meter
  pinMode(meterpin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // check serial available
  if (Serial.available()) {
    //set timeout to stop reading in milliseconds
    Serial.setTimeout(1000);
    // Read Serial data into int currentmbps - gets speed as kbps and divides by 100 to get Mbps value.
    int currentmbps = (Serial.parseInt()/100);
    // determine percentage of max speed and convert to percentage of max voltage range (0 - 255)
    int voltageValue = ((currentmbps/maxmbps)*255);
    // Check if voltageValue is greater than 1
    if (voltageValue >= 255) {
      analogWrite(meterpin, 255);
    }
    if (voltageValue < 1) {
      analogWrite(meterpin, voltageValue);
    }
    
  }
  
}
