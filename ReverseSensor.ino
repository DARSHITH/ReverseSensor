const int greenled = 4;     //D2
const int redledbuzzer = 5; //D1
const int trigPin = 2;      //D4
const int echoPin = 0;      //D3
long duration;
int distance;

void setup() {
  pinMode(redledbuzzer, OUTPUT);  // Sets the redledbuzzer as an Output
  pinMode(greenled, OUTPUT);      // Sets the greenled as an Output
  pinMode(trigPin, OUTPUT);       // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);        // Sets the echoPin as an Input
  Serial.begin(115200);           // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 us
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads echoPin, returns the sound wave travel time in us
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance>15)
{
  digitalWrite(redledbuzzer, LOW);
  digitalWrite(greenled, HIGH);
  delay(1000);
  digitalWrite(greenled, LOW);
  delay(1000);
  }
if(distance<=15)
  {
  digitalWrite(greenled, LOW);
  if(distance>10){
    digitalWrite(redledbuzzer, HIGH);
    delay(1000);
    digitalWrite(redledbuzzer, LOW);
    delay(1000);
    }
  else if(distance<=10 && distance>5){
    digitalWrite(redledbuzzer, HIGH);
    delay(400);
    digitalWrite(redledbuzzer, LOW);
    delay(400);
    }
  else{
    digitalWrite(redledbuzzer, HIGH);
    }
  }
}
