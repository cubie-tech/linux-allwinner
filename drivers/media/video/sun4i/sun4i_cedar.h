/*
**************************************************************************************************************
*											         eLDK
*						            the Easy Portable/Player Develop Kits
*									           desktop system
*
*						        	 (c) Copyright 2009-2012, ,HUANGXIN China
*											 All Rights Reserved
*
* File    	: sun4i_cedar.h
* By      	: HUANGXIN
* Func		:
* Version	: v1.0
* ============================================================================================================
* 2011-5-25 9:57:05  HUANGXIN create this file, implements the fundemental interface;
**************************************************************************************************************
*/
#ifndef _SUN4I_CEDAR_H_
#define _SUN4I_CEDAR_H_

enum IOCTL_CMD {
	IOCTL_UNKOWN = 0x100,
	IOCTL_GET_ENV_INFO,
	IOCTL_WAIT_VE,
	IOCTL_RESET_VE,
	IOCTL_ENABLE_VE,
	IOCTL_DISABLE_VE,
	IOCTL_SET_VE_FREQ,

	IOCTL_CONFIG_AVS2 = 0x200,
	IOCTL_GETVALUE_AVS2 ,
	IOCTL_PAUSE_AVS2 ,
	IOCTL_START_AVS2 ,
	IOCTL_RESET_AVS2 ,
	IOCTL_ADJUST_AVS2,
	IOCTL_ENGINE_REQ,
	IOCTL_ENGINE_REL,
	IOCTL_ENGINE_CHECK_DELAY,
	IOCTL_GET_IC_VER,

	IOCTL_ADJUST_AVS2_ABS,
	IOCTL_FLUSH_CACHE,
};

struct cedarv_env_infomation{
	unsigned int phymem_start;
	int  phymem_total_size;
	unsigned int  address_macc;
};

struct cedarv_cache_range{
	long start;
	long end;
};

struct __cedarv_task {
	int task_prio;
	int ID;
	unsigned long timeout;
	unsigned int frametime;
	unsigned int block_mode;
};

struct cedarv_engine_task {
	struct __cedarv_task t;
	struct list_head list;
	struct task_struct *task_handle;
	unsigned int status;
	unsigned int running;
	unsigned int is_first_task;
};

/*利用优先级task_prio查询当前运行task的frametime，和比优先级task_prio高的task可能运行的总时间total_time*/
struct cedarv_engine_task_info {
	int task_prio;
	unsigned int frametime;
	unsigned int total_time;
};

/*--------------------------------------------------------------------------------*/
#define REGS_pBASE			(0x01C00000)	 	      // register base addr

#define SRAM_REGS_pBASE     (REGS_pBASE + 0x00000)    // SRAM Controller
#define CCMU_REGS_pBASE     (REGS_pBASE + 0x20000)    // clock manager unit
#define MACC_REGS_pBASE     (REGS_pBASE + 0x0E000)    // media accelerate VE
#define SS_REGS_pBASE       (REGS_pBASE + 0x15000)    // Security System
#define SDRAM_REGS_pBASE    (REGS_pBASE + 0x01000)    // SDRAM Controller
#define AVS_REGS_pBASE      (REGS_pBASE + 0x20c00)

#define SRAM_REGS_BASE      SRAM_REGS_pBASE           // SRAM Controller
#define CCMU_REGS_BASE      CCMU_REGS_pBASE           // Clock Control manager unit  OK
#define MACC_REGS_BASE      MACC_REGS_pBASE           // Media ACCelerate
#define SS_REGS_BASE        SS_REGS_pBASE             // Security System
#define SDRAM_REGS_BASE		SDRAM_REGS_pBASE          //SDRAM Controller   OK
#define AVS_REGS_BASE       AVS_REGS_pBASE

#define MPEG_REGS_BASE      (MACC_REGS_BASE + 0x100)  // MPEG engine
#define H264_REGS_BASE      (MACC_REGS_BASE + 0x200)  // H264 engine
#define VC1_REGS_BASE       (MACC_REGS_BASE + 0x300)  // VC-1 engine

#define SRAM_REGS_SIZE      (4096)  // 4K
#define CCMU_REGS_SIZE      (1024)  // 1K
#define MACC_REGS_SIZE      (4096)  // 4K
#define SS_REGS_SIZE        (4096)  // 4K
/*--------------------------------------------------------------------------------*/

#define SRAM_REG_o_CFG	    (0x00)
#define SRAM_REG_ADDR_CFG   (SRAM_REGS_BASE + SRAM_REG_o_CFG) // SRAM MAP Cfg Reg 0
/*--------------------------------------------------------------------------------*/

#endif
