const int light_pin = D2;

void setup() {
  Serial.begin(9600);
  pinMode(light_pin, INPUT);
}

void loop() {
  int light = analogRead(light_pin);
  Serial.println(light);
}
