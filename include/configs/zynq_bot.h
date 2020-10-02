#ifndef __ZYNQBOT_
#define _ZYNQBOT_

#undef CONFIG_EXTRA_ENV_SETTINGS

#define DUAL_FS_SD					"bootargs 'console=ttyPS0,115200 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait earlyprink'"
#define SINGLE_FS_SD				"bootargs=console=ttyPS0,115200 root=/dev/mmcblk0p1 rootfstype=ext4 rw rootwait earlyprink"

#define SD_TEST						"sd_test=ext4ls mmc 0:2 /boot/; if itest $? == 0; then setenv bdev 0:2; setenv " DUAL_FS_SD "; fi\0"

#define CONFIG_EXTRA_ENV_SETTINGS 	"bdev=0:1\0" \
									SINGLE_FS_SD "\0" \
									SD_TEST \
									"bcmd=ext4load mmc ${bdev} 0x3000000 /boot/uImage; ext4load mmc ${bdev} 0x2e00000 /boot/devicetree.dtb; bootm 0x3000000 - 0x2e00000;\0" \
									"loadbit=ext4load mmc ${bdev} 0x2000000 /boot/system.bit && fpga loadb 0 0x2000000 $filesize;\0" 

#define BOOTCMD						"run sd_test; " \
									"run loadbit; " \
									"run bcmd;"

#ifdef CONFIG_BOOTCOMMAND
#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND BOOTCMD
#endif

#endif
