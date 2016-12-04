#
# (C) Copyright 2000-2006
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# SPDX-License-Identifier:	GPL-2.0+
#

obj-y	:= board.o

hw-platform-y :=$(shell echo $(CONFIG_DEFAULT_DEVICE_TREE))

init-objs := $(if $(wildcard $(srctree)/$(src)/$(hw-platform-y)/ps7_init_gpl.c),\
	$(hw-platform-y)/ps7_init_gpl.o)

ifeq ($(init-objs),)
ifneq ($(wildcard $(srctree)/$(src)/ps7_init_gpl.c),)
init-objs := ps7_init_gpl.o
$(if $(CONFIG_SPL_BUILD),\
$(warning Put custom ps7_init_gpl.c/h to board/xilinx/zynq/custom_hw_platform/))
endif
endif

obj-$(CONFIG_SPL_BUILD) += $(init-objs)

# Suppress "warning: function declaration isn't a prototype"
CFLAGS_REMOVE_ps7_init_gpl.o := -Wstrict-prototypes

# To include xil_io.h
CFLAGS_ps7_init_gpl.o := -I$(srctree)/$(src)

# Warn if CONFIG_TARGET_ZYNQ_ZC70X is enabled
ifeq ($(CONFIG_TARGET_ZYNQ_ZC70X),y)
ifeq ($(CONFIG_SPL_BUILD),y)
$(warning CONFIG_TARGET_ZYNQ_ZC70X is deprecated.)
$(warning Enable CONFIG_TARGET_ZYNQ_ZC702 or CONFIG_TARGET_ZYNQ_706 instead.)
$(warning "make zynq_zc70x_defconfig" is also deprecated.)
$(warning Use "make zynq_zc702_defconfig" or "make zynq_zc706_defconfig".)
endif
endif
