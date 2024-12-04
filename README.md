# Project Template
This is an STM32 engineering file module developed based on the Keil5 standard library core_cm3 kernel.For the STM32F103C8T6 that STM32 is often used in daily development, its core uses the 32-bit CPU of the ARM CortexTM-M3 series, which works at 72MHz, has built-in 64KByte Flash and 20KByte SRAM storage resources, and has a variety of peripherals, which has the characteristics of high performance, low power consumption, easy development and strong anti-interference ability.

这是基于 Keil5 标准库core_cm3内核开发的 STM32 工程文件模块。针对STM32日常开发中经常使用STM32F103C8T6，其内核采用了ARM CortexTM-M3系列的32位CPU，工作频率为72MHz，内置了64KByte Flash和20KByte SRAM存储资源，并拥有多种外设，具有高性能、低功耗、易开发、抗干扰能力强等特点。

In this project, we wrote a number of peripheral boot files that will be called by the STM32 project in the /Hardware file, including but not limited to software simulation and hardware peripheral read/write for I2C and SPI communication, USART serial port, TIM clock, PWM output and input capture functions.

在这个项目中，我们在 /Hardware 文件中编写了大量可以用于调用 STM32 外设启动的项目文件，包括但不限于用于 I2C 和 SPI 通信的软件仿真和硬件外设读/写、USART 串口、TIM 时钟、PWM 输出和输入捕获功能。

You can safely use IDE editing tools such as Keil5 or VsCode to delete the program, and then call the peripheral functions that we have reserved in the main program.
