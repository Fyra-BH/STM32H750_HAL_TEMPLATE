TARGET :=libstm32h750xxhal.a


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og



#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################

SRCDIRS	:=\
Src \

C_SOURCES := $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))

# C includes
C_INCLUDES =  \
-I../../Inc \
-I../../Drivers/STM32H7xx_HAL_Driver/Inc \
-I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy \
-I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include \
-I../../Drivers/CMSIS/Include \

# ASM sources
ASM_SOURCES =  \
startup_stm32h750xx.s


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.

CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
AR = $(PREFIX)ar
SZ = $(PREFIX)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m7

# fpu
FPU = -mfpu=fpv5-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32H750xx

# AS includes
AS_INCLUDES = 

# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif

OBJECTS = $(notdir $(C_SOURCES:.c=.o))
vpath %.c $(sort $(dir $(C_SOURCES)))

# Generate dependency information
# CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"

all: $(TARGET) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET):$(OBJECTS)
	$(AR) -rcs $@ $^
	rm *.o

clean:
	rm $(TARGET)
