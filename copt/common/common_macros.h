//common_macros.h header file

/////////////////////
// vertex filters for recoloring and infra-chrom

#define RECOLOR_SWAP(v,vswap,recol,j) {				\
m_unsel.erase_bit((v));								\
m_colsets[(j)].set_bit((vswap));					\
m_colsets[(recol)].set_bit((v));					\
m_colsets[(recol)].erase_bit((vswap));				\
}

#define INFRA_CHROM(v,recol,j) {					\
m_unsel.erase_bit((v));								\
m_forbidden.set_bit((j));							\
m_forbidden.set_bit((recol));						\
}

#define RECOLOR_SIMPLE_SWAP(v,recol)  {				\
m_unsel.erase_bit((v));								\
m_colsets[(recol)].set_bit((v));					\
}


/////////////////////
// vertex filters for recoloring and infra-chrom 
// for multicore

#define RECOLOR_SWAP_PARA(v,vswap,recol,j) {		\
m_unsel[ID].erase_bit((v));								\
m_colsets[ID][(j)].set_bit((vswap));					\
m_colsets[ID][(recol)].set_bit((v));					\
m_colsets[ID][(recol)].erase_bit((vswap));				\
}

#define INFRA_CHROM_PARA(v,recol,j) {				\
m_unsel[ID].erase_bit((v));								\
m_forbidden[ID].set_bit((j));							\
m_forbidden[ID].set_bit((recol));						\
}

#define RECOLOR_SIMPLE_SWAP_PARA(v,recol)  {		\
m_unsel[ID].erase_bit((v));								\
m_colsets[ID][(recol)].set_bit((v));					\
}
