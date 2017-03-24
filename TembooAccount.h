/*
IMPORTANT NOTE about TembooAccount.h

TembooAccount.h contains your Temboo account information and must be included
alongside your sketch. To do so, make a new tab in Arduino, call it TembooAccount.h,
and copy this content into it. 
*/

#define TEMBOO_ACCOUNT "unasligo"  // Your Temboo account name 
#define TEMBOO_APP_KEY_NAME "GoogleSpreadSheetApp"  // Your Temboo app key name
#define TEMBOO_APP_KEY "Hg4y7cKbrH5gbV8SE5n3i4HF31O3vYel"  // Your Temboo app key

#if TEMBOO_LIBRARY_VERSION < 2
#error "Your Temboo library is not up to date. You can update it using the Arduino library manager under Sketch > Include Library > Manage Libraries..."
#endif

/* 
The same TembooAccount.h file settings can be used for all Temboo SDK sketches.  
Keeping your account information in a separate file means you can share the 
main .ino file without worrying that you forgot to delete your credentials.
*/