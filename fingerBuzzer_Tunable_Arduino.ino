const byte numChars = 20;
char dataIn[numChars];
const short pins[] = {2,3,6,9,12};
//const short pins[] = {6,5,4,3,2};
char startMarker = '<';
char endMarker = '>';

#define ON 255 //max value of 255
#define OFF 0

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
  pinMode(pins[i], OUTPUT);
  analogWrite(pins[i], OFF);
  delay(5);
  analogWrite(pins[i], ON);
  delay(300);
  analogWrite(pins[i], OFF);
  }

  delay(100);
}

void loop() {
  updateData();

  for (int i = 0; i < 5; i++) {
    if (dataIn[i] == '1') {
      analogWrite(pins[i], ON);
    } else {
      analogWrite(pins[i], OFF);
    }
  }

}

void updateData() {
    static boolean recvInProgress = false;
    static byte j = 0;
    char rc;
    bool newData = false;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                dataIn[j] = rc;
                j++;
                if (j >= numChars) {
                    j = numChars - 1;
                }
            }
            else {
                dataIn[j] = '\0';
                recvInProgress = false;
                j = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}
