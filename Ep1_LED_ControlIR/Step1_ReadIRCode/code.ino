#include <IRremote.h>

#define IR_RECEIVE_PIN 15  // Pin data sensor IR di ESP32 (gunakan pin sesuai keinginan)

void setup() {
  Serial.begin(115200);  
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Aktifkan IR receiver
  Serial.println("Siap terima sinyal remote!");
}

void loop() {
  if (IrReceiver.decode()) {  // Cek ada sinyal masuk atau nggak
    unsigned long kodeIR = IrReceiver.decodedIRData.decodedRawData;  // Ambil kode IR-nya

    if (kodeIR != 0 && kodeIR != 0xFFFFFFFF) {  // Cek valid atau enggak
      Serial.print("Kode IR Diterima: ");
      Serial.println(kodeIR, HEX);  // Tampilkan kode dalam format HEX
    }

    IrReceiver.resume();  // Reset untuk baca sinyal berikutnya
  }
  delay(100);
}
