char serialData;

//define os pinos usados pelos LEDs
#define led_1 2
#define led_2 4
#define led_3 6

//variaveis de atividade dos LEDs
bool LED_1 = false;
bool LED_2 = false;
bool LED_3 = false;


void setup() {
  Serial.begin(9600);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    
    serialData = Serial.read();
    Serial.println(serialData);

    switch (serialData) {
      case 'A':
        LED_1 = !LED_1;
        Serial.println(serialData);
        break;
        
      case 'B':
        LED_2 = !LED_2;
        Serial.println(serialData);
        break;
        
      case 'C':
        LED_3 = !LED_3;
        Serial.println(serialData);
        break;
        
      default:
        break;
    }
    digitalWrite(led_1, LED_1);
    digitalWrite(led_2, LED_2);
    digitalWrite(led_3, LED_3);
  }
}
