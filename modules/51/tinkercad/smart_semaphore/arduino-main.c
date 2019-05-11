//
// Signal stays green for 45 seconds then goes red for 10 seconds
// If pedestrian presses button signal goes red
// Pedestrian can only press buitton again after 20 seconds
//

const unsigned long carRedDuration = 10000L;
const unsigned long carYellowDuration = 2000;
const unsigned long carGreenDuration = 45000L; // 90 seconds

const unsigned long minimumWaitForPedestrianGreen = 20000L;
const unsigned long blinkPedestrianRedFor = 2000L;
const unsigned long blinkPedestrianGreenFor = 1000L;

const int phaseCarRed = 0;
const int phaseCarYellow = 1;
const int phaseCarGreen = 2;

const int carRedLed = 13;
const int carYellowLed = 12;
const int carGreenLed = 11;
const int pedestrianRedLed = 10;
const int pedestrianGreenLed = 9;
const int pedestrianButton = 7;
const int pedestrianButtonWarningLed = 6;

unsigned long nextPedestrianButtonAllowed = 0L;
unsigned long nextTimer = 0;
int phase = phaseCarRed;
int userPressedButton = 0;
int lastButtonState = 0;
int detectUserPressedButton = 0;

void setup()
{
  pinMode(carRedLed, OUTPUT);
  pinMode(carYellowLed, OUTPUT);
  pinMode(carGreenLed, OUTPUT);
  pinMode(pedestrianRedLed, OUTPUT);
  pinMode(pedestrianGreenLed, OUTPUT);
  pinMode(pedestrianButtonWarningLed, OUTPUT);
  pinMode(pedestrianButton, INPUT);
  
  Serial.begin(9600);
}

void progressSemaphore() {
  unsigned long time = millis();
  long nextTimerDiff = nextTimer - time;
  int blinkOutput = LOW;
  if (time % 200L > 100L) {
    blinkOutput = HIGH;
  }
  
  int triggerPedestrianCycle = 0;
  // Has the user pressed the button?
  if (userPressedButton > 0) {
    digitalWrite(pedestrianButtonWarningLed, blinkOutput);
    if (time > nextPedestrianButtonAllowed) {
      nextPedestrianButtonAllowed = time + minimumWaitForPedestrianGreen;
      digitalWrite(pedestrianButtonWarningLed, LOW);
      userPressedButton = 0;
      triggerPedestrianCycle = 1;
    }
  }
  
  // Check if the phase should change
  if (nextTimerDiff <= 0 || triggerPedestrianCycle > 0) {
    // Progress things
    digitalWrite(carRedLed, LOW);
    digitalWrite(carYellowLed, LOW);
    digitalWrite(carGreenLed, LOW);
    digitalWrite(pedestrianRedLed, LOW);
    digitalWrite(pedestrianGreenLed, LOW);

    if (triggerPedestrianCycle) {
      phase = phaseCarYellow;
	  digitalWrite(carYellowLed, HIGH);
      nextTimer = time + carYellowDuration;
    } else if (phase == phaseCarRed) {
      // After red comes green
      phase = phaseCarGreen;
	  digitalWrite(carGreenLed, HIGH);
	  digitalWrite(pedestrianRedLed, HIGH);
      nextTimer = time + carGreenDuration;
    } else if (phase == phaseCarYellow) {
      // After yellow comes red
      phase = phaseCarRed;
	  digitalWrite(carRedLed, HIGH);
	  digitalWrite(pedestrianGreenLed, HIGH);
      nextTimer = time + carRedDuration;
    } else if (phase == phaseCarGreen) {
      // After green comes yellow
      phase = phaseCarYellow;
	  digitalWrite(carYellowLed, HIGH);
      nextTimer = time + carYellowDuration;
    }
  } else {
    // Stay on the same, no change - but blink
    if (phase == phaseCarRed) {
      // Next phase for pedestrian is blink green, see if should blink
      if (nextTimerDiff < blinkPedestrianRedFor) {
        digitalWrite(pedestrianRedLed, blinkOutput);
      }
    } else if (phase == phaseCarYellow) {
      digitalWrite(pedestrianGreenLed, blinkOutput);
    } else if (phase == phaseCarGreen) {
      if (nextTimerDiff < blinkPedestrianGreenFor) {
        digitalWrite(pedestrianGreenLed, blinkOutput);
      }
    }
  }
}

void loop()
{
  int button = digitalRead(pedestrianButton);
  if (button != lastButtonState) {
    if (button == HIGH) {
      userPressedButton = 1;
    }
    lastButtonState = button;
  }
  progressSemaphore();
    
  
  delay(1);
}