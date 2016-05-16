//ARDUINO 1.0+ ONLY
//ARDUINO 1.0+ ONLY

#include <Ethernet.h>
#include <SPI.h>
#include <string.h>
int fn,dg;
boolean reading = false;
String readString,data,myString;

    String firstValue;
     String secondValue;
    String thirdValue;
    String forthValue;
    String fifthValue;
    String sixthValue;
    String seventhValue;
    String eighthValue;
    String ninthValue;
   int startIndex,commaIndex,endIndex,secondCommaIndex,thirdCommaIndex,forthCommaIndex,fifthCommaIndex,sixthCommaIndex,seventhCommaIndex,eighthCommaIndex,ninthCommaIndex;
    

int functionval,outputpin;
int i=0;





////////////////////////////////////////////////////////////////////////
//CONFIGURE
////////////////////////////////////////////////////////////////////////
//byte ip[] = { 192, 168, 2, 200 };   //Manual setup only
//byte gateway[] = { 192, 168, 2, 1 }; //Manual setup only
//byte subnet[] = { 255, 255, 255, 0 }; //Manual setup only

// if need to change the MAC address (Very Rare)
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetServer server = EthernetServer(80); //port 80
////////////////////////////////////////////////////////////////////////


void setup(){
  Serial.begin(9600);

  pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
      pinMode(2, OUTPUT);
        pinMode(3, OUTPUT);
          pinMode(4, OUTPUT);
            pinMode(5, OUTPUT);
              pinMode(6, OUTPUT);
                pinMode(7, OUTPUT);
                  pinMode(8, OUTPUT);  
                  pinMode(9, OUTPUT);
                    pinMode(10, OUTPUT);
                      pinMode(11, OUTPUT);
                        pinMode(12, OUTPUT);
                          pinMode(13, OUTPUT);
                        

  Ethernet.begin(mac);
//  Ethernet.begin(mac, ip, gateway, subnet); //for manual setup

  server.begin();
  Serial.println(Ethernet.localIP());

}//END OF SETUP

void loop(){
 

  // listen for incoming clients, and process qequest.
  listenForEthernetClients();

}//end of loop



void listenForEthernetClients() {

  boolean sentHeader = false;
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("Got a client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply

        if (readString.length() < 100) {

          //store characters to string
          readString += c;

          //Serial.print(c);
        }



        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header

          if(!sentHeader){
            // send a standard http response header
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println();
            sentHeader = true;
          }

          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
 
    myString=readString;
    //clearing string for next read
    readString="";
     startIndex= myString.indexOf('?');//look for start character
     commaIndex = myString.indexOf(',');//this is our delimiters
     endIndex = myString.indexOf(';');//look for end character
     firstValue = myString.substring(startIndex+1, commaIndex);
     secondCommaIndex = myString.indexOf(',', commaIndex+1);
     thirdCommaIndex = myString.indexOf(',', secondCommaIndex+1);
     forthCommaIndex = myString.indexOf(',', thirdCommaIndex+1);
     fifthCommaIndex = myString.indexOf(',', forthCommaIndex+1);
     sixthCommaIndex = myString.indexOf(',', fifthCommaIndex+1);
     seventhCommaIndex = myString.indexOf(',', sixthCommaIndex+1);
     seventhCommaIndex = myString.indexOf(',', sixthCommaIndex+1);
     eighthCommaIndex = myString.indexOf(',', seventhCommaIndex+1);
     ninthCommaIndex = myString.indexOf(',', eighthCommaIndex+1);
 
    functionval=firstValue.toInt();
    //this is the function, it defines what happens next

    
    
TwoParam(myString);
outputpin=functionval;
  digitalWrite(outputpin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(outputpin, LOW);    // turn the LED off by making the voltage LOW


  }
} 




void TwoParam(String inputstring){    secondValue =inputstring.substring(commaIndex+1, endIndex);

    Serial.println("Input String: "+myString);
    Serial.println("First value: "+firstValue);
    Serial.println("Second value: "+secondValue);

};//end of void


