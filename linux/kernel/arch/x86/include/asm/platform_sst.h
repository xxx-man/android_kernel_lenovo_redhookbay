
/*
 * platform_sst.h:  sst audio platform data header file
 *
 * Copyright (C) 2013 Intel Corporation
 * Author: Dharageswari R <dharageswari.r@intel.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef _PLATFORM_SST_H_
#define _PLATFORM_SST_H_

#include <linux/sfi.h>
#define SST_MAX_SSP_PORTS 4
#define SST_MAX_DMA 2

enum {
	SST_SSP_AUDIO = 0,
	SST_SSP_MODEM,
	SST_SSP_BT,
	SST_SSP_FM,
};

struct sst_gpio_config {
	u32 i2s_rx_alt;
	u32 i2s_tx_alt;
	u32 i2s_frame;
	u32 i2s_clock;
	u32 alt_function;
};

struct sst_ssp_info {
	u32 base_add;
	struct sst_gpio_config gpio;
	bool in_use;
};

struct sst_info {
	u32 iram_start;
	u32 iram_end;
	bool iram_use;
	u32 dram_start;
	u32 dram_end;
	bool dram_use;
	u32 imr_start;
	u32 imr_end;
	bool imr_use;
	bool use_elf;
	bool dma_addr_ia_viewpt;
	unsigned int max_streams;
	u32 dma_max_len;
	u8 num_probes;
};

struct sst_ssp_platform_cfg {
	u8 ssp_cfg_sst;
	u8 port_number;
	u8 is_master;
	u8 pack_mode;
	u8 num_slots_per_frame;
	u8 num_bits_per_slot;
	u8 active_tx_map;
	u8 active_rx_map;
	u8 ssp_frame_format;
	u8 frame_polarity;
	u8 serial_bitrate_clk_mode;
	u8 frame_sync_width;
	u8 dma_handshake_interface_tx;
	u8 dma_handshake_interface_rx;
	u8 reserved[2];
	u32 sst_ssp_base_add;
};

struct sst_board_config_data {
	struct sst_ssp_platform_cfg ssp_platform_data[SST_MAX_SSP_PORTS];
	u8 active_ssp_ports;
	u8 platform_id;
	u8 board_id;
	u8 ihf_num_chan;
	u32 osc_clk_freq;
};

struct sst_platform_config_data {
	u32 sst_sram_buff_base;
	u32 sst_dma_base[SST_MAX_DMA];
};

struct sst_pci_info {
	struct sst_info *probe_data;
	struct sst_ssp_info *ssp_data;
	struct sst_board_config_data *bdata;
	struct sst_platform_config_data *pdata;
};

#endif
