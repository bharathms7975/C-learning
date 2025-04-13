#include <stdint.h>
#include <stdio.h>

// Global variables
volatile uint8_t g_button_pressed = 0;
volatile uint32_t g_button_press_count = 0;

void button_init(void);

// Register addresses
uint32_t volatile *pEXTTIPendReg      = (uint32_t*)(0x40013C00 + 0x14);
uint32_t volatile *pClkCtrlReg        = (uint32_t*)(0x40023800 + 0x30);
uint32_t volatile *pClkCtrlRegApb2    = (uint32_t*)(0x40023800 + 0x44);
uint32_t volatile *pGPIOAModeReg      = (uint32_t*)(0x40020000 + 0x00);
uint32_t volatile *pSYSCFG_EXTICR1    = (uint32_t*)(0x40013800 + 0x08);
uint32_t volatile *pEXTIMaskReg       = (uint32_t*)(0x40013C00 + 0x00);
uint32_t volatile *pEXTTIEdgeCtrlReg  = (uint32_t*)(0x40013C00 + 0x08);
uint32_t volatile *pEXTTIFallingEdgeReg = (uint32_t*)(0x40013C00 + 0x0C);
uint32_t volatile *pNVICIRQEnReg      = (uint32_t*)0xE000E100;

int main(void)
{
    button_init();

    while(1)
    {
        *pEXTIMaskReg &= ~(1 << 0);  // Disable EXTI0 to avoid multiple triggers

        if (g_button_pressed) {
            for (volatile uint32_t i = 0; i < 250000; i++);  // Simple debounce delay
            g_button_press_count++;
            printf("Button pressed: %lu times\n", g_button_press_count);
            g_button_pressed = 0;
        }

        *pEXTIMaskReg |= (1 << 0);  // Re-enable EXTI0
    }
}

void button_init(void)
{
    *pClkCtrlReg |= (1 << 0);      // Enable GPIOA clock
    *pClkCtrlRegApb2 |= (1 << 14); // Enable SYSCFG clock

    *pSYSCFG_EXTICR1 &= ~(0xF << 0);  // Map PA0 to EXTI0
    *pEXTTIEdgeCtrlReg |= (1 << 0);   // Enable Rising Edge Trigger
    *pEXTTIFallingEdgeReg &= ~(1 << 0); // Disable Falling Edge Trigger

    *pEXTIMaskReg |= (1 << 0);     // Enable EXTI0
    *pNVICIRQEnReg |= (1 << 6);    // Enable IRQ6 (EXTI0 Interrupt)
}

void EXTI0_IRQHandler(void)
{
    g_button_pressed = 1;
    *pEXTTIPendReg |= (1 << 0);  // Clear pending interrupt flag
}
