int n;
int sum;
double average;
void setup()
{
  //variables
  Serial.begin(19200);
  n = 1;
  sum = 0.0;
  average = 0.0;
}

void loop()
{
 int AnalogValue;
  if(n<50)
  {
    AnalogValue = analogRead(A0);
    sum = sum + AnalogValue;
    average = (double)(sum / n);
    n = n + 1;
  
    Serial.print("Light sensor value = \"");
    Serial.println(AnalogValue);
    Serial.print("New average = \"");
    Serial.println(average);
    Serial.print("\"");

    delay(1000);
  }
 else if ( n == 50)
 {
    n++;
    if (average >= 500)
    {
      Serial.print("Based on the sunlight from this area, we recommend that you place a plant that can tolerate low levels of light.");
      Serial.print("\"");
    }

    else if(average < 500 )
    {
      Serial.print("Based on the sunlight from this area, we recommend that you place a plant that can tolerate full sunlight.");
      Serial.print("\"");
    }
  }
}
