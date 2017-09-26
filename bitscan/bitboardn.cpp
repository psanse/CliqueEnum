// BitBoardN.cpp: implementation of the BitBoardN class.
//
//////////////////////////////////////////////////////////////////////

#include "bitboardn.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
 
using namespace std;

BitBoardN&  AND (const BitBoardN& lhs, const BitBoardN& rhs,  BitBoardN& res){
	for(int i=0; i<lhs.m_nBB; i++){
		res.m_aBB[i]=lhs.m_aBB[i] & rhs.m_aBB[i];
	}
return res;
}

BitBoardN&  OR	(const BitBoardN& lhs, const BitBoardN& rhs,  BitBoardN& res){
	for(int i=0; i<lhs.m_nBB; i++){
		res.m_aBB[i]=lhs.m_aBB[i] | rhs.m_aBB[i];
	}
return res;
}

BitBoardN&   AND (int first_block, const BitBoardN& lhs, const BitBoardN& rhs,  BitBoardN& res){
	for(int i=first_block; i<lhs.m_nBB; i++){
		res.m_aBB[i]=rhs.m_aBB[i] & lhs.m_aBB[i];
	}
return res;
}

BitBoardN&   AND (int first_block, int last_block, const BitBoardN& lhs, const BitBoardN& rhs,  BitBoardN& res){
	for(int i=first_block; i<=last_block; i++){
		res.m_aBB[i]=rhs.m_aBB[i] & lhs.m_aBB[i];
	}
return res;
}

BitBoardN&  AND	(const BitBoardN& lhs, const BitBoardN& rhs,  BitBoardN& res, int last_vertex, bool lazy){
///////////////
// AND circumscribed to vertices [0,last_vertex(
//
// A non-lazy operations cleans the remaining blocks after last-vertex as well

	int nbb=WDIV(last_vertex);
	for(int i=0; i<=nbb; i++){
		res.m_aBB[i]=rhs.m_aBB[i] & lhs.m_aBB[i];
	}

	//trim last
	res.m_aBB[nbb] &= Tables::mask_right[WMOD(last_vertex)];
	
	//delete the rest of bitstring if the operation is not lazy
	if(!lazy){
		for(int i=nbb+1; i<lhs.m_nBB; i++){
			res.m_aBB[i]=ZERO;
		}
	}

return res;
}

int* AND (const BitBoardN& lhs, const BitBoardN& rhs, int last_vertex, int* res, int& size){
///////////////
// AND circumscribed to vertices [0,last_vertex(
//
// RETURNS result as a set of vertices (res) and number of vertices in the set (size)
//
// OBSERVATIONS: ***Experimental-efficiency
	
	size=0; BITBOARD bb; int offset;
	
	int nbb=WDIV(last_vertex);
	for(int i=0; i<nbb; i++){
		bb=rhs.m_aBB[i] & lhs.m_aBB[i];
		offset=WMUL(i);
		while(bb){
			int v=BitBoard::lsb64_intrinsic(bb);
			res[size++]=offset+v;
			bb^=Tables::mask[v];
		}
	}

	//trim last
	bb= rhs.m_aBB[nbb] & lhs.m_aBB[nbb] & Tables::mask_right[WMOD(last_vertex)];
	while(bb){
		int v=BitBoard::lsb64_intrinsic(bb);
		res[size++]=WMUL(nbb)+v;
		bb^=Tables::mask[v];
	}

return res;
}



BitBoardN&  ERASE(const BitBoardN& lhs, const BitBoardN& rhs,  BitBoardN& res){
/////////////
// removes rhs FROM lhs

	for(int i=0; i<lhs.m_nBB; i++){
		res.m_aBB[i]=lhs.m_aBB[i] &~ rhs.m_aBB[i];
	}

return res;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BitBoardN::BitBoardN(int popsize /*1 based*/ , bool reset){
			
	m_nBB=INDEX_1TO1(popsize);

#ifndef _MEM_ALIGNMENT
	if(!(m_aBB= new BITBOARD[m_nBB])){
#else
	if(!(m_aBB = (BITBOARD*)_aligned_malloc(sizeof(BITBOARD)*m_nBB,_MEM_ALIGNMENT))){
#endif
			printf("Error al reservar memoria");
			m_nBB=-1;
	}
	
	//Sets to 0 all bits
	if(reset) erase_bit();
}

BitBoardN::BitBoardN(const BitBoardN& bbN){
///////////////////////////
// copy constructor

	//allcoates memory
	if(bbN.m_aBB==NULL || bbN.m_nBB<0 ){
		m_nBB=-1;
		m_aBB=NULL;
	return;
	}
	
 	m_nBB=bbN.m_nBB;

#ifndef _MEM_ALIGNMENT
	m_aBB=new BITBOARD[m_nBB];
#else
	m_aBB = (BITBOARD*)_aligned_malloc(sizeof(BITBOARD)*m_nBB, _MEM_ALIGNMENT );
#endif
 
	//copies bitblocks
	for(int i=0; i<m_nBB; i++)
 				m_aBB[i]=bbN.m_aBB[i];
 }

BitBoardN::BitBoardN(const vector<int>& v){
///////////////////
// vector elements should be zero based (i.e v[0]=3, bit-index 3=1)

	//Getting BB Size
	m_nBB=INDEX_0TO1(*(max_element(v.begin(), v.end())) ) ; 
#ifndef _MEM_ALIGNMENT
	m_aBB=new BITBOARD[m_nBB];
#else
	m_aBB = (BITBOARD*)_aligned_malloc(sizeof(BITBOARD)*m_nBB, _MEM_ALIGNMENT );
#endif
	erase_bit();
	for(int i=0; i<v.size(); i++){
		if(v[i]>=0)
			set_bit(v[i]);
	}
}

BitBoardN::~BitBoardN(){
	if(m_aBB!=NULL){	
		delete [] m_aBB;
	}
	m_aBB=NULL;
}

BitBoardN::BitBoardN (const std::vector<int>& v, int popsize){
///////////////////
// vector elements should be zero based (i.e v[0]=3, bit-index 3=1)
// first_update: 12/11/16
// last_update: 12/11/16

	m_nBB=INDEX_1TO1(popsize);

#ifndef _MEM_ALIGNMENT
	if(!(m_aBB= new BITBOARD[m_nBB])){
#else
	if(!(m_aBB = (BITBOARD*)_aligned_malloc(sizeof(BITBOARD)*m_nBB,_MEM_ALIGNMENT))){
#endif
			printf("BitBoardN()::Error in allocation");
			m_nBB=-1;
			return;
	}
	
	//Sets to 0 all bits
	erase_bit();
	for(int i=0; i<v.size(); i++){
		if(v[i]>=0 && v[i]<popsize)	set_bit(v[i]);
		else{
			cout<<"BitBoardN::vector element:"<<v[i]<<" lost during construction"<<endl;
		}
	}

}

void BitBoardN::init(int popsize, const vector<int> &v){
///////////////////////////
// values in vector are 1-bits in the bitboard (0 based)
	
	if(m_aBB!=NULL){
#ifndef _MEM_ALIGNMENT
		delete [] m_aBB;
#else
		_aligned_free(m_aBB);
#endif
		m_aBB=NULL;
	}
	
	m_nBB=INDEX_1TO1(popsize); //((popsize-1)/WORD_SIZE)+1;
	 
#ifndef _MEM_ALIGNMENT
	m_aBB= new BITBOARD[m_nBB];
#else
	m_aBB = (BITBOARD*)_aligned_malloc(sizeof(BITBOARD)*m_nBB,_MEM_ALIGNMENT);
#endif

	//sets bit conveniently
	erase_bit();
	for(int i=0; i<v.size(); i++){
		if(v[i]>=0 && v[i]<popsize)
						set_bit(v[i]);
		else{
			erase_bit();		//Errr. exit
			cout<<"Error en valor.BitBoardN.New(...)"<<endl;
			break;
		}
	}
}


BITBOARD* BitBoardN::get_bitstring (){
	return m_aBB;
}

const BITBOARD* BitBoardN::get_bitstring ()	const{
	return m_aBB;
}

void BitBoardN::init(int popsize, bool reset){
//////////////////////
// only way to change storage space once constructed

	if(m_aBB!=NULL){
#ifndef _MEM_ALIGNMENT
		delete [] m_aBB;
#else
		_aligned_free(m_aBB);
#endif
		m_aBB=NULL;
	}

	//nBBs
	m_nBB=INDEX_1TO1(popsize); 
	
#ifndef _MEM_ALIGNMENT
	m_aBB= new BITBOARD[m_nBB];
#else
	m_aBB = (BITBOARD*)_aligned_malloc(sizeof(BITBOARD)*m_nBB,_MEM_ALIGNMENT);
#endif

	//Sets to 0
	if(reset)
		erase_bit();

return ;
}



//void BitBoardN::add_bitstring_left(){
/////////////////////
////
//// Adds 1 bit to MSB
////
//// Date of creation: 26/4/2010
//// Date last modified: 26/4/2010
//// Autor:PSS
//
//	int nvertex=this->msbn64();		//is -1 if empty
//	if(nvertex!=(WMUL(nvertex)-1)){
//			set_bit(nvertex+1);				//add bit 0 if BB empty
//	}
//}

//////////////////////////
//
// BITSET OPERATORS
// (size is determined by *this)
/////////////////////////

BitBoardN& BitBoardN::operator &=	(const BitBoardN& bbn){
	for(int i=0; i<m_nBB; i++)
				m_aBB[i]&=bbn.m_aBB[i];
return *this;
}

BitBoardN& BitBoardN::operator |=	(const BitBoardN& bbn){
	for(int i=0; i<m_nBB; i++)
				m_aBB[i]|=bbn.m_aBB[i];
return *this;
}

BitBoardN&  BitBoardN::AND_EQ (int first_block, const BitBoardN& rhs ){
//////////////////////
// mask in range [first_block , END[
	for(int i=first_block; i<m_nBB; i++)
				m_aBB[i]&=rhs.m_aBB[i];
return *this;
}


BitBoardN&  BitBoardN::OR_EQ (int first_block, const BitBoardN& rhs ){
//////////////////////
// mask in range [first_block , END[

	for(int i=first_block; i<m_nBB; i++)
				m_aBB[i]|=rhs.m_aBB[i];
return *this;
}



BitBoardN& BitBoardN::operator ^=	(const BitBoardN& bbn){
	for(int i=0; i<m_nBB; i++)
				m_aBB[i]^=bbn.m_aBB[i];
return *this;
}


BitBoardN& BitBoardN::flip	(){
	for(int i=0; i<m_nBB; i++)
			m_aBB[i]=~m_aBB[i];
return *this;
}

//////////////////////////
//
// BOOLEAN FUNCTIONS
//
//////////////////////////


//////////////////////////
//
// I/O FILES
//
//////////////////////////


void BitBoardN::print(std::ostream& o, bool show_pc ) const {
/////////////////////////
// shows bit string as [bit1 bit2 bit3 ... <(pc)>]  (if empty: [ ]) (<pc> optional)
	
	o<<"[";
		
	int nBit=EMPTY_ELEM;
	while(1){
		nBit=next_bit(nBit);
		if(nBit==EMPTY_ELEM) break;
		o<<nBit<<" ";
	}

	if(show_pc){
		int pc=popcn64();
		if(pc)	o<<"("<<popcn64()<<")";
	}
	
	o<<"]";
}

string BitBoardN::to_string (){
	ostringstream sstr;
	sstr<<"[";
	this->print();
	int nBit=EMPTY_ELEM;
	while(true){
		nBit=next_bit(nBit);
		if(nBit==EMPTY_ELEM) break;
		sstr<<nBit<<" ";
	}

	sstr<<"("<<popcn64()<<")";
	sstr<<"]";

return sstr.str();
}


void BitBoardN::to_vector(vector<int>& vl ) const {
//////////////////////
// copies bit string to vector 

	vl.clear();

	int v=EMPTY_ELEM;
	while(true){
		v=next_bit(v);
		if(v==EMPTY_ELEM) break;

		vl.push_back(v);
	}
}

int* BitBoardN::to_old_vector (int* lv, int& size) 	{
	size=0;
	int v=EMPTY_ELEM;
	while(true){
		if( (v=next_bit(v))!=EMPTY_ELEM ){
			lv[size++]=v;
		}else break;
	}
	return lv;
}

int* BitBoardN::to_old_vector_reverse (int* lv, int& size) 	{
	size=0;
	int v=EMPTY_ELEM;
	while(true){
		if( (v=previous_bit(v))!=EMPTY_ELEM ){
			lv[size++]=v;
		}else break;
	}
	return lv;
}


BitBoardN& BitBoardN::operator =  (const BitBoardN& bbN){
	if(m_nBB!=bbN.m_nBB){
		//allocates memory
		init(bbN.m_nBB,false);		
	}

	for(int i=0; i<m_nBB; i++)
			m_aBB[i]=bbN.m_aBB[i];
return *this;
}



