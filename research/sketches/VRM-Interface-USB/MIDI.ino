#include "MIDIUSB.h"

bool isConnected = false;




void noteOn(byte channel, byte pitch, byte velocity) 
{
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}


void noteOff(byte channel, byte pitch, byte velocity) 
{
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) 
{
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}


void sendFeedbackMIDI (float value)
{
  value = floor(value*127);
  noteOn(0, value, 64);
  //midi.send(0x90, value, 0x64);
}


void sendPhasingMIDI (float value)
{
  value = floor(value*127);
  noteOn(1, value, 64);
  //midi.send(0x91, value, 0x64);
}


void sendButtonPressMIDI ()
{
 //0xC0 = Channel 1 Program Change
  //midi.send(0xC2, 0); 
  controlChange(2, 0, 0);
}


void sendButtonPressTwiceMIDI ()
{
 //0xC0 = Channel 1 Program Change
  //midi.send(0xC3, 0); 
  controlChange(3, 0, 0);
}


void sendButtonHoldMIDI ()
{
 //0xC0 = Channel 1 Program Change
  controlChange(4, 0, 0);
}


/*
void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}


void connected(void)
{
  isConnected = true;
  Serial.println("CONNECTED!");
  delay(500);

}


void disconnect(void)
{
  Serial.println("disconnected...");
  isConnected = false;
}



void BleMidiRX(uint16_t timestamp, uint8_t status, uint8_t byte1, uint8_t byte2)
{
  Serial.print("[MIDI ");
  Serial.print(timestamp);
  Serial.print(" ] ");

  Serial.print(status, HEX); Serial.print(" ");
  Serial.print(byte1 , HEX); Serial.print(" ");
  Serial.print(byte2 , HEX); Serial.print(" ");

  Serial.println();
}



void setupMIDI()
{
  Serial.print(F("Initialising the Bluefruit LE module: "));

  if ( !ble.begin(VERBOSE_MODE) )
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));

  Serial.println( F("OK!") );

  if ( FACTORYRESET_ENABLE )
  {
    Serial.println(F("Performing a factory reset: "));
    if ( ! ble.factoryReset() )
      error(F("Couldn't factory reset"));
  }

  //ble.sendCommandCheckOK(F("AT+uartflow=off"));
  ble.echo(false);

  Serial.println("Requesting Bluefruit info:");
  ble.info();

  ble.setConnectCallback(connected);
  ble.setDisconnectCallback(disconnect);

  // Set MIDI RX callback
  midi.setRxCallback(BleMidiRX);

  Serial.println(F("Enable MIDI: "));
  if ( ! midi.begin(true) )
    error(F("Could not enable MIDI"));

  ble.verbose(false);
  Serial.println(F("Waiting for a connection..."));
}


void loopMIDI(void)
{
  // interval for each scanning ~ 500ms (non blocking)
  ble.update(500);

  // bail if not connected
  if (! isConnected)
    return;

}
*/
