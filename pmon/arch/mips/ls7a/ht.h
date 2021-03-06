/*******************************
 * file: ht.h
 * ht related definations
 * for CPU: LS3A2000/LS3A3000
 * for PCH: LS7A1000
*******************************/

#define ALLOW_EXT_IOI

#ifdef LOONGSON3A4000
#define LS3A_HT_REG_NUM 160
#else
#define LS3A_HT_REG_NUM 98
#endif
#define LS7A_HT_REG_NUM 154

#define HT_GEN1_FREQ_CTRL_200M   (0)
#define HT_GEN1_FREQ_CTRL_400M   (2)
#define HT_GEN1_FREQ_CTRL_800M   (5)

#define HT_GEN3_FREQ_CTRL_400M   (0)
#define HT_GEN3_FREQ_CTRL_800M   (2)
#define HT_GEN3_FREQ_CTRL_1600M  (9)

#define HT_WIDTH_CTRL_8BIT  (0)
#define HT_WIDTH_CTRL_16BIT (1)

#define HT_WIDTH_CTRL_8     (0x00)
#define HT_WIDTH_CTRL_16    (0x11)

#define LS7A_HT_PLL_DIV_LO      22
#define LS7A_HT_PLL_DIV_HI      18
#define LS7A_HT_PLL_DIV_REFC    16
#define LS7A_HT_PLL_LOOPC       9
#define LS7A_HT_PLL_DIV_CTRL    5

#define LS3A_HT_PLL_3200M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (2 << LS7A_HT_PLL_DIV_REFC) | (32*2 << LS7A_HT_PLL_LOOPC) | (8 << LS7A_HT_PLL_DIV_CTRL))
#define LS3A_HT_PLL_2600M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (26*3 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS3A_HT_PLL_2200M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (22*3 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS3A_HT_PLL_2000M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (20*3 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#ifdef BONITO_100M
#define LS3A_HT_PLL_2400M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (24*3 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS3A_HT_PLL_1600M  ((2 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (32*3 << LS7A_HT_PLL_LOOPC) | (8 << LS7A_HT_PLL_DIV_CTRL))
#elif BONITO_33M
#define LS3A_HT_PLL_2400M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (24*3 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS3A_HT_PLL_1600M  ((2 << LS7A_HT_PLL_DIV_LO) | (2 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (32*3 << LS7A_HT_PLL_LOOPC) | (8 << LS7A_HT_PLL_DIV_CTRL))
#else //25M
#define LS3A_HT_PLL_2400M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (1 << LS7A_HT_PLL_DIV_REFC) | (24*4 << LS7A_HT_PLL_LOOPC) | (8 << LS7A_HT_PLL_DIV_CTRL))
#define LS3A_HT_PLL_1600M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (1 << LS7A_HT_PLL_DIV_REFC) | (32*2 << LS7A_HT_PLL_LOOPC) | (8 << LS7A_HT_PLL_DIV_CTRL))
#endif
#define LS3A_HT_PLL_1200M  ((2 << LS7A_HT_PLL_DIV_LO) | (2 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (24*3 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS3A_HT_PLL_1000M  ((2 << LS7A_HT_PLL_DIV_LO) | (2 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (20*3 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS3A_HT_PLL_800M   ((2 << LS7A_HT_PLL_DIV_LO) | (2 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (16*3 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS3A_HT_PLL_600M   ((4 << LS7A_HT_PLL_DIV_LO) | (4 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (24*3 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS3A_HT_PLL_400M   ((4 << LS7A_HT_PLL_DIV_LO) | (4 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (16*3 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS3A_HT_PLL_200M   ((8 << LS7A_HT_PLL_DIV_LO) | (8 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (16*3 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))

#define LS7A_HT_PLL_3200M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (2 << LS7A_HT_PLL_DIV_REFC) | (32*2 << LS7A_HT_PLL_LOOPC) | (8 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_HT_PLL_2600M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (26*4 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_HT_PLL_2400M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (24*4 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_HT_PLL_2200M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (22*4 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_HT_PLL_2000M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (20*4 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_HT_PLL_1600M  ((2 << LS7A_HT_PLL_DIV_LO) | (2 << LS7A_HT_PLL_DIV_HI) | (2 << LS7A_HT_PLL_DIV_REFC) | (32*2 << LS7A_HT_PLL_LOOPC) | (8 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_HT_PLL_1200M  ((2 << LS7A_HT_PLL_DIV_LO) | (2 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (24*4 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_HT_PLL_1000M  ((2 << LS7A_HT_PLL_DIV_LO) | (2 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (20*4 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_HT_PLL_800M   ((2 << LS7A_HT_PLL_DIV_LO) | (2 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (16*4 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_HT_PLL_600M   ((4 << LS7A_HT_PLL_DIV_LO) | (4 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (24*4 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_HT_PLL_400M   ((4 << LS7A_HT_PLL_DIV_LO) | (4 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (16*4 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_HT_PLL_200M   ((8 << LS7A_HT_PLL_DIV_LO) | (8 << LS7A_HT_PLL_DIV_HI) | (3 << LS7A_HT_PLL_DIV_REFC) | (16*4 << LS7A_HT_PLL_LOOPC) | (4 << LS7A_HT_PLL_DIV_CTRL))

#define LS7A_C_HT_PLL_2000M  ((1 << LS7A_HT_PLL_DIV_LO) | (1 << LS7A_HT_PLL_DIV_HI) | (2 << LS7A_HT_PLL_DIV_REFC) | (20*2 << LS7A_HT_PLL_LOOPC) | (3 << LS7A_HT_PLL_DIV_CTRL))
#define LS7A_C_HT_PLL_1600M  ((2 << LS7A_HT_PLL_DIV_LO) | (2 << LS7A_HT_PLL_DIV_HI) | (2 << LS7A_HT_PLL_DIV_REFC) | (32*2 << LS7A_HT_PLL_LOOPC) | (5 << LS7A_HT_PLL_DIV_CTRL))
#ifdef LOONGSON3A4000
#define LS3A_HT_RX_CACHE_WIN0_OFFSET    0x140
#define LS3A_HT_RX_CACHE_WIN1_OFFSET    0x148
#define LS3A_HT_RX_CACHE_WIN2_OFFSET    0x150
#define LS3A_HT_RX_CACHE_WIN3_OFFSET    0x158
#define LS3A_HT_RX_CACHE_WIN4_OFFSET    0x160
#define LS3A_HT_TX_POST_WIN0_OFFSET     0x170
#define LS3A_HT_TX_POST_WIN1_OFFSET     0x178
#define LS3A_HT_RX_UNCACHE_WIN0_OFFSET  0x190
#define LS3A_HT_RX_UNCACHE_WIN1_OFFSET  0x198
#define LS3A_HT_RX_UNCACHE_WIN2_OFFSET  0x1A0

#define LS3A_HT_FREQ			0x4C
#define LS3A_HT_RETRY_CONTROL		0x64
#define LS3A_HT_REVISION		0x6C
#define LS3A_HT_LINK_TRAIN		0xD0
#define LS3A_HT_RX_BUS			0x1C8
#define LS3A_HT_RX_BUFFER_DEFAULT	0x1DC
#define LS3A_HT_PLL_CONF		0x1F4

#else
#define LS3A_HT_RX_CACHE_WIN0_OFFSET    0x60
#define LS3A_HT_RX_CACHE_WIN1_OFFSET    0x68
#define LS3A_HT_RX_CACHE_WIN2_OFFSET    0x70
#define LS3A_HT_RX_CACHE_WIN3_OFFSET    0x148
#define LS3A_HT_RX_CACHE_WIN4_OFFSET    0x150
#define LS3A_HT_TX_POST_WIN0_OFFSET     0xD0
#define LS3A_HT_TX_POST_WIN1_OFFSET     0xD8
#define LS3A_HT_RX_UNCACHE_WIN0_OFFSET  0xF0
#define LS3A_HT_RX_UNCACHE_WIN1_OFFSET  0xF8
#define LS3A_HT_RX_UNCACHE_WIN2_OFFSET  0x168

#define LS3A_HT_FREQ			0x48
#define LS3A_HT_RETRY_CONTROL		0x118
#define LS3A_HT_REVISION		0x110
#define LS3A_HT_LINK_TRAIN		0x130
#define LS3A_HT_RX_BUS			0x54
#define LS3A_HT_RX_BUFFER_DEFAULT	0x5C
#define LS3A_HT_PLL_CONF		0x178

#endif

#define LS7A_HT_RX_WIN0_OFFSET      0x140
#define LS7A_HT_RX_WIN1_OFFSET      0x148
#define LS7A_HT_TX_POST_WIN0_OFFSET 0x170
#define LS7A_HT_TX_POST_WIN1_OFFSET 0x178
