//benchmark_clique.h: batch for tests which generate instances on the fly
#ifndef __BENCHMARK_CLIQUE_H__
#define __BENCHMARK_CLIQUE_H__

#include <iostream>
#include <sstream>
#include "utils/benchmark.h"

using namespace std;

#define CASTLE		20			//number of images of data set
#define FOUNTAIN	25			//number of images of data set
#define DINO		36			//number of images of data set
#define AIRVIEW		30			//too easy (1000 node graphs)
#define PIEDRA		10	
#define	KAPEL		75
#define	HERZJESU	23
#define	HELIGRANDE	181			//a reduced subset
#define	UALBERTA	100			//up to 450	(around 1000 vertices)
#define FPV1		108				

class BkClique:public Benchmark{
public:
	BkClique(string path):Benchmark(path){}

	void Dimacs();
	void Brock();
	void Gen();
	void Frb();
	void San();
	void Phat();
	void Keller();
	void Hamming();
	void Dsj();
	void C();
	void Mann();
	void SubsetEasyDimacs();		//also includes subset of bhoshlib
	void SubsetHardDimacs();		//also includes subset of bhoshlib
	void ExpectedSubSecondDimacs();	//for robust time measures (n-repetitions)
	void SubsetBhoshlib();
	void Evil();					//Bogdan zavalnij graphs
	void Monotone();
	void Snap();
	void Others();					//for general purpose experiments

	void vcp();						//a step to solve VCP (Furini)

	//real graphs
	void Real50();
	void Real50_100();
	void Real101_300();
	void Real301_700();

	void Real_GOMS();				//created for GOMS 16 paper (BBMCW)	

	//real graphs for enumeration
	void RealLargeEnum(int degeneracy);
	void RealTrivialEnum(int degeneracy);
	void RealDimacsEnum();
	void RealLargeHardEnum();
	void RealLargeExtremelyHardEnum();

	
	//matching images
	void Castle();
	void Fountain();
	void Dino();
	void Airview();
	void Piedra();
	void Kapel();
	void Herzjesu();
	void HeliGrande();
	void Ualberta();
	void Fpv1();

	//csp-as provided by Li
	void black_hole();
	void bqwh();
	void csp_dsjc();
	void csp_geom();
	void csp_le450();
	void csp_myciel();
	void driver();
	void marc();
	void rand_2_Xs();
	void lard();
	void csp_queens();
	void composed();
	void ehi();
	void csp_frb();
	void hanoi();
	void langford();
	void qcp();
	void qwh();
	void tightness();
	void csp_all();
	void csp_all_except_frb();
};

class BkCliqueILS:public Benchmark{
public:
	BkCliqueILS(string path):Benchmark(path){}

	void GenILS();
	void FrbILS();
	void KellerILS();
	void HammingILS();
	void DimacsILS();
	void SubsetHardDimacsILS();
	void SubsetEasyDimacsILS();
	void OthersILS();	


	//matching images
	void Castle_ILS();
	void Castle_B_ILS();
	void Herzjesu_big_ILS();
	void Fpv1_big_ILS();
};

//class for weighted cliquw
class BkCliqueW:public Benchmark{
public:
	BkCliqueW(string path):Benchmark(path){}


	void EasyWeighted();
	void SubsetEasyDimacs();
	void SubsetHardDimacs();
	void Dimacs();
	void Brock();
	void Gen();
	void Frb();
	void San();
	void Phat();
	void Keller();
	void Hamming();
	void Dsj();
	void C();
	void Mann();
	void WinnerDetermination_100();			/* hardest by a long way */
	void WinnerDetermination_200();
	void WinnerDetermination_300();
	void WinnerDetermination_400();			/* only 99 instances */
	void WinnerDetermination_500();
	void WinnerDetermination_All();			/* hardest by a long way */
};

#endif