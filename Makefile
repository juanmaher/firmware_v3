########################################################################
# Do not edit this file!!!
########################################################################
# -------- Program path and name default values ------------------------
# Program path
# relative to this folder, leave void if the program is in this folder
PROGRAM_PATH = examples/c
# Program name
PROGRAM_NAME = app
# -------- Program path and name from an external projec.mk file -------
-include program.mk

# Compose program path and name
ifeq ($(PROGRAM_PATH),)
PROGRAM_PATH_AND_NAME=$(PROGRAM_NAME)
else
PROGRAM_PATH_AND_NAME=$(PROGRAM_PATH)/$(PROGRAM_NAME)
endif

# -------- config.mk default values -----------------------------------
# Compile options
VERBOSE=n
OPT=g
USE_NANO=y
SEMIHOST=n
USE_FPU=y
# Libraries
USE_LPCOPEN=y
USE_SAPI=y
# -------- Include config.mk file fom program --------------------------
-include $(PROGRAM_PATH_AND_NAME)/config.mk
# ----------------------------------------------------------------------

MODULES=$(sort $(dir $(wildcard libs/*/)))
SRC=$(wildcard $(PROGRAM_PATH_AND_NAME)/src/*.c)
SRC+=$(foreach m, $(MODULES), $(wildcard $(m)/src/*.c))

CXXSRC=$(wildcard $(PROGRAM_PATH_AND_NAME)/src/*.cpp)
CXXSRC+=$(foreach m, $(MODULES), $(wildcard $(m)/src/*.cpp))

ASRC=$(wildcard $(PROGRAM_PATH_AND_NAME)/src/*.s)
ASRC+=$(foreach m, $(MODULES), $(wildcard $(m)/src/*.s))

OUT=$(PROGRAM_PATH_AND_NAME)/out
OBJECTS=$(CXXSRC:%.cpp=$(OUT)/%.o) $(ASRC:%.s=$(OUT)/%.o) $(SRC:%.c=$(OUT)/%.o)
DEPS=$(OBJECTS:%.o=%.d)

OOCD_SCRIPT=scripts/openocd/lpc4337.cfg

TARGET=$(OUT)/$(PROGRAM_NAME).elf
TARGET_BIN=$(basename $(TARGET)).bin
TARGET_LST=$(basename $(TARGET)).lst
TARGET_MAP=$(basename $(TARGET)).map
TARGET_NM=$(basename $(TARGET)).names.csv

INCLUDE_FLAGS=$(foreach m, $(MODULES), -I$(m)/inc) -I$(PROGRAM_PATH_AND_NAME)/inc $(INCLUDES)
DEFINES_FLAGS=$(foreach m, $(DEFINES), -D$(m))
OPT_FLAGS=-ggdb3 -O$(OPT) -ffunction-sections -fdata-sections
LIBSDEPS=$(addprefix $(OUT)/, $(addsuffix .a, $(basename $(foreach l, $(LIBS), $(foreach m, $(MODULES), $(wildcard $(m)/lib/lib$(l).hexlib) ) ))))

COMMON_FLAGS=$(ARCH_FLAGS) $(DEFINES_FLAGS) $(INCLUDE_FLAGS) $(OPT_FLAGS)

CFLAGS=$(COMMON_FLAGS) -std=c99
CXXFLAGS=$(COMMON_FLAGS) -fno-rtti -fno-exceptions -std=c++11

LDFLAGS=$(ARCH_FLAGS)
LDFLAGS+=$(addprefix -L, $(foreach m, $(MODULES), $(wildcard $(m)/lib)))
LDFLAGS+=$(addprefix -L, $(wildcard $(dir $(LIBSDEPS))))
LDFLAGS+=$(addprefix -l, $(LIBS))
LDFLAGS+=-T$(LDSCRIPT)
LDFLAGS+=-nostartfiles -Wl,-gc-sections -Wl,-Map=$(TARGET_MAP) -Wl,--cref

ifeq ($(USE_NANO),y)
LDFLAGS+=--specs=nano.specs
endif

ifeq ($(SEMIHOST),y)
DEFINES+=USE_SEMIHOST
LDFLAGS+=--specs=rdimon.specs
endif

CROSS=arm-none-eabi-
CC=$(CROSS)gcc
CXX=$(CROSS)g++
ifeq ($(CXXSRC),)
LD=$(CROSS)gcc
else
LD=$(CROSS)g++
endif
SIZE=$(CROSS)size
LIST=$(CROSS)objdump -xdS
OBJCOPY=$(CROSS)objcopy
NM=$(CROSS)nm
GDB=$(CROSS)gdb
OOCD=openocd

ifeq ($(VERBOSE),y)
Q=
else
Q=@
endif

# Build program

all: $(TARGET) $(TARGET_BIN) $(TARGET_LST) $(TARGET_NM) size

-include $(foreach m, $(MODULES), $(wildcard $(m)/module.mk))

-include $(DEPS)

$(OUT)/%.o: %.c
	@echo CC $(notdir $<)
	@mkdir -p $(dir $@)
	$(Q)$(CC) -MMD $(CFLAGS) -c -o $@ $<

$(OUT)/%.o: %.cpp
	@echo CXX $(notdir $<)
	@mkdir -p $(dir $@)
	$(Q)$(CXX) -MMD $(CXXFLAGS) -c -o $@ $<

$(OUT)/%.o: %.s
	@echo AS $(notdir $<)
	@mkdir -p $(dir $@)
	$(Q)$(CC) -MMD $(CFLAGS) -c -o $@ $<

$(OUT)/%.a: %.hexlib
	@echo DEBLOB $(notdir $<)
	@mkdir -p $(dir $@)
	$(Q)$(OBJCOPY) -I ihex -O binary $< $@

$(OUT)/linker-params: $(OBJECTS) $(LIBSDEPS) Makefile
	@echo LD params
	@mkdir -p $(dir $@)
	$(Q)echo "-Wl,-( $(OBJECTS) -Wl,-) $(LDFLAGS)" > $@

$(TARGET): $(OUT)/linker-params
	@echo LD $@...
	$(Q)$(LD) -o $@ @$(OUT)/linker-params

$(TARGET_BIN): $(TARGET)
	@echo COPY $(notdir $<) TO $(notdir $@)
	@mkdir -p $(dir $@)
	$(Q)$(OBJCOPY) -O binary $< $@

$(TARGET_LST): $(TARGET)
	@echo LIST
	$(Q)$(LIST) $< > $@

# If you have sed
#$(TARGET_NM): $(TARGET)
#	@echo NAME
#	$(Q)$(NM) -nAsSCp $< \
#		| sed -r 's/(.+?\:[^ ]+) ([a-zA-Z\?] [a-zA-Z_].*)/\1 00000000 \2/' \
#		| sed -r 's/(.+?)\:([a-fA-F0-9]+) ([a-fA-F0-9]+) ([a-zA-Z\?]) (.*)/\1\t0x\2\t0x\3\t\4\t\5/' \
#		> $@

# If you doesn't have sed
$(TARGET_NM): $(TARGET)
	@echo NAME
	$(Q)$(NM) -nAsSCp $< > $@

# Build program size

size: $(TARGET)
	$(Q)$(SIZE) $<

# Download a program into board

.download_flash: $(TARGET_BIN)
	@echo DOWNLOAD to FLASH
	$(Q)$(OOCD) -f $(OOCD_SCRIPT) \
		-c "init" \
		-c "halt 0" \
		-c "flash write_image erase unlock $< 0x1A000000 bin" \
		-c "reset run" \
		-c "shutdown" 2>&1

.download_ram: $(TARGET_BIN)
	@echo DOWNLOAD to RAM
	$(Q)$(OOCD) -f $(OOCD_SCRIPT) \
			 -c "init" \
			 -c "halt 0" \
			 -c "load_image $< 0x20000000 bin" \
			 -c "reset run" \
			 -c "shutdown" 2>&1

ifeq ($(LOAD_INRAM),y)
download: .download_ram
else
download: .download_flash
endif

# Erase Flash memory

erase:
	@echo ERASE
	$(Q)$(OOCD) -f $(OOCD_SCRIPT) \
		-c "init" \
		-c "halt 0" \
		-c "flash erase_sector 0 0 last" \
		-c "shutdown" 2>&1

# Remove compilation generated files

clean:
	@echo CLEAN
	$(Q)rm -fR $(OBJECTS) $(TARGET) $(TARGET_BIN) $(TARGET_LST) $(DEPS) $(OUT)

# Debug with Embedded IDE

.debug:
	@echo DEBUG
	$(Q)$(OOCD) -f $(OOCD_SCRIPT) 2>&1

.run: $(TARGET)
	$(Q)$(OOCD) -f $(OOCD_SCRIPT) &
	$(Q)socketwaiter :3333 && arm-none-eabi-gdb -batch $(TARGET) -x scripts/openocd/gdbinit

# Information

.info:
	LANG=C $(MAKE) -B -p  -r -n

# Tests

# Build all programs
.test_build_all:
	@sh scripts/test/test-build-all.sh

# Run Hardware tests
.hardware_test: $(TARGET)
	$(Q)$(OOCD) -f $(OOCD_SCRIPT) > $(TARGET).log &
	$(Q)sleep 3 && arm-none-eabi-gdb -batch $(TARGET) -x scripts/openocd/gdbinit
	$(Q)cat $(TARGET).log
	$(Q)cat $(TARGET).log | grep FAIL -o >/dev/null && exit 1 || exit 0

# New program generator
new_program:
	@sh scripts/program/new_program.sh

# Select program to compile
select_program:
	@sh scripts/program/select_program.sh


.PHONY: all size download erase clean new_program select_program
