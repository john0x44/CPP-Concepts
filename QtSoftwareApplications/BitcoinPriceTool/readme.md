## BitcoinPriceTool

Demonstrating visual use of the Bitcoin price tool

Goal: extending the use of 'StockListener.cpp' into this project, connecting to the internet and making a user friendly interface made with the use of the QT framework.


add target link to CMakeLists.txt

target_link_libraries(BitcoinPriceTool PRIVATE wininet)

![Visual demonstration](https://i.gyazo.com/5e756f4c34b01314055294e06b61867f.gif)

