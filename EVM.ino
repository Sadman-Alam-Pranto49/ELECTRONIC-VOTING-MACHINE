#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define S1 15
#define S2 16
#define S3 17
#define S4 18
#define S5 19
int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;
void setup()
{
pinMode(S1, INPUT);
pinMode(S2,INPUT);
pinMode(S3,INPUT);
pinMode(S4,INPUT);
pinMode(S5,INPUT);
lcd.begin(16, 2);
lcd.print(" Electronic ");
lcd.setCursor(0,1);
lcd.print(" Voting Machine ");
delay(4000);
digitalWrite(S1, HIGH);
digitalWrite(S2, HIGH);
digitalWrite(S3, HIGH);
digitalWrite(S4, HIGH);
digitalWrite(S5, HIGH);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("A");
lcd.setCursor(4,0);
lcd.print("B");
lcd.setCursor(8,0);
lcd.print("C");
lcd.setCursor(12,0);
lcd.print("D");
}
void loop()
{
lcd.setCursor(0,0);
lcd.print("A");
lcd.setCursor(1,1);
lcd.print(vote1);
lcd.setCursor(4,0);
lcd.print("B");
lcd.setCursor(5,1);
lcd.print(vote2);
lcd.setCursor(8,0);
lcd.print("C");
lcd.setCursor(9,1);
lcd.print(vote3);
lcd.setCursor(12,0);
lcd.print("D");
lcd.setCursor(13,1);
lcd.print(vote4);
if(digitalRead(S1)==0)
vote1++;
while(digitalRead(S1)==0);
if(digitalRead(S2)==0)
vote2++;
while(digitalRead(S2)==0);
if(digitalRead(S3)==0)
vote3++;
while(digitalRead(S3)==0);
if(digitalRead(S4)==0)
vote4++;
while(digitalRead(S4)==0);
if(digitalRead(S5)==0)
{
int vote=vote1+vote2+vote3+vote4;
if(vote)
{
if((vote1 > vote2 && vote1 > vote3 && vote1 > vote4))
{
lcd.clear();
lcd.print("A is Winner");
delay(3000);
lcd.clear();
}
else if((vote2 > vote1 && vote2 > vote3 && vote2 > vote4))
{
lcd.clear();
lcd.print("B is Winner");
delay(3000);
lcd.clear();
}
else if((vote3 > vote1 && vote3 > vote2 && vote3 > vote4))
{
lcd.clear();
lcd.print("C is Winner");
delay(3000);
lcd.clear();
}
else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
{
lcd.setCursor(0,0);
lcd.clear();
lcd.print("D is Winner");
delay(3000);
lcd.clear();
}

else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
{
lcd.setCursor(0,0);
lcd.clear();
lcd.print("D is Winner");
delay(3000);
lcd.clear();
}

else
{
lcd.clear();
lcd.print(" Tie Up Or ");
lcd.setCursor(0,1);
lcd.print(" No Result ");
delay(3000);
lcd.clear();
}

}
else
{
lcd.clear();
lcd.print("No Voting....");
delay(3000);
lcd.clear();
}
vote1=0;vote2=0;vote3=0;vote4=0,vote=0;
lcd.clear();
}

}
