#include <WiFi.h>
#include <ThingSpeak.h>
char ssid[] = "Dinh Thanh";   
char pass[] = "thanhdat16";   
const char* server = "api.thingspeak.com";
WiFiClient  client;

unsigned long myChannelNumber = 1945126;
const char * myWriteAPIKey = "STBKFTQ0L6CTE4WQ";
#define MQ2 34               //Khai báo tên chân GPIO 34 là MQ2 (để đọc giá trị analog) 
  float giatri;              //Khai báo biến chứa giá trị analog

void setup() {
 
  pinMode(MQ2,INPUT);       //Chế độ chân MQ2 
  Serial.begin(115200);  //Khởi tạo serial
  while (!Serial) {
    ; 
  }
  
  WiFi.mode(WIFI_STA);        
  ThingSpeak.begin(client);  // Khởi tạo ThingSpeak
}

void loop() {
  giatri= analogRead(MQ2);   //Đọc giá trị analog từ chân MQ2
  Serial.println(giatri);    //In ra giá trị đó
  
  // Kêt nối wifi 
      WiFi.begin(ssid, pass); 
    ThingSpeak.writeField(myChannelNumber, 1, giatri, myWriteAPIKey);  //Ghi giá trị lên biểu đồ 1 của ThingSpeak
  delay(20000); // cập nhật giá trị sau mỗi 20s
}
