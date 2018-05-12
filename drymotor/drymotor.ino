// DECLARE VARIABLES

byte incoming;
int countSteps = 0;

// BIG STEPPER:
const int step_pin = 8;
const int direction_pin = 9;
const int STEPS_PER_TURN = 200;
// for 60 RPM speed
const int delay_between_step_microsec = 9000; //make it higher to make platform move slower

// SMALL STEPPER FOR RACK AND PINION (YOGURT):
int Pin0 = 7;
int Pin1 = 6;
int Pin2 = 5;
int Pin3 = 4;
int _step = 0;
boolean dir = false;// gre

// SMALL STEPPER FOR DRY DISPENSER:
int Pin4 = 13;
int Pin5 = 12;
int Pin6 = 11;
int Pin7 = 10;

// SETUP
void setup()
{
  Serial.begin(9600);
  pinMode(step_pin, OUTPUT);
  pinMode(direction_pin, OUTPUT);
  pinMode(Pin0, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  pinMode(Pin5, OUTPUT);
  pinMode(Pin6, OUTPUT);
  pinMode(Pin7, OUTPUT);
}

void loop() {
  // start dispensing dry stuff
  for (int i = 0; i <= 2000; i++) {
    dir = false;
    dry_step();
    delay(2);
  }
  for (int i = 0; i <= 2000; i++) {
    dir = true;
    dry_step();
    delay(2);
  }

}

void step(bool forward)
{
  // setting the direction
  if (forward == true)
  {
    digitalWrite(direction_pin, HIGH);
  }
  else
  {
    digitalWrite(direction_pin, LOW);
  }
  // creating a step
  digitalWrite(step_pin, HIGH);
  // minimum delay is 1.9us
  //delay(500);
  digitalWrite(step_pin, LOW);
}

// STEPPING THE BIG STEPPER
void big_steps(int number_of_steps)
{
  bool move_forward = true;
  // Establishing the direction
  if (number_of_steps >= 0)
  {
    move_forward = true;
  }
  else
  {
    move_forward = false;
    number_of_steps = -number_of_steps;
  }
  // Generating the steps
  for (int i = 0; i < number_of_steps; i++)
  {
    step(move_forward);
    // Delay for proper speed
    delayMicroseconds(delay_between_step_microsec);
  }
}

// STEPPING THE SMALL STEPPER FOR YOGURT
void small_steps() {
  // write current _step to motor
  switch (_step) {
    case 0:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
    case 1:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      break;
    case 2:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 3:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 4:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 5:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 6:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 7:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
    default:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
  }
  //
  // change step

  if (dir) {
    _step++;
  } else {
    _step--;
  }
  if (_step > 7) {
    _step = 0;
  }
  if (_step < 0) {
    _step = 7;
  }
}

// STEPPING THE SMALL STEPPER FOR DRY
void dry_step() {
  // write current _step to motor
  switch (_step) {
    case 0:
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin7, HIGH);
      break;
    case 1:
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin6, HIGH);
      digitalWrite(Pin7, HIGH);
      break;
    case 2:
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin6, HIGH);
      digitalWrite(Pin7, LOW);
      break;
    case 3:
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin5, HIGH);
      digitalWrite(Pin6, HIGH);
      digitalWrite(Pin7, LOW);
      break;
    case 4:
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin5, HIGH);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin7, LOW);
      break;
    case 5:
      digitalWrite(Pin4, HIGH);
      digitalWrite(Pin5, HIGH);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin7, LOW);
      break;
    case 6:
      digitalWrite(Pin4, HIGH);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin7, LOW);
      break;
    case 7:
      digitalWrite(Pin4, HIGH);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin7, HIGH);
      break;
    default:
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin7, LOW);
      break;
  }
  //
  // change step

  if (dir) {
    _step++;
  } else {
    _step--;
  }
  if (_step > 7) {
    _step = 0;
  }
  if (_step < 0) {
    _step = 7;
  }
}



