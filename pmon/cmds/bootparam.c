#include "bootparam.h"

struct loongson_params  g_lp = { 0 };
struct efi_memory_map_loongson g_map = { 0 };
struct efi_cpuinfo_loongson g_cpuinfo_loongson = { 0 };
struct system_loongson g_sysitem = { 0 };
struct irq_source_routing_table g_irq_source = { 0 };
struct interface_info g_interface = { 0 };
struct interface_info g_board = { 0 };
struct loongson_special_attribute g_special = { 0 };

int init_boot_param(struct boot_params *bp)
{
  
  init_efi(&(bp->efi));

  return bp;
}

void init_efi(struct efi *efi)
{
    init_smbios(&(efi->smbios));
}

void init_smbios(struct smbios_tables *smbios)
{
  
  smbios->vers = 0;
  smbios->vga_bios = 0xc3f00000;

  init_loongson_params(&(smbios->lp)); 

}


void init_loongson_params(struct loongson_params *lp)
{

  lp->memory_offset = (unsigned long long)init_memory_map() - (unsigned long long)lp;
  lp->cpu_offset = (unsigned long long)init_cpu_info() - (unsigned long long)lp; 
  lp->system_offset = (unsigned long long)init_system_loongson() - (unsigned long long)lp;
  lp->irq_offset = (unsigned long long)init_irq_source() - (unsigned long long)lp; 
  lp->interface_offset = (unsigned long long)init_interface_info() - (unsigned long long)lp;
  lp->boarddev_table_offset = (unsigned long long)board_devices_info() - (unsigned long long)lp;
  //lp->special_offset = (unsigned long long)init_special() - (unsigned long long)lp; 
}


struct efi_memory_map_loongson * init_memory_map()
{
  struct efi_memory_map_loongson *emap = &g_map;


  //map->mem_start_addr = 0x80000000;
  emap->nr_map = 2; 
  emap->mem_freq = 300000000; //300M
  //map->memsz_high = atoi(getenv("highmemsize"));
  //map->mem_size = atoi(getenv("memsize"));
  //map->memsz_reserved = 16;

#if 1
 
  emap->map[0].node_id = 0;
  //strcpy(emap->map[0].mem_name, "node0_low");
  emap->map[0].mem_type = 1;
  emap->map[0].mem_start = 0x01000000;
  emap->map[0].mem_size = atoi(getenv("memsize"));

  emap->map[1].node_id = 0;
  //strcpy(emap->map[1].mem_name, "node0_high");
  emap->map[1].mem_type = 2;
  emap->map[1].mem_start = 0x90000000;
  emap->map[1].mem_size = atoi(getenv("highmemsize"));
#endif


  return emap;
}

#ifdef LOONGSON_3BSINGLE
  #define PRID_IMP_LOONGSON    0x6506
 enum loongson_cpu_type cputype = Loongson_3B;
#endif
#ifdef LOONGSON_3ASINGLE
  #define PRID_IMP_LOONGSON    0x6505
  enum loongson_cpu_type cputype = Loongson_3A;
#endif
#ifdef LOONGSON_3ASERVER
  #define PRID_IMP_LOONGSON    0x6505
  enum loongson_cpu_type cputype = Loongson_3A;
#endif
struct efi_cpuinfo_loongson *init_cpu_info()
{
  struct efi_cpuinfo_loongson *c = &g_cpuinfo_loongson;

  c->processor_id = PRID_IMP_LOONGSON;
  c->cputype  = cputype;

  c->cpu_clock_freq = atoi(getenv("cpuclock"));

#ifdef LOONGSON_3ASERVER
  c->total_node = 4;
  c->nr_cpus = 8;
#endif
#ifdef LOONGSON_3BSINGLE
  c->total_node = 4;
  c->nr_cpus = 8;
#endif
#ifdef LOONGSON_3ASINGLE
  c->total_node = 1;
  c->nr_cpus = 4;
#endif

  c->cpu_startup_core_id = 0;

return c;
}
 
struct system_loongson *init_system_loongson()
{
 struct system_loongson *s = &g_sysitem;
  s->ccnuma_smp = 1;
#ifdef LOONGSON_3ASERVER
  s->ccnuma_smp = 1;
  s->sing_double_channel = 2;
#endif
#ifdef LOONGSON_3BSINGLE
  s->ccnuma_smp = 1;
  s->sing_double_channel = 2;
#endif
#ifdef LOONGSON_3ASINGLE
  s->ccnuma_smp = 0;
  s->sing_double_channel = 1;
#endif

  return s;
}

enum loongson_irq_source_enum
{
  HT,I8259,UNKNOWN
};



struct irq_source_routing_table *init_irq_source()
{

 struct irq_source_routing_table *irq_info = &g_irq_source ;

	
	irq_info->PIC_type = HT;

 
#ifdef LOONGSON_3BSINGLE
	irq_info->ht_int_bit = 1<<16;
#else
	irq_info->ht_int_bit = 1<<24;
#endif
	irq_info->ht_enable = 0x0000d17b;

#ifdef LOONGSON_3BSINGLE
	irq_info->node_id = 1;
#else
	irq_info->node_id = 0;
#endif

	irq_info->pci_mem_start_addr = 0x40000000ul;
	irq_info->pci_mem_end_addr = 0x7ffffffful;

	return irq_info;
}

struct interface_info *init_interface_info()
{
  
 struct interface_info *inter = &g_interface;
 
  inter->vers = 0x0001;
  inter->size = 0x5 ;
  inter->flag = 1;

  strcpy(inter->description,"PMON_Version_v2.1");
  
  return inter;
}

struct board_devices *board_devices_info()
{
  
 struct board_devices *bd = &g_board;
 
#ifdef LOONGSON_3ASINGLE
  strcpy(bd->name,"Loongson-3A780E-1-V1.03-demo");
#endif
#ifdef LOONGSON_3ASERVER
  strcpy(bd->name,"Loongson-3A780E-2-V1.02-demo");
#endif
#ifdef LEMOTE_3AITX
  strcpy(bd->name,"lemote-3a-itx-a1101");
#endif
#ifdef LEMOTE_3ANOTEBOOK
  strcpy(bd->name,"lemote-3a-notebook-a1004");
#endif
  bd->num_resources = 10;
 
  return bd;
}
