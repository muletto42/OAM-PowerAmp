#ifdef BOARD_POWERAMP_PiPicoBCU

    #define DEVICE_ID "PowerAmp_V0_PiPicoBCU"

    #define PROG_LED_PIN 21
    #define PROG_LED_PIN_ACTIVE_ON HIGH
    #define PROG_BUTTON_PIN 22
    #define SAVE_INTERRUPT_PIN 20
    #define KNX_SERIAL Serial1
    #define KNX_UART_NUM 0
    #define KNX_UART_RX_PIN 1
    #define KNX_UART_TX_PIN 0

    // Serial is the USB serial port
    // The RP2040 provides two hardware-based UARTS with configurable pin selection.
    // Serial1 is UART0 --> KNX
    // Serial2 is UART1 --> frei
#endif

#ifdef BOARD_POWERAMP_BOARD

    #define DEVICE_ID "PowerAmp"
    #define HARDWARE_NAME "PowerAmp"
    #define DEVICE_NAME "PowerAmp"

    #define INFO_LED_PIN 15
    #define INFO_LED_PIN_ACTIVE_ON HIGH
    #define PROG_LED_PIN 14
    #define PROG_LED_PIN_ACTIVE_ON HIGH
    #define PROG_BUTTON_PIN 10
    #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
    #define SAVE_INTERRUPT_PIN 11
    #define KNX_SERIAL Serial1
    #define KNX_UART_RX_PIN 13
    #define KNX_UART_TX_PIN 12
    #ifndef KNX_UART_NUM
        #define KNX_UART_NUM 0
    #endif

    // Serial is the USB serial port
    // The RP2040 provides two hardware-based UARTS with configurable pin selection.
    // Serial1 is UART0 --> KNX
    // Serial2 is UART1 --> frei
#endif

#define OPENKNX_AMP_CHANNEL_COUNT 2 

// ein HardwareUART
#define AMP_HW_SERIAL 2 // Serial2 // Serial2 = UART1
#define AMP_HW_UART_TX_PIN	8      // UART1 TX mit Amp RX verbinden //GP8
#define AMP_HW_UART_RX_PIN	9      // UART1 RX mit Amp TX verbinden //GP9
/*
// alternative Pins
#define AMP_HW_UART_TX_PIN	4      // UART1 TX mit Amp RX verbinden //GP4 
#define AMP_HW_UART_RX_PIN 	5      // UART1 RX mit Amp TX verbinden //GP5 
*/

// dann noch einen Software Serial benutzen
// frei wählbare Pins für SoftwareSerial
#define AMP_SWSERIAL_TXPINS 4
#define AMP_SWSERIAL_RXPINS 5


#define BAUD_ARLYIC 115200 // Baudrate für Arylic UART

#if defined(AMP_HW_UART_TX_PIN) && defined(AMP_HW_UART_RX_PIN)
    #if !((AMP_HW_UART_TX_PIN == 4) || (AMP_HW_UART_TX_PIN == 8) || (AMP_HW_UART_TX_PIN == 12) || (AMP_HW_UART_TX_PIN == 16) || (AMP_HW_UART_TX_PIN == 20))
        #error "AMP_HW_UART_TX_PIN ist kein typischer UART1-TX-Pin auf dem RP2040!"
    #endif
    #if !((AMP_HW_UART_RX_PIN == 5) || (AMP_HW_UART_RX_PIN == 9) || (AMP_HW_UART_RX_PIN == 13) || (AMP_HW_UART_RX_PIN == 17) || (AMP_HW_UART_RX_PIN == 21))
        #error "AMP_HW_UART_RX_PIN ist kein typischer UART1-RX-Pin auf dem RP2040!"
    #endif
#endif



#define OPENKNX_SWA_CHANNEL_COUNT 2
#define OPENKNX_SWA_SET_PINS 3, 19  // GPIO3, GPIO19 // Es wird der GPIO angegeben, nicht der Pin 
#define OPENKNX_SWA_RESET_PINS 2, 18  //GPIO2, GPIO18 // Es wird der GPIO angegeben, nicht der Pin 
#define OPENKNX_SWA_SET_ACTIVE_ON HIGH
#define OPENKNX_SWA_RESET_ACTIVE_ON HIGH
#define OPENKNX_SWA_BISTABLE_IMPULSE_LENGTH 50


