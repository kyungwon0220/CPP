#include "�ǽ�����8.h"

void Trace::put(string tag, string info) {
	Trace::tag[Trace::i] = tag;
	Trace::info[Trace::i++] = info;
}

void Trace::print(string tag) {

	if (tag.compare("��� Trace") == 0) {
		cout << "===== " << tag << " ������ ����մϴ�. ===== " << endl;

		for (unsigned short j = 0; j < Trace::i; j++)
			cout << Trace::tag[j] << ":" << Trace::info[j] << endl;
	}
	else {
		cout << "===== " << tag << " �±��� Trace ������ ����մϴ�. ===== " << endl;

		for (unsigned short j = 0; j < Trace::i; j++) {
			if (tag.compare(Trace::tag[j]) == 0)
				cout << Trace::tag[j] << ":" << Trace::info[j] << endl;
		}
	}
}