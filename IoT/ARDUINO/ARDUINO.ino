#include <Servo.h>

int servo_1 = 3;
int servo_2 = 5;
int servo_3 = 6;
int servo_push = 10;

int E18_1 = 2;
int E18_2 = 4;
int E18_3 = 7;

// Servo
Servo Servo_1;
Servo Servo_2;
Servo Servo_3;
Servo Servo_Push;

int ledPin = 13;

void setup()
{
    Serial.begin(115200); // UART Start
    pinMode(ledPin, OUTPUT);

    pinMode(E18_1, INPUT);
    pinMode(E18_2, INPUT);
    pinMode(E18_3, INPUT);

    Servo_1.attach(servo_1);
    Servo_2.attach(servo_2);
    Servo_3.attach(servo_3);
    Servo_Push.attach(servo_push);

    Servo_1.write(180);
    Servo_2.write(0);
    Servo_3.write(180);
    Servo_Push.write(0);
}

void check_1()
{
    int value;
    while (true)
    {
        value = digitalRead(E18_1);
        if (value == 0)
        {
            Serial.println("Yes");
            Servo_1.write(90);
            delay(1000);
            Servo_1.write(0);
            delay(1000);
            Servo_1.write(180);
            delay(1000);
            break; // Break out of the loop after moving the servo back to position 0
        }
        else
        {
            Serial.println("No");
        }
        delay(100);
    }
}

void check_2()
{
    int value;
    while (true)
    {
        value = digitalRead(E18_2);
        if (value == 0)
        {
            Serial.println("Yes");
            Servo_2.write(90);
            delay(1000);
            Servo_2.write(180);
            delay(1000);
            Servo_2.write(0);
            delay(1000);
            break;
        }
        else
        {
            Serial.println("No");
        }
        delay(100);
    }
}

void check_3()
{
    int value;
    while (true)
    {
        value = digitalRead(E18_3);
        if (value == 0)
        {
            Serial.println("Yes");
            Servo_3.write(90);
            delay(1000);
            Servo_3.write(0);
            delay(1000);
            Servo_3.write(180);
            delay(1000);
            break;
        }
        else
        {
            Serial.println("No");
        }
        delay(100);
    }
}

void loop()
{
    if (Serial.available())
    {
        String command = "";
        while (Serial.available())
        {
            command = Serial.readString();
        }

        if (command == "ledon")
        {
            digitalWrite(ledPin, HIGH);
            Serial.println("ledon");
        }
        else if (command == "ledoff")
        {
            digitalWrite(ledPin, LOW);
            Serial.println("ledoff");
        }

        if (command == "type1" || command == "type2" || command == "type3" || command == "type4")
        {
            Servo_Push.write(135);
            delay(1000);
            Servo_Push.write(0);
            delay(100);
            if (command == "type1")
            {
                Serial.println("type1");
                check_1();
                Serial.println("type1 done");
            }
            else if (command == "type2")
            {
                Serial.println("type2");
                check_2();
                Serial.println("type2 done");
            }
            else if (command == "type3")
            {
                Serial.println("type3");
                check_3();
                Serial.println("type3 done");
            }
            else if (command == "type4")
            {
                Serial.println("type4");
                delay(400);
            }
        }
    }
}
