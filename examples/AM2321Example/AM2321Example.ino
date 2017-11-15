#include <AM2321.h>

AM2321 am2321;

char str[8];
unsigned long result = 0;
unsigned int temp, humi = 0;
unsigned int amID = 0;

void setup()
{
    Serial.begin(115200);
    am2321.begin();
}

void loop()
{
    amID = am2321.readID();
    delay(2000);	//必须等待至少2s才能对器件进行下一次读取
    result = am2321.readAll();
    humi = result>>16;
    temp = result & 0xFFFF;

    Serial.print("ID: ");
    Serial.print(amID);
    Serial.print(", Temp: ");
    Serial.print(temp/10.0);
    Serial.print(", Humi: ");
    Serial.println(humi/10.0);
    delay(2000); //必须等待至少2s才能对器件进行下一次读取
}
