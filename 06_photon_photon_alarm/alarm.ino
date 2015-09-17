// Pins
int ledPin = D5;
int buzzerPin = D1; 

// Variables for the flashing LDED
int ledState = LOW;
long previousMillis = 0; 
long interval = 100;  // Interval at which to blink (milliseconds)

// Alarm
bool alarmOn = false;

void setup() {
    
  // Set pins as outputs
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Subscribe to other board light level measurement
  Particle.subscribe("motion_yjMgA5xX", myHandler);
  
  // Declare function
  Particle.function("stop", stopAlarm);
  
}


void loop() {
    
  if (alarmOn) {
      unsigned long currentMillis = millis();
      if(currentMillis - previousMillis > interval) {
        previousMillis = currentMillis;   
        
        if (ledState == LOW) {ledState = HIGH;}
        else {ledState = LOW;}
      }
        
      // Switch the LED
      digitalWrite(ledPin, ledState);
      
      // Activate buzzer
      tone(buzzerPin, 1000);
  }
  else {
      // Switch alarm off
      digitalWrite(ledPin, 0);
      noTone(buzzerPin);
  }
  
}


// Function called whenever ambient light level is published
void myHandler(const char *event, const char *data)
{
  
  // Convert data to int
  int motion = atoi(data);
  
  // Activate alarm ?
  if (motion == 1) { 
    alarmOn = true;
  }
}

// Function to stop the alarm
int stopAlarm(String command)
{
  alarmOn = false;
  return 1;
}