const byte numChars = 20;
char dataIn[numChars];

const short pins[] = {2,3,6,9,12};
//change pins[] to reflect actual wiring of arduino

char startMarker = '<';
char endMarker = '>';

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
  pinMode(pins[i], OUTPUT);
  digitalWrite(pins[i], 0);
  delay(5);
  digitalWrite(pins[i], 1);
  delay(300);
  digitalWrite(pins[i], 0);
  }

  delay(100);
}

void loop() {
  updateData();

  for (int i = 0; i < 5; i++) {
    if (dataIn[i] == '1') {
      digitalWrite(pins[i], 1);
    } else {
      digitalWrite(pins[i], 0);
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
