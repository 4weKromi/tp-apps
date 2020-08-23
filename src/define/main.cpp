
/*
	https://github.com/4wekromi
*/

#include "TextParse.h"

int help(){
	std::cout<<"\n\t define [option]/[\"your text\"] \n";
	std::cout<<"\n\t --help \t\t displays help page \n";
	std::cout<<"\n\t --version \t displays version \n";
	std::cout<<"\n\t --all \t displays all info \n";
	std::cout<<"\n\n\t Example : define GCC \n";
	std::cout<<"\t\t define \"Text with spaces\" \n\n";
	return 0;
}

int check(std::string tmp){
	//TextParse app("filename.conf"); //userdefined file
	TextParse app("db.dat");
	if(app.loadFile()){
		if(app.dataParse()){
			int len = app.getParseDataSize();
			if(tmp.compare("--help") == 0){
				help();
				return 1;
			}
			else if(tmp.compare("--version") == 0){
				std::cout<<"\n App version 0.1 \n";
				return 1;
			}
			else if(tmp.compare("--all") == 0){
				/* 	O(n) time */
				for(int i = 0;i<len;i++){
					std::cout<<"\n "<<app.getConfigKey(i)<<" : "<<app.getConfigValue(i)<<" \n";
				}
				return 1;
			} else {
				/* 	O(n) time */
				for(int i = 0;i<len;i++){
					if(tmp.compare(app.getConfigKey(i)) == 0){
						std::cout<<"\n "<<app.getConfigValue(i)<<" \n";
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int main(int argc, char **argv){
	if(argc == 2){
		if(check(std::string(argv[1]))){
			//search sucessfull, do nothing :-)
		} else {
			std::cout<<"\n No data found \n";
		}
	} else {
		std::cout<<"\n\t Incorrect syntax !\n\t try define --help \n";
	}
	return 0;
}
