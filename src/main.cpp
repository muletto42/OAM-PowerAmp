
#include "FileTransferModule.h"
#include "UsbExchangeModule.h"
#include "PowerAmpModule.h"
#include "Logic.h"
// #include "DfaModule.h"
#include "SwitchActuatorModule.h"




void setup()
{
    //Bei Firmwareänderungen, die keine neue knxprod benötigen, kann die Revision erhöht werden.  // change this also in library.json
    const uint8_t firmwareRevision = 0;
    openknx.init(firmwareRevision);

    openknx.addModule(1, openknxLogic);
    // openknx.addModule(2, openknxDfaModule);
    openknx.addModule(3, openknxFileTransferModule);
    openknx.addModule(5, openknxSwitchActuatorModule);
    openknx.addModule(6, openknxPowerAmpModule);
    openknx.addModule(9, openknxUsbExchangeModule);


    openknx.setup();
}

void loop()
{
    openknx.loop();
}
