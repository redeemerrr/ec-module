/*
 * EC(Embedded Controller) KB3310B Misc device driver header file in linux
 * Author	: liujl <liujl@lemote.com>
 * Date		: 2008-04-20
 *
 * NOTE :
 * 		1, The application layer for reading, writing ec registers and code 
 * 		program are supported.
 */
/* XBI relative registers */
#define REG_XBISEG0     0xFEA0
#define REG_XBISEG1     0xFEA1
#define REG_XBIRSV2     0xFEA2
#define REG_XBIRSV3     0xFEA3
#define REG_XBIRSV4     0xFEA4
#define REG_XBICFG      0xFEA5
#define REG_XBICS       0xFEA6
#define REG_XBIWE       0xFEA7
#define REG_XBISPIA0    0xFEA8
#define REG_XBISPIA1    0xFEA9
#define REG_XBISPIA2    0xFEAA
#define REG_XBISPIDAT   0xFEAB
#define REG_XBISPICMD   0xFEAC
#define REG_XBISPICFG   0xFEAD
#define REG_XBISPIDATR  0xFEAE
#define REG_XBISPICFG2  0xFEAF

/* commands definition for REG_XBISPICMD */
#define	SPICMD_WRITE_STATUS		0x01
#define	SPICMD_BYTE_PROGRAM		0x02
#define	SPICMD_READ_BYTE		0x03
#define	SPICMD_WRITE_DISABLE	0x04
#define	SPICMD_READ_STATUS		0x05
#define	SPICMD_WRITE_ENABLE		0x06
#define	SPICMD_HIGH_SPEED_READ	0x0B
#define	SPICMD_POWER_DOWN		0xB9
#define	SPICMD_SST_EWSR			0x50
#define	SPICMD_SST_SEC_ERASE	0x20
#define	SPICMD_SST_BLK_ERASE	0x52
#define	SPICMD_SST_CHIP_ERASE	0x60
#define	SPICMD_FRDO				0x3B
#define	SPICMD_SEC_ERASE		0xD7
#define	SPICMD_BLK_ERASE		0xD8
#define SPICMD_CHIP_ERASE		0xC7

/* bits definition for REG_XBISPICFG */
#define	SPICFG_AUTO_CHECK		0x01
#define	SPICFG_SPI_BUSY			0x02
#define	SPICFG_DUMMY_READ		0x04
#define	SPICFG_EN_SPICMD		0x08
#define	SPICFG_LOW_SPICS		0x10
#define	SPICFG_EN_SHORT_READ	0x20
#define	SPICFG_EN_OFFSET_READ	0x40
#define	SPICFG_EN_FAST_READ		0x80



/**************************************************************/

/* Ec misc device name */
#define	EC_MISC_DEV		"ec_misc"

/* Ec misc device minor number */
#define	ECMISC_MINOR_DEV	MISC_DYNAMIC_MINOR	

#define	EC_IOC_MAGIC		'E'
/* misc ioctl operations */
#define	IOCTL_RDREG			_IOR(EC_IOC_MAGIC, 1, int)
#define	IOCTL_WRREG			_IOW(EC_IOC_MAGIC, 2, int)
#define	IOCTL_READ_EC		_IOR(EC_IOC_MAGIC, 3, int)
#define	IOCTL_PROGRAM_IE	_IOW(EC_IOC_MAGIC, 4, int)
#define	IOCTL_PROGRAM_EC	_IOW(EC_IOC_MAGIC, 5, int)

/* start address for programming of EC content or IE */
#define	EC_START_ADDR	0x00000000	// ec running code start address
#define	IE_START_ADDR	0x00020000	// ec information element storing address

/* EC state */
#define	EC_STATE_IDLE	0x00	// ec in idle state
#define	EC_STATE_BUSY	0x01	// ec in busy state

/* timeout value for programming */
#define	EC_FLASH_TIMEOUT	0x1000	// ec program timeout

/* EC content max size */
#define	EC_CONTENT_MAX_SIZE	(61 * 1024)
#define	IE_CONTENT_MAX_SIZE	(0x100000 - IE_START_ADDR)
/* the register operation access struct */
struct ec_reg {
	u32 addr;	/* the address of kb3310 registers */
	u8	val;	/* the register value */
};

struct ec_info {
	u32 start_addr;
	u32 size;
	u8	*buf;
};