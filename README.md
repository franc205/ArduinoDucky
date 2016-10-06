# Arduino Ducky

Requirement list:
Arduino UNO R3
OS (We recomment linux)
dfu-programmer packet
Arduino-keyboard-0.3.hex (USB keyboard firmware)
Arduino-usbserial-uno.hex (Arduino Original firmware)

Setting up guide :
Boot to DFU Mode : Youtube Guide
Flash original Arduino UNO Firmware

    sudo dfu-programmer atmega16u2 erase --force
    sudo dfu-programmer atmega16u2 flash 'Arduino-usbserial-uno.hex'
    sudo dfu-programmer atmega16u2 reset
Upload code.ino to your arduino
Flash Arduino Keyboard Firmwere

    sudo dfu-programmer atmega16u2 erase --force
    sudo dfu-programmer atmega16u2 flash 'Arduino-keyboard-0.3.hex.hex'
    sudo dfu-programmer atmega16u2 reset

Code Guide
Press key

    keyPress(0, <Keycode>); 

Example

    keyPress(LEFT_GUI, 0x15); // Press R Key

Press Multiple key

    keyPress(<Modifier Key>, <KeyCode>);

Example

    keyPress(LEFT_GUI, 0x15); // Press Windows Key + R

Release Key

    keyRelease();

Write Text

    keyString(<Text>);

Example

    keyString("Hello World!"); // Write Hello World
