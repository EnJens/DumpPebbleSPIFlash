#ifndef _HAS_HEADER_DEFS_H_
#define _HAS_HEADER_DEFS_H_
#include <stdint.h>
#define __IO volatile

#define PERIPH_BASE           ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region */
#define APB1PERIPH_BASE       PERIPH_BASE

#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000)

#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)

#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000)

#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800)
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000)

#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400)

#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800)

#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00)

#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000)

#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400)

#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800)

#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00)

#define GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000)



typedef struct

{

  __IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */

  __IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */

  __IO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */

  __IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */

  __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */

  __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */

  __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */

  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */

  __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */

  __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */

  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */

  __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */

  __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */

  __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */

  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */

  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */

  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */

  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */

  __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */

  __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */

  __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */

  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */

  __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */

  __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */

  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */

  __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */

  __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */

  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */

  __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */

  __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */

} RCC_TypeDef;

typedef struct

{

  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */

  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */

  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */

  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */

  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */

  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */

  __IO uint16_t BSRRL;    /*!< GPIO port bit set/reset low register,  Address offset: 0x18      */

  __IO uint16_t BSRRH;    /*!< GPIO port bit set/reset high register, Address offset: 0x1A      */

  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */

  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */

} GPIO_TypeDef;


typedef struct

{

  __IO uint16_t CR1;        /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */

  uint16_t      RESERVED0;  /*!< Reserved, 0x02                                                           */

  __IO uint16_t CR2;        /*!< SPI control register 2,                             Address offset: 0x04 */

  uint16_t      RESERVED1;  /*!< Reserved, 0x06                                                           */

  __IO uint16_t SR;         /*!< SPI status register,                                Address offset: 0x08 */

  uint16_t      RESERVED2;  /*!< Reserved, 0x0A                                                           */

  __IO uint16_t DR;         /*!< SPI data register,                                  Address offset: 0x0C */

  uint16_t      RESERVED3;  /*!< Reserved, 0x0E                                                           */

  __IO uint16_t CRCPR;      /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */

  uint16_t      RESERVED4;  /*!< Reserved, 0x12                                                           */

  __IO uint16_t RXCRCR;     /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */

  uint16_t      RESERVED5;  /*!< Reserved, 0x16                                                           */

  __IO uint16_t TXCRCR;     /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */

  uint16_t      RESERVED6;  /*!< Reserved, 0x1A                                                           */

  __IO uint16_t I2SCFGR;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */

  uint16_t      RESERVED7;  /*!< Reserved, 0x1E                                                           */

  __IO uint16_t I2SPR;      /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */

  uint16_t      RESERVED8;  /*!< Reserved, 0x22                                                           */

} SPI_TypeDef;


#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI               ((GPIO_TypeDef *) GPIOI_BASE)

#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)



#endif


