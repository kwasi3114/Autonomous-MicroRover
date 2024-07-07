/*Arduino pin is connected to the Motor drive module*/
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

//#define ECHO_PIN A4
//#define TRIG_PIN A5

/*
  Control motor：Car movement forward
*/
void forward(int16_t in_carSpeed)
{
  analogWrite(ENA, in_carSpeed);
  analogWrite(ENB, in_carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

/*
  Control motor：Car moving backwards
*/
void back(int16_t in_carSpeed)
{
  analogWrite(ENA, in_carSpeed);
  analogWrite(ENB, in_carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void setup() {
  // put your setup code here, to run once:
    //set constant speed to 41.62, or roughly 2cm/s
  //Serial.begin(9600);
  //Serial.print("Serial Live"\n);

}

void loop() {
  // put your main code here, to run repeatedly:
  forward(1000);
  delay(1000);
  back(1000);
  delay(1000);
}
