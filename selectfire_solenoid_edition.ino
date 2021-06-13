
// For private use only
// contact me at alphamods.commissions@gmail.com to find out more
//feedback is welcome
//enjoy






// A nice way of controlling things to ensure that if something isn't right, I can change it with two words rather than twenty
const int ON = HIGH;
const int OFF = LOW;

// Pin slots and counting

int trigger = 1;

int semi = 2;
int full = 4;
int burst = 3;

int sol = 5;
int val = 0;
int counter = 0;

//sets isFiring to false

bool isFiring = false;

// This part controls the timing of the firing
// delay is not yet set to proper timings, and as such should be adjusted for your use

void fireBullet() {
    if (isFiring = false) {
      isFiring = true;
      digitalWrite (sol, ON);
      delay(500);
      digitalWrite(sol, OFF);
      delay(500);
      isFiring = false;
    }
  }
// tells it how many times to fire


void fireBulletFixedAmt(int bulletAmt) {

  for (int i = 0; i < bulletAmt; i++) {
      fireBullet();
    }
  }


//setup the pins
void setup() {
  pinMode(trigger, INPUT);
  pinMode(semi, INPUT);
  pinMode(burst, INPUT);
  pinMode(full, INPUT);
  
  pinMode(sol, OUTPUT); 

}

//begins selecting module

void loop() {
 
  
 // checks if trigger is pulled
  if (digitalRead(trigger) == ON)
  {  
// checks which is selected and which to do   
    
    //burst
    if (digitalRead(burst)== ON){
      fireBulletFixedAmt(3);
    }
    
    //single
    if (digitalRead(semi)== ON){
      fireBulletFixedAmt(1);
    }
    
    //full auto
    if (digitalRead(full)== ON){
      fireBullet();
    }
  }  
  else
  {
       digitalWrite(sol, OFF);
  }
}




// Made by Alpha for private use and for all modders
