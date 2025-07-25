

#ifdef BOARD_PowerAmp_PiPicoBCU

#define DEVICE_ID "PowerAmp_V0_PiPicoBCU"

#define PROG_LED_PIN 21
#define PROG_LED_PIN_ACTIVE_ON HIGH
#define PROG_BUTTON_PIN 22
#define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
#define SAVE_INTERRUPT_PIN 20
#define KNX_SERIAL Serial1
#define KNX_UART_RX_PIN 1
#define KNX_UART_TX_PIN 0


// Serial is the USB serial port
// The RP2040 provides two hardware-based UARTS with configurable pin selection.
// Serial1 is UART0 --> KNX
// Serial2 is UART1 --> frei

#define ArylicUARTPORT Serial2 // Serial2 = UART1 //auto& ArylicUART = Serial1; //das geht auch als Namensgeber
//#define ARYLIC_TX_PIN 6        // UART1 TX mit Amp RX verbinden //GP4
//#define ARYLIC_RX_PIN 7        // UART1 RX mit Amp TX verbinden //GP5
#define ARYLIC_TX_PIN	11      // UART1 TX mit Amp RX verbinden //GP8
#define ARYLIC_RX_PIN	12      // UART1 RX mit Amp TX verbinden //GP9
#define BAUD_ARLYIC 115200 // Baudrate für Arylic UART

#endif

#ifdef BOARD_PowerAmp_BOARD

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

    #define OPENKNX_AMP_CHANNEL_COUNT 2

    #if OPENKNX_AMP_CHANNEL_COUNT > 0
        // Der erste UART ist immer ein HardwareUART
        #define AMP_HARDWARE_SERIAL Serial2 // Serial2 = UART1
        #define HW_UART_TX_PIN	8      // UART1 TX mit Amp RX verbinden //GP8
        #define HW_UART_RX_PIN	9      // UART1 RX mit Amp TX verbinden //GP9
        // alternative Pins
        // #define HW_UART_TX_PIN	4      // UART1 TX mit Amp RX verbinden //GP4 // 
        // #define HW_UART_RX_PIN 	5      // UART1 RX mit Amp TX verbinden //GP5 // 
    #endif

    #if OPENKNX_AMP_CHANNEL_COUNT > 1 // dann noch einen Software Serial benutzen
    // frei wählbare Pins für SoftwareSerial
    // noch mehr durch Komma trennen z.B. 4, 6
        #define OPENKNX_SWSERIAL_TXPINS 4
        #define OPENKNX_SWSERIAL_RXPINS 5
    #endif

    #define BAUD_ARLYIC 115200 // Baudrate für Arylic UART

    #if defined(HW_UART_TX_PIN) && defined(HW_UART_RX_PIN)
        #if !((HW_UART_TX_PIN == 4) || (HW_UART_TX_PIN == 8) || (HW_UART_TX_PIN == 12) || (HW_UART_TX_PIN == 16) || (HW_UART_TX_PIN == 20))
            #error "HW_UART_TX_PIN ist kein typischer UART1-TX-Pin auf dem RP2040!"
        #endif
        #if !((HW_UART_RX_PIN == 5) || (HW_UART_RX_PIN == 9) || (HW_UART_RX_PIN == 13) || (HW_UART_RX_PIN == 17) || (HW_UART_RX_PIN == 21))
            #error "HW_UART_RX_PIN ist kein typischer UART1-RX-Pin auf dem RP2040!"
        #endif
    #endif



    #define OPENKNX_SWA_CHANNEL_COUNT 2
    #define OPENKNX_SWA_SET_PINS 3, 19
    #define OPENKNX_SWA_RESET_PINS 2, 18
    #define OPENKNX_SWA_SET_ACTIVE_ON HIGH
    #define OPENKNX_SWA_RESET_ACTIVE_ON HIGH
    #define OPENKNX_SWA_BISTABLE_IMPULSE_LENGTH 30

    #define OPENKNX_SWA_GPIO_OUTPUT_OFFSET 0x0100
    #define OPENKNX_SWA_GPIO_OUTPUT_ACTIVE_ON HIGH
    #define OPENKNX_SWA_GPIO_INPUT_OFFSET 0x0108
    #define OPENKNX_SWA_GPIO_INPUT_ACTIVE_ON LOW

#endif