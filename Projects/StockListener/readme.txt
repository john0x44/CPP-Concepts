Description: Listens to a user specified stock price change every 10 seconds 
Connects to the internet using windows api - Wininet

make sure you add this to the linker commands: 
-lwininet 

More info on wininet api: 
https://learn.microsoft.com/en-us/windows/win32/wininet/about-wininet
http://speed.eik.bme.hu/help/html/Web_Programming_Unleashed/ch17.htm
https://discover.hubpages.com/technology/C-Tutorial-Interaction-with-internet-using-Wininet
https://cplusplus.com/forum/beginner/75062/

json header used from: 
https://github.com/nlohmann/json

to run open both files to ide and run 'StockListener.cpp'

--testing: type "SPY" for example
