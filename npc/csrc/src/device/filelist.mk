#***************************************************************************************
# Copyright (c) 2014-2022 Zihao Yu, Nanjing University
#
# NEMU is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2
#
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
# EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
# MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
#
# See the Mulan PSL v2 for more details.
#**************************************************************************************/

DIRS += $(NPC_HOME)/csrc/src/device/io
SRCS-$(CONFIG_DEVICE) += $(NPC_HOME)/csrc/src/device/device.c $(NPC_HOME)/csrc/src/device/alarm.c $(NPC_HOME)/csrc/src/device/intr.c
SRCS-$(CONFIG_HAS_SERIAL) += $(NPC_HOME)/csrc/src/device/serial.c
SRCS-$(CONFIG_HAS_TIMER) += $(NPC_HOME)/csrc/src/device/time.c
SRCS-$(CONFIG_HAS_KEYBOARD) += $(NPC_HOME)/csrc/src/device/keyboard.c
SRCS-$(CONFIG_HAS_VGA) += $(NPC_HOME)/csrc/src/device/vga.c
SRCS-$(CONFIG_HAS_AUDIO) += $(NPC_HOME)/csrc/src/device/audio.c
SRCS-$(CONFIG_HAS_DISK) += $(NPC_HOME)/csrc/src/device/disk.c
