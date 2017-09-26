#include "benchmark_clique.h"

void BkClique::Brock(){
	
	add_test("brock200_1.clq");
	add_test("brock200_2.clq");
	add_test("brock200_3.clq");		
	add_test("brock200_4.clq");	
	add_test("brock400_1.clq");			
	add_test("brock400_2.clq");
	add_test("brock400_3.clq");
	add_test("brock400_4.clq");
	add_test("brock800_1.clq");			
	add_test("brock800_2.clq");				
	add_test("brock800_3.clq");				
	add_test("brock800_4.clq");
}

void BkClique::Gen(){
	add_test("gen200_p0.9_44.clq");	
	add_test("gen200_p0.9_55.clq");				
	add_test("gen400_p0.9_55.clq");
	add_test("gen400_p0.9_65.clq");		
	add_test("gen400_p0.9_75.clq");

}



void BkClique::Frb(){
	add_test("frb30-15-1.clq");	
	add_test("frb30-15-2.clq");				
	add_test("frb30-15-3.clq");	
	add_test("frb30-15-4.clq");	
	add_test("frb30-15-5.clq");
	add_test("frb35-17-1.clq");	
	add_test("frb35-17-2.clq");				
	add_test("frb35-17-3.clq");	
	add_test("frb35-17-4.clq");	
	add_test("frb35-17-5.clq");
	add_test("frb40-19-1.clq");	
	add_test("frb40-19-2.clq");				
	add_test("frb40-19-3.clq");	
	add_test("frb40-19-4.clq");	
	add_test("frb40-19-5.clq");
	add_test("frb45-21-1.clq");	
	add_test("frb45-21-2.clq");	
	add_test("frb45-21-3.clq");	
	add_test("frb45-21-4.clq");	
	add_test("frb45-21-5.clq");
	add_test("frb50-23-1.clq");	
	add_test("frb50-23-2.clq");	
	add_test("frb50-23-3.clq");	
	add_test("frb50-23-4.clq");	
	add_test("frb50-23-5.clq");

	add_test("frb53-24-1.clq");	
	add_test("frb53-24-2.clq");	
	add_test("frb53-24-3.clq");	
	add_test("frb53-24-4.clq");	
	add_test("frb53-24-5.clq");

	/*add_test("frb56-24-1.clq");	
	add_test("frb56-24-2.clq");	
	add_test("frb56-24-3.clq");	
	add_test("frb56-24-4.clq");	
	add_test("frb56-24-5.clq");*/

	add_test("frb59-26-1.clq");	
	add_test("frb59-26-2.clq");	
	add_test("frb59-26-3.clq");	
	add_test("frb59-26-4.clq");	
	add_test("frb59-26-5.clq");

	//add_test("frb100-40.clq");
}

void BkClique::San(){
	
	add_test("san200_0.7_1.clq");
	add_test("san200_0.7_2.clq");				
	add_test("san200_0.9_1.clq");				
	add_test("san200_0.9_2.clq");			
	//add_test("san200_0.9_3.clq");			
	add_test("san400_0.5_1.clq");			
	add_test("san400_0.7_1.clq");			
	add_test("san400_0.7_2.clq");			
	add_test("san400_0.7_3.clq");			
	//add_test("san400_0.9_1.clq");	

	add_test("san1000.clq");	

	add_test("sanr200_0.7.clq");			
	add_test("sanr200_0.9.clq");				
	add_test("sanr400_0.5.clq");				
	add_test("sanr400_0.7.clq");
}

void  BkClique::Phat(){
	add_test("p_hat300-1.clq");				
	add_test("p_hat300-2.clq");				
	add_test("p_hat300-3.clq");				
	add_test("p_hat500-1.clq");				
	add_test("p_hat500-2.clq");				
	add_test("p_hat500-3.clq");				
	add_test("p_hat700-1.clq");				
	add_test("p_hat700-2.clq");				
	add_test("p_hat700-3.clq");				
	add_test("p_hat1000-1.clq");				
	add_test("p_hat1000-2.clq");			
	//	add_test("p_hat1000-3.clq");				
	add_test("p_hat1500-1.clq");				
	add_test("p_hat1500-2.clq");				
	//	add_test("p_hat1500-3.clq");	
}

void BkClique::Keller(){
	
	add_test("keller4.clq");	
	add_test("keller5.clq");	
	add_test("keller6.clq");	
}

void BkClique::Hamming(){
	add_test("hamming6-2.clq");	
	add_test("hamming6-4.clq");	
	add_test("hamming8-2.clq");	
	add_test("hamming8-4.clq");	
	add_test("hamming10-2.clq");
	add_test("hamming10-4.clq");
}

void BkClique::Dsj(){

	add_test("dsjc250.5.clq");	
	add_test("dsjc500.1.clq");		
	add_test("dsjc500.5.clq");	
	//add_test("dsjc500.9.clq");	
	add_test("dsjc1000.1.clq");	
	add_test("dsjc1000.5.clq");
	add_test("dsjc1000.9.clq");
}

void BkClique::C(){
	add_test("C125.9.clq");	
	add_test("C250.9.clq");				
	add_test("C500.9.clq");	
	add_test("C1000.9.clq");	
	add_test("C2000.5.clq");
}

void BkClique::Mann(){
	add_test("MANN_a9.clq");				
	add_test("MANN_a27.clq");				
	add_test("MANN_a45.clq");
	//add_test("MANN_a81.clq");			//parado despues de 5 dias en el I7 de casa	
}

void BkClique::Evil(){	
		
	add_test("evil-N120-p98-chv12x10.clq");				
	add_test("evil-N120-p98-myc5x24.clq");				
	add_test("evil-N121-p98-myc11x11.clq");
	add_test("evil-N125-p98-s3m25x5.clq");
	add_test("evil-N138-p98-myc23x6.clq");
	add_test("evil-N150-p98-myc5x30.clq");
	add_test("evil-N150-p98-s3m25x6.clq");

//	add_test("evil-N154-p98-myc11x14.clq"); //6500s
//	add_test("evil-N180-p98-chv12x15.clq"); //3500s
	add_test("evil-N180-p98-myc5x36.clq");
	add_test("evil-N184-p98-myc23x8.clq");
//	add_test("evil-N187-p98-myc11x17.clq");
	add_test("evil-N200-p98-s3m25x8.clq");
	add_test("evil-N210-p98-myc5x42.clq");  //trivial for CliqueInfra

	//add_test("evil-N220-p98-myc11x20.clq");
	//add_test("evil-N230-p98-myc23x10.clq");
	//add_test("evil-N240-p98-chv12x20.clq");
	//add_test("evil-N240-p98-myc5x48.clq");
	//add_test("evil-N250-p98-s3m25x10.clq");
	//add_test("evil-N253-p98-myc11x23.clq");
}

void BkClique::Monotone(){
	add_test("monoton-7.clq");				
	add_test("monoton-8.clq");				
	add_test("monoton-9.clq");
}


void BkClique::Dimacs(){
///////////////////
// DIMACS-clique main set of instances for test validation (no ILS info)
// (includes some frb-30 from Bhoshlib)
//
// DO NOT CHANGE THE ORDER!

	add_test("brock200_1.clq");
	add_test("brock200_2.clq");
	add_test("brock200_3.clq");		
	add_test("brock200_4.clq");	
	add_test("brock400_1.clq");			
	add_test("brock400_2.clq");
	add_test("brock400_3.clq");
	add_test("brock400_4.clq");
	add_test("brock800_1.clq");			
	add_test("brock800_2.clq");				
	add_test("brock800_3.clq");				
	add_test("brock800_4.clq");

	add_test("C125.9.clq");	
	add_test("C250.9.clq");				
	//add_test("C500.9.clq");	
	//add_test("C1000.9.clq");	
	//add_test("C2000.5.clq");

	add_test("c-fat200-1.clq");				
	add_test("c-fat200-2.clq");			
	add_test("c-fat200-5.clq");			
	add_test("c-fat500-1.clq");			
	add_test("c-fat500-2.clq");			 	
	add_test("c-fat500-5.clq");		
	add_test("c-fat500-10.clq");
	
	add_test("dsjc250.5.clq");
	add_test("dsjc500.1.clq");				
	add_test("dsjc500.5.clq");	
//	add_test("dsjc500.9.clq");	
	add_test("dsjc1000.1.clq");	
	add_test("dsjc1000.5.clq");
//	add_test("dsjc1000.9.clq");  

	//the only bhoshlib
	add_test("frb30-15-1.clq");	
	add_test("frb30-15-2.clq");				
	add_test("frb30-15-3.clq");	
	add_test("frb30-15-4.clq");	
	add_test("frb30-15-5.clq");

	add_test("gen200_p0.9_44.clq");	
	add_test("gen200_p0.9_55.clq");				
	add_test("gen400_p0.9_55.clq");	
	add_test("gen400_p0.9_65.clq");	
	add_test("gen400_p0.9_75.clq");
	
	add_test("hamming6-2.clq");
	add_test("hamming6-4.clq");
	add_test("hamming8-2.clq");	
	add_test("hamming8-4.clq");	
	add_test("hamming10-2.clq");
	//add_test("hamming10-4.clq");	

	add_test("johnson8-2-4.clq");	
	add_test("johnson8-4-4.clq");		
	add_test("johnson16-2-4.clq");
	//add_test("johnson32-2-4.clq");

	add_test("keller4.clq");	
	add_test("keller5.clq");
	//add_test("keller6.clq");

	add_test("MANN_a9.clq");				
	add_test("MANN_a27.clq");				
	add_test("MANN_a45.clq");
	//add_test("MANN_a81.clq");			

	add_test("p_hat300-1.clq");				
	add_test("p_hat300-2.clq");				
	add_test("p_hat300-3.clq");				
	add_test("p_hat500-1.clq");				
	add_test("p_hat500-2.clq");				
	add_test("p_hat500-3.clq");				
	add_test("p_hat700-1.clq");				
	add_test("p_hat700-2.clq");				
	add_test("p_hat700-3.clq");				
	add_test("p_hat1000-1.clq");				
	add_test("p_hat1000-2.clq");			
	add_test("p_hat1000-3.clq");				
	add_test("p_hat1500-1.clq");				
	add_test("p_hat1500-2.clq");				
	//	add_test("p_hat1500-3.clq");	

	add_test("san200_0.7_1.clq");				
	add_test("san200_0.7_2.clq");				
	add_test("san200_0.9_1.clq");				
	add_test("san200_0.9_2.clq");			
	add_test("san200_0.9_3.clq");			
	add_test("san400_0.5_1.clq");			
	add_test("san400_0.7_1.clq");			
	add_test("san400_0.7_2.clq");			
	add_test("san400_0.7_3.clq");			
	add_test("san400_0.9_1.clq");	

	add_test("san1000.clq");	

	add_test("sanr200_0.7.clq");			
	add_test("sanr200_0.9.clq");				
	add_test("sanr400_0.5.clq");				
	add_test("sanr400_0.7.clq");
}


void BkClique::SubsetEasyDimacs(){
//////////////////	
//last configuration: Review Infra-chromatic I COR (11/11/2014)


	add_test("brock200_1.clq");
	add_test("brock200_2.clq");
	add_test("brock200_3.clq");		
	add_test("brock200_4.clq");	
	
	add_test("brock400_2.clq");
	add_test("brock400_4.clq");

	add_test("C125.9.clq");	
	

	/*add_test("c-fat200-1.clq");				
	add_test("c-fat200-2.clq");			
	add_test("c-fat200-5.clq");			
	add_test("c-fat500-1.clq");			
	add_test("c-fat500-2.clq");			 	
	add_test("c-fat500-5.clq");		
	add_test("c-fat500-10.clq");*/	

	add_test("dsjc250.5.clq");				
	add_test("dsjc500.1.clq");				
	add_test("dsjc500.5.clq");	
	add_test("dsjc1000.1.clq");	
	add_test("dsjc1000.5.clq");	

	add_test("gen200_p0.9_44.clq");	
	add_test("gen200_p0.9_55.clq");			
	

	add_test("hamming6-2.clq");				
	add_test("hamming6-4.clq");					
	add_test("hamming8-2.clq");		
	add_test("hamming8-4.clq");			      
	//add_test("hamming10-2.clq");					
  

	add_test("johnson8-2-4.clq");		
	add_test("johnson8-4-4.clq");		
	add_test("johnson16-2-4.clq");
	
	add_test("keller4.clq");				
	

	add_test("MANN_a9.clq");				
	add_test("MANN_a27.clq");				
	/*add_test("MANN_a45.clq");*/	

	
	add_test("p_hat300-1.clq");				
	add_test("p_hat300-2.clq");				
	add_test("p_hat300-3.clq");				
	add_test("p_hat500-1.clq");				
	add_test("p_hat500-2.clq");				
	add_test("p_hat500-3.clq");				
	add_test("p_hat700-1.clq");				
	add_test("p_hat700-2.clq");				
	add_test("p_hat1000-1.clq");				
	add_test("p_hat1000-2.clq");			
	add_test("p_hat1500-1.clq");				
	
	add_test("san200_0.7_1.clq");				
	add_test("san200_0.7_2.clq");				
/*	add_test("san200_0.9_1.clq");				
	add_test("san200_0.9_2.clq");			
	add_test("san200_0.9_3.clq");*/			
	add_test("san400_0.5_1.clq");			
	add_test("san400_0.7_1.clq");			
	add_test("san400_0.7_2.clq");			
	add_test("san400_0.7_3.clq");			
	/*add_test("san400_0.9_1.clq");	*/		
	
	add_test("san1000.clq");	

	add_test("sanr200_0.7.clq");			
	add_test("sanr200_0.9.clq");				
	add_test("sanr400_0.5.clq");				
	add_test("sanr400_0.7.clq");
}

void BkClique::ExpectedSubSecondDimacs(){
/////////////
// For robust time measures (n-repetitions)

	add_test("brock200_1.clq");
	add_test("brock200_2.clq");
	add_test("brock200_3.clq");		
	add_test("brock200_4.clq");
	
	add_test("C125.9.clq");	

	add_test("dsjc500.1.clq");				
	add_test("dsjc500.5.clq");	
	add_test("dsjc1000.1.clq");	
	
	add_test("gen200_p0.9_44.clq");	
	add_test("gen200_p0.9_55.clq");			
	
	add_test("hamming8-2.clq");		
	add_test("hamming8-4.clq");			      
	add_test("hamming10-2.clq");	

	add_test("johnson8-2-4.clq");		
	add_test("johnson8-4-4.clq");		
	add_test("johnson16-2-4.clq");

	add_test("keller4.clq");	

	add_test("MANN_a9.clq");				
	add_test("MANN_a27.clq");
	
	add_test("p_hat300-1.clq");				
	add_test("p_hat300-2.clq");				
	add_test("p_hat300-3.clq");				
	add_test("p_hat500-1.clq");				
	add_test("p_hat500-2.clq");	
	add_test("p_hat700-1.clq");			
	add_test("p_hat1000-1.clq");
		
	add_test("san200_0.7_1.clq");				
	add_test("san200_0.7_2.clq");				
	add_test("san200_0.9_1.clq");				
	add_test("san200_0.9_2.clq");			
	add_test("san200_0.9_3.clq");			
	add_test("san400_0.5_1.clq");			
	add_test("san400_0.7_1.clq");			
	add_test("san400_0.7_2.clq");			
	add_test("san400_0.7_3.clq");			
	add_test("san400_0.9_1.clq");	

	add_test("san1000.clq");

	add_test("sanr200_0.7.clq");			
	add_test("sanr400_0.5.clq");	
}

void BkClique::SubsetHardDimacs(){
////////////////
//Complements SubsetEasyDimacs()

	add_test("brock400_1.clq");			
	add_test("brock400_3.clq");
	add_test("brock800_1.clq");			
	add_test("brock800_2.clq");				
	add_test("brock800_3.clq");				
	add_test("brock800_4.clq");

	add_test("C250.9.clq");				
	/*add_test("C500.9.clq");	
	add_test("C1000.9.clq");	
	add_test("C2000.5.clq");	*/
		
	add_test("dsjc500.9.clq");					//*** normally remove	
	//add_test("dsjc1000.9.clq");

	add_test("frb30-15-1.clq");	
	add_test("frb30-15-2.clq");				
	add_test("frb30-15-3.clq");	
	add_test("frb30-15-4.clq");	
	add_test("frb30-15-5.clq");

	add_test("gen400_p0.9_55.clq");	
	add_test("gen400_p0.9_65.clq");	
	add_test("gen400_p0.9_75.clq");	
		
	//add_test("hamming10-4.clq");	

	//add_test("johnson32-2-4.clq");

	add_test("keller5.clq");				
	//add_test("keller6.clq");	
		
	//add_test("MANN_a81.clq");	

	add_test("p_hat700-3.clq");				
	add_test("p_hat1000-3.clq");				//*** normally remove	
	add_test("p_hat1500-2.clq");				
	add_test("p_hat1500-3.clq");				//*** normally remove
}

void BkClique::SubsetBhoshlib(){

	add_test("frb30-15-1.clq");	
	add_test("frb30-15-2.clq");				
	add_test("frb30-15-3.clq");	
	add_test("frb30-15-4.clq");	
	add_test("frb30-15-5.clq");

	add_test("frb35-17-1.clq");	
	add_test("frb35-17-2.clq");				
	add_test("frb35-17-3.clq");	
	add_test("frb35-17-4.clq");	
	add_test("frb35-17-5.clq");

	add_test("frb40-19-1.clq");	
	add_test("frb40-19-2.clq");				
	add_test("frb40-19-3.clq");	
	add_test("frb40-19-4.clq");	
	add_test("frb40-19-5.clq");

	add_test("frb45-21-1.clq");	
	add_test("frb45-21-2.clq");				
	add_test("frb45-21-3.clq");	
	add_test("frb45-21-4.clq");	
	add_test("frb45-21-5.clq");

	//***
}

void BkClique::Snap(){
//////////////////////////
//Dimacs format

	//snap
	add_test("0.edges");				
	add_test("1.edges");	
	add_test("2.edges");	
	add_test("3.edges");	
	add_test("4.edges");	
	add_test("5.edges");	
	add_test("6.edges");	
	add_test("7.edges");	
	add_test("8.edges");	
	add_test("9.edges");

	add_test("CA-AstroPh.txt");
	add_test("CA-CondMat.txt");


	add_test("cEmail-Enron.txt");
	add_test("com-amazon.ungraph.txt");
	add_test("com-dblp.ungraph.txt");
	add_test("com-youtube.ungraph.txt");


	add_test("oregon1_010331.txt");				
	add_test("oregon1_010407.txt");	
	add_test("oregon1_010414.txt");	
	add_test("oregon1_010421.txt");
	add_test("oregon1_010428.txt");
	add_test("oregon1_010505.txt");
	add_test("oregon1_010512.txt");
	add_test("oregon1_010519.txt");
	add_test("oregon1_010526.txt");

	//pajek
		//add_test("out.petster-carnivore");	
	add_test("out.petster-friendships-cat");	
	add_test("out.petster-friendships-dog");


	add_test("roadNet-CA.txt");	
	add_test("roadNet-PA.txt");
	add_test("roadNet-TX.txt");


	//***
}

void BkClique::Others(){
//For ad hoc tests

	//  add_test("keller5.clq"); 
	add_test("p_hat1000-3.clq");

	/*add_test("brock400_2.clq");		
	add_test("brock400_4.clq");	
	add_test("brock800_1.clq");			
	add_test("brock800_2.clq");	*/			
	/*add_test("brock800_3.clq");				
	add_test("brock800_4.clq");
	add_test("dsjc250.5.clq");
	add_test("p_hat1000-3.clq");*/
	/*add_test("C500.9.clq");
	add_test("dsjc500.9.clq");	
	add_test("p_hat1500-3.clq");*/
	return;

	add_test("C125.9.clq");
	add_test("c-fat500-5.clq");
	add_test("dsjc1000.5.clq");
	add_test("dsjc500.5.clq");
	add_test("hamming8-4.clq");
	add_test("johnson8-2-4.clq");
	add_test("san400_0.5_1.clq");
	add_test("sanr200_0.7.clq");
	add_test("sanr400_0.5.clq");
}

void BkClique::Real50(){
//////////////////
// 42 real graphs up from 3000 up to 50000 vertices

	add_test("bio-dmela.mtx");
	add_test("cit-HepTh2007_u.edges");
	add_test("cora_subelj_u.edges");
	add_test("cs4.mtx");
	add_test("cti.mtx");
	add_test("delaunay_n12.mtx");
	add_test("delaunay_n13.mtx");
	add_test("delaunay_n14.mtx");
	add_test("delaunay_n15.mtx");
	add_test("fe-4elt2.mtx");
	add_test("fe-body.mtx");
	add_test("fe-sphere.mtx");
	add_test("wing_nodal.mtx");
	add_test("ia-reality.mtx");
	add_test("misc-jung-code-dep_u.edges");
	add_test("ia-email-EU.mtx");
	add_test("ia-enron-large.mtx");
	add_test("soc-anybeat_u.edges");
	add_test("soc-epinions.mtx");
	add_test("socfb-Berkeley13.mtx");
	add_test("socfb-CMU.mtx");
	add_test("socfb-Duke14.mtx");
	add_test("socfb-Indiana.mtx");
	add_test("socfb-UIllinois.mtx");
	add_test("socfb-MIT.mtx");
	add_test("soc-gplus_u.edges");
	add_test("socfb-Penn94.mtx");
	add_test("socfb-Stanford3.mtx");
	add_test("socfb-Texas84.mtx");
	add_test("socfb-UCLA.mtx");
	add_test("socfb-UF.mtx");
	add_test("socfb-UConn.mtx");
	add_test("socfb-UCSB37.mtx");
	add_test("socfb-Wisconsin87.mtx");
	add_test("tech-as-caida2007.mtx");
	add_test("tech-internet-as.mtx");
	add_test("tech-pgp_u.edges");
	add_test("tech-WHOIS.mtx");
	add_test("web-EPA_u.edges");
	add_test("scc_retweet.mtx");
	add_test("scc_twitter-copen.mtx");
	add_test("web-spam.mtx");

}

void BkClique::Real50_100(){
//////////////////
// 19 real graphs from 50,000 up to 100,000 vertices

	add_test("fe_rotor.mtx");
	add_test("fe-tooth.mtx");
	add_test("wing.mtx");
	add_test("t60k.mtx");
	add_test("delaunay_n16.mtx");
	add_test("rec-eachmovie_u.edges");
	add_test("ia-wiki-Talk.mtx");
	add_test("sc-nasasrb.mtx");
	add_test("sc-pkustk11.mtx");
	add_test("sc-pkustk13.mtx");
	add_test("soc-BlogCatalog.mtx");
	add_test("soc-brightkite.mtx");
	add_test("soc-slashdot.mtx");
	add_test("socfb-OR.mtx");
	add_test("soc-loc-brightkite_u.edges");
	add_test("soc-Slashdot0811_u.edges");
	add_test("soc-Slashdot0902_u.edges");
	add_test("soc-themarker_u.edges");
	add_test("tech-p2p-gnutella.mtx");
}

void BkClique::Real101_300(){
//////////////////
//26 real graphs from 100,001 up to 300,000 vertices

	add_test("144.mtx");
	add_test("598a.mtx");
	add_test("aff-github-user2project_u.edges");
	add_test("citationCiteseer.mtx");
	add_test("delaunay_n17.mtx");
	add_test("delaunay_n18.mtx");
	add_test("fe-ocean.mtx");
	add_test("ia-email-EU-dir_u.edges");
	add_test("m14b.mtx");
	add_test("rec-dating_u.edges");
	add_test("rec-github_u.edges");
	add_test("rec-libimseti-dir_noweights_u.edges");
	add_test("rec-yelp-user-business_u.edges");
	add_test("sc-pwtk.mtx");
	add_test("sc-shipsec1.mtx");
	add_test("sc-shipsec5.mtx");
	add_test("soc-academia_u.edges");
	add_test("soc-buzznet.mtx");
	add_test("soc-catster_u.edges");
	add_test("soc-douban.mtx");
	add_test("soc-gowalla.mtx");
	add_test("soc-LiveMocha.mtx");
	add_test("soc-google-plus_u.edges");
	add_test("tech-caidaRouterLevel.mtx");
	add_test("tech-RL-caida.mtx");
	add_test("web-Stanford_u.edges");
}

void BkClique::Real301_700(){
//////////////////
// 16 real graphs from 300,001 up to 700,000 vertices

	add_test("aff-dbpedia-users2country_u.edges");
	add_test("aff-flickr-user-groups_u.edges");
	add_test("auto.mtx");
	add_test("delaunay_n19.mtx");
	add_test("ia-dbpedia-team-bi_u.edges");
	add_test("rt-higgs_u.edges");
	add_test("sc-msdoor.mtx");
	add_test("soc-delicious.mtx");
	add_test("soc-dogster_u.edges");
	add_test("soc-youtube.mtx");
	add_test("soc-flickr.mtx");
	add_test("soc-FourSquare.mtx");
	add_test("soc-twitter-follows.mtx");
	add_test("soc-twitter-follows-mun_u.edges");
	add_test("web-baidu-baike-related_u.edges");
	add_test("web-BerkStan-dir_u.edges");
}

void BkClique::RealLargeEnum(int d){
/////////////
// Real graphs (category LARGE) for enumeration tests based on degeneracy number
// date of creation: 1/1/15
// motivation: tests with enumeration algorithms
// categories: d<=10, 11<=d<=20, 21<=d<=30, 31<=d<=40, 41<=d<=50, d>=51

	if(d<=10){
		add_test("aff-dbpedia-users2country_u.edges");
		add_test("aff-wiki-en-article-cat_u.edges");
		add_test("bio-MUTAG_g1_u.edges");
		add_test("cora_subelj_u.edges");
		add_test("fs-adjnoun_adj_copperfield_u.edges");
		add_test("ia-dbpedia-team-bi_u.edges");
		add_test("ia-reality.mtx");
		add_test("ia-southernwomen_u.edges");
		add_test("rt-twitter-copen.mtx");
		
		add_test("144.mtx");
		add_test("598a.mtx");
		add_test("auto.mtx");
		add_test("bio-celegans-dir_u.edges");
		add_test("chesapeake.mtx");
		add_test("cs4.mtx");
		add_test("cti.mtx");
		add_test("delaunay_n10.mtx");
		add_test("delaunay_n11.mtx");
		add_test("delaunay_n12.mtx");
		add_test("delaunay_n13.mtx");
		add_test("delaunay_n14.mtx");
		add_test("delaunay_n15.mtx");
		add_test("delaunay_n16.mtx");
		add_test("delaunay_n17.mtx");
		add_test("delaunay_n18.mtx");
		add_test("delaunay_n19.mtx");
		add_test("delaunay_n20.mtx");
		add_test("delaunay_n21.mtx");
		add_test("delaunay_n22.mtx");
		add_test("delaunay_n23.mtx");
		add_test("fe_rotor.mtx");
		add_test("fe-tooth.mtx");
		add_test("fe-4elt2.mtx");
		add_test("fe-body.mtx");
		add_test("fe-ocean.mtx");
		add_test("fe_rotor.mtx");
	//	add_test("fe-sphere.mtx");					//not working with kcore_UB
		add_test("t60k.mtx");
		add_test("ia-enron-only.mtx");
		add_test("packing-500x100x100-b050.mtx");
		add_test("inf-belgium_osm.mtx");
		add_test("inf-netherlands_osm.mtx");
		add_test("m14b.mtx");
		add_test("soc-wiki-Vote.mtx");
		add_test("tech-p2p-gnutella.mtx");
	}else if(d<=20){
		add_test("rt-higgs_u.edges");
		add_test("soc-gplus_u.edges");

		add_test("bio-dmela.mtx");
		add_test("citationCiteseer.mtx");
		add_test("ia-fb-messages.mtx");
		add_test("ia-infect-dublin.mtx");
		add_test("rgg_n_2_20_s0.mtx");
		add_test("rt-retweet-crawl.mtx");
		add_test("soc-douban.mtx");
	}else if(d<=30){
		add_test("ca-IMDB_u.edges");
		add_test("ia-email-EU.mtx");
		add_test("inf-openflights_u.edges");
		add_test("misc-IMDB-bi_u.edges");
		add_test("rec-yelp-user-business_u.edges");
		add_test("soc-academia_u.edges");


		add_test("ia-infect-hyper.mtx");
		add_test("ia-email-EU-dir_u.edges");
		add_test("sc-shipsec1.mtx");
		add_test("sc-shipsec5.mtx");
		add_test("soc-twitter-follows.mtx");
		add_test("tech-as-caida2007.mtx");
		add_test("tech-internet-as.mtx");
	}else if(d<=50){
		add_test("aff-github-user2project_u.edges");
		add_test("cit-HepTh2007_u.edges");
		add_test("rec-github_u.edges");
		add_test("soc-anybeat_u.edges");
		add_test("soc-twitter-follows-mun_u.edges");
		add_test("tech-pgp_u.edges");


		add_test("ia-enron-large.mtx");
		add_test("sc-ldoor.mtx");
		add_test("sc-msdoor.mtx");
		add_test("sc-nasasrb.mtx");
		add_test("sc-pkustk11.mtx");
		add_test("sc-pkustk13.mtx");
		add_test("sc-pwtk.mtx");
		add_test("soc-delicious.mtx");
		add_test("soc-pokec.mtx");
		add_test("soc-epinions.mtx");
		add_test("soc-youtube.mtx");
		add_test("tech-caidaRouterLevel.mtx");
		add_test("tech-RL-caida.mtx");
	}else{
	//	add_test("aff-digg_u.edges");
		add_test("aff-flickr-user-groups_u.edges");
		add_test("ia-wiki-Talk.mtx");
		add_test("ia-wiki-Talk-dir_add_one_u.edges");
		add_test("misc-jung-code-dep_u.edges");
		add_test("rec-dating_u.edges");
		add_test("rec-eachmovie_u.edges");
		add_test("rec-epinions_u.edges");
		add_test("rec-libimseti-dir_noweights_u.edges");
		add_test("scc_fb-forum.mtx");
		add_test("scc_retweet.mtx");
		add_test("scc_twitter-copen.mtx");
	//	add_test("soc-BlogCatalog.mtx");
		add_test("soc-brightkite.mtx");
		add_test("soc-buzznet.mtx");
	//	add_test("soc-catster_u.edges");
	//	add_test("soc-digg.mtx");
	//	add_test("soc-dogster_u.edges");
		add_test("socfb-B-anon.mtx");
		add_test("socfb-Berkeley13.mtx");
		add_test("socfb-CMU.mtx");
		add_test("socfb-Duke14.mtx");
		add_test("socfb-Indiana.mtx");
		add_test("socfb-MIT.mtx");
		add_test("socfb-OR.mtx");
		add_test("socfb-Penn94.mtx");
		add_test("socfb-Stanford3.mtx");
		add_test("socfb-Texas84.mtx");
		add_test("socfb-UCLA.mtx");
		add_test("socfb-UConn.mtx");
		add_test("socfb-UCSB37.mtx");
		add_test("socfb-UF.mtx");
		add_test("socfb-UIllinois.mtx");
		add_test("socfb-Wisconsin87.mtx");
	//	add_test("soc-flickr.mtx");
	//	add_test("soc-flickr-und_u.edges");
		add_test("soc-flixster.mtx");
		add_test("soc-FourSquare.mtx");
		add_test("soc-google-plus_u.edges");
		add_test("soc-gowalla.mtx");
		add_test("soc-lastfm.mtx");
		add_test("soc-LiveMocha.mtx");
		add_test("soc-loc-brightkite_u.edges");
		add_test("soc-slashdot.mtx");
		add_test("soc-Slashdot0811_u.edges");
		add_test("soc-Slashdot0902_u.edges");
		add_test("soc-themarker_u.edges");
		add_test("soc-wiki-Talk-dir_u.edges");
		add_test("soc-youtube-snap.mtx");
		add_test("tech-as-skitter.mtx");
		add_test("tech-ip_u.edges");
		add_test("tech-WHOIS.mtx");

	}
}


void BkClique::Real_GOMS(){
////////////////
// subset of instances chosen in the
// report in GOMS paper on BBMCW

	add_test("rec-eachmovie_u.edges");
	add_test("soc-BlogCatalog.mtx");
	add_test("socfb-Berkeley13.mtx");
	add_test("socfb-Indiana.mtx");
	add_test("socfb-UF.mtx");
	add_test("socfb-UIllinois.mtx");
	add_test("socfb-Penn94.mtx");
	add_test("socfb-Texas84.mtx");
	add_test("socfb-UCLA.mtx");
	add_test("soc-themarker_u.edges");
	add_test("socfb-Wisconsin87.mtx");

}

void BkClique::RealLargeHardEnum(){
	//	add_test("aff-digg_u.edges");
		add_test("aff-flickr-user-groups_u.edges");
		add_test("ia-wiki-Talk-dir_add_one_u.edges");
		add_test("rec-dating_u.edges");
		add_test("rec-eachmovie_u.edges");
		add_test("rec-epinions_u.edges");
		add_test("rec-libimseti-dir_noweights_u.edges");
	//	add_test("scc_fb-forum.mtx");				//w=266 but not difficult
		add_test("scc_retweet.mtx");
	//	add_test("scc_twitter-copen.mtx");			//w=581 but not difficult
	//	add_test("soc-BlogCatalog.mtx");
		add_test("soc-brightkite.mtx");
		add_test("soc-buzznet.mtx");
	//	add_test("soc-catster_u.edges");
	//	add_test("soc-digg.mtx");
	//	add_test("soc-dogster_u.edges");
		add_test("socfb-B-anon.mtx");
		add_test("socfb-Berkeley13.mtx");
		add_test("socfb-CMU.mtx");
		add_test("socfb-Duke14.mtx");
		add_test("socfb-Indiana.mtx");
		add_test("socfb-MIT.mtx");
		add_test("socfb-OR.mtx");
		add_test("socfb-Penn94.mtx");
		add_test("socfb-Stanford3.mtx");
		add_test("socfb-Texas84.mtx");
		add_test("socfb-UCLA.mtx");
		add_test("socfb-UConn.mtx");
		add_test("socfb-UCSB37.mtx");
		add_test("socfb-UF.mtx");
		add_test("socfb-UIllinois.mtx");
		add_test("socfb-Wisconsin87.mtx");
	//	add_test("soc-flickr.mtx");
	//	add_test("soc-flickr-und_u.edges");
		add_test("soc-flixster.mtx");
		add_test("soc-FourSquare.mtx");
		add_test("soc-google-plus_u.edges");
		add_test("soc-gowalla.mtx");
		add_test("soc-lastfm.mtx");
		add_test("soc-LiveMocha.mtx");
		add_test("soc-loc-brightkite_u.edges");
		add_test("soc-slashdot.mtx");
		add_test("soc-Slashdot0811_u.edges");
		add_test("soc-Slashdot0902_u.edges");
		add_test("soc-themarker_u.edges");
		add_test("soc-wiki-Talk-dir_u.edges");
		add_test("soc-youtube-snap.mtx");
		add_test("tech-as-skitter.mtx");
		add_test("tech-ip_u.edges");
		add_test("tech-WHOIS.mtx");
}

void BkClique::RealLargeExtremelyHardEnum(){
	add_test("aff-flickr-user-groups_u.edges");
	add_test("aff-wiki-en-article-cat_u.edges");
	add_test("cit-HepTh2007_u.edges");
	add_test("ia-email-EU-dir_u.edges");
	add_test("ia-enron-large.mtx");
	add_test("ia-wiki-Talk-dir_add_one_u.edges");
	add_test("rec-dating_u.edges");
	add_test("rec-epinions_u.edges");
	add_test("rec-libimseti-dir_noweights_u.edges");
	add_test("soc-buzznet.mtx");
	add_test("soc-LiveMocha.mtx");
	add_test("soc-themarker_u.edges");
}

void BkClique::RealTrivialEnum(int d){
/////////////
// Real graphs (category TRIVIAL --for our max clique alg--) for enumeration tests based on degeneracy number
// date of creation: 1/1/15
// motivation: tests with enumeration algorithms
// categories: d<=10, 11<=d<=20, 21<=d<=30, 31<=d<=40, 41<=d<=50, d>=51

	if(d<=10){
		add_test("aff-amazon-copurchases_u.edges");
		add_test("bio-diseasome.mtx");
		add_test("bio-yeast.mtx");
		add_test("bio-yeast-protein-inter_u.edges");
		add_test("ca-CSphd_u.edges");
		add_test("ca-Erdos992.mtx");
		add_test("inf-asia_osm.mtx");
		add_test("inf-europe_osm.mtx");
		add_test("inf-euroroad.edges");
		add_test("inf-luxembourg_osm.mtx");
		add_test("inf-power.mtx");
		add_test("inf-road_central.mtx");
		add_test("inf-roadNet-CA.mtx");
		add_test("inf-roadNet-PA.mtx");
		add_test("inf-roadNet-TX.mtx");
		add_test("inf-road-usa.mtx");
		add_test("rec-amazon.mtx");
		add_test("rt-retweet.mtx");
		add_test("scc_rt_assad.mtx");
		add_test("scc_rt_bahrain.mtx");
		add_test("scc_rt_barackobama.mtx");
		add_test("scc_rt_damascus.mtx");
		add_test("scc_rt_dash.mtx");
		add_test("scc_rt_gop.mtx");
		add_test("scc_rt_http.mtx");
		add_test("scc_rt_israel.mtx");
		add_test("scc_rt_mittromney.mtx");
		add_test("scc_rt_obama.mtx");
		add_test("scc_rt_occupy.mtx");
		add_test("scc_rt_oman.mtx");
		add_test("scc_rt_p2.mtx");
		add_test("scc_rt_qatif.mtx");
		add_test("scc_rt_saudi.mtx");
		add_test("scc_rt_tcot.mtx");
		add_test("scc_rt_uae.mtx");
		add_test("scc_rt_voteonedirection.mtx");
		add_test("soc-dolphins.mtx");
		add_test("socfb-nips-ego.edges");
		add_test("soc-karate.mtx");
		add_test("scc_rt_ksa.mtx");
		add_test("scc_rt_lebanon.mtx");
		add_test("scc_rt_libya.mtx");
	}else if(d<=20){
		add_test("ia-email-univ.mtx");
		add_test("rgg_n_2_15_s0.mtx");
		add_test("rgg_n_2_16_s0.mtx");
		add_test("rgg_n_2_17_s0.mtx");
		add_test("rgg_n_2_18_s0.mtx");
		add_test("rgg_n_2_19_s0.mtx");
		add_test("rgg_n_2_21_s0.mtx");
		add_test("rgg_n_2_22_s0.mtx");
		add_test("rgg_n_2_23_s0.mtx");
		add_test("scc_retweet-crawl.mtx");
		add_test("scc_rt_alwefaq.mtx");
		add_test("scc_rt_justinbieber.mtx");
		add_test("scc_rt_occupywallstnyc.mtx");
		add_test("tech-routers-rf.mtx");
		add_test("web-google.mtx");
	}else if(d<=30){
		add_test("ca-CondMat.mtx");
		add_test("ca-MathSciNet.mtx");
		add_test("scc_rt_gmanews.mtx");
		add_test("soc-hamsterster.edges");
		add_test("web-BerkStan.mtx");
		add_test("web-edu.mtx");
	}else if(d<=50){
		add_test("ca-GrQc.mtx");
		add_test("scc_rt_lolgop.mtx");
		add_test("web-indochina-2004.mtx");
	}else{
		add_test("ca-AstroPh.mtx");	
		add_test("ca-citeseer.mtx");
		//add_test("ca-cit-HepTh_noweights.edges");
		add_test("ca-coauthors-dblp.mtx");
		add_test("ca-dblp-2010.mtx");
		add_test("ca-dblp-2012.mtx");
		add_test("ca-HepPh.mtx");
		//add_test("ca-hollywood-2009.mtx");
		add_test("coAuthorsCiteseer.mtx");
		add_test("co-papers-citeseer.mtx");
		add_test("co-papers-dblp.mtx");
		add_test("scc_enron-only.mtx");
		add_test("scc_fb-messages.mtx");
		add_test("scc_infect-dublin.mtx");
		add_test("scc_infect-hyper.mtx");
		add_test("scc_reality.mtx");
		add_test("soc-livejournal.mtx");
		add_test("web-arabic-2005.mtx");
		add_test("web-hudong_u.edges");
		add_test("web-it-2004.mtx");
		add_test("web-italycnr-2000_u.edges");
		add_test("web-sk-2005.mtx");
		//add_test("web-sk-2005-all_u.edges");
		//add_test("web-sk-2002-all_u.edges");
		add_test("web-uk-2005.mtx");
		//add_test("web-uk-2005-all_u.edges");
		add_test("web-webbase-2001.mtx");
		//add_test("web-webbase-2001-all_u.edges");
	}
}

void BkClique::RealDimacsEnum(){
////////////////////
// Small set of DIMACS graphs for enumeration
	
	add_test("brock200_1.clq");
	add_test("brock200_2.clq");
	add_test("brock200_3.clq");
	add_test("brock200_4.clq");

	add_test("c-fat200-5.clq");
	add_test("c-fat500-10.clq");

	add_test("dsjc500.1.clq");
	add_test("dsjc1000.1.clq");	

	add_test("hamming6-2.clq");
	add_test("hamming6-4.clq");

	add_test("johnson8-4-4.clq");
	add_test("johnson16-2-4.clq");

	add_test("keller4.clq");
	add_test("MANN_a9.clq");

	add_test("p_hat300-1.clq");
	add_test("p_hat300-2.clq");

	//recently added instances
	add_test("p_hat500-1.clq");
	add_test("p_hat700-1.clq");
	add_test("p_hat1000-1.clq");
	add_test("p_hat1500-1.clq");
		
	add_test("sanr400_0.5.clq");	
	add_test("san400_0.5_1.clq");	

//intractable under 7200s
// add_test("frb30-15-1.clq");	
//	add_test("san1000.clq");	
}

void BkClique::vcp(){
////////////////
// instances taken from the vertex coloring problems. The original instance is modified so that an independent set in the new graph
// maps to any feasible coloring (non-edges are nodes etc.) The concrete instance (dim) is the complement graph of this one
// The graphs are very hard to solve since the problem is equivalent to solving the VCP in the original graph
	
	
	//add_test("1-FullIns_4.col.dimacs.dim");
	//add_test("1-FullIns_5.col.dimacs.dim");
/*	add_test("2-FullIns_3.col.dimacs.dim");
	//add_test("2-FullIns_4.col.dimacs.dim");
	add_test("3-FullIns_3.col.dimacs.dim");
	add_test("4-FullIns_3.col.dimacs.dim");*/
	//add_test("5-FullIns_3.col.dimacs.dim");
	
	/*add_test("1-Insertions_4.col.dimacs.dim");
	add_test("1-Insertions_5.col.dimacs.dim");
	add_test("2-Insertions_4.col.dimacs.dim");
	add_test("4-Insertions_3.col.dimacs.dim");*/
		
	add_test("anna.col.dimacs.dim");
	add_test("david.col.dimacs.dim");
	add_test("huck.col.dimacs.dim");
	add_test("jean.col.dimacs.dim");
	
	/*add_test("DSJC125.1.col.dimacs.dim");
	add_test("DSJC125.5.col.dimacs.dim");*/
	add_test("DSJC125.9.col.dimacs.dim");
	//add_test("DSJC250.1.col.dimacs.dim");
	//add_test("DSJC250.5.col.dimacs.dim");
	add_test("DSJC250.9.col.dimacs.dim");
	//add_test("DSJC500.9.col.dimacs.dim");
	add_test("DSJR500.1c.col.dimacs.dim");

	add_test("games120.col.dimacs.dim");
		
	add_test("miles250.col.dimacs.dim");
	add_test("miles500.col.dimacs.dim");
	add_test("miles750.col.dimacs.dim");
	add_test("miles750.col.dimacs.dim");
	add_test("miles1000.col.dimacs.dim");
	add_test("miles1500.col.dimacs.dim");
		
	add_test("mug88_1.col.dimacs.dim");
	add_test("mug88_25.col.dimacs.dim");
	add_test("mug100_1.col.dimacs.dim");
	add_test("mug100_25.col.dimacs.dim");

	add_test("myciel3.col.dimacs.dim");
	add_test("myciel4.col.dimacs.dim");
	add_test("myciel5.col.dimacs.dim");
	add_test("myciel6.col.dimacs.dim");
	add_test("myciel7.col.dimacs.dim");

	add_test("mulsol.i.1.col.dimacs.dim");
	add_test("mulsol.i.2.col.dimacs.dim");
	add_test("mulsol.i.3.col.dimacs.dim");
	add_test("mulsol.i.4.col.dimacs.dim");
	add_test("mulsol.i.5.col.dimacs.dim");
		
	add_test("queen5_5.col.dimacs.dim");
	add_test("queen6_6.col.dimacs.dim");
	add_test("queen7_7.col.dimacs.dim");	
	add_test("queen8_8.col.dimacs.dim");	
	add_test("queen9_9.col.dimacs.dim");
	add_test("queen10_10.col.dimacs.dim");
	add_test("queen11_11.col.dimacs.dim");
	add_test("queen12_12.col.dimacs.dim");	
	add_test("queen13_13.col.dimacs.dim");	
	add_test("queen14_14.col.dimacs.dim");
	/*add_test("queen15_15.col.dimacs.dim");
	add_test("queen16_16.col.dimacs.dim");*/
	
	add_test("zeroin.i.1.col.dimacs.dim");
	add_test("zeroin.i.2.col.dimacs.dim");
	add_test("zeroin.i.3.col.dimacs.dim");
}

void BkCliqueILS::DimacsILS(){
///////////////////
// BHOSH and DIMACS main set of instances for test validation
// Includes initial clique info as provided by strong ILS heuristic on init (Iterative Local Search heur)
//
// Comments: Alphabetical order

	add_test("brock200_1.clq",21);
	add_test("brock200_2.clq",12);
	add_test("brock200_3.clq",15);		
	add_test("brock200_4.clq",17);	
	add_test("brock400_1.clq",25);			
	add_test("brock400_2.clq",25);
	add_test("brock400_3.clq",31);
	add_test("brock400_4.clq",33);
	add_test("brock800_1.clq",21);			
	add_test("brock800_2.clq",21);				
	add_test("brock800_3.clq",22);				
	add_test("brock800_4.clq",21);

	
	add_test("C125.9.clq",34);	
	add_test("C250.9.clq",44);				
	//add_test("C500.9.clq");	
	//	add_test("C1000.9.clq");	
	//	add_test("C2000.5.clq");

	add_test("dsjc500.1.clq",5);				
	add_test("dsjc500.5.clq",13);	
	add_test("dsjc500.9.clq",46);	
	add_test("dsjc1000.1.clq",6);	
	add_test("dsjc1000.5.clq",15);

	
	add_test("frb30-15-1.clq",30);	
	add_test("frb30-15-2.clq",30);				
	add_test("frb30-15-3.clq",30);	
	add_test("frb30-15-4.clq",30);	
	add_test("frb30-15-5.clq",30);

	
	add_test("gen200_p0.9_44.clq",44);	
	add_test("gen200_p0.9_55.clq",55);				
	add_test("gen400_p0.9_55.clq",55);	
	add_test("gen400_p0.9_65.clq",65);	
	add_test("gen400_p0.9_75.clq",75);

	add_test("hamming8-2.clq",128);	
	add_test("hamming8-4.clq",16);	
	add_test("hamming10-2.clq",512);
	//add_test("hamming10-4.clq");

	add_test("johnson8-2-4.clq",4);
	add_test("johnson8-4-4.clq",14);
	add_test("johnson16-2-4.clq",8);
	add_test("johnson32-2-4.clq",16);

	add_test("keller4.clq",11);	
	add_test("keller5.clq",27);
	//add_test("keller6.clq");
	
	add_test("MANN_a9.clq",16);				
	add_test("MANN_a27.clq",126);				
	add_test("MANN_a45.clq",344);
	//add_test("MANN_a81.clq",1100);	

	add_test("p_hat300-1.clq",8);				
	add_test("p_hat300-2.clq",25);				
	add_test("p_hat300-3.clq",36);				
	add_test("p_hat500-1.clq",9);				
	add_test("p_hat500-2.clq",36);				
	add_test("p_hat500-3.clq",50);				
	add_test("p_hat700-1.clq",11);				
	add_test("p_hat700-2.clq",44);				
	add_test("p_hat700-3.clq",62);				
	add_test("p_hat1000-1.clq",10);				
	add_test("p_hat1000-2.clq",46);			
	add_test("p_hat1000-3.clq",68);				
	add_test("p_hat1500-1.clq",12);				
	add_test("p_hat1500-2.clq",65);				
	//add_test("p_hat1500-3.clq",94);	
		
	add_test("san200_0.7_1.clq",30);				
	add_test("san200_0.7_2.clq",18);				
	add_test("san200_0.9_1.clq",70);				
	add_test("san200_0.9_2.clq",60);			
	add_test("san200_0.9_3.clq",44);			
	add_test("san400_0.5_1.clq",13);			
	add_test("san400_0.7_1.clq",40);			
	add_test("san400_0.7_2.clq",30);			
	add_test("san400_0.7_3.clq",22);			
	add_test("san400_0.9_1.clq",100);		

	add_test("san1000.clq",15);	

	add_test("sanr200_0.7.clq",18);			
	add_test("sanr200_0.9.clq",42);				
	add_test("sanr400_0.5.clq",13);				
	add_test("sanr400_0.7.clq",21);
}

void BkCliqueILS::SubsetHardDimacsILS(){
///////////////////
// BHOSH and DIMACS main set of instances for test validation
// Includes initial clique info as provided by strong ILS heuristic on init (Iterative Local Search heur)
//
// Comments: Alphabetical order

	add_test("brock400_1.clq",25);			
	add_test("brock400_3.clq",31);
	add_test("brock800_1.clq",21);			
	add_test("brock800_2.clq",21);				
	add_test("brock800_3.clq",22);				
	add_test("brock800_4.clq",21);

	add_test("C250.9.clq",44);				
	//	add_test("C1000.9.clq");	
	//	add_test("C2000.5.clq");

	add_test("dsjc500.9.clq",46);	
	//	add_test("dsjc1000.9.clq");

	add_test("frb30-15-1.clq",30);	
	add_test("frb30-15-2.clq",30);				
	add_test("frb30-15-3.clq",30);	
	add_test("frb30-15-4.clq",30);	
	add_test("frb30-15-5.clq",30);

	add_test("gen400_p0.9_55.clq",55);	
	add_test("gen400_p0.9_65.clq",65);	
	add_test("gen400_p0.9_75.clq",75);


	//add_test("hamming10-4.clq");

	add_test("johnson32-2-4.clq",16);
	
	add_test("keller5.clq",27);
	//add_test("keller6.clq");	
	
			
	//add_test("MANN_a81.clq",1100);			

	add_test("p_hat700-3.clq",62);	
	add_test("p_hat1000-3.clq",68);				
	add_test("p_hat1500-2.clq",65);				
	//add_test("p_hat1500-3.clq",94);	

}

void BkCliqueILS::GenILS(){
	
	add_test("gen200_p0.9_44.clq",44);	
	add_test("gen200_p0.9_55.clq",55);				
	add_test("gen400_p0.9_55.clq",55);	
	add_test("gen400_p0.9_65.clq",65);	
	add_test("gen400_p0.9_75.clq",75);
}

void BkCliqueILS::FrbILS(){
		
	add_test("frb30-15-1.clq",30);	
	add_test("frb30-15-2.clq",30);				
	add_test("frb30-15-3.clq",30);	
	add_test("frb30-15-4.clq",30);	
	add_test("frb30-15-5.clq",30);

}

void BkCliqueILS::KellerILS(){

	add_test("keller4.clq",11);	
	add_test("keller5.clq",27);

}

void BkCliqueILS::HammingILS(){

	add_test("hamming8-2.clq",128);	
	add_test("hamming8-4.clq",16);	
	add_test("hamming10-2.clq",512);
	add_test("hamming10-4.clq",40);

}

void BkCliqueILS::SubsetEasyDimacsILS(){
////////////////////
// A subset of ILS instances for fast tests

	add_test("brock200_1.clq",21);
	add_test("brock200_2.clq",12);
	add_test("brock200_3.clq",15);		
	add_test("brock200_4.clq",17);	
	add_test("brock400_2.clq",25);
	add_test("brock400_4.clq",33);

	add_test("C125.9.clq",34);	
	
	add_test("dsjc250.5.clq");
	add_test("dsjc500.1.clq",5);				
	add_test("dsjc500.5.clq",13);	
	add_test("dsjc1000.1.clq",6);	
	add_test("dsjc1000.5.clq",15);

	add_test("gen200_p0.9_44.clq",44);	
	add_test("gen200_p0.9_55.clq",55);		
	
	//add_test("hamming6-2.clq");				
	//add_test("hamming6-4.clq");					
	add_test("hamming8-2.clq",128);		
	add_test("hamming8-4.clq",16);			      
	add_test("hamming10-2.clq",512);
	

	add_test("johnson8-2-4.clq",4);	
	add_test("johnson8-4-4.clq",14);		
	add_test("johnson16-2-4.clq",8);
	
	add_test("keller4.clq",11);	
	
	add_test("MANN_a9.clq",16);				
	add_test("MANN_a27.clq",126);	
	add_test("MANN_a45.clq");	

	add_test("p_hat300-1.clq",8);				
	add_test("p_hat300-2.clq",25);				
	add_test("p_hat300-3.clq",36);				
	add_test("p_hat500-1.clq",9);				
	add_test("p_hat500-2.clq",36);				
	add_test("p_hat500-3.clq",50);				
	add_test("p_hat700-1.clq",11);				
	add_test("p_hat700-2.clq",44);				
	add_test("p_hat1000-1.clq",10);				
	add_test("p_hat1000-2.clq",46);			
	add_test("p_hat1500-1.clq",12);		
	
	add_test("san200_0.7_1.clq",30);				
	add_test("san200_0.7_2.clq",18);				
	add_test("san200_0.9_1.clq",70);				
	add_test("san200_0.9_2.clq",60);			
	add_test("san200_0.9_3.clq",44);			
	add_test("san400_0.5_1.clq",13);			
	add_test("san400_0.7_1.clq",40);			
	add_test("san400_0.7_2.clq",30);			
	add_test("san400_0.7_3.clq",22);			
	add_test("san400_0.9_1.clq",100);		
	
	add_test("san1000.clq",15);	
	
	add_test("sanr200_0.7.clq",18);			
	add_test("sanr200_0.9.clq",42);				
	add_test("sanr400_0.5.clq",13);				
	add_test("sanr400_0.7.clq",21);
	
}

void BkCliqueILS::OthersILS(){
	add_test("brock400_3.clq",31);
	add_test("brock400_4.clq",33);
	add_test("MANN_a45.clq",342);	
	add_test("san1000.clq",15);	
}

void BkClique::Castle(){
	//20 images, adds all pairs
	stringstream sstr("");
	for(int i=0; i<CASTLE-1; i++){
		for(int j=i+1; j<CASTLE; j++){
			sstr<<"grafo"<<"_"<<i<<"_"<<j<<".clq";
			add_test(sstr.str());	
			sstr.str("");
		}
	
	}
		
}

void BkCliqueILS::Castle_ILS(){
	//20 images,initial solution known
	add_test("grafo_3_10.clq",52);	
	add_test("grafo_5_7.clq",116);	
}

void BkCliqueILS::Castle_B_ILS(){
	//20 images,initial solution known
	add_test("grafo_4_6.clq",100);	
	add_test("grafo_5_8.clq",82);	
	add_test("grafo_15_17.clq",74);	
	add_test("grafo_15_18.clq",34);	
	add_test("grafo_16_18.clq",69);	
}

void BkClique::Fountain(){
	
	stringstream sstr("");
	for(int i=0; i<FOUNTAIN-1; i++){
		for(int j=i+1; j<FOUNTAIN; j++){
			sstr<<"grafo"<<"_"<<i<<"_"<<j<<".clq";
			add_test(sstr.str());	
			sstr.str("");
		}
		
	}
}

void BkClique::Dino(){
	
	stringstream sstr("");
	for(int i=0; i<DINO-1; i++){
		for(int j=i+1; j<DINO; j++){
			sstr<<"grafo"<<"_"<<i<<"_"<<j<<".clq";
			add_test(sstr.str());	
			sstr.str("");
		}
		
	}
}

void BkClique::Airview(){
	
	stringstream sstr("");
	for(int i=0; i<AIRVIEW-1; i++){
		for(int j=i+1; j<AIRVIEW; j++){
			sstr<<"grafo"<<"_"<<i<<"_"<<j<<".clq";
			add_test(sstr.str());
			sstr.str("");
		}
		
	}
}

void BkClique::Piedra(){
	
	stringstream sstr("");
	for(int i=0; i<PIEDRA-1; i++){
		for(int j=i+1; j<PIEDRA; j++){
			sstr<<"grafo"<<"_"<<i<<"_"<<j<<".clq";
			add_test(sstr.str());
			sstr.str("");
		}
		
	}
}

void BkClique::Kapel(){
	
	stringstream sstr("");
	for(int i=0; i<KAPEL-1; i++){
		for(int j=i+1; j<KAPEL; j++){
			sstr<<"grafo"<<"_"<<i<<"_"<<j<<".clq";
			add_test(sstr.str());
			sstr.str("");
		}
	}
}

void BkClique::Herzjesu(){
	
	stringstream sstr("");
	for(int i=10; i<HERZJESU-1; i++){
		for(int j=i+1; j<HERZJESU; j++){
			sstr<<"grafo"<<"_"<<i<<"_"<<j<<".clq";
			add_test(sstr.str());
			sstr.str("");
		}
	}
}

void BkCliqueILS::Herzjesu_big_ILS(){
//Using Tabu heuristic algorithm during 2-3s 
//over  match_big instances only

	//for match_big instances only
	//add_test("grafo_0_1.clq",755);		//max 760
	//add_test("grafo_0_2.clq",65 );		//max 117
	//add_test("grafo_1_2.clq",197);		//max 203
	//add_test("grafo_1_3.clq",95);		//max 108
	//add_test("grafo_2_3.clq",621);		//max 625
	//add_test("grafo_2_4.clq",110);		//max 148		
	//add_test("grafo_3_4.clq",643);		//max 644 
	//add_test("grafo_3_5.clq",120);		//max 140
	//add_test("grafo_4_5.clq",352);		//max 358?
	//add_test("grafo_4_6.clq",197);		
	//add_test("grafo_5_6.clq",872);	
	//add_test("grafo_5_7.clq",505);
	//add_test("grafo_6_7.clq",759);
	//add_test("grafo_6_8.clq",49);		//max 59
	add_test("grafo_7_8.clq",51);		//max 62
	add_test("grafo_7_9.clq",50);		//max 57?
	add_test("grafo_8_10.clq",3);		//???
	add_test("grafo_10_11.clq",1171);
	add_test("grafo_10_12.clq",146);
	add_test("grafo_11_12.clq",172);
	add_test("grafo_11_13.clq",79);
	add_test("grafo_12_13.clq",482);
	add_test("grafo_12_14.clq",275);
	add_test("grafo_13_14.clq",645);
	add_test("grafo_13_15.clq",342);
	add_test("grafo_14_15.clq",658);
	add_test("grafo_14_16.clq",84);
	add_test("grafo_15_16.clq",35);
	add_test("grafo_15_17.clq",60);
	add_test("grafo_16_17.clq",170);
	add_test("grafo_16_18.clq",127);
	add_test("grafo_17_18.clq",437);
	add_test("grafo_17_19.clq",114);
	add_test("grafo_18_19.clq",257);
	add_test("grafo_19_20.clq",110);
	add_test("grafo_19_21.clq",43);
	add_test("grafo_20_21.clq",155);
	add_test("grafo_20_22.clq",53);
	add_test("grafo_21_22.clq",144);

}

void BkCliqueILS::Fpv1_big_ILS(){
//Using Tabu heuristic algorithm during 2-3s 
//over match_big instances only

	add_test("grafo_0_1.clq",	1190);
	add_test("grafo_0_2.clq",	1134);
	add_test("grafo_1_2.clq",	1225	);
	add_test("grafo_1_3.clq",	1143	);
	add_test("grafo_10_11.clq",	1249	);
	add_test("grafo_10_12.clq",	1172	);
	add_test("grafo_100_101.clq",	1152	);
	add_test("grafo_100_102.clq",	1108	);
	add_test("grafo_101_102.clq",	1169	);
	add_test("grafo_101_103.clq",	1134	);
	add_test("grafo_102_103.clq",	1175	);
	add_test("grafo_102_104.clq",	1137	);
	add_test("grafo_103_104.clq",	1157	);
	add_test("grafo_103_105.clq",	1127	);
	add_test("grafo_104_105.clq",	1160	);
	add_test("grafo_104_106.clq",	1134	);
	add_test("grafo_105_106.clq",	1172	);
	add_test("grafo_105_107.clq",	1113	);
	add_test("grafo_106_107.clq",	1186	);
	add_test("grafo_11_12.clq",	1230	);
	add_test("grafo_11_13.clq",	1111	);
	add_test("grafo_12_13.clq",	1200	);
	add_test("grafo_12_14.clq",	1171	);
	add_test("grafo_13_14.clq",	1206	);
	add_test("grafo_13_15.clq",	1147	);
	add_test("grafo_14_15.clq",	1226	);
	add_test("grafo_14_16.clq",	1158	);
	add_test("grafo_15_16.clq",	1256	);
	add_test("grafo_15_17.clq",	1193	);
	add_test("grafo_16_17.clq",	1267	);
	add_test("grafo_16_18.clq",	1147	);
	add_test("grafo_17_18.clq",	1217	);
	add_test("grafo_17_19.clq",	1164	);
	add_test("grafo_18_19.clq",	1220	);
	add_test("grafo_18_20.clq",	1129	);
	add_test("grafo_19_20.clq",	1190	);
	add_test("grafo_19_21.clq",	1120	);
	add_test("grafo_2_3.clq",	1223	);
	add_test("grafo_2_4.clq",	1124	);
	add_test("grafo_20_21.clq",	1187	);
	add_test("grafo_20_22.clq",	1100	);
	add_test("grafo_21_22.clq",	1187	);
	add_test("grafo_21_23.clq",	1094	);
	add_test("grafo_22_23.clq",	1202	);
	add_test("grafo_22_24.clq",	1138	);
	add_test("grafo_23_24.clq",	1235	);
	add_test("grafo_23_25.clq",	1168	);
	add_test("grafo_24_25.clq",	1236	);
	add_test("grafo_24_26.clq",	1160	);
	add_test("grafo_25_26.clq",	1254	);
	add_test("grafo_25_27.clq",	1191	);
	add_test("grafo_26_27.clq",	1263	);
	add_test("grafo_26_28.clq",	1177	);
	add_test("grafo_27_28.clq",	1267	);
	add_test("grafo_27_29.clq",	1184	);
	add_test("grafo_28_29.clq",	1247	);
	add_test("grafo_28_30.clq",	1159	);
	add_test("grafo_29_30.clq",	1213	);
	add_test("grafo_29_31.clq",	1195	);
	add_test("grafo_3_4.clq",	1261	);
	add_test("grafo_3_5.clq",	1157	);
	add_test("grafo_30_31.clq",	1237	);
	add_test("grafo_30_32.clq",	1196	);
	add_test("grafo_31_32.clq",	1287	);
	add_test("grafo_31_33.clq",	1178	);
	add_test("grafo_32_33.clq",	1258	);
	add_test("grafo_32_34.clq",	1227	);
	add_test("grafo_33_34.clq",	1275	);
	add_test("grafo_33_35.clq",	1172	);
	add_test("grafo_34_35.clq",	1290	);
	add_test("grafo_34_36.clq",	1209	);
	add_test("grafo_35_36.clq",	1241	);
	add_test("grafo_35_37.clq",	1184	);
	add_test("grafo_36_37.clq",	1229	);
	add_test("grafo_36_38.clq",	1181	);
	add_test("grafo_37_38.clq",	1228	);
	add_test("grafo_37_39.clq",	1162	);
	add_test("grafo_38_39.clq",	1328	);
	add_test("grafo_38_40.clq",	1277	);
	add_test("grafo_39_40.clq",	1301	);
	add_test("grafo_39_41.clq",	1222	);
	add_test("grafo_4_5.clq",	1214	);
	add_test("grafo_4_6.clq",	1169	);
	add_test("grafo_40_41.clq",	1321	);
	add_test("grafo_40_42.clq",	1216	);
	add_test("grafo_41_42.clq",	1290	);
	add_test("grafo_41_43.clq",	1175	);
	add_test("grafo_42_43.clq",	1228	);
	add_test("grafo_42_44.clq",	1189	);
	add_test("grafo_43_44.clq",	1231	);
	add_test("grafo_43_45.clq",	1192	);
	add_test("grafo_44_45.clq",	1257	);
	add_test("grafo_44_46.clq",	1196	);
	add_test("grafo_45_46.clq",	1273	);
	add_test("grafo_45_47.clq",	1243	);
	add_test("grafo_46_47.clq",	1268	);
	add_test("grafo_46_48.clq",	1195	);
	add_test("grafo_47_48.clq",	1202	);
	add_test("grafo_47_49.clq",	1199	);
	add_test("grafo_48_49.clq",	1266	);
	add_test("grafo_48_50.clq",	1249	);
	add_test("grafo_49_50.clq",	1300	);
	add_test("grafo_49_51.clq",	1220	);
	add_test("grafo_5_6.clq",	1223	);
	add_test("grafo_5_7.clq",	1149	);
	add_test("grafo_50_51.clq",	1280	);
	add_test("grafo_50_52.clq",	1294	);
	add_test("grafo_51_52.clq",	1284	);
	add_test("grafo_51_53.clq",	1258	);
	add_test("grafo_52_53.clq",	1305	);
	add_test("grafo_52_54.clq",	1266	);
	add_test("grafo_53_54.clq",	1297	);
	add_test("grafo_53_55.clq",	1260	);
	add_test("grafo_54_55.clq",	1269	);
	add_test("grafo_54_56.clq",	1245	);
	add_test("grafo_55_56.clq",	1269	);
	add_test("grafo_55_57.clq",	1190	);
	add_test("grafo_56_57.clq",	1260	);
	add_test("grafo_56_58.clq",	1198	);
	add_test("grafo_57_58.clq",	1240	);
	add_test("grafo_57_59.clq",	1223	);
	add_test("grafo_58_59.clq",	1272	);
	add_test("grafo_58_60.clq",	1254	);
	add_test("grafo_59_60.clq",	1296	);
	add_test("grafo_59_61.clq",	1241	);
	add_test("grafo_6_7.clq",	1269	);
	add_test("grafo_6_8.clq",	1192	);
	add_test("grafo_60_61.clq",	1359	);
	add_test("grafo_60_62.clq",	1285	);
	add_test("grafo_61_62.clq",	1312	);
	add_test("grafo_61_63.clq",	1248	);
	add_test("grafo_62_63.clq",	1277	);
	add_test("grafo_62_64.clq",	1244	);
	add_test("grafo_63_64.clq",	1283	);
	add_test("grafo_63_65.clq",	1208	);
	add_test("grafo_64_65.clq",	1276	);
	add_test("grafo_64_66.clq",	1236	);
	add_test("grafo_65_66.clq",	1279	);
	add_test("grafo_65_67.clq",	1241	);
	add_test("grafo_66_67.clq",	1278	);
	add_test("grafo_66_68.clq",	1224	);
	add_test("grafo_67_68.clq",	1280	);
	add_test("grafo_67_69.clq",	1217	);
	add_test("grafo_68_69.clq",	1247	);
	add_test("grafo_68_70.clq",	1211	);
	add_test("grafo_69_70.clq",	1314	);
	add_test("grafo_69_71.clq",	1227	);
	add_test("grafo_7_8.clq",	1256	);
	add_test("grafo_7_9.clq",	1154	);
	add_test("grafo_70_71.clq",	1285	);
	add_test("grafo_70_72.clq",	1236	);
	add_test("grafo_71_72.clq",	1286	);
	add_test("grafo_71_73.clq",	1221	);
	add_test("grafo_72_73.clq",	1244	);
	add_test("grafo_72_74.clq",	1202	);
	add_test("grafo_73_74.clq",	1206	);
	add_test("grafo_73_75.clq",	1168	);
	add_test("grafo_74_75.clq",	1192	);
	add_test("grafo_74_76.clq",	1164	);
	add_test("grafo_75_76.clq",	1256	);
	add_test("grafo_75_77.clq",	1158	);
	add_test("grafo_76_77.clq",	1209	);
	add_test("grafo_76_78.clq",	1154	);
	add_test("grafo_77_78.clq",	1216	);
	add_test("grafo_77_79.clq",	1179	);
	add_test("grafo_78_79.clq",	1265	);
	add_test("grafo_78_80.clq",	1227	);
	add_test("grafo_79_80.clq",	1239	);
	add_test("grafo_79_81.clq",	1174	);
	add_test("grafo_8_10.clq",	1179	);
	add_test("grafo_8_9.clq",	1217	);
	add_test("grafo_80_81.clq",	1221	);
	add_test("grafo_80_82.clq",	1134	);
	add_test("grafo_81_82.clq",	1221	);
	add_test("grafo_81_83.clq",	1184	);
	add_test("grafo_82_83.clq",	1225	);
	add_test("grafo_82_84.clq",	1109	);
	add_test("grafo_83_84.clq",	1231	);
	add_test("grafo_83_85.clq",	1180	);
	add_test("grafo_84_85.clq",	1180	);
	add_test("grafo_84_86.clq",	1158	);
	add_test("grafo_85_86.clq",	1192	);
	add_test("grafo_85_87.clq",	1165	);
	add_test("grafo_86_87.clq",	1176	);
	add_test("grafo_86_88.clq",	1092	);
	add_test("grafo_87_88.clq",	1089	);
	add_test("grafo_87_89.clq",	1069	);
	add_test("grafo_88_89.clq",	1139	);
	add_test("grafo_88_90.clq",	1100	);
	add_test("grafo_89_90.clq",	1160	);
	add_test("grafo_89_91.clq",	1107	);
	add_test("grafo_9_10.clq",	1215	);
	add_test("grafo_9_11.clq",	1130	);
	add_test("grafo_90_91.clq",	1148	);
	add_test("grafo_90_92.clq",	1112	);
	add_test("grafo_91_92.clq",	1170	);
	add_test("grafo_91_93.clq",	1149	);
	add_test("grafo_92_93.clq",	1178	);
	add_test("grafo_92_94.clq",	1134	);
	add_test("grafo_93_94.clq",	1160	);
	add_test("grafo_93_95.clq",	1110	);
	add_test("grafo_94_95.clq",	1147	);
	add_test("grafo_94_96.clq",	1110	);
	add_test("grafo_95_96.clq",	1123	);
	add_test("grafo_95_97.clq",	1089	);
	add_test("grafo_96_97.clq",	1154	);
	add_test("grafo_96_98.clq",	1121	);
	add_test("grafo_97_98.clq",	1147	);
	add_test("grafo_97_99.clq",	1098	);
	add_test("grafo_98_100.clq",	1104	);
	add_test("grafo_98_99.clq",	1128	);
	add_test("grafo_99_100.clq",	1129	);
	add_test("grafo_99_101.clq",	1114	);
}

void BkClique::HeliGrande(){
	
	stringstream sstr("");
	for(int i=0; i<HELIGRANDE-1; i++){
		for(int j=i+1; j<HELIGRANDE; j++){
			sstr<<"grafo"<<"_"<<i<<"_"<<j<<".clq";
			add_test(sstr.str());
			sstr.str("");
		}
		
	}
}

void BkClique::Ualberta(){
	stringstream sstr("");
	for(int i=0; i<UALBERTA-1; i++){
		for(int j=i+1; j<UALBERTA; j++){
			sstr<<"grafo"<<"_"<<i<<"_"<<j<<".clq";
			add_test(sstr.str());
			sstr.str("");
		}
		
	}
}

void BkClique::Fpv1(){
	stringstream sstr("");
	for(int i=0; i<FPV1-1; i++){
		for(int j=i+1; j<FPV1; j++){
			sstr<<"grafo"<<"_"<<i<<"_"<<j<<".clq";
			add_test(sstr.str());
			sstr.str("");
		}
	}
}


void BkClique::black_hole(){
	add_test("normalized-BlackHole-4-4-e-0_ext.clq");
	add_test("normalized-BlackHole-4-4-e-1_ext.clq");
	add_test("normalized-BlackHole-4-4-e-2_ext.clq");
	add_test("normalized-BlackHole-4-4-e-3_ext.clq");
	add_test("normalized-BlackHole-4-4-e-4_ext.clq");
	add_test("normalized-BlackHole-4-4-e-5_ext.clq");
	add_test("normalized-BlackHole-4-7-e-0_ext.clq");
}

void BkClique::bqwh(){
	add_test("normalized-bqwh-15-106-21_ext.clq");
	add_test("normalized-bqwh-15-106-36_ext.clq");
	add_test("normalized-bqwh-15-106-47_ext.clq");
	add_test("normalized-bqwh-15-106-55_ext.clq");
	add_test("normalized-bqwh-15-106-76_ext.clq");
	add_test("normalized-bqwh-18-141-13_ext.clq");
	add_test("normalized-bqwh-18-141-23_ext.clq");
	add_test("normalized-bqwh-18-141-29_ext.clq");
	add_test("normalized-bqwh-18-141-36_ext.clq");
	add_test("normalized-bqwh-18-141-40_ext.clq");
}

void BkClique::composed(){
	add_test("normalized-composed-25-1-2-0_ext.clq");
	add_test("normalized-composed-25-1-2-3_ext.clq");
	add_test("normalized-composed-25-1-2-5_ext.clq");
	add_test("normalized-composed-25-1-2-7_ext.clq");
	add_test("normalized-composed-25-1-2-8_ext.clq");
	add_test("normalized-composed-25-1-2-9_ext.clq");

	add_test("normalized-composed-25-1-25-0_ext.clq");
	add_test("normalized-composed-25-1-25-2_ext.clq");
	add_test("normalized-composed-25-1-25-5_ext.clq");
	add_test("normalized-composed-25-1-25-7_ext.clq");
	add_test("normalized-composed-25-1-25-8_ext.clq");

	add_test("normalized-composed-75-1-2-0_ext.clq");
	add_test("normalized-composed-75-1-2-2_ext.clq");
	
}

void BkClique::csp_dsjc(){
	add_test("normalized-dsjc-125-1-4-ext.clq");
	add_test("normalized-dsjc-125-1-5-ext.clq");
}

void BkClique::csp_geom(){
	/*add_test("normalized-geom-30a-4-ext.clq");
	add_test("normalized-geom-30a-5-ext.clq");*/

	add_test("normalized-geo50-20-d4-75-43_ext.clq");
	add_test("normalized-geo50-20-d4-75-46_ext.clq");
	add_test("normalized-geo50-20-d4-75-59_ext.clq");
	add_test("normalized-geo50-20-d4-75-78_ext.clq");
	add_test("normalized-geo50-20-d4-75-84_ext.clq");
	add_test("normalized-geo50-20-d4-75-94_ext.clq");
	
	
	
}

void BkClique::csp_le450(){
	add_test("normalized-le-450-5a-2-ext.clq");
	add_test("normalized-le-450-5a-3-ext.clq");
}

void BkClique::csp_myciel(){
	add_test("normalized-myciel-5g-3-ext.clq");
	add_test("normalized-myciel-5g-4-ext.clq");
	add_test("normalized-myciel-5g-5-ext.clq");
}

void BkClique::driver(){
	add_test("normalized-driverlogw-01c-sat_ext.clq");
	add_test("normalized-driverlogw-02c-sat_ext.clq");
	add_test("normalized-driverlogw-04c-sat_ext.clq");
	add_test("normalized-driverlogw-05c-sat_ext.clq");
	add_test("normalized-driverlogw-08c-sat_ext.clq");
	add_test("normalized-driverlogw-08cc-sat_ext.clq");
	add_test("normalized-driverlogw-09-sat_ext.clq");
}

void BkClique::marc(){
////////////////
// order of magnitude better CSP 2009
	add_test("normalized-large-80-sat_ext.clq");
	add_test("normalized-large-80-unsat_ext.clq");
	add_test("normalized-large-84-sat_ext.clq");
	add_test("normalized-large-84-unsat_ext.clq");
	add_test("normalized-large-88-sat_ext.clq");
	add_test("normalized-large-88-unsat_ext.clq");
	add_test("normalized-large-92-sat_ext.clq");
	add_test("normalized-large-92-unsat_ext.clq");
	/*add_test("normalized-large-96-sat_ext.clq");
	add_test("normalized-large-96-unsat_ext.clq");*/		/*trivial but takes time to read from file*/
}

void BkClique::lard(){
/////////////////
// order of magnitude better CSP 2009
//  (up to 92 in VENUS)

	add_test("normalized-lard-83-83.clq");
	add_test("normalized-lard-84-84.clq");
	add_test("normalized-lard-85-85.clq");
	add_test("normalized-lard-86-86.clq");

	//...
}

void BkClique::csp_queens(){
	add_test("normalized-queens-5-5-3-ext.clq");
	add_test("normalized-queens-5-5-3-ext.clq");
}

void BkClique::ehi(){
	add_test("normalized-ehi-85-297-19_ext.clq");
	add_test("normalized-ehi-85-297-28_ext.clq");
	add_test("normalized-ehi-85-297-72_ext.clq");
	add_test("normalized-ehi-85-297-74_ext.clq");
	add_test("normalized-ehi-85-297-83_ext.clq");
	add_test("normalized-ehi-90-315-48_ext.clq");
	add_test("normalized-ehi-90-315-73_ext.clq");
}

void BkClique::csp_frb(){
	add_test("frb30-15-1.clq");
	add_test("frb30-15-2.clq");
	add_test("frb30-15-3.clq");
	add_test("frb30-15-4.clq");
	add_test("frb30-15-5.clq");
	add_test("frb35-17-1.clq");
	add_test("frb35-17-2.clq");
	add_test("frb35-17-3.clq");
	add_test("frb35-17-4.clq");
	add_test("frb35-17-5.clq");
	add_test("frb40-19-1.clq");
	add_test("frb40-19-2.clq");
	add_test("frb40-19-3.clq");
	add_test("frb40-19-4.clq");
	add_test("frb40-19-5.clq");
	add_test("frb45-21-1.clq");
	add_test("frb45-21-2.clq");
	add_test("frb45-21-3.clq");
	add_test("frb45-21-4.clq");
	add_test("frb45-21-5.clq");
	add_test("frb50-23-1.clq");
	add_test("frb50-23-2.clq");
	add_test("frb50-23-3.clq");
	add_test("frb50-23-4.clq");
	add_test("frb50-23-5.clq");
	add_test("frb53-24-1.clq");
	add_test("frb53-24-2.clq");
	add_test("frb53-24-3.clq");
	add_test("frb53-24-4.clq");
	add_test("frb53-24-5.clq");
	add_test("frb59-26-1.clq");
	add_test("frb59-26-2.clq");
	add_test("frb59-26-3.clq");
	add_test("frb59-26-4.clq");
	add_test("frb59-26-5.clq");

	//add_test("normalized-frb30-15-1-mgd_ext.clq");
	//add_test("normalized-frb30-15-3-mgd_ext.clq");
	//add_test("normalized-frb30-15-4-mgd_ext.clq");
	//add_test("normalized-frb30-15-5-mgd_ext.clq");
	//add_test("normalized-frb35-17-1_ext.clq");
	//add_test("normalized-frb35-17-2-mgd_ext.clq");
	//add_test("normalized-frb35-17-4-mgd_ext.clq");
	//add_test("normalized-frb40-19-1-mgd_ext.clq");
	//add_test("normalized-frb40-19-3-mgd_ext.clq");
	//add_test("normalized-frb40-19-4_ext.clq");
	//add_test("normalized-frb40-19-5_ext.clq");
	//add_test("normalized-frb45-21-2-mgd_ext.clq");
	//add_test("normalized-frb45-21-4_ext.clq");
	//add_test("normalized-frb45-21-5-mgd_ext.clq");
}

void BkClique::hanoi(){
	add_test("normalized-hanoi-3_ext.clq");
	add_test("normalized-hanoi-4_ext.clq");
}

void BkClique::langford(){
	add_test("normalized-langford-2-4-ext.clq");
	add_test("normalized-langford-3-9-ext.clq");
	add_test("normalized-langford-3-11-ext.clq");
}

void BkClique::qcp(){
			
	add_test("normalized-qcp-10-67-0_ext.clq");
	add_test("normalized-qcp-10-67-1_ext.clq");
	add_test("normalized-qcp-10-67-2_ext.clq");
	add_test("normalized-qcp-10-67-3_ext.clq");
	add_test("normalized-qcp-10-67-4_ext.clq");
	add_test("normalized-qcp-10-67-5_ext.clq");
	add_test("normalized-qcp-10-67-6_ext.clq");
	add_test("normalized-qcp-10-67-7_ext.clq");
	add_test("normalized-qcp-10-67-8_ext.clq");
	add_test("normalized-qcp-10-67-9_ext.clq");
	add_test("normalized-qcp-10-67-10_ext.clq");
	add_test("normalized-qcp-15-120-0_ext.clq");
	add_test("normalized-qcp-20-187-0_ext.clq");
	add_test("normalized-qcp-20-187-1_ext.clq");
	add_test("normalized-qcp-20-187-4_ext.clq");
}

void BkClique::qwh(){
	add_test("normalized-qwh-10-57-0_ext.clq");
	add_test("normalized-qwh-10-57-1_ext.clq");
	add_test("normalized-qwh-10-57-2_ext.clq");
	add_test("normalized-qwh-10-57-3_ext.clq");
	add_test("normalized-qwh-10-57-4_ext.clq");
	add_test("normalized-qwh-10-57-5_ext.clq");
	add_test("normalized-qwh-10-57-6_ext.clq");
	add_test("normalized-qwh-10-57-7_ext.clq");
	add_test("normalized-qwh-10-57-8_ext.clq");
	add_test("normalized-qwh-10-57-9_ext.clq");

	add_test("normalized-qwh-25-235-9_ext.clq");
}

void BkClique::rand_2_Xs(){
	add_test("normalized-rand-23-23-253-131-46021_ext.clq");
	add_test("normalized-rand-23-23-253-131-47021_ext.clq");
	add_test("normalized-rand-23-23-253-131-49021_ext.clq");
	add_test("normalized-rand-23-23-253-131-50021_ext.clq");
	add_test("normalized-rand-23-23-253-131-51021_ext.clq");
	add_test("normalized-rand-23-23-253-131-52021_ext.clq");
	add_test("normalized-rand-23-23-253-131-53021_ext.clq");
	add_test("normalized-rand-23-23-253-131-54021_ext.clq");
	add_test("normalized-rand-23-23-253-131-55021_ext.clq");

	add_test("normalized-rand-24-24-276-139-48021_ext.clq");
	add_test("normalized-rand-24-24-276-139-49021_ext.clq");
	add_test("normalized-rand-24-24-276-139-50021_ext.clq");
	add_test("normalized-rand-24-24-276-139-51021_ext.clq");
	add_test("normalized-rand-24-24-276-139-52021_ext.clq");
	add_test("normalized-rand-24-24-276-139-53021_ext.clq");
	add_test("normalized-rand-24-24-276-139-54021_ext.clq");
	add_test("normalized-rand-24-24-276-139-55021_ext.clq");
	add_test("normalized-rand-24-24-276-139-56021_ext.clq");
	add_test("normalized-rand-24-24-276-139-57021_ext.clq");

	add_test("normalized-rand-25-25-300-147-50021_ext.clq");
	add_test("normalized-rand-25-25-300-147-51021_ext.clq");
	add_test("normalized-rand-25-25-300-147-52021_ext.clq");
	add_test("normalized-rand-25-25-300-147-53021_ext.clq");
	add_test("normalized-rand-25-25-300-147-54021_ext.clq");
	add_test("normalized-rand-25-25-300-147-55021_ext.clq");
	add_test("normalized-rand-25-25-300-147-56021_ext.clq");
	add_test("normalized-rand-25-25-300-147-57021_ext.clq");
	add_test("normalized-rand-25-25-300-147-58021_ext.clq");
	add_test("normalized-rand-25-25-300-147-59021_ext.clq");
	
	add_test("normalized-rand-27-27-351-163-54021_ext.clq");
	add_test("normalized-rand-27-27-351-163-55021_ext.clq");
	add_test("normalized-rand-27-27-351-163-56021_ext.clq");
	add_test("normalized-rand-27-27-351-163-57021_ext.clq");
	add_test("normalized-rand-27-27-351-163-58021_ext.clq");
	add_test("normalized-rand-27-27-351-163-59021_extt.clq");
	add_test("normalized-rand-27-27-351-163-60021_ext.clq");
	add_test("normalized-rand-27-27-351-163-61021_ext.clq");
	add_test("normalized-rand-27-27-351-163-62021_ext.clq");
	add_test("normalized-rand-27-27-351-163-63021_ext.clq");

	//add_test("normalized-rand-2-50-23-587-230-fcd-17_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-19_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-20_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-21_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-22_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-23_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-25_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-29_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-30_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-32_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-33_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-35_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-38_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-39_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-41_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-42_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-43_ext.clq");
	//add_test("normalized-rand-2-50-23-587-230-fcd-45_ext.clq");
}

void BkClique::tightness(){

	add_test("normalized-rand-2-40-8-753-100-12_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-15_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-16_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-20_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-30_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-17_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-18_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-20_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-25_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-37_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-0_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-2_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-7_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-18_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-20_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-21_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-27_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-36_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-41_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-62_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-63_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-70_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-71_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-77_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-79_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-13_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-15_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-16_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-23_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-27_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-38_ext.clq");
	add_test("normalized-rand-2-40-40-135-650-10_ext.clq");
	add_test("normalized-rand-2-40-40-135-650-11_ext.clq");
	add_test("normalized-rand-2-40-40-135-650-25_ext.clq");
	add_test("normalized-rand-2-40-40-135-650-29_ext.clq");

	
}

void BkClique::csp_all(){
	add_test("frb30-15-1.clq");
	add_test("frb30-15-2.clq");
	add_test("frb30-15-3.clq");
	add_test("frb30-15-4.clq");
	add_test("frb30-15-5.clq");
	add_test("frb35-17-1.clq");
	add_test("frb35-17-2.clq");
	add_test("frb35-17-3.clq");
	add_test("frb35-17-4.clq");
	add_test("frb35-17-5.clq");
	add_test("frb40-19-1.clq");
	add_test("frb40-19-2.clq");
	add_test("frb40-19-3.clq");
	add_test("frb40-19-4.clq");
	add_test("frb40-19-5.clq");
	add_test("frb45-21-1.clq");
	add_test("frb45-21-2.clq");
	add_test("frb45-21-3.clq");
	add_test("frb45-21-4.clq");
	add_test("frb45-21-5.clq");
	add_test("frb50-23-1.clq");
	add_test("frb50-23-2.clq");
	add_test("frb50-23-3.clq");
	add_test("frb50-23-4.clq");
	add_test("frb50-23-5.clq");
	add_test("frb53-24-1.clq");
	add_test("frb53-24-2.clq");
	add_test("frb53-24-3.clq");
	add_test("frb53-24-4.clq");
	add_test("frb53-24-5.clq");
	add_test("frb59-26-1.clq");
	add_test("frb59-26-2.clq");
	add_test("frb59-26-3.clq");
	add_test("frb59-26-4.clq");
	add_test("frb59-26-5.clq");
	add_test("normalized-BlackHole-4-4-e-0_ext.clq");
	add_test("normalized-BlackHole-4-4-e-1_ext.clq");
	add_test("normalized-BlackHole-4-4-e-2_ext.clq");
	add_test("normalized-BlackHole-4-4-e-3_ext.clq");
	add_test("normalized-BlackHole-4-4-e-4_ext.clq");
	add_test("normalized-BlackHole-4-4-e-5_ext.clq");
	add_test("normalized-BlackHole-4-7-e-0_ext.clq");
	add_test("normalized-bqwh-15-106-21_ext.clq");
	add_test("normalized-bqwh-15-106-36_ext.clq");
	add_test("normalized-bqwh-15-106-47_ext.clq");
	add_test("normalized-bqwh-15-106-55_ext.clq");
	add_test("normalized-bqwh-15-106-76_ext.clq");
	add_test("normalized-bqwh-18-141-13_ext.clq");
	add_test("normalized-bqwh-18-141-23_ext.clq");
	add_test("normalized-bqwh-18-141-29_ext.clq");
	add_test("normalized-bqwh-18-141-36_ext.clq");
	add_test("normalized-bqwh-18-141-40_ext.clq");
	add_test("normalized-composed-25-1-2-0_ext.clq");
	add_test("normalized-composed-25-1-2-3_ext.clq");
	add_test("normalized-composed-25-1-2-5_ext.clq");
	add_test("normalized-composed-25-1-2-7_ext.clq");
	add_test("normalized-composed-25-1-2-8_ext.clq");
	add_test("normalized-composed-25-1-2-9_ext.clq");
	add_test("normalized-driverlogw-01c-sat_ext.clq");
	add_test("normalized-driverlogw-02c-sat_ext.clq");
	add_test("normalized-driverlogw-04c-sat_ext.clq");
	add_test("normalized-driverlogw-05c-sat_ext.clq");
	add_test("normalized-driverlogw-08c-sat_ext.clq");
	add_test("normalized-driverlogw-08cc-sat_ext.clq");
	add_test("normalized-driverlogw-09-sat_ext.clq");
	add_test("normalized-dsjc-125-1-4-ext.clq");
	add_test("normalized-dsjc-125-1-5-ext.clq");
	add_test("normalized-geom-30a-4-ext.clq");
	add_test("normalized-geom-30a-5-ext.clq");
	add_test("normalized-le-450-5a-2-ext.clq");
	add_test("normalized-le-450-5a-3-ext.clq");
	add_test("normalized-myciel-5g-3-ext.clq");
	add_test("normalized-myciel-5g-4-ext.clq");
	add_test("normalized-myciel-5g-5-ext.clq");
	add_test("normalized-queens-5-5-3-ext.clq");
	add_test("normalized-queens-5-5-3-ext.clq");
	add_test("normalized-ehi-85-297-19_ext.clq");
	add_test("normalized-ehi-85-297-28_ext.clq");
	add_test("normalized-ehi-85-297-72_ext.clq");
	add_test("normalized-ehi-85-297-74_ext.clq");
	add_test("normalized-ehi-85-297-83_ext.clq");
	add_test("normalized-ehi-90-315-48_ext.clq");
	add_test("normalized-ehi-90-315-73_ext.clq");
	add_test("normalized-hanoi-3_ext.clq");
	add_test("normalized-hanoi-4_ext.clq");
	add_test("normalized-langford-2-4-ext.clq");
	add_test("normalized-langford-3-9-ext.clq");
	add_test("normalized-langford-3-11-ext.clq");
	add_test("normalized-lard-83-83.clq");
	add_test("normalized-lard-84-84.clq");
	add_test("normalized-lard-85-85.clq");
	add_test("normalized-lard-86-86.clq");
	add_test("normalized-large-80-sat_ext.clq");
	add_test("normalized-large-80-unsat_ext.clq");
	add_test("normalized-large-84-sat_ext.clq");
	add_test("normalized-large-84-unsat_ext.clq");
	add_test("normalized-large-88-sat_ext.clq");
	add_test("normalized-large-88-unsat_ext.clq");
	add_test("normalized-large-92-sat_ext.clq");
	add_test("normalized-large-92-unsat_ext.clq");
	add_test("normalized-qcp-10-67-0_ext.clq");
	add_test("normalized-qcp-10-67-1_ext.clq");
	add_test("normalized-qcp-10-67-2_ext.clq");
	add_test("normalized-qcp-10-67-3_ext.clq");
	add_test("normalized-qcp-10-67-4_ext.clq");
	add_test("normalized-qcp-10-67-5_ext.clq");
	add_test("normalized-qcp-10-67-6_ext.clq");
	add_test("normalized-qcp-10-67-7_ext.clq");
	add_test("normalized-qcp-10-67-8_ext.clq");
	add_test("normalized-qcp-10-67-9_ext.clq");
	add_test("normalized-qcp-10-67-10_ext.clq");
	add_test("normalized-qcp-15-120-0_ext.clq");
	add_test("normalized-qcp-20-187-0_ext.clq");
	add_test("normalized-qcp-20-187-1_ext.clq");
	add_test("normalized-qcp-20-187-4_ext.clq");
	add_test("normalized-qwh-10-57-0_ext.clq");
	add_test("normalized-qwh-10-57-1_ext.clq");
	add_test("normalized-rand-23-23-253-131-46021_ext.clq");
	add_test("normalized-rand-23-23-253-131-47021_ext.clq");
	add_test("normalized-rand-23-23-253-131-49021_ext.clq");
	add_test("normalized-rand-23-23-253-131-50021_ext.clq");
	add_test("normalized-rand-23-23-253-131-51021_ext.clq");
	add_test("normalized-rand-23-23-253-131-52021_ext.clq");
	add_test("normalized-rand-23-23-253-131-53021_ext.clq");
	add_test("normalized-rand-23-23-253-131-54021_ext.clq");
	add_test("normalized-rand-23-23-253-131-55021_ext.clq");

	add_test("normalized-rand-24-24-276-139-48021_ext.clq");
	add_test("normalized-rand-24-24-276-139-49021_ext.clq");
	add_test("normalized-rand-24-24-276-139-50021_ext.clq");
	add_test("normalized-rand-24-24-276-139-51021_ext.clq");
	add_test("normalized-rand-24-24-276-139-52021_ext.clq");
	add_test("normalized-rand-24-24-276-139-53021_ext.clq");
	add_test("normalized-rand-24-24-276-139-54021_ext.clq");
	add_test("normalized-rand-24-24-276-139-55021_ext.clq");
	add_test("normalized-rand-24-24-276-139-56021_ext.clq");
	add_test("normalized-rand-24-24-276-139-57021_ext.clq");

	add_test("normalized-rand-25-25-300-147-50021_ext.clq");
	add_test("normalized-rand-25-25-300-147-51021_ext.clq");
	add_test("normalized-rand-25-25-300-147-50021_ext.clq");
	add_test("normalized-rand-25-25-300-147-52021_ext.clq");
	add_test("normalized-rand-25-25-300-147-53021_ext.clq");
	add_test("normalized-rand-25-25-300-147-54021_ext.clq");
	add_test("normalized-rand-25-25-300-147-55021_ext.clq");
	add_test("normalized-rand-25-25-300-147-56021_ext.clq");
	add_test("normalized-rand-25-25-300-147-57021_ext.clq");
	add_test("normalized-rand-25-25-300-147-58021_ext.clq");
	add_test("normalized-rand-25-25-300-147-59021_ext.clq");
	
	add_test("normalized-rand-27-27-351-163-54021_ext.clq");
	add_test("normalized-rand-27-27-351-163-55021_ext.clq");
	add_test("normalized-rand-27-27-351-163-56021_ext.clq");
	add_test("normalized-rand-27-27-351-163-57021_ext.clq");
	add_test("normalized-rand-27-27-351-163-58021_ext.clq");
	add_test("normalized-rand-27-27-351-163-59021_extt.clq");
	add_test("normalized-rand-27-27-351-163-60021_ext.clq");
	add_test("normalized-rand-27-27-351-163-61021_ext.clq");
	add_test("normalized-rand-27-27-351-163-62021_ext.clq");
	add_test("normalized-rand-27-27-351-163-63021_ext.clq");

	add_test("normalized-rand-2-40-8-753-100-12_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-15_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-16_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-20_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-30_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-17_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-18_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-20_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-25_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-37_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-0_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-2_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-7_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-18_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-20_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-21_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-27_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-36_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-41_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-62_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-63_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-70_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-71_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-77_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-79_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-13_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-15_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-16_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-23_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-27_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-38_ext.clq");
	add_test("normalized-rand-2-40-40-135-650-10_ext.clq");
}

void BkClique::csp_all_except_frb(){
	
	/*add_test("normalized-BlackHole-4-4-e-0_ext.clq");
	add_test("normalized-BlackHole-4-4-e-1_ext.clq");
	add_test("normalized-BlackHole-4-4-e-2_ext.clq");
	add_test("normalized-BlackHole-4-4-e-3_ext.clq");
	add_test("normalized-BlackHole-4-4-e-4_ext.clq");
	add_test("normalized-BlackHole-4-4-e-5_ext.clq");
	add_test("normalized-BlackHole-4-7-e-0_ext.clq");*/
	add_test("normalized-bqwh-15-106-21_ext.clq");
	add_test("normalized-bqwh-15-106-36_ext.clq");
	add_test("normalized-bqwh-15-106-47_ext.clq");
	add_test("normalized-bqwh-15-106-55_ext.clq");
	add_test("normalized-bqwh-15-106-76_ext.clq");
	add_test("normalized-bqwh-18-141-13_ext.clq");
	add_test("normalized-bqwh-18-141-23_ext.clq");
	add_test("normalized-bqwh-18-141-29_ext.clq");
	add_test("normalized-bqwh-18-141-36_ext.clq");
	add_test("normalized-bqwh-18-141-40_ext.clq");
	add_test("normalized-composed-25-1-2-0_ext.clq");
	add_test("normalized-composed-25-1-2-3_ext.clq");
	add_test("normalized-composed-25-1-2-5_ext.clq");
	add_test("normalized-composed-25-1-2-7_ext.clq");
	add_test("normalized-composed-25-1-2-8_ext.clq");
	add_test("normalized-composed-25-1-2-9_ext.clq");
	add_test("normalized-composed-25-1-25-0_ext.clq");
	add_test("normalized-composed-25-1-25-2_ext.clq");
	add_test("normalized-composed-25-1-25-5_ext.clq");
	add_test("normalized-composed-25-1-25-7_ext.clq");
	add_test("normalized-composed-25-1-25-8_ext.clq");
	add_test("normalized-composed-75-1-2-0_ext.clq");
	add_test("normalized-composed-75-1-2-2_ext.clq");
	add_test("normalized-driverlogw-01c-sat_ext.clq");
	add_test("normalized-driverlogw-02c-sat_ext.clq");
	add_test("normalized-driverlogw-04c-sat_ext.clq");
	add_test("normalized-driverlogw-05c-sat_ext.clq");
	add_test("normalized-driverlogw-08c-sat_ext.clq");
	add_test("normalized-driverlogw-08cc-sat_ext.clq");
	add_test("normalized-driverlogw-09-sat_ext.clq");
	add_test("normalized-dsjc-125-1-4-ext.clq");
	add_test("normalized-dsjc-125-1-5-ext.clq");
	add_test("normalized-geom-30a-4-ext.clq");
	add_test("normalized-geom-30a-5-ext.clq");
	add_test("normalized-le-450-5a-2-ext.clq");
	add_test("normalized-le-450-5a-3-ext.clq");
	add_test("normalized-myciel-5g-3-ext.clq");
	add_test("normalized-myciel-5g-4-ext.clq");
	add_test("normalized-myciel-5g-5-ext.clq");
	add_test("normalized-queens-5-5-3-ext.clq");
	add_test("normalized-queens-5-5-3-ext.clq");
	add_test("normalized-ehi-85-297-19_ext.clq");
	add_test("normalized-ehi-85-297-28_ext.clq");
	add_test("normalized-ehi-85-297-72_ext.clq");
	add_test("normalized-ehi-85-297-74_ext.clq");
	add_test("normalized-ehi-85-297-83_ext.clq");
	add_test("normalized-ehi-90-315-48_ext.clq");
	add_test("normalized-ehi-90-315-73_ext.clq");
	add_test("normalized-hanoi-3_ext.clq");
	add_test("normalized-hanoi-4_ext.clq");
	add_test("normalized-langford-2-4-ext.clq");
	add_test("normalized-langford-3-9-ext.clq");
	add_test("normalized-langford-3-11-ext.clq");
	add_test("normalized-lard-83-83.clq");
	add_test("normalized-lard-84-84.clq");
	add_test("normalized-lard-85-85.clq");
	add_test("normalized-lard-86-86.clq");
	add_test("normalized-large-80-sat_ext.clq");
	add_test("normalized-large-80-unsat_ext.clq");
	add_test("normalized-large-84-sat_ext.clq");
	add_test("normalized-large-84-unsat_ext.clq");
	add_test("normalized-large-88-sat_ext.clq");
	add_test("normalized-large-88-unsat_ext.clq");
	add_test("normalized-large-92-sat_ext.clq");
	add_test("normalized-large-92-unsat_ext.clq");
	add_test("normalized-qcp-10-67-0_ext.clq");
	add_test("normalized-qcp-10-67-1_ext.clq");
	add_test("normalized-qcp-10-67-2_ext.clq");
	add_test("normalized-qcp-10-67-3_ext.clq");
	add_test("normalized-qcp-10-67-4_ext.clq");
	add_test("normalized-qcp-10-67-5_ext.clq");
	add_test("normalized-qcp-10-67-6_ext.clq");
	add_test("normalized-qcp-10-67-7_ext.clq");
	add_test("normalized-qcp-10-67-8_ext.clq");
	add_test("normalized-qcp-10-67-9_ext.clq");
	add_test("normalized-qcp-10-67-10_ext.clq");
	add_test("normalized-qcp-15-120-0_ext.clq");
	add_test("normalized-qcp-20-187-0_ext.clq");
	/*add_test("normalized-qcp-20-187-1_ext.clq");
	add_test("normalized-qcp-20-187-4_ext.clq");*/
	add_test("normalized-qwh-10-57-0_ext.clq");
	add_test("normalized-qwh-10-57-1_ext.clq");

	add_test("normalized-rand-23-23-253-131-46021_ext.clq");
	add_test("normalized-rand-23-23-253-131-47021_ext.clq");
	add_test("normalized-rand-23-23-253-131-49021_ext.clq");
	add_test("normalized-rand-23-23-253-131-50021_ext.clq");
	add_test("normalized-rand-23-23-253-131-51021_ext.clq");
	add_test("normalized-rand-23-23-253-131-52021_ext.clq");
	add_test("normalized-rand-23-23-253-131-53021_ext.clq");
	add_test("normalized-rand-23-23-253-131-54021_ext.clq");
	add_test("normalized-rand-23-23-253-131-55021_ext.clq");

	add_test("normalized-rand-24-24-276-139-48021_ext.clq");
	add_test("normalized-rand-24-24-276-139-49021_ext.clq");
	add_test("normalized-rand-24-24-276-139-50021_ext.clq");
	add_test("normalized-rand-24-24-276-139-51021_ext.clq");
	add_test("normalized-rand-24-24-276-139-52021_ext.clq");
	add_test("normalized-rand-24-24-276-139-53021_ext.clq");
	add_test("normalized-rand-24-24-276-139-54021_ext.clq");
	add_test("normalized-rand-24-24-276-139-55021_ext.clq");
	add_test("normalized-rand-24-24-276-139-56021_ext.clq");
	add_test("normalized-rand-24-24-276-139-57021_ext.clq");

	add_test("normalized-rand-25-25-300-147-50021_ext.clq");
	add_test("normalized-rand-25-25-300-147-51021_ext.clq");
	add_test("normalized-rand-25-25-300-147-50021_ext.clq");
	add_test("normalized-rand-25-25-300-147-52021_ext.clq");
	add_test("normalized-rand-25-25-300-147-53021_ext.clq");
	add_test("normalized-rand-25-25-300-147-54021_ext.clq");
	add_test("normalized-rand-25-25-300-147-55021_ext.clq");
	add_test("normalized-rand-25-25-300-147-56021_ext.clq");
	add_test("normalized-rand-25-25-300-147-57021_ext.clq");
	add_test("normalized-rand-25-25-300-147-58021_ext.clq");
	add_test("normalized-rand-25-25-300-147-59021_ext.clq");
	
	add_test("normalized-rand-27-27-351-163-54021_ext.clq");
	add_test("normalized-rand-27-27-351-163-55021_ext.clq");
	add_test("normalized-rand-27-27-351-163-56021_ext.clq");
	add_test("normalized-rand-27-27-351-163-57021_ext.clq");
	add_test("normalized-rand-27-27-351-163-58021_ext.clq");
	add_test("normalized-rand-27-27-351-163-59021_extt.clq");
	add_test("normalized-rand-27-27-351-163-60021_ext.clq");
	add_test("normalized-rand-27-27-351-163-61021_ext.clq");
	add_test("normalized-rand-27-27-351-163-62021_ext.clq");
	add_test("normalized-rand-27-27-351-163-63021_ext.clq");


	add_test("normalized-rand-2-40-8-753-100-12_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-15_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-16_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-20_ext.clq");
	add_test("normalized-rand-2-40-8-753-100-30_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-17_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-18_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-20_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-25_ext.clq");
	add_test("normalized-rand-2-40-11-414-200-37_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-0_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-2_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-7_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-18_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-20_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-21_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-27_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-36_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-41_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-62_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-63_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-70_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-71_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-77_ext.clq");
	add_test("normalized-rand-2-40-16-250-350-79_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-13_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-15_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-16_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-23_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-27_ext.clq");
	add_test("normalized-rand-2-40-25-180-500-38_ext.clq");
	add_test("normalized-rand-2-40-40-135-650-10_ext.clq");
	add_test("normalized-rand-2-40-40-135-650-11_ext.clq");
	add_test("normalized-rand-2-40-40-135-650-25_ext.clq");
	add_test("normalized-rand-2-40-40-135-650-29_ext.clq");
}


/////////////////
// Weighted
void BkCliqueW::EasyWeighted(){
	add_test("p06.col");
	add_test("p07.col");
	add_test("p08.col");
	add_test("p09.col");
	add_test("p10.col");
	add_test("p11.col");
	add_test("p12.col");
	add_test("p13.col");
	add_test("p14.col");
	add_test("p15.col");
	add_test("p16.col");
	add_test("p17.col");
	add_test("p18.col");
	add_test("p19.col");
	add_test("p20.col");
	add_test("p21.col");
	add_test("p22.col");
	add_test("p23.col");
	add_test("p24.col");
	add_test("p25.col");
	add_test("p26.col");
	add_test("p27.col");
	add_test("p28.col");
	add_test("p29.col");
	add_test("p30.col");
	add_test("p31.col");
	add_test("p32.col");
	add_test("p33.col");
	add_test("p34.col");
	add_test("p35.col");
	add_test("p36.col");
	add_test("p38.col");
	add_test("p40.col");
	add_test("p41.col");
	add_test("p42.col");
	add_test("r01.col");
	add_test("r02.col");
	add_test("r03.col");
	add_test("r04.col");
	add_test("r05.col");
	add_test("r06.col");
	add_test("r07.col");
	add_test("r08.col");
	add_test("r09.col");
	add_test("r13.col");
	add_test("r14.col");
	add_test("r15.col");
	add_test("r16.col");
	add_test("r17.col");
	add_test("r18.col");
	add_test("r19.col");
	add_test("r20.col");
	add_test("r21.col");
	add_test("r22.col");
	add_test("r23.col");
	add_test("r24.col");
	add_test("r25.col");
	add_test("r26.col");
	add_test("r27.col");
	add_test("r28.col");
	add_test("r29.col");
	add_test("r30.col");
	add_test("R50_1gb.col");
	add_test("R50_1g.col");
	add_test("R50_5gb.col");
	add_test("R50_5g.col");
	add_test("R50_9gb.col");
	add_test("R50_9g.col");
	add_test("R75_1gb.col");
	add_test("R75_1g.col");
	add_test("R75_5gb.col");
	add_test("R75_5g.col");
	add_test("R75_9gb.col");
	add_test("R75_9g.col");
	add_test("R100_1gb.col");
	add_test("R100_1g.col");
	add_test("R100_5g.col");
	add_test("R100_9gb.col");
	add_test("R100_9g.col");
	add_test("DSJC125_1gb.col");
	add_test("DSJC125_1g.col");
	add_test("DSJC125_5gb.col");
	add_test("DSJC125_5g.col");
	add_test("DSJC125_9gb.col");
	add_test("DSJC125_9g.col");
	add_test("GEOM100a.col");
	add_test("GEOM100b.col");
	add_test("GEOM100.col");
	add_test("GEOM110a.col");
	add_test("GEOM110b.col");
	add_test("GEOM110.col");
	add_test("GEOM120a.col");
	add_test("GEOM120b.col");
	add_test("GEOM120.col");
	add_test("GEOM30b.col");
	add_test("GEOM40b.col");
	add_test("GEOM50b.col");
	add_test("GEOM60b.col");
	add_test("GEOM70a.col");
	add_test("GEOM70b.col");
	add_test("GEOM70.col");
	add_test("GEOM80a.col");
	add_test("GEOM80b.col");
	add_test("GEOM80.col");
	add_test("GEOM90a.col");
	add_test("GEOM90b.col");
	add_test("GEOM90.col");
}

void BkCliqueW::SubsetEasyDimacs(){
	add_test("brock200_1.clq");
	add_test("brock200_2.clq");
	add_test("brock200_3.clq");		
	add_test("brock200_4.clq");	

	add_test("C125.9.clq");	

	add_test("c-fat200-1.clq");				
	add_test("c-fat200-2.clq");			
	add_test("c-fat200-5.clq");			
	add_test("c-fat500-1.clq");			
	add_test("c-fat500-2.clq");			 	
	add_test("c-fat500-5.clq");		
	add_test("c-fat500-10.clq");

	add_test("dsjc250.5.clq");
	add_test("dsjc500.1.clq");				
	add_test("dsjc500.5.clq");
	add_test("dsjc1000.1.clq");


	add_test("gen200_p0.9_44.clq");	
	add_test("gen200_p0.9_55.clq");				

	
	add_test("hamming6-2.clq");
	add_test("hamming6-4.clq");
/*	add_test("hamming8-2.clq");	
	add_test("hamming8-4.clq"); */	
//	add_test("hamming10-2.clq");			/* currently problematic!, but sensitive to local bounds (25/8/17) */


	add_test("johnson8-2-4.clq");	
	add_test("johnson8-4-4.clq");		
	add_test("johnson16-2-4.clq");
	
	add_test("keller4.clq");	
	
	add_test("MANN_a9.clq");				
//	add_test("MANN_a27.clq");				/* currently problematic (25/8/17) */		
	

	add_test("p_hat300-1.clq");				
	add_test("p_hat300-2.clq");				
	add_test("p_hat300-3.clq");				
	add_test("p_hat500-1.clq");				
	add_test("p_hat500-2.clq");				
//	add_test("p_hat500-3.clq");				
	add_test("p_hat700-1.clq");				
	add_test("p_hat700-2.clq");				
//	add_test("p_hat700-3.clq");				
	add_test("p_hat1000-1.clq");				
//	add_test("p_hat1000-2.clq");			/* takes some time but shoudl be solved nicely compared with MWSS (25/8/17) */	
	add_test("p_hat1500-1.clq");				

	add_test("san200_0.7_1.clq");				
	add_test("san200_0.7_2.clq");				
	add_test("san200_0.9_1.clq");				
	add_test("san200_0.9_2.clq");			
	add_test("san200_0.9_3.clq");			
	add_test("san400_0.5_1.clq");			
	add_test("san400_0.7_1.clq");			
	add_test("san400_0.7_2.clq");			
	add_test("san400_0.7_3.clq");			

	add_test("san1000.clq");	

	add_test("sanr200_0.7.clq");			
	add_test("sanr200_0.9.clq");				
	add_test("sanr400_0.5.clq");				
	add_test("sanr400_0.7.clq");
}

void BkCliqueW::SubsetHardDimacs(){

	add_test("brock400_1.clq");			
	add_test("brock400_2.clq");
	add_test("brock400_3.clq");
	add_test("brock400_4.clq");
	add_test("brock800_1.clq");			
	add_test("brock800_2.clq");				
	add_test("brock800_3.clq");				
	add_test("brock800_4.clq");

	add_test("C250.9.clq");	

	add_test("dsjc1000.5.clq");

//	add_test("hamming10-2.clq");			/* currently problematic!, but sensitive to local bounds (25/8/17) */

	add_test("MANN_a27.clq");				/* currently problematic (25/8/17) */		
//	add_test("MANN_a45.clq");

	add_test("p_hat500-3.clq");
	add_test("p_hat700-3.clq");
	add_test("p_hat1000-2.clq");			/* takes some time but shoudl be solved nicely compared with MWSS (25/8/17) */	
}

void BkCliqueW::Dimacs(){
	add_test("brock200_1.clq");
	add_test("brock200_2.clq");
	add_test("brock200_3.clq");		
	add_test("brock200_4.clq");	

	add_test("brock400_1.clq");			
	add_test("brock400_2.clq");
	add_test("brock400_3.clq");
	add_test("brock400_4.clq");
/*	add_test("brock800_1.clq");			
	add_test("brock800_2.clq");				
	add_test("brock800_3.clq");				
	add_test("brock800_4.clq");*/

	add_test("C125.9.clq");	
	add_test("C250.9.clq");				
	//add_test("C500.9.clq");	
	//add_test("C1000.9.clq");	
	//add_test("C2000.5.clq");

	add_test("c-fat200-1.clq");				
	add_test("c-fat200-2.clq");			
	add_test("c-fat200-5.clq");			
	add_test("c-fat500-1.clq");			
	add_test("c-fat500-2.clq");			 	
	add_test("c-fat500-5.clq");		
	add_test("c-fat500-10.clq");
	
	add_test("dsjc250.5.clq");
	add_test("dsjc500.1.clq");				
	add_test("dsjc500.5.clq");	
//	add_test("dsjc500.9.clq");	
	add_test("dsjc1000.1.clq");
	add_test("dsjc1000.5.clq");
//	add_test("dsjc1000.9.clq");  

	//the only bhoshlib
	add_test("frb30-15-1.clq");	
	add_test("frb30-15-2.clq");				
	add_test("frb30-15-3.clq");	
	add_test("frb30-15-4.clq");	
	add_test("frb30-15-5.clq");

	add_test("gen200_p0.9_44.clq");	
	add_test("gen200_p0.9_55.clq");				
	/*add_test("gen400_p0.9_55.clq");	
	add_test("gen400_p0.9_65.clq");	
	add_test("gen400_p0.9_75.clq");*/
	
	add_test("hamming6-2.clq");
	add_test("hamming6-4.clq");
	add_test("hamming8-2.clq");	
	add_test("hamming8-4.clq");	
	add_test("hamming10-2.clq");			/* currently problematic!, but sensitive to local bounds (25/8/17) */
	//add_test("hamming10-4.clq");	

	add_test("johnson8-2-4.clq");	
	add_test("johnson8-4-4.clq");		
	add_test("johnson16-2-4.clq");
	//add_test("johnson32-2-4.clq");

	add_test("keller4.clq");	
	//add_test("keller5.clq");
	//add_test("keller6.clq");

	add_test("MANN_a9.clq");				
	add_test("MANN_a27.clq");				/* currently problematic (25/8/17) */		
	//add_test("MANN_a45.clq");
	//add_test("MANN_a81.clq");			

	add_test("p_hat300-1.clq");				
	add_test("p_hat300-2.clq");				
	add_test("p_hat300-3.clq");				
	add_test("p_hat500-1.clq");				
	add_test("p_hat500-2.clq");				
	add_test("p_hat500-3.clq");				
	add_test("p_hat700-1.clq");				
	add_test("p_hat700-2.clq");				
	add_test("p_hat700-3.clq");				
	add_test("p_hat1000-1.clq");				
	add_test("p_hat1000-2.clq");			/* takes some time but shoudl be solved nicely compared with MWSS (25/8/17) */	
	add_test("p_hat1000-3.clq");				
	add_test("p_hat1500-1.clq");				
//	add_test("p_hat1500-2.clq");				
//	add_test("p_hat1500-3.clq");	

	add_test("san200_0.7_1.clq");				
	add_test("san200_0.7_2.clq");				
	add_test("san200_0.9_1.clq");				
	add_test("san200_0.9_2.clq");			
	add_test("san200_0.9_3.clq");			
	add_test("san400_0.5_1.clq");			
	add_test("san400_0.7_1.clq");			
	add_test("san400_0.7_2.clq");			
	add_test("san400_0.7_3.clq");			
//	add_test("san400_0.9_1.clq");	

	add_test("san1000.clq");	

	add_test("sanr200_0.7.clq");			
	add_test("sanr200_0.9.clq");				
	add_test("sanr400_0.5.clq");				
	add_test("sanr400_0.7.clq");
}

void BkCliqueW::Brock(){
	add_test("brock200_1.clq");
	add_test("brock200_2.clq");
	add_test("brock200_3.clq");		
	add_test("brock200_4.clq");	

	add_test("brock400_1.clq");			
	add_test("brock400_2.clq");
	add_test("brock400_3.clq");
	add_test("brock400_4.clq");
}
void BkCliqueW::Gen(){
	add_test("gen200_p0.9_44.clq");	
	add_test("gen200_p0.9_55.clq");				
	add_test("gen400_p0.9_55.clq");	
	add_test("gen400_p0.9_65.clq");	
	/*add_test("gen400_p0.9_75.clq");*/
}
void BkCliqueW::Frb(){
	add_test("frb30-15-1.clq");	
	add_test("frb30-15-2.clq");				
	add_test("frb30-15-3.clq");	
	add_test("frb30-15-4.clq");	
	add_test("frb30-15-5.clq");
}
void BkCliqueW::San(){
	add_test("sanr400_0.7.clq");

	add_test("san200_0.7_1.clq");				
	add_test("san200_0.7_2.clq");				
	add_test("san200_0.9_1.clq");				
	add_test("san200_0.9_2.clq");			
	add_test("san200_0.9_3.clq");			
	add_test("san400_0.5_1.clq");			
	add_test("san400_0.7_1.clq");			
	add_test("san400_0.7_2.clq");			
	add_test("san400_0.7_3.clq");			
//	add_test("san400_0.9_1.clq");	

	add_test("san1000.clq");	

	add_test("sanr200_0.7.clq");			
	add_test("sanr200_0.9.clq");				
	add_test("sanr400_0.5.clq");				
	add_test("sanr400_0.7.clq");
}
void BkCliqueW::Phat(){
	add_test("p_hat300-1.clq");				
	add_test("p_hat300-2.clq");				
	add_test("p_hat300-3.clq");				
	add_test("p_hat500-1.clq");				
	add_test("p_hat500-2.clq");				
	add_test("p_hat500-3.clq");				
	add_test("p_hat700-1.clq");				
	add_test("p_hat700-2.clq");				
	add_test("p_hat700-3.clq");				
	add_test("p_hat1000-1.clq");				
	add_test("p_hat1000-2.clq");			/* takes some time but shoudl be solved nicely compared with MWSS (25/8/17) */	
//	add_test("p_hat1000-3.clq");				
	add_test("p_hat1500-1.clq");				
	add_test("p_hat1500-2.clq");				
//	add_test("p_hat1500-3.clq");
}
void BkCliqueW::Keller(){
	add_test("keller4.clq");	
	//add_test("keller5.clq");
	//add_test("keller6.clq");
}
void BkCliqueW::Hamming(){
	add_test("hamming6-2.clq");
	add_test("hamming6-4.clq");
	add_test("hamming8-2.clq");	
	add_test("hamming8-4.clq");	
	add_test("hamming10-2.clq");			/* currently problematic!, but sensitive to local bounds (25/8/17) */
	//add_test("hamming10-4.clq");	
}
void BkCliqueW::Dsj(){
	add_test("dsjc250.5.clq");
	add_test("dsjc500.1.clq");				
	add_test("dsjc500.5.clq");	
//	add_test("dsjc500.9.clq");	
	add_test("dsjc1000.1.clq");	
	add_test("dsjc1000.5.clq");
//	add_test("dsjc1000.9.clq");  

}
void BkCliqueW::C(){
	add_test("C125.9.clq");	
	add_test("C250.9.clq");				
	//add_test("C500.9.clq");	
	//add_test("C1000.9.clq");	
	//add_test("C2000.5.clq");
}
void BkCliqueW::Mann(){
/*	add_test("MANN_a9.clq");			*/	
	add_test("MANN_a27.clq");				/* currently problematic (25/8/17) */		
//	add_test("MANN_a45.clq");
	//add_test("MANN_a81.clq");		
	
}



void BkCliqueW::WinnerDetermination_100(){

	add_test("in101.wclq");
	add_test("in102.wclq");
	add_test("in103.wclq");
	add_test("in104.wclq");
	add_test("in105.wclq");
	add_test("in106.wclq");
	add_test("in107.wclq");
	add_test("in108.wclq");
	add_test("in109.wclq");
	add_test("in110.wclq");
	add_test("in111.wclq");
	add_test("in112.wclq");
	add_test("in113.wclq");
	add_test("in114.wclq");
	add_test("in115.wclq");
	add_test("in116.wclq");
	add_test("in117.wclq");
	add_test("in118.wclq");
	add_test("in119.wclq");
	add_test("in120.wclq");
	add_test("in121.wclq");
	add_test("in122.wclq");
	add_test("in123.wclq");
	add_test("in124.wclq");
	add_test("in125.wclq");
	add_test("in126.wclq");
	add_test("in127.wclq");
	add_test("in128.wclq");
	add_test("in129.wclq");
	add_test("in130.wclq");
	add_test("in131.wclq");
	add_test("in132.wclq");
	add_test("in133.wclq");
	add_test("in134.wclq");
	add_test("in135.wclq");
	add_test("in136.wclq");
	add_test("in137.wclq");
	add_test("in138.wclq");
	add_test("in139.wclq");
	add_test("in140.wclq");
	add_test("in141.wclq");
	add_test("in142.wclq");
	add_test("in143.wclq");
	add_test("in144.wclq");
	add_test("in145.wclq");
	add_test("in146.wclq");
	add_test("in147.wclq");
	add_test("in148.wclq");
	add_test("in149.wclq");
	add_test("in150.wclq");
	add_test("in151.wclq");
	add_test("in152.wclq");
	add_test("in153.wclq");
	add_test("in154.wclq");
	add_test("in155.wclq");
	add_test("in156.wclq");
	add_test("in157.wclq");
	add_test("in158.wclq");
	add_test("in159.wclq");
	add_test("in160.wclq");
	add_test("in161.wclq");
	add_test("in162.wclq");
	add_test("in163.wclq");
	add_test("in164.wclq");
	add_test("in165.wclq");
	add_test("in166.wclq");
	add_test("in167.wclq");
	add_test("in168.wclq");
	add_test("in169.wclq");
	add_test("in170.wclq");
	add_test("in171.wclq");
	add_test("in172.wclq");
	add_test("in173.wclq");
	add_test("in174.wclq");
	add_test("in175.wclq");
	add_test("in176.wclq");
	add_test("in177.wclq");
	add_test("in178.wclq");
	add_test("in179.wclq");
	add_test("in180.wclq");
	add_test("in181.wclq");
	add_test("in182.wclq");
	add_test("in183.wclq");
	add_test("in184.wclq");
	add_test("in185.wclq");
	add_test("in186.wclq");
	add_test("in187.wclq");
	add_test("in188.wclq");
	add_test("in189.wclq");
	add_test("in190.wclq");
	add_test("in191.wclq");
	add_test("in192.wclq");
	add_test("in193.wclq");
	add_test("in194.wclq");
	add_test("in195.wclq");
	add_test("in196.wclq");
	add_test("in197.wclq");
	add_test("in198.wclq");
	add_test("in199.wclq");
	add_test("in200.wclq");
}

void BkCliqueW::WinnerDetermination_200(){

	add_test("in201.wclq");
	add_test("in202.wclq");
	add_test("in203.wclq");
	add_test("in204.wclq");
	add_test("in205.wclq");
	add_test("in206.wclq");
	add_test("in207.wclq");
	add_test("in208.wclq");
	add_test("in209.wclq");
	add_test("in210.wclq");
	add_test("in211.wclq");
	add_test("in212.wclq");
	add_test("in213.wclq");
	add_test("in214.wclq");
	add_test("in215.wclq");
	add_test("in216.wclq");
	add_test("in217.wclq");
	add_test("in218.wclq");
	add_test("in219.wclq");
	add_test("in220.wclq");
	add_test("in221.wclq");
	add_test("in222.wclq");
	add_test("in223.wclq");
	add_test("in224.wclq");
	add_test("in225.wclq");
	add_test("in226.wclq");
	add_test("in227.wclq");
	add_test("in228.wclq");
	add_test("in229.wclq");
	add_test("in230.wclq");
	add_test("in231.wclq");
	add_test("in232.wclq");
	add_test("in233.wclq");
	add_test("in234.wclq");
	add_test("in235.wclq");
	add_test("in236.wclq");
	add_test("in237.wclq");
	add_test("in238.wclq");
	add_test("in239.wclq");
	add_test("in240.wclq");
	add_test("in241.wclq");
	add_test("in242.wclq");
	add_test("in243.wclq");
	add_test("in244.wclq");
	add_test("in245.wclq");
	add_test("in246.wclq");
	add_test("in247.wclq");
	add_test("in248.wclq");
	add_test("in249.wclq");
	add_test("in250.wclq");
	add_test("in251.wclq");
	add_test("in252.wclq");
	add_test("in253.wclq");
	add_test("in254.wclq");
	add_test("in255.wclq");
	add_test("in256.wclq");
	add_test("in257.wclq");
	add_test("in258.wclq");
	add_test("in259.wclq");
	add_test("in260.wclq");
	add_test("in261.wclq");
	add_test("in262.wclq");
	add_test("in263.wclq");
	add_test("in264.wclq");
	add_test("in265.wclq");
	add_test("in266.wclq");
	add_test("in267.wclq");
	add_test("in268.wclq");
	add_test("in269.wclq");
	add_test("in270.wclq");
	add_test("in271.wclq");
	add_test("in272.wclq");
	add_test("in273.wclq");
	add_test("in274.wclq");
	add_test("in275.wclq");
	add_test("in276.wclq");
	add_test("in277.wclq");
	add_test("in278.wclq");
	add_test("in279.wclq");
	add_test("in280.wclq");
	add_test("in281.wclq");
	add_test("in282.wclq");
	add_test("in283.wclq");
	add_test("in284.wclq");
	add_test("in285.wclq");
	add_test("in286.wclq");
	add_test("in287.wclq");
	add_test("in288.wclq");
	add_test("in289.wclq");
	add_test("in290.wclq");
	add_test("in291.wclq");
	add_test("in292.wclq");
	add_test("in293.wclq");
	add_test("in294.wclq");
	add_test("in295.wclq");
	add_test("in296.wclq");
	add_test("in297.wclq");
	add_test("in298.wclq");
	add_test("in299.wclq");
	add_test("in300.wclq");

}

void BkCliqueW::WinnerDetermination_300(){
	add_test("in401.wclq");
	add_test("in402.wclq");
	add_test("in403.wclq");
	add_test("in404.wclq");
	add_test("in405.wclq");
	add_test("in406.wclq");
	add_test("in407.wclq");
	add_test("in408.wclq");
	add_test("in409.wclq");
	add_test("in410.wclq");
	add_test("in411.wclq");
	add_test("in412.wclq");
	add_test("in413.wclq");
	add_test("in414.wclq");
	add_test("in415.wclq");
	add_test("in416.wclq");
	add_test("in417.wclq");
	add_test("in418.wclq");
	add_test("in419.wclq");
	add_test("in420.wclq");
	add_test("in421.wclq");
	add_test("in422.wclq");
	add_test("in423.wclq");
	add_test("in424.wclq");
	add_test("in425.wclq");
	add_test("in426.wclq");
	add_test("in427.wclq");
	add_test("in428.wclq");
	add_test("in429.wclq");
	add_test("in430.wclq");
	add_test("in431.wclq");
	add_test("in432.wclq");
	add_test("in433.wclq");
	add_test("in434.wclq");
	add_test("in435.wclq");
	add_test("in436.wclq");
	add_test("in437.wclq");
	add_test("in438.wclq");
	add_test("in439.wclq");
	add_test("in440.wclq");
	add_test("in441.wclq");
	add_test("in442.wclq");
	add_test("in443.wclq");
	add_test("in444.wclq");
	add_test("in445.wclq");
	add_test("in446.wclq");
	add_test("in447.wclq");
	add_test("in448.wclq");
	add_test("in449.wclq");
	add_test("in450.wclq");
	add_test("in451.wclq");
	add_test("in452.wclq");
	add_test("in453.wclq");
	add_test("in454.wclq");
	add_test("in455.wclq");
	add_test("in456.wclq");
	add_test("in457.wclq");
	add_test("in458.wclq");
	add_test("in459.wclq");
	add_test("in460.wclq");
	add_test("in461.wclq");
	add_test("in462.wclq");
	add_test("in463.wclq");
	add_test("in464.wclq");
	add_test("in465.wclq");
	add_test("in466.wclq");
	add_test("in467.wclq");
	add_test("in468.wclq");
	add_test("in469.wclq");
	add_test("in470.wclq");
	add_test("in471.wclq");
	add_test("in472.wclq");
	add_test("in473.wclq");
	add_test("in474.wclq");
	add_test("in475.wclq");
	add_test("in476.wclq");
	add_test("in477.wclq");
	add_test("in478.wclq");
	add_test("in479.wclq");
	add_test("in480.wclq");
	add_test("in481.wclq");
	add_test("in482.wclq");
	add_test("in483.wclq");
	add_test("in484.wclq");
	add_test("in485.wclq");
	add_test("in486.wclq");
	add_test("in487.wclq");
	add_test("in488.wclq");
	add_test("in489.wclq");
	add_test("in490.wclq");
	add_test("in491.wclq");
	add_test("in492.wclq");
	add_test("in493.wclq");
	add_test("in494.wclq");
	add_test("in495.wclq");
	add_test("in496.wclq");
	add_test("in497.wclq");
	add_test("in498.wclq");
	add_test("in499.wclq");
	add_test("in500.wclq");

}

void BkCliqueW::WinnerDetermination_400(){
////////////////
// To note:only 99 instances!

	add_test("in501.wclq");
	add_test("in502.wclq");
	add_test("in503.wclq");
	add_test("in504.wclq");
	add_test("in505.wclq");
	add_test("in506.wclq");
	add_test("in507.wclq");
	add_test("in508.wclq");
	add_test("in509.wclq");
	add_test("in510.wclq");
	add_test("in511.wclq");
	add_test("in512.wclq");
	add_test("in513.wclq");
	add_test("in514.wclq");
	add_test("in515.wclq");
	add_test("in516.wclq");
	add_test("in517.wclq");
	add_test("in518.wclq");
	add_test("in519.wclq");
	add_test("in520.wclq");
	add_test("in521.wclq");
	add_test("in522.wclq");
	add_test("in523.wclq");
	add_test("in524.wclq");
	add_test("in525.wclq");
	add_test("in526.wclq");
	add_test("in527.wclq");
	add_test("in528.wclq");
	add_test("in529.wclq");
	add_test("in530.wclq");
	add_test("in531.wclq");
	add_test("in532.wclq");
	add_test("in533.wclq");
	add_test("in534.wclq");
	add_test("in535.wclq");
	add_test("in536.wclq");
	add_test("in537.wclq");
	add_test("in538.wclq");
	add_test("in539.wclq");
	add_test("in540.wclq");
	add_test("in541.wclq");
	add_test("in542.wclq");
	add_test("in543.wclq");
	add_test("in544.wclq");
	add_test("in545.wclq");
	add_test("in546.wclq");
	add_test("in547.wclq");
	add_test("in548.wclq");
	add_test("in549.wclq");
	add_test("in550.wclq");
	add_test("in551.wclq");
	add_test("in552.wclq");
	add_test("in553.wclq");
	add_test("in554.wclq");
	add_test("in555.wclq");
	add_test("in556.wclq");
	add_test("in557.wclq");
	add_test("in558.wclq");
	add_test("in559.wclq");
	add_test("in560.wclq");
	add_test("in561.wclq");
	add_test("in562.wclq");
	add_test("in563.wclq");
	add_test("in564.wclq");
	add_test("in565.wclq");
	add_test("in566.wclq");
	add_test("in567.wclq");
	add_test("in568.wclq");
	add_test("in569.wclq");
	add_test("in570.wclq");
	add_test("in571.wclq");
	add_test("in572.wclq");
	add_test("in573.wclq");
	add_test("in574.wclq");
	add_test("in575.wclq");
	add_test("in576.wclq");
	add_test("in577.wclq");
	add_test("in578.wclq");
	add_test("in579.wclq");
	add_test("in580.wclq");
	add_test("in581.wclq");
	add_test("in582.wclq");
	add_test("in583.wclq");
	add_test("in584.wclq");
	add_test("in585.wclq");
	add_test("in586.wclq");
	add_test("in587.wclq");
	add_test("in588.wclq");
	add_test("in589.wclq");
	add_test("in590.wclq");
	add_test("in591.wclq");
	add_test("in592.wclq");
	add_test("in593.wclq");
	add_test("in594.wclq");
	add_test("in595.wclq");
	add_test("in596.wclq");
	add_test("in597.wclq");
	add_test("in598.wclq");
	add_test("in599.wclq");
//	add_test("in600.wclq");				/* NOT PROVIDED */

}

void BkCliqueW::WinnerDetermination_500(){
	add_test("in601.wclq");
	add_test("in602.wclq");
	add_test("in603.wclq");
	add_test("in604.wclq");
	add_test("in605.wclq");
	add_test("in606.wclq");
	add_test("in607.wclq");
	add_test("in608.wclq");
	add_test("in609.wclq");
	add_test("in610.wclq");
	add_test("in611.wclq");
	add_test("in612.wclq");
	add_test("in613.wclq");
	add_test("in614.wclq");
	add_test("in615.wclq");
	add_test("in616.wclq");
	add_test("in617.wclq");
	add_test("in618.wclq");
	add_test("in619.wclq");
	add_test("in620.wclq");
	add_test("in621.wclq");
	add_test("in622.wclq");
	add_test("in623.wclq");
	add_test("in624.wclq");
	add_test("in625.wclq");
	add_test("in626.wclq");
	add_test("in627.wclq");
	add_test("in628.wclq");
	add_test("in629.wclq");
	add_test("in630.wclq");
	add_test("in631.wclq");
	add_test("in632.wclq");
	add_test("in633.wclq");
	add_test("in634.wclq");
	add_test("in635.wclq");
	add_test("in636.wclq");
	add_test("in637.wclq");
	add_test("in638.wclq");
	add_test("in639.wclq");
	add_test("in640.wclq");
	add_test("in641.wclq");
	add_test("in642.wclq");
	add_test("in643.wclq");
	add_test("in644.wclq");
	add_test("in645.wclq");
	add_test("in646.wclq");
	add_test("in647.wclq");
	add_test("in648.wclq");
	add_test("in649.wclq");
	add_test("in650.wclq");
	add_test("in651.wclq");
	add_test("in652.wclq");
	add_test("in653.wclq");
	add_test("in654.wclq");
	add_test("in655.wclq");
	add_test("in656.wclq");
	add_test("in657.wclq");
	add_test("in658.wclq");
	add_test("in659.wclq");
	add_test("in660.wclq");
	add_test("in661.wclq");
	add_test("in662.wclq");
	add_test("in663.wclq");
	add_test("in664.wclq");
	add_test("in665.wclq");
	add_test("in666.wclq");
	add_test("in667.wclq");
	add_test("in668.wclq");
	add_test("in669.wclq");
	add_test("in670.wclq");
	add_test("in671.wclq");
	add_test("in672.wclq");
	add_test("in673.wclq");
	add_test("in674.wclq");
	add_test("in675.wclq");
	add_test("in676.wclq");
	add_test("in677.wclq");
	add_test("in678.wclq");
	add_test("in679.wclq");
	add_test("in680.wclq");
	add_test("in681.wclq");
	add_test("in682.wclq");
	add_test("in683.wclq");
	add_test("in684.wclq");
	add_test("in685.wclq");
	add_test("in686.wclq");
	add_test("in687.wclq");
	add_test("in688.wclq");
	add_test("in689.wclq");
	add_test("in690.wclq");
	add_test("in691.wclq");
	add_test("in692.wclq");
	add_test("in693.wclq");
	add_test("in694.wclq");
	add_test("in695.wclq");
	add_test("in696.wclq");
	add_test("in697.wclq");
	add_test("in698.wclq");
	add_test("in699.wclq");
	add_test("in700.wclq");
}


void BkCliqueW::WinnerDetermination_All(){
	add_test("in101.wclq");
	add_test("in102.wclq");
	add_test("in103.wclq");
	add_test("in104.wclq");
	add_test("in105.wclq");
	add_test("in106.wclq");
	add_test("in107.wclq");
	add_test("in108.wclq");
	add_test("in109.wclq");
	add_test("in110.wclq");
	add_test("in111.wclq");
	add_test("in112.wclq");
	add_test("in113.wclq");
	add_test("in114.wclq");
	add_test("in115.wclq");
	add_test("in116.wclq");
	add_test("in117.wclq");
	add_test("in118.wclq");
	add_test("in119.wclq");
	add_test("in120.wclq");
	add_test("in121.wclq");
	add_test("in122.wclq");
	add_test("in123.wclq");
	add_test("in124.wclq");
	add_test("in125.wclq");
	add_test("in126.wclq");
	add_test("in127.wclq");
	add_test("in128.wclq");
	add_test("in129.wclq");
	add_test("in130.wclq");
	add_test("in131.wclq");
	add_test("in132.wclq");
	add_test("in133.wclq");
	add_test("in134.wclq");
	add_test("in135.wclq");
	add_test("in136.wclq");
	add_test("in137.wclq");
	add_test("in138.wclq");
	add_test("in139.wclq");
	add_test("in140.wclq");
	add_test("in141.wclq");
	add_test("in142.wclq");
	add_test("in143.wclq");
	add_test("in144.wclq");
	add_test("in145.wclq");
	add_test("in146.wclq");
	add_test("in147.wclq");
	add_test("in148.wclq");
	add_test("in149.wclq");
	add_test("in150.wclq");
	add_test("in151.wclq");
	add_test("in152.wclq");
	add_test("in153.wclq");
	add_test("in154.wclq");
	add_test("in155.wclq");
	add_test("in156.wclq");
	add_test("in157.wclq");
	add_test("in158.wclq");
	add_test("in159.wclq");
	add_test("in160.wclq");
	add_test("in161.wclq");
	add_test("in162.wclq");
	add_test("in163.wclq");
	add_test("in164.wclq");
	add_test("in165.wclq");
	add_test("in166.wclq");
	add_test("in167.wclq");
	add_test("in168.wclq");
	add_test("in169.wclq");
	add_test("in170.wclq");
	add_test("in171.wclq");
	add_test("in172.wclq");
	add_test("in173.wclq");
	add_test("in174.wclq");
	add_test("in175.wclq");
	add_test("in176.wclq");
	add_test("in177.wclq");
	add_test("in178.wclq");
	add_test("in179.wclq");
	add_test("in180.wclq");
	add_test("in181.wclq");
	add_test("in182.wclq");
	add_test("in183.wclq");
	add_test("in184.wclq");
	add_test("in185.wclq");
	add_test("in186.wclq");
	add_test("in187.wclq");
	add_test("in188.wclq");
	add_test("in189.wclq");
	add_test("in190.wclq");
	add_test("in191.wclq");
	add_test("in192.wclq");
	add_test("in193.wclq");
	add_test("in194.wclq");
	add_test("in195.wclq");
	add_test("in196.wclq");
	add_test("in197.wclq");
	add_test("in198.wclq");
	add_test("in199.wclq");
	add_test("in200.wclq");

	add_test("in201.wclq");
	add_test("in202.wclq");
	add_test("in203.wclq");
	add_test("in204.wclq");
	add_test("in205.wclq");
	add_test("in206.wclq");
	add_test("in207.wclq");
	add_test("in208.wclq");
	add_test("in209.wclq");
	add_test("in210.wclq");
	add_test("in211.wclq");
	add_test("in212.wclq");
	add_test("in213.wclq");
	add_test("in214.wclq");
	add_test("in215.wclq");
	add_test("in216.wclq");
	add_test("in217.wclq");
	add_test("in218.wclq");
	add_test("in219.wclq");
	add_test("in220.wclq");
	add_test("in221.wclq");
	add_test("in222.wclq");
	add_test("in223.wclq");
	add_test("in224.wclq");
	add_test("in225.wclq");
	add_test("in226.wclq");
	add_test("in227.wclq");
	add_test("in228.wclq");
	add_test("in229.wclq");
	add_test("in230.wclq");
	add_test("in231.wclq");
	add_test("in232.wclq");
	add_test("in233.wclq");
	add_test("in234.wclq");
	add_test("in235.wclq");
	add_test("in236.wclq");
	add_test("in237.wclq");
	add_test("in238.wclq");
	add_test("in239.wclq");
	add_test("in240.wclq");
	add_test("in241.wclq");
	add_test("in242.wclq");
	add_test("in243.wclq");
	add_test("in244.wclq");
	add_test("in245.wclq");
	add_test("in246.wclq");
	add_test("in247.wclq");
	add_test("in248.wclq");
	add_test("in249.wclq");
	add_test("in250.wclq");
	add_test("in251.wclq");
	add_test("in252.wclq");
	add_test("in253.wclq");
	add_test("in254.wclq");
	add_test("in255.wclq");
	add_test("in256.wclq");
	add_test("in257.wclq");
	add_test("in258.wclq");
	add_test("in259.wclq");
	add_test("in260.wclq");
	add_test("in261.wclq");
	add_test("in262.wclq");
	add_test("in263.wclq");
	add_test("in264.wclq");
	add_test("in265.wclq");
	add_test("in266.wclq");
	add_test("in267.wclq");
	add_test("in268.wclq");
	add_test("in269.wclq");
	add_test("in270.wclq");
	add_test("in271.wclq");
	add_test("in272.wclq");
	add_test("in273.wclq");
	add_test("in274.wclq");
	add_test("in275.wclq");
	add_test("in276.wclq");
	add_test("in277.wclq");
	add_test("in278.wclq");
	add_test("in279.wclq");
	add_test("in280.wclq");
	add_test("in281.wclq");
	add_test("in282.wclq");
	add_test("in283.wclq");
	add_test("in284.wclq");
	add_test("in285.wclq");
	add_test("in286.wclq");
	add_test("in287.wclq");
	add_test("in288.wclq");
	add_test("in289.wclq");
	add_test("in290.wclq");
	add_test("in291.wclq");
	add_test("in292.wclq");
	add_test("in293.wclq");
	add_test("in294.wclq");
	add_test("in295.wclq");
	add_test("in296.wclq");
	add_test("in297.wclq");
	add_test("in298.wclq");
	add_test("in299.wclq");
	add_test("in300.wclq");

	add_test("in401.wclq");
	add_test("in402.wclq");
	add_test("in403.wclq");
	add_test("in404.wclq");
	add_test("in405.wclq");
	add_test("in406.wclq");
	add_test("in407.wclq");
	add_test("in408.wclq");
	add_test("in409.wclq");
	add_test("in410.wclq");
	add_test("in411.wclq");
	add_test("in412.wclq");
	add_test("in413.wclq");
	add_test("in414.wclq");
	add_test("in415.wclq");
	add_test("in416.wclq");
	add_test("in417.wclq");
	add_test("in418.wclq");
	add_test("in419.wclq");
	add_test("in420.wclq");
	add_test("in421.wclq");
	add_test("in422.wclq");
	add_test("in423.wclq");
	add_test("in424.wclq");
	add_test("in425.wclq");
	add_test("in426.wclq");
	add_test("in427.wclq");
	add_test("in428.wclq");
	add_test("in429.wclq");
	add_test("in430.wclq");
	add_test("in431.wclq");
	add_test("in432.wclq");
	add_test("in433.wclq");
	add_test("in434.wclq");
	add_test("in435.wclq");
	add_test("in436.wclq");
	add_test("in437.wclq");
	add_test("in438.wclq");
	add_test("in439.wclq");
	add_test("in440.wclq");
	add_test("in441.wclq");
	add_test("in442.wclq");
	add_test("in443.wclq");
	add_test("in444.wclq");
	add_test("in445.wclq");
	add_test("in446.wclq");
	add_test("in447.wclq");
	add_test("in448.wclq");
	add_test("in449.wclq");
	add_test("in450.wclq");
	add_test("in451.wclq");
	add_test("in452.wclq");
	add_test("in453.wclq");
	add_test("in454.wclq");
	add_test("in455.wclq");
	add_test("in456.wclq");
	add_test("in457.wclq");
	add_test("in458.wclq");
	add_test("in459.wclq");
	add_test("in460.wclq");
	add_test("in461.wclq");
	add_test("in462.wclq");
	add_test("in463.wclq");
	add_test("in464.wclq");
	add_test("in465.wclq");
	add_test("in466.wclq");
	add_test("in467.wclq");
	add_test("in468.wclq");
	add_test("in469.wclq");
	add_test("in470.wclq");
	add_test("in471.wclq");
	add_test("in472.wclq");
	add_test("in473.wclq");
	add_test("in474.wclq");
	add_test("in475.wclq");
	add_test("in476.wclq");
	add_test("in477.wclq");
	add_test("in478.wclq");
	add_test("in479.wclq");
	add_test("in480.wclq");
	add_test("in481.wclq");
	add_test("in482.wclq");
	add_test("in483.wclq");
	add_test("in484.wclq");
	add_test("in485.wclq");
	add_test("in486.wclq");
	add_test("in487.wclq");
	add_test("in488.wclq");
	add_test("in489.wclq");
	add_test("in490.wclq");
	add_test("in491.wclq");
	add_test("in492.wclq");
	add_test("in493.wclq");
	add_test("in494.wclq");
	add_test("in495.wclq");
	add_test("in496.wclq");
	add_test("in497.wclq");
	add_test("in498.wclq");
	add_test("in499.wclq");
	add_test("in500.wclq");

	add_test("in501.wclq");
	add_test("in502.wclq");
	add_test("in503.wclq");
	add_test("in504.wclq");
	add_test("in505.wclq");
	add_test("in506.wclq");
	add_test("in507.wclq");
	add_test("in508.wclq");
	add_test("in509.wclq");
	add_test("in510.wclq");
	add_test("in511.wclq");
	add_test("in512.wclq");
	add_test("in513.wclq");
	add_test("in514.wclq");
	add_test("in515.wclq");
	add_test("in516.wclq");
	add_test("in517.wclq");
	add_test("in518.wclq");
	add_test("in519.wclq");
	add_test("in520.wclq");
	add_test("in521.wclq");
	add_test("in522.wclq");
	add_test("in523.wclq");
	add_test("in524.wclq");
	add_test("in525.wclq");
	add_test("in526.wclq");
	add_test("in527.wclq");
	add_test("in528.wclq");
	add_test("in529.wclq");
	add_test("in530.wclq");
	add_test("in531.wclq");
	add_test("in532.wclq");
	add_test("in533.wclq");
	add_test("in534.wclq");
	add_test("in535.wclq");
	add_test("in536.wclq");
	add_test("in537.wclq");
	add_test("in538.wclq");
	add_test("in539.wclq");
	add_test("in540.wclq");
	add_test("in541.wclq");
	add_test("in542.wclq");
	add_test("in543.wclq");
	add_test("in544.wclq");
	add_test("in545.wclq");
	add_test("in546.wclq");
	add_test("in547.wclq");
	add_test("in548.wclq");
	add_test("in549.wclq");
	add_test("in550.wclq");
	add_test("in551.wclq");
	add_test("in552.wclq");
	add_test("in553.wclq");
	add_test("in554.wclq");
	add_test("in555.wclq");
	add_test("in556.wclq");
	add_test("in557.wclq");
	add_test("in558.wclq");
	add_test("in559.wclq");
	add_test("in560.wclq");
	add_test("in561.wclq");
	add_test("in562.wclq");
	add_test("in563.wclq");
	add_test("in564.wclq");
	add_test("in565.wclq");
	add_test("in566.wclq");
	add_test("in567.wclq");
	add_test("in568.wclq");
	add_test("in569.wclq");
	add_test("in570.wclq");
	add_test("in571.wclq");
	add_test("in572.wclq");
	add_test("in573.wclq");
	add_test("in574.wclq");
	add_test("in575.wclq");
	add_test("in576.wclq");
	add_test("in577.wclq");
	add_test("in578.wclq");
	add_test("in579.wclq");
	add_test("in580.wclq");
	add_test("in581.wclq");
	add_test("in582.wclq");
	add_test("in583.wclq");
	add_test("in584.wclq");
	add_test("in585.wclq");
	add_test("in586.wclq");
	add_test("in587.wclq");
	add_test("in588.wclq");
	add_test("in589.wclq");
	add_test("in590.wclq");
	add_test("in591.wclq");
	add_test("in592.wclq");
	add_test("in593.wclq");
	add_test("in594.wclq");
	add_test("in595.wclq");
	add_test("in596.wclq");
	add_test("in597.wclq");
	add_test("in598.wclq");
	add_test("in599.wclq");

	add_test("in601.wclq");
	add_test("in602.wclq");
	add_test("in603.wclq");
	add_test("in604.wclq");
	add_test("in605.wclq");
	add_test("in606.wclq");
	add_test("in607.wclq");
	add_test("in608.wclq");
	add_test("in609.wclq");
	add_test("in610.wclq");
	add_test("in611.wclq");
	add_test("in612.wclq");
	add_test("in613.wclq");
	add_test("in614.wclq");
	add_test("in615.wclq");
	add_test("in616.wclq");
	add_test("in617.wclq");
	add_test("in618.wclq");
	add_test("in619.wclq");
	add_test("in620.wclq");
	add_test("in621.wclq");
	add_test("in622.wclq");
	add_test("in623.wclq");
	add_test("in624.wclq");
	add_test("in625.wclq");
	add_test("in626.wclq");
	add_test("in627.wclq");
	add_test("in628.wclq");
	add_test("in629.wclq");
	add_test("in630.wclq");
	add_test("in631.wclq");
	add_test("in632.wclq");
	add_test("in633.wclq");
	add_test("in634.wclq");
	add_test("in635.wclq");
	add_test("in636.wclq");
	add_test("in637.wclq");
	add_test("in638.wclq");
	add_test("in639.wclq");
	add_test("in640.wclq");
	add_test("in641.wclq");
	add_test("in642.wclq");
	add_test("in643.wclq");
	add_test("in644.wclq");
	add_test("in645.wclq");
	add_test("in646.wclq");
	add_test("in647.wclq");
	add_test("in648.wclq");
	add_test("in649.wclq");
	add_test("in650.wclq");
	add_test("in651.wclq");
	add_test("in652.wclq");
	add_test("in653.wclq");
	add_test("in654.wclq");
	add_test("in655.wclq");
	add_test("in656.wclq");
	add_test("in657.wclq");
	add_test("in658.wclq");
	add_test("in659.wclq");
	add_test("in660.wclq");
	add_test("in661.wclq");
	add_test("in662.wclq");
	add_test("in663.wclq");
	add_test("in664.wclq");
	add_test("in665.wclq");
	add_test("in666.wclq");
	add_test("in667.wclq");
	add_test("in668.wclq");
	add_test("in669.wclq");
	add_test("in670.wclq");
	add_test("in671.wclq");
	add_test("in672.wclq");
	add_test("in673.wclq");
	add_test("in674.wclq");
	add_test("in675.wclq");
	add_test("in676.wclq");
	add_test("in677.wclq");
	add_test("in678.wclq");
	add_test("in679.wclq");
	add_test("in680.wclq");
	add_test("in681.wclq");
	add_test("in682.wclq");
	add_test("in683.wclq");
	add_test("in684.wclq");
	add_test("in685.wclq");
	add_test("in686.wclq");
	add_test("in687.wclq");
	add_test("in688.wclq");
	add_test("in689.wclq");
	add_test("in690.wclq");
	add_test("in691.wclq");
	add_test("in692.wclq");
	add_test("in693.wclq");
	add_test("in694.wclq");
	add_test("in695.wclq");
	add_test("in696.wclq");
	add_test("in697.wclq");
	add_test("in698.wclq");
	add_test("in699.wclq");
	add_test("in700.wclq");

}
