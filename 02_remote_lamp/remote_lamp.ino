// Define the pins
int lamp_pin = D5;

// Lamp state
bool lamp_state;

// This routine runs only once upon reset
void setup()
{
   // Register our Particle function here
   Particle.function("lamp", lampControl);
   
   // Set relay pin to OUTPUT
   pinMode(lamp_pin,OUTPUT);
   
   // Shut lamp off by default
   digitalWrite(lamp_pin, 0);
   lamp_state = false;
   
}


// This routine loops forever 
void loop()
{
   // Nothing to do here
}

// Lamp control
int lampControl(String command)
{
  // Invert state
  lamp_state = !lamp_state;

  // Apply command
  digitalWrite(lamp_pin,lamp_state);
   
   return 1;
}