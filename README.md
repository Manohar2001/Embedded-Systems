**Title:**
Integrated ATM System using ESP32, Telegram Bot, and Google Sheets

**Introduction:**
The ATM System designed here combines cutting-edge technologies, including ESP32, Telegram Bot, and Google Sheets, to provide users with a seamless banking experience. With the integration of these resources, users can access their bank data conveniently through a Telegram interface, while the ESP32 acts as the gateway to execute their commands securely.

**System Components:**

ESP32: The Internet of Things (IoT) device responsible for connecting the ATM system to the internet and handling data communication between the Telegram Bot and Google Sheets.

Telegram Bot: Serving as the user interface, the Telegram Bot allows users to interact with the ATM System using simple commands. Users can inquire about their account balance, deposit funds, withdraw money, and review transaction history, all within the familiar Telegram messaging platform.

Google Sheets: The user database is stored on Google Sheets, containing essential information such as user names, passwords, account balances, and transaction histories. The ESP32 communicates with Google Sheets through a custom-written code in the Arduino IDE, ensuring secure data retrieval and updates.

**User Experience:**
To utilize the ATM System, users interact with the Telegram Bot by sending commands through the messaging app. For instance, a user can request their account balance by typing "/check_balance." Upon receiving the command, the Telegram Bot forwards the request to the ESP32 device.

**ESP32 Processing:**
The ESP32 processes the user's command, utilizing the data connection established with Google Sheets. The custom code written in the Arduino IDE enables the ESP32 to fetch the user's data from the Google Sheets database, ensuring the user's privacy and security.

**Transaction Handling:**
When a user wishes to perform a transaction, such as depositing money into their account or making a withdrawal, the Telegram Bot relays the command to the ESP32. The ESP32, in turn, verifies the user's credentials from Google Sheets and updates the account balance accordingly.

**Transaction History:**
Users can also inquire about their transaction history through the Telegram Bot. Upon receiving the relevant command, the ESP32 retrieves the data from the Google Sheets database and delivers it to the user via the Telegram interface.

**Conclusion:**
By combining the power of ESP32, Telegram Bot, and Google Sheets, the ATM System provides a user-friendly, secure, and efficient banking solution. Users can access their account information and perform transactions conveniently through Telegram, while the ESP32 seamlessly communicates with the Google Sheets database in the background. This integrated ATM System is a testament to the possibilities of modern technologies working in harmony to enhance user experiences and data management in the banking domain.



