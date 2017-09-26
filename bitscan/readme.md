
BITSCAN
===================
BITSCAN is a C++ 64-bit library which manipulates bit arrays (alias bit strings, bit sets etc.) and is specifically oriented for fast bitscanning operations. BITSCAN is the result of years of research in combinatorial optimization problems, and has been used succesfully to model amd reason with sets of elements. In this type of models a bitstring represents a population set and members belonging to the set are marked as a 1-bit and referred by the position in the bitstring.

The library currently offers the following types for bitstrings

- `bitblock`: Wrapper for bit manipulation of 64-bit numbers (*lsb*, *msb*, *popcount* etc.).
- `simple_bitarray`: Extends bit manipulation to bit arrays
- `bitarray`: Main type for standard bit manipualtion. Uses compiler intrinsics (or assembler equivalents) enhancements.
- `watched_bitarray`: Extends the bitarray type for populations with low density but not really sparse.Empty bit blocks are still stored in full, but two pointers (aka sentinels) which point (alias *watch*) the highest and lowest empty blocks respectively, determine the range of useful bitmasks.
- `simple_sparse_bitarray`: General operations for sparse bit arrays.
- `sparse_bitarray`: Main type for efficiente sparse bit arrays.  Uses compiler intrinsics (or assembler equivalents) enhancements.

**BITSCAN has been tested in Linux and Windows OS**. Please note that 64-bit configurations are required. 

GETTING STARTED
-------------------------------
To include the BITSCAN library in your project just add the dependency to the *bitscan.h file*. Here is a simple example which defines an efficient bitstring for bitscanning with a population size of 100 and sets the eleventh element to 1. 

    #include "<path>/bitscan/bitscan.h"
	//...
    int main(){
    	bitarray bbi(100);
		bbi.set_bit(10);
		cout<<bbi;
    }
 You will find many more examples in the *tests* folder of the block.  


CONFIGURATION PARAMETERS
-------------------------

The file *config.h* contains customization parameters. Critical issues are:

1. POPCOUNT_64: Disable in processor architectures which do not support intrinsic popcount64 assembly instruction. 
2. DE\_BRUIJN: When enabled uses De Bruijn hashing for fast bit scanning.
3. CACHED\_INDEX\_OPERATIONS: When enabled, uses additional memory to cache bitboard indexes for fast bitscanning.  The default cache size is a population size of 15001 (i.e. MAX\_CACHED\_INDEX=15001). Disable for bitarrays with population greater than 15000.

LEGAL
-----
BITSCAN is distributed under the conditions in *legal.txt*.  Note **the use is limited to research purposes only**.

Acknowledgements
-------------------------
This research has been partially funded by the Spanish Ministry of Economy and Competitiveness (MINECO), national grants DPI 2010-21247-C02-01, DPI 2014-53525-C3-1-R.

