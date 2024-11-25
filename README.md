# Project Template
This is an STM32 engineering file module developed based on the Keil5 standard library core_cm3 kernel.For the STM32F103C8T6 that STM32 is often used in daily development, its core uses the 32-bit CPU of the ARM CortexTM-M3 series, which works at 72MHz, has built-in 64KByte Flash and 20KByte SRAM storage resources, and has a variety of peripherals, which has the characteristics of high performance, low power consumption, easy development and strong anti-interference ability.

In this project, we wrote a number of peripheral boot files that will be called by the STM32 project in the /Hardware file, including but not limited to software simulation and hardware peripheral read/write for I2C and SPI communication, USART serial port, TIM clock, PWM output and input capture functions.

You can safely use IDE editing tools such as Keil5 or VsCode to delete the program, and then call the peripheral functions that we have reserved in the main program.
