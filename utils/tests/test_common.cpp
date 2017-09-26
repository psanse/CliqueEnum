#include <iostream>
#include <sstream>
#include "gtest/gtest.h"
#include "../common.h"
#include <string>
#include <vector>

using namespace std;
using namespace com;


TEST(Common, path){
	string path_1("c:\\kk");
	string path_2("c:\\kk/");  //a posix slash at the end

	com::dir::append_slash(path_1);
	com::dir::append_slash(path_2);

	string sol1("c:\\kk\\");
	string sol2("c:\\kk/");
#ifdef _MSC_VER
	EXPECT_EQ(sol1, path_1);
	EXPECT_EQ(sol2, path_2);
#elif __GNUC__
	//***

#endif

	cout<<path_1<<endl;
	cout<<path_2<<endl;
}

TEST(Common, collection_equality){
//***FIXME THIS TEST BREAKS
	cout<<"Common:collection_equality-----------------------"<<endl;
	vector<int> v(10, 1);
	EXPECT_TRUE(com::stl::all_equal(v));
	com::stl::print_collection(v);
	
	v.push_back(2);
	EXPECT_FALSE(com::stl::all_equal(v));

	//***FIXME THIS TEST BREAKS
	//empty vector is equal as well 
	//v.swap(vector<int>());
	//EXPECT_TRUE(com::stl::all_equal(v));

	//single element is also equal
	/*v.push_back(1);
	EXPECT_TRUE(com::stl::all_equal(v));*/

	cout<<"-------------------------------------------------"<<endl;
}

TEST(Common, my_stack){
cout<<"Common:my stack-----------------------"<<endl;
	const int N=10;
	stack_t<int> s(N);
	
	EXPECT_EQ(0, s.size());

	s.push(10);
	s.push(20);
	s.push(30);

	EXPECT_EQ(3, s.size());
	EXPECT_EQ(30, s.pop());
	EXPECT_EQ(20, s.pop());
	EXPECT_EQ(10, s.pop());
	EXPECT_EQ(0, s.size());
	EXPECT_TRUE(s.empty());

	s.push(10);
	s.push(20);
	s.push(30);

	cout<<s;

	s.erase();
	EXPECT_TRUE(s.empty());

cout<<"Common:my stack-----------------------"<<endl;

}
