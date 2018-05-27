// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// ID115 disclaimer: make sure you've selected Tools > Low frequency clock > Synthesized

// Import libraries (BLEPeripheral depends on SPI)
#include <SPI.h>
#include <BLEPeripheral.h>
#include "SEGGER_RTT.h"

// LED pin
#define LED_PIN   30

//custom boards may override default pin definitions with BLEPeripheral(PIN_REQ, PIN_RDY, PIN_RST)
BLEPeripheral                    blePeripheral                            = BLEPeripheral();

// create service
BLEService               ledService           = BLEService("19b10000e8f2537e4f6cd104768a1214");

// create switch characteristic
BLECharCharacteristic    switchCharacteristic = BLECharCharacteristic("19b10001e8f2537e4f6cd104768a1214", BLERead | BLEWrite);

void setup() {  

  SEGGER_RTT_WriteString(0, "BLE LED\n");
  // set LED pin to output mode
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  // set advertised local name and service UUID
  blePeripheral.setLocalName("LED");
  blePeripheral.setAdvertisedServiceUuid(ledService.uuid());

  // add service and characteristic
  blePeripheral.addAttribute(ledService);
  blePeripheral.addAttribute(switchCharacteristic);

  // begin initialization
  blePeripheral.begin();

//  Serial.println(F("BLE LED Peripheral"));
  SEGGER_RTT_WriteString(0, "BLE LED PERIPHERAL\n");
}

void loop() {
  BLECentral central = blePeripheral.central();

  if (central) {
    // central connected to peripheral
    while (central.connected()) {
      // central still connected to peripheral
      if (switchCharacteristic.written()) {
        // central wrote new value to characteristic, update LED
        if (switchCharacteristic.value()) {
          SEGGER_RTT_WriteString(0, "LED ON\n");
          digitalWrite(LED_PIN, HIGH);
        } else {
          SEGGER_RTT_WriteString(0, "LED OFF\n");
          digitalWrite(LED_PIN, LOW);
        }
      }
    }
  }
}
