
#include "FileTransferModule.h"
#include "PowerAmpModule.h"
#include "SwitchActuatorModule.h"

#include "UsbExchangeModule.h"
#include "Logic.h"
#include "DfaModule.h"

// RX, TX, isHardwareSerial, hwPort
const uint8_t AMPchannelPins[][4] = 
{
    {AMP_HW_UART_RX_PIN, AMP_HW_UART_TX_PIN,  true, AMP_HW_SERIAL},   // Kanal 0 -> HardwareSerial
    {AMP_SWSERIAL_RXPINS, AMP_SWSERIAL_TXPINS, false, 0}, // Kanal 1 -> SoftwareSerial
 // weitere (Software-SerialPins)
};

void setup()
{
    //Bei Firmwareänderungen, die keine neue knxprod benötigen, kann die Revision erhöht werden.  // change this also in library.json
    const uint8_t firmwareRevision = 0;
    openknx.init(firmwareRevision);

    openknx.addModule(1, openknxPowerAmpModule);
    openknx.addModule(2, openknxFileTransferModule);
    openknx.addModule(3, openknxSwitchActuatorModule);
    openknx.addModule(4, openknxLogic);
    openknx.addModule(5, openknxDfaModule);
    openknx.addModule(9, openknxUsbExchangeModule);

    openknxPowerAmpModule.setSerialChannelPins(AMPchannelPins, 2);
    openknx.setup();

    
}

void loop()
{
    openknx.loop();
}
