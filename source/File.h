#include <iostream>
#include <fstream>
#include <string>
namespace JPH {
	class File {
	public:
		File();
		//Expects file name / dir of de file
		File(const char* filename);
		virtual ~File();
		//return true if succes needs a valid file name to work
		bool readFile();
		//set file name
		void setfilename(const char* _filename);
		//returns the filedata as a char
		std::string getfiledata();
		//return the last error in read file
		std::string getlasterror();
		
	private:
		const char* filename;
		std::string filedata;
		std::string lasterror;
	};
}