#include <Wire.h>
#include <wiinunchuck.h>

void setup() {
  // Initialize the nunchuk
  nunchuk_setpowerpins();
  nunchuk_init();
  nunchuk_send_request();
  
  // Open the serial port at 9600 baud
  Serial.begin(9600);
  Serial.println("Ready");
}

// forward -> left
// back -> right
// left -> back
// right -> forward

void loop() {
  if (nunchuk_get_data() > 0) {
    // at this point, nunchuk_buf contains data
    int angle = nunchuk_joyangle() - 90;
    
    if (angle < 0) {
      angle += 360;
    }
    
    Serial.print(nunchuk_zbutton());
    Serial.print(" ");
    Serial.print(nunchuk_cbutton());
    Serial.print(" ");
    Serial.print(angle);
    Serial.print(" ");
    Serial.print(nunchuk_joyrad());
    Serial.print(" ");
    Serial.println(nunchuk_rollangle());
  }
}
