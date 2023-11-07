int receivedZero = 0;
const int ledPin2 = 2;
const int ledPin3 = 3;
const int ledPin4 = 4;
const int ledPin5 = 5;
String receivedString = "";

void setup() {
  Serial.begin(9600);
  
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    receivedString = Serial.readStringUntil('\n');  // Lee una cadena hasta encontrar una nueva línea ('\n')
    receivedString.trim();  // Elimina espacios en blanco adicionales alrededor de la cadena

    if (receivedString == "0") {
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, LOW);
      Serial.println("Holas");
      delay(1000);
      Serial.println("0");
    }  else if (receivedString == "3") {
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, LOW);
      delay(10);
    } else if (receivedString == "4") {
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, HIGH);
      digitalWrite(ledPin5, LOW);
      delay(10);
    } else if (receivedString == "5") {
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, HIGH);
      delay(10);
    }else if (receivedString == "Hola Arduino, ¿como estás?") {
      Serial.println("Holas, bien y tu?");
      delay(10);
      Serial.println("0");
    }else if (receivedString == "bien") {
      Serial.println("que weno");
      delay(10);
      Serial.println("0");
    }
  }
}

