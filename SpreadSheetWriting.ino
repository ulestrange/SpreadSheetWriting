/*
 * thid code was generted from Temboo and then I edited it to make it
 * easier to process.
 * However I sometimes a java.net.SocketException:Connection reset error
 * It seems to be a bit random boo hoo!
 * when I run it - or the original code I downloaded from Temboo.
 * 
 */





#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information, as described below

int calls = 0;   // Execution count, so this doesn't run forever
int maxCalls = 10;   // This will  write to the spreadsheet 10 times.





void setup() {

    Bridge.begin();
}

void loop() {
  if (calls <= maxCalls) {


      WriteToSpreadsheet("Wednesday", "una here");

      
  delay(30000); // wait 30 seconds between Writing to the spreadsheet calls

}
    
}

void WriteToSpreadsheet(String stringToWrite1, String stringToWrite2)
{
  unsigned long now = millis();
 
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
   
    AppendValuesChoreo.addInput("ClientID", "1097200809465-p26qu9m0l0fbnd9nduj95mqetiqcjlt2.apps.googleusercontent.com");
    AppendValuesChoreo.addInput("SpreadsheetID", "1UqzkubbbiAZ2Y5ZKPN-5tlhSX8URtlEe35Rz8YBVxIw");
    
    // Identify the Choreo to run
    AppendValuesChoreo.setChoreo("/Library/Google/Sheets/AppendValues");



    // convert the time and sensor values to a comma separated string
    String rowData = "[[\"" + String(now) + "\", \"" + stringToWrite1 +"\", \"" + stringToWrite2 + "\"]]";

    // add the RowData input item
    AppendValuesChoreo.addInput("Values", rowData);
    
    // Run the Choreo; when results are available, print them to serial
    AppendValuesChoreo.run();
    
  while(AppendValuesChoreo.available()) {
   char c = AppendValuesChoreo.read();
   Serial.print(c);
  }
    AppendValuesChoreo.close();
  }




