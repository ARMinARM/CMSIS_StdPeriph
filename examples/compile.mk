
# Toolchain
CC = $(PREFIX)gcc
LD = $(PREFIX)gcc
AR = $(PREFIX)ar
AS = $(PREFIX)as
OBJCOPY = $(PREFIX)objcopy
GDB = $(PREFIX)gdb

# Paths
CORE = $(COMMON)/CMSIS_v3.6.1/Include
SYSTEM = $(COMMON)/CMSIS_v3.6.1/Device/ST/STM32F10x
STARTUP = $(COMMON)
PERIPH = $(COMMON)/STM32F10x_StdPeriph_Driver_v3.6.1
USB = $(COMMON)/STM32_USB-FS-Device_Driver_v4.0.0
SRC = src
INC = inc

# Includes
INCLUDES +=	-I$(COMMON) \
			-I$(BOARD) \
			-I$(CORE) \
			-I$(SYSTEM)/Include \
			-I$(PERIPH)/inc \
			-I$(USB)/inc \
			-I$(INC) \
			-I$(SRC)

# Linker script
LDSCRIPT = $(COMMON)/stm32_f103_gcc.ld

# Flags
CFLAGS  = -O0 -g -Wall -I.\
   -mcpu=cortex-m3 -mthumb \
   $(INCLUDES) -DUSE_STDPERIPH_DRIVER -DSTM32F10X_HD

LDFLAGS += -T$(LDSCRIPT) -mcpu=cortex-m3 -mthumb -nostdlib

# Startup + System
SOURCES += $(STARTUP)/startup_stm32f10x_hd.c
SOURCES += $(SYSTEM)/Source/Templates/system_stm32f10x.c

# Peripherals:
SOURCES += \
			$(PERIPH)/src/misc.c \
			$(PERIPH)/src/stm32f10x_adc.c \
			$(PERIPH)/src/stm32f10x_gpio.c \
			$(PERIPH)/src/stm32f10x_usart.c \
			$(PERIPH)/src/stm32f10x_rcc.c \
			$(PERIPH)/src/stm32f10x_tim.c \
			$(PERIPH)/src/stm32f10x_exti.c \
			$(PERIPH)/src/stm32f10x_spi.c 

# USB:
ifdef USE_USB
SOURCES += \
			$(USB)/src/usb_core.c \
			$(USB)/src/usb_init.c \
			$(USB)/src/usb_int.c \
			$(USB)/src/usb_mem.c \
			$(USB)/src/usb_regs.c \
			$(USB)/src/usb_sil.c 
endif

# Go for it
OBJECTS = $(addprefix $(BUILDDIR)/, $(addsuffix .o, $(basename $(SOURCES))))

ELF = $(BUILDDIR)/$(PROJECT_NAME).elf
HEX = $(BUILDDIR)/$(PROJECT_NAME).hex
BIN = $(BUILDDIR)/$(PROJECT_NAME).bin

all: $(HEX) $(BIN)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

$(ELF): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

$(BUILDDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/%.o: %.s
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/%.o: %.S
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

flash: $(BIN)
	arminarm flash $(BIN)
#	st-flash write $(BIN) 0x8000000

debug: $(ELF)
	$(GDB) -tui $(ELF)

.PHONY: clean
clean:
	rm -rf build
