
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <HTTPClient.h>

// Wifi network station credentials
#define WIFI_SSID "Manohar"
#define WIFI_PASSWORD "Manohar@123"
// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "5788342062:AAGxNmZSMcpkzzAWJgLWB3htJ1HrgyjWFEY"

String GOOGLE_SCRIPT_ID = "AKfycbxcdGdc7c95HyIcG-M-n1L_dyjQUJIFQrwp2npBWbwIfLzmIVQIzqJuRRP2o_5SE1o3gA";

const unsigned long BOT_MTBS = 1000; // mean time between scan messages

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime; // last time messages' scan has been done

String f = "";
String user="";
String username="";
String password="";
String flag="";
String debit_amount="0";
String credit_amount="0";
String k="";
int num=0;
int pass=0;
int money=0;
int credit_money=0;
String username_password_verification(String,String,String,String,String);

void handleNewMessages(int numNewMessages)
{
  for (int i = 0; i < numNewMessages; i++)
  {
    String text=bot.messages[i].text;
    //Serial.println(text);
    if(num==1&&pass==0)
    {
      username=text;
      //Serial.println(username);
    }
    if(pass==1)
    {
      password=text;
      //Serial.println(password);
    }
    if(num==1&&pass==1)
    {
      flag=1;
      k=username_password_verification(username,password,debit_amount,credit_amount,flag);
      //Serial.println(k);
      if(k=="1")
      {
        bot.sendMessage(bot.messages[i].chat_id,"Your are Loged In","");
        bot.sendMessage(bot.messages[i].chat_id,"Select any of these to continue\n");
        String message="------ /Withdrawal ----\n";
        message+="------ /Deposit ------- \n";
        message+="------ /Balance_Inquiry ----\n";
        bot.sendMessage(bot.messages[i].chat_id,message,"");
      }
      else if(k=="0")
      {
        bot.sendMessage(bot.messages[i].chat_id,"Wrong Username or Password","");
      }
      num=0;
      pass=0;
    }
    if(text=="/start")
    {
      String welcome="Welcome to ATM\n";
      welcome+="-----/LOGIN ----- ";
      bot.sendMessage(bot.messages[i].chat_id, welcome,"");
    }
    else if(text=="/LOGIN")
    {
      bot.sendMessage(bot.messages[i].chat_id,"Enter Username","");
      num=1;
    }
    else if(pass!=1&&num==1)
    {
      bot.sendMessage(bot.messages[i].chat_id,"Enter Password","");
      pass=1;
    }
    else if(text=="/Withdrawal")
    {
      bot.sendMessage(bot.messages[i].chat_id,"Enter amount to Withdraw","");
      money=1;
    }
    else if(text=="/Deposit"){
      bot.sendMessage(bot.messages[i].chat_id,"Enter amount to deposit","");
      credit_money=1;
    }
    else if(text=="/Balance_Inquiry"||text=="/YES")
    {
      flag=5;
      String balance_aval=username_password_verification(username,password,debit_amount,credit_amount,flag);
      Serial.println("Available balance="+balance_aval);
      bot.sendMessage(bot.messages[i].chat_id,"Available balance="+balance_aval);
      delay(5000);
      String logout="You want to Log out\n";
      logout+="---/LogOut---\n";
      logout+="---/StayIn---\n";
      bot.sendMessage(bot.messages[i].chat_id,logout);
    }
    else if(text=="/No")
    {
      String logout="You want to Log out\n";
      logout+="---/LogOut---\n";
      logout+="---/StayIn---\n";
      bot.sendMessage(bot.messages[i].chat_id,logout);
    }
    else if(text=="/LogOut"){
      username="";
      password="";
      bot.sendMessage(bot.messages[i].chat_id,"You are Logged Out\n");
      bot.sendMessage(bot.messages[i].chat_id,"Thank You");
    }
    else if(text=="/StayIn"){
      bot.sendMessage(bot.messages[i].chat_id,"Select any of these options to continue","");
      String message="------ /Withdrawal ----\n";
      message+="------ /Deposit ------- \n";
      message+="------ /Balance_Inquiry ----\n";
      bot.sendMessage(bot.messages[i].chat_id,message,"");
    }
    else if(money==1)
    {
      flag=2;
      //Serial.println(text);
      String check_amount=username_password_verification(username,password,text,credit_amount,flag);
      if(check_amount=="1")
      {
        debit_amount=text;
        flag=3;
        String amount_rem=username_password_verification(username,password,text,credit_amount,flag);
        bot.sendMessage(bot.messages[i].chat_id, "Transaction Details:\n");
        bot.sendMessage(bot.messages[i].chat_id,"Opening Balance=15000\n");
        bot.sendMessage(bot.messages[i].chat_id,"Amount Debited="+text);
        //bot.sendMessage(bot.messages[i].chat_id,"Avaliable balance="+amount_rem);
        delay(5000);
        String balance_in="Want to check Available Balance \n";
        balance_in+="---/YES---\n";
        balance_in+="---/No----\n";
        bot.sendMessage(bot.messages[i].chat_id,balance_in);
        Serial.println("Transaction Details\n");
        Serial.println("Opening Balance:15000");
        Serial.println("Amount Debited="+text);
        Serial.println("Avaliable balance="+amount_rem);
        debit_amount="0";
      }
      else if(check_amount=="0")
      {
        bot.sendMessage(bot.messages[i].chat_id,"Insufficient Balance");
      }
      money=0;
    }
    else if(credit_money==1)
    {
      flag=4;
      Serial.println(text);
      credit_amount=text;
      String amount_aval=username_password_verification(username,password,debit_amount,text,flag);
      bot.sendMessage(bot.messages[i].chat_id,"Transaction Details:\n");
      bot.sendMessage(bot.messages[i].chat_id,"Opening balance=15000");
      bot.sendMessage(bot.messages[i].chat_id,"Amount Credited="+text);
      //bot.sendMessage(bot.messages[i].chat_id,"Available balance="+amount_aval);
      String balance_in="Want to check Available Balance \n";
      balance_in+="---/YES---\n";
      balance_in+="---/No----\n";
      bot.sendMessage(bot.messages[i].chat_id,balance_in);
      Serial.println("Transaction Details:");
      Serial.println("Opening balance=15000");
      Serial.println("Amount Credited="+text);
      Serial.println("Available balance="+amount_aval);
      credit_money=0;      
    }
  }
}


void setup()
{
  Serial.begin(115200);
  Serial.println();

  // attempt to connect to Wifi network:
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    if(numNewMessages!=0)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
    }
    //numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    bot_lasttime = millis();
}


String username_password_verification(String username,String password,String Debit_amount,String Credit_amount,String flag){
  String urlFinal = "https://script.google.com/macros/s/"+GOOGLE_SCRIPT_ID+
    "/exec?"+"username=" + username + "&password="+  password +"&Debit_amount="+ Debit_amount +"&Credit_amount="+ Credit_amount + "&flag=" + flag;
    Serial.print ("POST data to spreadsheet:");
    Serial.println (urlFinal);
    HTTPClient http;
    http.begin (urlFinal.c_str () );
    http.setFollowRedirects (HTTPC_STRICT_FOLLOW_REDIRECTS) ;
    int httpCode = http.GET () ;
    f = http.getString();
    Serial.print ("HTTP Status Code: ");
    Serial.println (httpCode);
    Serial.print("payload: ");
    Serial.println(f);
    http.end () ;
    delay (1000);
    if(f=="success")
    {
      return "1";
    } 
    else if(f=="fail")
    {
      return "0";
    }
    else if(debit_amount!=0)
    {
     // Serial.println(f);
      return f;
    }
    else if(credit_amount!=0)
    {
      //Serial.println(f);
      credit_amount="0";
      return f;
    }
    else if(flag=="5")
    {
     // Serial.println(f);
      return f;
    }
}


