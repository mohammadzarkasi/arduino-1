//const int PI
int myTimer = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  double potentio = analogRead(0);
  

//  int v = map(potentio, 0,1023, 50, 1000);
  int v = map(potentio, 0,1023, 0, 255);

  Serial.print("analog: ");
  Serial.print(potentio);
  Serial.print(", delay blip: ");
  Serial.println(v);
  
//  analogWrite(10, v);
//  tone(6, 40);
//  delay(500);
//  tone(6, 1000);
//  delay(500);
//  tone(6, 500);
//  delay(500);
//  if(v>=1000){
//      analogWrite(10, 0);
//    delay(v);
//  }
//  else {
//    analogWrite(10, 50);
//    delay(v);
//    analogWrite(10, 0);
//    delay(v);
//  }
  
//  blink1();

//  playNote('c', 100);
//  playNote('C', 100);
//  playNote('e', 1);
//  playNote('f', 1);
//char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
//  tone(6, 1915);
//  delay(500);
//  tone(6, 1700);
//  delay(500);
//  tone(6, 1519);
//  delay(500);
//  delay(1000);
  myTone(tones, 500);
}

void myTone(int *tones, int d){
//  int l = sizeof(tones);
  for(int i = 7; i >= 0; i--){
    tone(6, tones[i]);
    delay(d);
  }
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(6, HIGH);
    delayMicroseconds(tone);
    digitalWrite(6, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void blink1(){
  myTimer++;
  if(myTimer > 10) {
    myTimer = 0;
  }

  if(myTimer < 5) {
    digitalWrite(11, HIGH);
  }
  else if(myTimer < 10) {
    digitalWrite(11, LOW);
  }
}
