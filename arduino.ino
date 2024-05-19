#define BUZZER_PIN_NUM              6
#define ULTRASONIC_TRIG_PIN_NUM     9
#define ULTRASONIC_ECHO_PIN_NUM     10

void setup() {
  // put your setup code here, to run once:
  pinMode(ULTRASONIC_TRIG_PIN_NUM, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN_NUM, INPUT);
  pinMode(BUZZER_PIN_NUM, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float g_duration, g_distance;
  digitalWrite(ULTRASONIC_TRIG_PIN_NUM, LOW);
	delayMicroseconds(10);
	digitalWrite(ULTRASONIC_TRIG_PIN_NUM, HIGH);
  g_duration = pulseIn(ULTRASONIC_ECHO_PIN_NUM, HIGH);
  g_distance = (g_duration*.0343)/2;
  Serial.print("Distance: ");
	Serial.println(g_distance);
  delay(10);
  if (g_distance < 15){
      if (g_distance < 3){
        tone(BUZZER_PIN_NUM, 1000);
      }
      else{
        tone(BUZZER_PIN_NUM, 1000);
        delay(1000 - map((int)g_distance, 2, 15, 1000, 0));
        noTone(BUZZER_PIN_NUM);
        delay(1000 - map((int)g_distance, 2, 15, 1000, 0));
      }
  }
}
