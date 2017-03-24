#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information, as described below

int calls = 1;   // Execution count, so this doesn't run forever
int maxCalls = 10;   // Maximum number of times the Choreo should be executed

void setup() {
  Serial.begin(9600);
  
  // For debugging, wait until the serial console is connected
  delay(4000);
  while(!Serial);
  Bridge.begin();
}

void loop() {
  if (calls <= maxCalls) {
    Serial.println("Running AppendValues - Run #" + String(calls++));
    
    TembooChoreo AppendValuesChoreo;

    // Invoke the Temboo client
    AppendValuesChoreo.begin();

    // Set Temboo account credentials
    AppendValuesChoreo.setAccountName(TEMBOO_ACCOUNT);
    AppendValuesChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    AppendValuesChoreo.setAppKey(TEMBOO_APP_KEY);
    
    // Set Choreo inputs
    AppendValuesChoreo.addInput("RefreshToken", "1/D2IJoPtl1D5ioK4v0oyO9goNB2SfdZlB8MZqB4DMWWU");
    AppendValuesChoreo.addInput("ClientSecret", "gfzhG-hGpPqtb_oFA89N7PN4");
    AppendValuesChoreo.addInput("Values", "[[\"una\",\"was\",\"here\"]]");
    AppendValuesChoreo.addInput("ClientID", "1097200809465-p26qu9m0l0fbnd9nduj95mqetiqcjlt2.apps.googleusercontent.com");
    AppendValuesChoreo.addInput("SpreadsheetID", "1UqzkubbbiAZ2Y5ZKPN-5tlhSX8URtlEe35Rz8YBVxIw");
    
    // Identify the Choreo to run
    AppendValuesChoreo.setChoreo("/Library/Google/Sheets/AppendValues");
    
    // Run the Choreo; when results are available, print them to serial
    AppendValuesChoreo.run();
    
    while(AppendValuesChoreo.available()) {
      char c = AppendValuesChoreo.read();
      Serial.print(c);
    }
    AppendValuesChoreo.close();
  }

  Serial.println("Waiting...");
  delay(30000); // wait 30 seconds between AppendValues calls
}
