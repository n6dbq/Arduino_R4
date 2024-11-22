#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_GS4 41
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define REST 0
// its a small world notes
int melody[] = {
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_E5,
  NOTE_C5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_B4, NOTE_B4, NOTE_D4,
  NOTE_E4, NOTE_F4, NOTE_D5, NOTE_B4,
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_G4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_C5, NOTE_A4, NOTE_D5,
  NOTE_E5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_G4, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_C5, NOTE_C5, REST, NOTE_C5,
  REST, NOTE_C5, NOTE_E5,
  NOTE_C5, NOTE_D5, REST, NOTE_D5,
  NOTE_D5, NOTE_D5, REST, NOTE_D5,
  NOTE_F5, NOTE_D5, NOTE_E5, REST,
  NOTE_E5, NOTE_E5, NOTE_E5, REST,
  NOTE_E5, NOTE_G5, NOTE_E5, NOTE_F5,
  REST, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_G4, NOTE_B4, NOTE_C5, NOTE_C5, REST
};
int noteDurations[] = {
  8, 8, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8,
  4, 4, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4,
  8, 8, 4, 8, 8, 4, 4, 4, 4, 2, 4, 4, 4, 8, 8, 4, 4,
  4, 8, 8, 2, 4, 8, 8, 4, 4, 4, 8, 8,
  2, 4, 8, 8, 4, 4, 4, 8, 8, 4, 8, 8, 2, 2, 2, 4, 4
};
int buzPin = 3;
int note;

void setup() {
  pinMode(buzPin, OUTPUT);
  Serial.begin(115200);
  for (note = 0; note < sizeof(melody); note = note + 1) {
    tone(buzPin, melody[note], 2000 / noteDurations[note]);
    delay(2000 / noteDurations[note] * 1.2);
  }
}
void loop() {
  digitalWrite(buzPin, LOW);  //to quiet the buzzer after song
}
