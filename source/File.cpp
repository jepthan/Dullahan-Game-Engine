#include "File.h"

JPH::File::File()
{
	this->filename = NULL;
	this->filedata = nullptr;
	this->lasterror = nullptr;
}

JPH::File::File(const char* _filename)
{
	this->filename = _filename;
	this->filedata = nullptr;
	this->lasterror = nullptr;
}

JPH::File::~File()
{

}

bool JPH::File::readFile()
{
	if (filename == NULL) {
		this->lasterror = "File name / dir not set";
		return false;
	}

	std::ifstream fl(filename);
	bool result = false;
	if (fl.is_open()) {
		std::string line;
		while (std::getline(fl, line)) {
			this->filedata.append(line);
			this->filedata.append("\n");
		}
		fl.close();
		result = true;
	}
	else {
		this->lasterror = "could not open the file";
		
	}


	return result;

}

void JPH::File::setfilename(const char* _filename)
{
	this->filename = _filename;
}

std::string JPH::File::getfiledata()
{
	return this->filedata;
}

std::string JPH::File::getlasterror()
{
	return this->lasterror;
}

