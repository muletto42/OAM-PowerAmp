
#include "FileTransferModule.h"
#include "PowerAmpModule.h"
#include "SwitchActuatorModule.h"

#include "UsbExchangeModule.h"
#include "Logic.h"
// #include "DfaModule.h"



void setup()
{
    //Bei Firmwareänderungen, die keine neue knxprod benötigen, kann die Revision erhöht werden.  // change this also in library.json
    const uint8_t firmwareRevision = 0;
    openknx.init(firmwareRevision);

    openknx.addModule(1, openknxPowerAmpModule);
    openknx.addModule(2, openknxFileTransferModule);
    openknx.addModule(3, openknxSwitchActuatorModule);
    openknx.addModule(4, openknxLogic);
    // openknx.addModule(5, openknxDfaModule);
    openknx.addModule(9, openknxUsbExchangeModule);

    openknx.setup();
}

void loop()
{
    openknx.loop();
}
