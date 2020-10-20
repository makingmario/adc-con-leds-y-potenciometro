/*
conversor de 10 bits: (2^10)=1024, los valores van desde 
0 a 1023
-Un pin ADC lee 5V e interpreta este valor como 1023
-un pin ADC lee 0V e interpreta este valor como 0
 entonces  podemos decir:
5V ---> 1023
0V ---> 0

Para facilitar las cosas vamos a utilzar el valor 
que obtiene el ADC

queremos saber el valor cuando el voltaje sea 1/3 de 5V (1.66V)
y 2/3 de 5V (3.33V)
____________________________
   5V --> 1023
1.66V --> X

x = 341
____________________________

   5V --> 1023
3.33V --> X

x = 682
____________________________

EJERCICIO:

voltaje en A0 <= 1.66V           ==> led verde ON
voltaje en A0 > 1.66V y <= 3.33V ==> led amarillo ON
voltaje en A0 > 3.33V y <= 5V    ==> led rojo ON
*/
#define rojo      13
#define amarillo  12
#define verde     11

void setup() 
{
 pinMode(rojo,OUTPUT);
 pinMode(amarillo,OUTPUT);
 pinMode(verde,OUTPUT);

 digitalWrite(rojo,LOW);
 digitalWrite(amarillo,LOW);
 digitalWrite(verde,LOW);
}

void loop() 
{
    if(analogRead(A0)<=341)//0 a 341 (0V a 1.66V)
    {
      digitalWrite(verde,HIGH);
      digitalWrite(amarillo,LOW);
      digitalWrite(rojo,LOW);
    }
  
  if(analogRead(A0)>341 && analogRead(A0)<=682)//342 a 682 (1.66V a 3.33V)
    {
      digitalWrite(verde,LOW);
      digitalWrite(amarillo,HIGH);
      digitalWrite(rojo,LOW);
    }
  
   if(analogRead(A0)>682)//683 a 1023 (3.33V a 5V)
    {
      digitalWrite(verde,LOW);
      digitalWrite(amarillo,LOW);
      digitalWrite(rojo,HIGH);
    }
}
