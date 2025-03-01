/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2019-2021 Intel Corporation <www.intel.com>
 */

#ifndef _SYSTEM_MANAGER_SOC64_H_
#define _SYSTEM_MANAGER_SOC64_H_

#include <linux/bitops.h>
void sysmgr_pinmux_init(void);
void populate_sysmgr_fpgaintf_module(void);
void populate_sysmgr_pinmux(void);

#define SYSMGR_SOC64_WDDBG			0x08
#define SYSMGR_SOC64_DMA			0x20
#define SYSMGR_SOC64_DMA_PERIPH			0x24
#define SYSMGR_SOC64_SDMMC			0x28
#define SYSMGR_SOC64_SDMMC_L3MASTER		0x2c
#define SYSMGR_SOC64_NANDGRP_L3MASTER		0x34
#define SYSMGR_SOC64_USB0_L3MASTER		0x38
#define SYSMGR_SOC64_USB1_L3MASTER		0x3c
#define SYSMGR_SOC64_EMAC_GLOBAL		0x40
#define SYSMGR_SOC64_EMAC0			0x44
#define SYSMGR_SOC64_EMAC1			0x48
#define SYSMGR_SOC64_EMAC2			0x4c
#define SYSMGR_SOC64_EMAC0_ACE			0x50
#define SYSMGR_SOC64_EMAC1_ACE			0x54
#define SYSMGR_SOC64_EMAC2_ACE			0x58
#define SYSMGR_SOC64_NAND_AXUSER		0x5c
#define SYSMGR_SOC64_FPGAINTF_EN1		0x68
#define SYSMGR_SOC64_FPGAINTF_EN2		0x6c
#define SYSMGR_SOC64_FPGAINTF_EN3		0x70
#define SYSMGR_SOC64_DMA_L3MASTER		0x74
#if IS_ENABLED(CONFIG_TARGET_SOCFPGA_N5X)
#define SYSMGR_SOC64_DDR_MODE			0xb8
#else
#define SYSMGR_SOC64_HMC_CLK			0xb4
#define SYSMGR_SOC64_IO_PA_CTRL			0xb8
#endif
#define SYSMGR_SOC64_NOC_TIMEOUT		0xc0
#define SYSMGR_SOC64_NOC_IDLEREQ_SET		0xc4
#define SYSMGR_SOC64_NOC_IDLEREQ_CLR		0xc8
#define SYSMGR_SOC64_NOC_IDLEREQ_VAL		0xcc
#define SYSMGR_SOC64_NOC_IDLEACK		0xd0
#define SYSMGR_SOC64_NOC_IDLESTATUS		0xd4
#define SYSMGR_SOC64_FPGA2SOC_CTRL		0xd8
#define SYSMGR_SOC64_FPGA_CONFIG		0xdc
#define SYSMGR_SOC64_IOCSRCLK_GATE		0xe0
#define SYSMGR_SOC64_GPO			0xe4
#define SYSMGR_SOC64_GPI			0xe8
#define SYSMGR_SOC64_MPU			0xf0
/*
 * Bits[31:28] reserved for N5X DDR retention, bits[27:0] reserved for SOC 64-bit
 * storing qspi ref clock (kHz)
 */
#define SYSMGR_SOC64_BOOT_SCRATCH_COLD0		0x200
/* store osc1 clock freq */
#define SYSMGR_SOC64_BOOT_SCRATCH_COLD1		0x204
/* store fpga clock freq */
#define SYSMGR_SOC64_BOOT_SCRATCH_COLD2		0x208
/* reserved for customer use */
#define SYSMGR_SOC64_BOOT_SCRATCH_COLD3		0x20c
/* store PSCI_CPU_ON value */
#define SYSMGR_SOC64_BOOT_SCRATCH_COLD4		0x210
/* store PSCI_CPU_ON value */
#define SYSMGR_SOC64_BOOT_SCRATCH_COLD5		0x214
/* store VBAR_EL3 value */
#define SYSMGR_SOC64_BOOT_SCRATCH_COLD6		0x218
/* store VBAR_EL3 value */
#define SYSMGR_SOC64_BOOT_SCRATCH_COLD7		0x21c
/* store ECC DBE register */
#define SYSMGR_SOC64_BOOT_SCRATCH_COLD8		0x220
/* store ECC DBE address */
#define SYSMGR_SOC64_BOOT_SCRATCH_COLD9		0x224
#define SYSMGR_SOC64_PINSEL0			0x1000
#define SYSMGR_SOC64_IOCTRL0			0x1130
#define SYSMGR_SOC64_EMAC0_USEFPGA		0x1300
#define SYSMGR_SOC64_EMAC1_USEFPGA		0x1304
#define SYSMGR_SOC64_EMAC2_USEFPGA		0x1308
#define SYSMGR_SOC64_I2C0_USEFPGA		0x130c
#define SYSMGR_SOC64_I2C1_USEFPGA		0x1310
#define SYSMGR_SOC64_I2C_EMAC0_USEFPGA		0x1314
#define SYSMGR_SOC64_I2C_EMAC1_USEFPGA		0x1318
#define SYSMGR_SOC64_I2C_EMAC2_USEFPGA		0x131c
#define SYSMGR_SOC64_NAND_USEFPGA		0x1320
#define SYSMGR_SOC64_SPIM0_USEFPGA		0x1328
#define SYSMGR_SOC64_SPIM1_USEFPGA		0x132c
#define SYSMGR_SOC64_SPIS0_USEFPGA		0x1330
#define SYSMGR_SOC64_SPIS1_USEFPGA		0x1334
#define SYSMGR_SOC64_UART0_USEFPGA		0x1338
#define SYSMGR_SOC64_UART1_USEFPGA		0x133c
#define SYSMGR_SOC64_MDIO0_USEFPGA		0x1340
#define SYSMGR_SOC64_MDIO1_USEFPGA		0x1344
#define SYSMGR_SOC64_MDIO2_USEFPGA		0x1348
#define SYSMGR_SOC64_JTAG_USEFPGA		0x1350
#define SYSMGR_SOC64_SDMMC_USEFPGA		0x1354
#define SYSMGR_SOC64_HPS_OSC_CLK		0x1358
#define SYSMGR_SOC64_IODELAY0			0x1400

/*
 * Bits for SYSMGR_SOC64_BOOT_SCRATCH_COLD0
 * Bits[31:28] reserved for DM DDR retention, bits[27:0] reserved for SOC 64-bit
 * storing qspi ref clock (kHz)
 */
#define SYSMGR_SCRATCH_REG_0_QSPI_REFCLK_MASK		GENMASK(27, 0)
#define ALT_SYSMGR_SCRATCH_REG_0_DDR_RETENTION_MASK	BIT(31)
#define ALT_SYSMGR_SCRATCH_REG_0_DDR_SHA_MASK		BIT(30)
#define ALT_SYSMGR_SCRATCH_REG_0_DDR_RESET_TYPE_MASK GENMASK(30, 28)
#define ALT_SYSMGR_SCRATCH_REG_0_DDR_RESET_TYPE_SHIFT	28

/*
 * Bits for SYSMGR_SOC64_BOOT_SCRATCH_COLD8
 * Bit[31] reserved for FSBL to check DBE is triggered (set by SDM to "1") ?
 *
 * Bit[30] reserved for FSBL to update the DDR init progress
 * 1 - means in progress, 0 - haven't started / DDR is up running.
 *
 * Bit[17:1] - Setting by Linux EDAC.
 * Bit[1](ECC_OCRAM), Bit[16](ECC_DDR0), Bit[17](ECC_DDR1)
 */
#define ALT_SYSMGR_SCRATCH_REG_8_DDR_DBE_MASK	BIT(31)
#define ALT_SYSMGR_SCRATCH_REG_8_DDR_PROGRESS_MASK	BIT(30)

#define SYSMGR_SDMMC				SYSMGR_SOC64_SDMMC

#define SYSMGR_ROMCODEGRP_CTRL_WARMRSTCFGPINMUX	BIT(0)
#define SYSMGR_ROMCODEGRP_CTRL_WARMRSTCFGIO	BIT(1)
#define SYSMGR_ECC_OCRAM_EN	BIT(0)
#define SYSMGR_ECC_OCRAM_SERR	BIT(3)
#define SYSMGR_ECC_OCRAM_DERR	BIT(4)
#define SYSMGR_FPGACONFIG_FPGA_COMPLETE		BIT(0)
#define SYSMGR_FPGACONFIG_EARLY_USERMODE	BIT(1)
#define SYSMGR_FPGACONFIG_READY_MASK	(SYSMGR_FPGACONFIG_FPGA_COMPLETE | \
					 SYSMGR_FPGACONFIG_EARLY_USERMODE)

#define SYSMGR_FPGAINTF_USEFPGA	0x1
#define SYSMGR_FPGAINTF_NAND	BIT(4)
#define SYSMGR_FPGAINTF_SDMMC	BIT(8)
#define SYSMGR_FPGAINTF_SPIM0	BIT(16)
#define SYSMGR_FPGAINTF_SPIM1	BIT(24)
#define SYSMGR_FPGAINTF_EMAC0	BIT(0)
#define SYSMGR_FPGAINTF_EMAC1	BIT(8)
#define SYSMGR_FPGAINTF_EMAC2	BIT(16)

#define SYSMGR_SDMMC_SMPLSEL_SHIFT	4
#define SYSMGR_SDMMC_DRVSEL_SHIFT	0

/* EMAC Group Bit definitions */
#define SYSMGR_EMACGRP_CTRL_PHYSEL_ENUM_GMII_MII	0x0
#define SYSMGR_EMACGRP_CTRL_PHYSEL_ENUM_RGMII		0x1
#define SYSMGR_EMACGRP_CTRL_PHYSEL_ENUM_RMII		0x2

#define SYSMGR_EMACGRP_CTRL_PHYSEL0_LSB			0
#define SYSMGR_EMACGRP_CTRL_PHYSEL1_LSB			2
#define SYSMGR_EMACGRP_CTRL_PHYSEL_MASK			0x3

#define SYSMGR_NOC_H2F_MSK		0x00000001
#define SYSMGR_NOC_LWH2F_MSK		0x00000010
#define SYSMGR_HMC_CLK_STATUS_MSK	0x00000001

#define SYSMGR_DMA_IRQ_NS		0xFF000000
#define SYSMGR_DMA_MGR_NS		0x00010000

#define SYSMGR_DMAPERIPH_ALL_NS		0xFFFFFFFF

#define SYSMGR_WDDBG_PAUSE_ALL_CPU	0x0F0F0F0F

#if IS_ENABLED(CONFIG_TARGET_SOCFPGA_N5X)
#define	SYSMGR_SOC64_DDR_MODE_MSK	BIT(0)
#endif

#endif /* _SYSTEM_MANAGER_SOC64_H_ */
