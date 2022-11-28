#include "OpenChallenge.h"

Morse::Morse() {
	string alpha[26] = {".-", "-...", "-.-.", "-..", ".","..-.", "--.", "....", "..", ".---","-.-", ".-..", "--", "-.", "---",".--.", "--.-", ".-.", "...", "-","..-", "...-", ".--", "-..-", "-.--", "--.." };
	string digital[10] = {"-----", ".----", "..---", "...--", "....-",".....", "-....", "--...", "---..", "----."};
	
	for (unsigned short i = 0; i < 26; i++) this->alphabet[i] = alpha[i]; // this->alphabet �ʱ�ȭ
	for (unsigned short i = 0; i < 10; i++) this->digit[i] = digital[i]; // this->tigit �ʱ�ȭ
	
	this->slash = "-..-.";
	this->question = "..--..";
	this->comma = "--..--";
	this->period = ".-.-.-";
	this->plus = ".-.-.";
	this->equal = "-...-";
}

void Morse::text2Morse(string text, string& morse) {
	
	morse = "";

	char temp;

	for (unsigned short i = 0; i < text.length(); i++) {
		temp = text.at(i);

		if (isalpha(temp)) {
			if (temp > 'A') temp=tolower(temp); // �빮�ڽ� �ҹ���ȭ

			morse += this->alphabet[temp-'a'] + " ";
		}
		else if (isdigit(temp)) morse += this->digit[(int)temp - 48] + " ";
		else if (temp == ' ') morse += "  ";
		else if (temp == '/') morse += slash + " ";
		else if (temp == '?') morse += question + " ";
		else if (temp == ',') morse += comma + " ";
		else if (temp == '.') morse += period + " ";
		else if (temp == '+') morse += plus + " ";
		else if (temp == '=') morse += equal + " ";
	}
}

bool Morse::morse2Text(string morse, string& text) {
	string retext = "";
	string substr;

	unsigned short index = 0;
	unsigned short findex=1;

	do {
		findex = morse.find(" ",index); // (string)morse �� ������ �ε��� �� == findex
		substr = morse.substr(index, findex-index);

		
		for (unsigned short i = 0; i < 26; i++) { // ���ĺ� �� ��ȣ�Ͻ�
			if (substr.compare(this->alphabet[i]) == 0) {
				retext += i + 'a';
				break;
			}
		}

		for (unsigned short i = 0; i < 10; i++) { // ���� �� ��ȣ�Ͻ�
			if (substr.compare(this->digit[i]) == 0) {
				retext += i + '0';
				break;
			}
		}

		if (substr.compare(this->slash) == 0) retext += "/";
		else if (substr.compare(this->question) == 0) retext += "?";
		else if (substr.compare(this->comma) == 0) retext += ",";
		else if (substr.compare(this->period) == 0) retext += ".";
		else if (substr.compare(this->plus) == 0) retext += "+";
		else if (substr.compare(this->equal) == 0) retext += "=";


		if (findex == morse.length() - 1) break; // ���� ��ġ�� �ش� break ���ǹ� ������, ERR (�ǹ�


		if (morse.at(findex) == ' ' && morse.at(findex + 1) == ' ' && morse.at(findex + 2) == ' ') {
			retext += " ";
			index = findex + 1;
		}

		index = findex+1;
	} while (1);


	if (retext.compare(text) == 0) return 1;
	else return 0;
}