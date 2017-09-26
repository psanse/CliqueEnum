//common.h: common utilities for the framework

#ifndef __COMMON_H__
#define	__COMMON_H__


#include <iostream>
#include <string>
#include <iterator>

using namespace std;


namespace com {
 
 namespace dir {

	  inline void append_slash(string & path){
		  /////////////////
		  // appends slash at the end of a path string if required taking into account SO

		  size_t pos;

		  pos=path.find_last_of("\\/");
		  if(pos==path.length()-1){
#ifdef  __GNUC__
			  if(path[pos]=='\\')
				  path.replace(pos,path.length(),"/");
#elif	_MSC_VER
			//Windows accepts both slashes so no changes are required
			/*  if(path[pos]=='/')
				  path.replace(pos,path.length(),"\\");*/
#endif
		  }else{ //no slash at the ends
#ifdef _MSC_VER
			  //default option for windows
			  path+='\\';

#elif  __GNUC__
			  path+='/';
#endif
		  }
	  }

  }

   namespace stl {

	   template<class Collection_t>
	   inline bool all_equal(const Collection_t& col){
		   if(col.empty()) return true;
		   for(typename Collection_t::const_iterator it=col.begin()+1; it!=col.end(); ++it){
			   if(col[0]!=*it) return false;
		   }
		return true;
	   }

	   template <class Collection_t>
	   void print_collection(const Collection_t& c,  ostream&  o= cout){
		   copy(c.begin(), c.end(), ostream_iterator<typename Collection_t::value_type>(o," " ));
	   }

   }
   
   //my minimal stack
   template <class T>
   struct stack_t{
	   int pt;													//stack pointer[0, MAX_SIZE-1], always points to a free position (top of the stack) 
	   T* stack;
	   	   
	   stack_t():pt(-1), stack(NULL){}
	   stack_t(int MAX_SIZE):stack(NULL){init(MAX_SIZE);}
	   ~stack_t(){clear();}
	   void init(int MAX_SIZE){clear(); stack = new T[MAX_SIZE]; pt=0;}
	   void clear(){if(stack){ delete [] stack; } stack=NULL;  pt=-1;}
	   
	   void push(T d){stack[pt++]=d;}							//*** no checking against N
	   T pop(){if(pt==0) return -1; else return stack[--pt];}
	   T get_elem(int pos){return stack[pos];}
	   void erase(int pos){stack[pos]=stack[--pt];}				//removes a single element at pos	*** DEFINE AN EMPTY UNIVERSAL VALUE OF stack[pt]?
	   void erase(){pt=0;}										//removes elements
	   unsigned int size(){return pt;}
	   bool empty(){return(pt==0);}								// no elements in the stack (allocated space)

	   friend ostream& operator <<(ostream& o, const stack_t & s){ 
		   o<<"[";   for(int i=0; i<s.pt; i++) {o<<s.stack[i]<<" ";} o<<"]"<<"["<<s.pt<<"]"<<endl;
			return o;
	   }
   };

   

   namespace mat{
	   inline
	   bool uniform_dist(double p){
		   //returns true with prob p, 0 with 1-p
		   double n_01=rand()/(double)RAND_MAX;
		   return (n_01<=p);
	   }
	   template<typename T>
	   inline 
	   T min3(T x, T y, T z){
		   return std::min<T>(std::min<T>(x, y),z);
	   }
   }
  
  
}




			


#endif