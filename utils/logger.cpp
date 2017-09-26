// logger.cpp: implementation of the Loggerclass.
//////////////////////////////////////////////////////////////////////

#include "logger.h" 
#include <algorithm>
#include <iostream>
#include <fstream>

#ifdef _WIN32
	#include <windows.h>
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ofstream Logger::file;
ostringstream Logger::string_stream;
bool Logger::use_string_stream=false;
int Logger::predefined_type=LOGGER_INFO;

Logger::Logger(int type)
{	

	set_type=type;
	#ifdef _WIN32
		HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if(type==LOGGER_ERROR)
		{		
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
		}
		if(type==LOGGER_WARNING)
		{		
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		}
		if(type==LOGGER_INFO)
		{		
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN| FOREGROUND_INTENSITY );
		}

		if(type==LOGGER_PRINT)
		{		
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
			//default=WHITE
		}

		//debug only in debug level
		if(type==LOGGER_DEBUG )//WHITE (default)
		{		
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED |  FOREGROUND_INTENSITY );
		}

	#elif __GNUC__
		std::string color;
		if(type==LOGGER_ERROR)//RED
		{		
			color = "\e[1;31m"; 
		}
		if(type==LOGGER_WARNING)//GREEN
		{	
			color = "\e[1;35m"; 	
		}
		if(type==LOGGER_INFO)//MAGENTA
		{		
			color = "\e[1;32m"; 
		}
		if(type==LOGGER_PRINT)//CYAN
		{		
			color = "\e[1;36m"; 	
		}
		os<<color;
	#endif
}

Logger::~Logger(){	
	
	//logic of log levels
	if(set_type<=predefined_type){	
		if(file.is_open()){
			file<<os.str()<<endl;
		}else{
			cout<<os.str()<<endl;			
		}

		if(use_string_stream)
			string_stream<<os.str()<<std::endl;
	}
		
	//reset color fonts to normal text
	#ifdef _WIN32
		HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN);
	#elif __GNUC__
		os<<"\e[0m";
	#endif

	//closes file
	if(file.is_open())
			file.close();

}
void Logger::SetFileStream(std::string filename){
	
	//close previous log file
	if(file.is_open() || filename.empty() ){
			file.close();
	}
	
	//opens new file
	file.open(filename.c_str());
	if(!file.is_open())
		cerr<<"could not open logger file: "<<filename<<endl;
	

}

