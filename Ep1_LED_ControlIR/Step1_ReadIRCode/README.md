# 🎯 Step 1: Baca Kode Remote IR  

## 🛠️ Tujuan  
- Membaca kode tombol dari remote IR.  
- Persiapan dasar buat kontrol LED di step berikutnya.  

---

## 🔧 Alat & Bahan  
- ESP32 / Arduino Uno  
- Sensor IR receiver (contoh: VS1838B)  
- Remote IR (bisa remote TV)  
- Kabel jumper  
- Breadboard  

---

## 🛠️ Rangkaian  
**Sambungkan komponen seperti ini:**  
**Pasang ESP32 di breadboard.**    
**Pasang sensor IR:**

**(gambar sensor IR)**

   - **Pin OUT** ke **GPIO 15** (atau pin lain).  
   - **Pin VCC** ke **3.3V** di ESP32.  
   - **Pin GND** ke **GND** ESP32.  

**(Tambahkan gambar rangkaian di sini)**  

---

## 💻 Kode Program  

<a href="https://github.com/SiB-Project13-7/Smart-Home-Mini/blob/main/Ep1_LED_ControlIR/Step1_ReadIRCode/code.ino">file kode </a>

```cpp
#include <IRremote.h>

#define IR_RECEIVE_PIN 15  // Pin data sensor IR di ESP32

void setup() {
  Serial.begin(115200);  
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Aktifkan IR receiver
  Serial.println("Siap terima sinyal remote!");
}

void loop() {
  if (IrReceiver.decode()) {  // Cek ada sinyal masuk nggak
    unsigned long kodeIR = IrReceiver.decodedIRData.decodedRawData;  // Ambil kode IR-nya

    if (kodeIR != 0 && kodeIR != 0xFFFFFFFF) {  // Cek valid atau enggak
      Serial.print("Kode IR Diterima: ");
      Serial.println(kodeIR, HEX);  // Tampilkan kode dalam format HEX
    }

    IrReceiver.resume();  // Reset untuk baca sinyal berikutnya
  }
  delay(100);
}
