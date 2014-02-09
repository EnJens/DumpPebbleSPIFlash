#include <pebble.h>
#include <stdint.h>
#include "registers.h"

// 16KB batch size. Total size to dump must be divisable by this number
// Note that it must also be smaller than 24KB.
#define BATCH_SIZE (16*1024)
#define DUMP_START 0x0
#define DUMP_END 0x3fffff

#if (DUMP_END - DUMP_START + 1) % BATCH_SIZE != 0 || BATCH_SIZE % 32 != 0 || (DUMP_END - DUMP_START + 1) < 32
#error Invalid configuration
#endif

static unsigned char data[BATCH_SIZE];


static unsigned short SendData(unsigned short value)
{
    while(!(SPI1->SR & 0x2));
    SPI1->DR = value;
    while(!(SPI1->SR & 0x1));
    return SPI1->DR;
}

int main(void) {
    int i,addr;

    for(addr=DUMP_START; addr < DUMP_END; addr += BATCH_SIZE)
    {
        memset(data, 0, BATCH_SIZE);
        int bytes_left = DUMP_END - addr;
        int step_bytes = bytes_left < BATCH_SIZE ? bytes_left : BATCH_SIZE;

        APP_LOG(APP_LOG_LEVEL_DEBUG, "Dumping %d bytes from offset 0x%X", step_bytes, addr);
        // Enable GPIOA, SPI1
        RCC->APB2ENR |= (uint32_t)(1<<12);
        RCC->AHB1ENR |= (uint32_t)(1<<0);
        // Reset SPI1
        RCC->APB2RSTR |= (uint32_t)(1<<12);
        RCC->APB2RSTR &= ~(uint32_t)(1<<12);

        // Clear CS line
        GPIOA->BSRRL = (1<<4);
        GPIOA->BSRRH = (1<<4);

        // Initialize SPI
        SPI1->CR1 = 0;
        SPI1->CR1 |= 0x304;
        SPI1->I2SCFGR = 0;
        SPI1->CRCPR = 0x7;
        SPI1->CR2 = 0;

        // SPE=1
        SPI1->CR1 |= 0x40;

        for(i=0; i < step_bytes; i++)
        {
            if(i % 256 == 0)
            {
                int tmpaddr = addr + i;
                GPIOA->BSRRL = (1<<4);
                GPIOA->BSRRH = (1<<4);

                SendData(0x3); // Read command
                // Address to read from
                SendData((tmpaddr & 0xFF0000) >> 16);
                SendData((tmpaddr & 0x00FF00) >> 8);
                SendData((tmpaddr & 0x0000FF));
            }
            data[i] = SendData(0xa9);
        }

        /* Disable SPI before sending log messages.
         * This is required because sending logs appear to maybe cause writes to the SPI storage
         * and pebble crashes if SPI is somehow active and running when this happens */
        GPIOA->BSRRL = (1<<4);
        RCC->AHB1ENR &= ~(uint32_t)(1<<0);
        RCC->APB2ENR &= ~(uint32_t)(1<<12);

        for(i=0; i < step_bytes; i+=32)
        {
            APP_LOG(APP_LOG_LEVEL_DEBUG,
                    "0x%08X: %02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X"
                    "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X"
                    "%02X%02X%02X%02X%02X%02X",
                addr+i,
                data[i], data[i+1], data[i+2], data[i+3],
                data[i+4], data[i+5], data[i+6], data[i+7],
                data[i+8], data[i+9], data[i+10], data[i+11],
                data[i+12], data[i+13], data[i+14], data[i+15],
                data[i+16], data[i+17], data[i+18], data[i+19],
                data[i+20], data[i+21], data[i+22], data[i+23],
                data[i+24], data[i+25], data[i+26], data[i+27],
                data[i+28], data[i+29], data[i+39], data[i+31]);
        }
        // Needed to ensure all the log messages are sent before we start filling the buffer again
        psleep(1000);
    }
    return 0;
}
