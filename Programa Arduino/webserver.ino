// Librería WiFi
#include <WiFi.h>

// Credenciales de la red WiFi a la que nos conectaremos
const char* ssid     = "OpenWrt-C7-2";
const char* password = "axtec2019";

// Puerto del servidor web, generalmente 80
WiFiServer server(80);

// Variable para almacenar los request HTTP
String header;

// Variable para almacenar el estado actual del LED
String ledStatus = "apagado";

// Pin del LED a controlar
const int ledPin = LED_BUILTIN;

// Pin del sensor de movimiento PIR
const int pirPin = 13;

void setup() {
  // Puerto serie a 115200 baudios
  Serial.begin(115200);
  
  // Pin del LED como salida
  pinMode(ledPin, OUTPUT);
  // Pin del sensor de movimiento PIR como entrada
  pinMode(pirPin, INPUT);
  // Apagamos el LED
  digitalWrite(ledPin, LOW);

  // Conección a la red WiFi
  Serial.print("Conectando a la red '");
  Serial.print(ssid);
  Serial.println("'");
  WiFi.begin(ssid, password);

  // Esperamos que se realice la conexión a la red
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  // Mostramos la dirección IP que se nos fue asignada
  Serial.println("");
  Serial.println("WiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Iniciamos el servidor web
  server.begin();
}

void loop(){

  WiFiClient client = server.available();   // Obtenemos el nuevo cliente conectado

  if (client) {                             // Conexión de un cliente disponible?
    Serial.println("Nuevo cliente!");       
    String currentLine = "";                // Variable para almacenar datos provenientes del cliente
    
    while (client.connected()) {            // Mientras el cliente esté conectado escuchamos los datos que envía
      if (client.available()) {             // El cliente envió algún dato?
        
        char c = client.read();             // Leemos un caracter del cliente
        header += c;                        // Agregamos el caracter leído al request HTPP
        
        if (c == '\n') {
          
          // Si la línea actual está vacía y llegamos hasta aquí es porque obtuvimos dos caracteres
          //  de nueva línea seguidos y eso es un indicador de que el request HTTP terminó y podemos
          //  ahora enviar una respuesta
          if (currentLine.length() == 0) {

            // Enviamos el estado del sensor de movimiento PIR
            if (header.indexOf("GET /pir/status") >= 0) {
              Serial.println("Estado del sensor de movimiento PIR " + digitalRead(pirPin));

              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:application/json");
              client.println("Connection: close");
              client.println();

              if(digitalRead(pirPin)) {
                client.println("{\"pir\": true}");
              }
              else {
                client.println("{\"pir\": false}");
              }
                            
              // La respuesta debe terminar con un caracter de nueva línea
              client.println();
                
              // Rompemos el bucle para luego desconectar al cliente
              break;
            }
            // Encendemos o apagamos el LED en base al request recibido del cliente
            else if (header.indexOf("GET /led/on") >= 0) {
              Serial.println("LED encendido");
              ledStatus = "encendido";
              digitalWrite(ledPin, HIGH);
            } 
            else if (header.indexOf("GET /led/off") >= 0) {
              Serial.println("LED apagado");
              ledStatus = "apagado";
              digitalWrite(ledPin, LOW);              
            }

            // Respuesta que enviamos al cliente. Este es el header HTTP para responder con el código 200
            //  e indicar que la respuesta es de tipo text/html
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // El siguiente código es el HTML de la página que es mostrada al cliente
            client.println("<!DOCTYPE html><html>");
            client.println("<title>AXTEC Domotica con Arduino</title>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; background-color: green }");
            client.println(".button { background-color: blue; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Título de la página web
            client.println("<body><h1>Servidor Web Arduino</h1>");
            
            // Mostramos el estado actual del LED
            client.println("<p>LED - Estado: " + ledStatus + "</p>");
            
            // Cambiamos el texto del botón en base al estado del LED   
            if (ledStatus == "apagado") {
              client.println("<p><a href=\"/led/on\"><button class=\"button\">Encender</button></a></p>");
            } 
            else {
              client.println("<p><a href=\"/led/off\"><button class=\"button button2\">Apagar</button></a></p>");
            }

            client.println("<script>setInterval(function(){var xhttp=new XMLHttpRequest();xhttp.onreadystatechange=function(){if(this.status == 200 && this.readyState == 4){var status = JSON.parse(this.responseText);if(status.pir){document.getElementsByTagName('html')[0].style.backgroundColor='red';}else{document.getElementsByTagName('html')[0].style.backgroundColor='green';}}};xhttp.open('GET','/pir/status',true);xhttp.send();},1000);</script>");
            client.println("</body>");
            client.println("</html>");
                        
            // La respuesta debe terminar con un caracter de nueva línea
            client.println();
            
            // Rompemos el bucle para luego desconectar al cliente
            break;
          }
          // Obtuvimos un caracter de nueva línea asi que comenzamos una nueva línea
          else {
            currentLine = "";
          }
        }
        // Cualquier otro caracter que no sea nueva línea ni retorno de carro es agregado a la línea actual
        else if (c != '\r') {
          currentLine += c;
        }
      }
    }

    // Cerramos la conexión con el cliente
    header = "";
    client.stop();
    Serial.println("Cliente desconectado");
  }
}
