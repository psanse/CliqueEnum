//logger.h: a light logger class (no timestamps, no file configuration, no multiple IDs)
//last update: 24/02/15

#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

enum {LOGGER_ERROR=0,LOGGER_WARNING,LOGGER_INFO,LOGGER_PRINT, LOGGER_DEBUG};

//complete log level
#define LOG_ERROR(msg)		Logger(LOGGER_ERROR).Log()<<msg
#define LOG_WARNING(msg)	Logger(LOGGER_WARNING).Log()<<msg
#define LOG_INFO(msg)		Logger(LOGGER_INFO).Log()<<msg
#define LOG_PRINT(msg)		Logger(LOGGER_PRINT).Log()<<msg
#define LOG_DEBUG(msg)		Logger(LOGGER_DEBUG).Log()<<msg

class Logger {
public:
	Logger(int type); 
	virtual ~Logger();

	ostringstream& Log(){return os;}

	//redirects std::cout to ofstream. 
	static void SetFileStream(std::string filename="");
	//duplicates output to ostringstream
	static void SetStringStream(bool set=true){use_string_stream=set;}
	static void SetInformationLevel(int type=LOGGER_PRINT)	{predefined_type=type;}

	static std::string GetString(){
		string str=string_stream.str();
		string_stream.str("");
		return str;
	}
private:
	int set_type;								//type of the current log
		
protected:
	ostringstream os;
	static ofstream file;
	static ostringstream string_stream;
	static bool use_string_stream;
	static int predefined_type;					//configured type for the Logger pattern

};

#endif 

