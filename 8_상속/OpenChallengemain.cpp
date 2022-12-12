// ������ ���� ��� ���踦 ���� Product, Book, CompactDisk, ConversationBook Ŭ������ �ۼ��ϰ� �Ʒ� ���� ȭ��� ���� ��ǰ�� �����ϴ� ���α׷��� �ۼ��϶�.
// Product ���������� ��ǰ�� �ĺ���(id), ��ǰ ����, ������, ������ ��Ÿ���� ������ �����Ѵ�.
// Book Ŭ������ ISBN ��ȣ, ����, å ���� ������ �����Ѵ�.
// CompactDisc Ŭ������ �ٹ� ����, ���� �̸� ������ �����Ѵ�.
// ConversationBook�� ȸȭ å���� �ٷ�� ��� �� ������ �����Ѵ�.
// ��ü ���� ���信 �����ϵ��� ������ ���� ������, ��� ���� �� �Լ�, ������ ���� �ۼ��϶�.
// main()������  �ִ� 100���� ��ǰ�� �����ϸ�, ��� ��ǰ�� ������ ��ȸ�� �� �ִ�.
// ��ǰ�� �ĺ��ڴ� ����� �� �ڵ����� ���δ�.

#include "OpenChallenge.h"

static unsigned short id = 0;

int main() {
	unsigned short sel;
	Product* p[100]; // �ִ� 100���� ��ǰ	
	
	cout << "***** ��ǰ ���� ���α׷��� �۵��մϴ� *****" << endl;

	while (1) {
		cout << endl << "��ǰ �߰�(1), ��� ��ǰ ��ȸ(2), ������(3) ? ";

		cin >> sel;

		if (sel == 1) {
			cout << "��ǰ ���� å(1), ����CD(2), ȸȭå(3) ?";

			unsigned short sell;
			cin >> sell;
			cin.ignore(); // �Է� ���� �������� ��

			switch (sell) {
			case 1:
			case 3: { // å(1), ȸȭå(3)
				cout << "��ǰ����>>";
				string p_expl;
				getline(cin, p_expl);

				cout << "������>>";
				string p_maker;
				getline(cin, p_maker);

				cout << "����>>";
				unsigned short p_price;
				cin >> p_price;
				cin.ignore(); // �Է� ���� �������� ��

				cout << "å����>>";
				string b_title;
				getline(cin, b_title);

				cout << "����>>";
				string b_author;
				getline(cin, b_author);

				if (sell == 3) {
					cout << "���>>";
					string b_len;
					getline(cin, b_len);

					cout << "ISBN>>";
					unsigned short b_ISBN;
					cin >> b_ISBN;

					ConversationBook* cb = new ConversationBook(p_expl, p_maker, p_price, b_title, b_author, b_ISBN, b_len);
					p[id++] = cb; // �� ĳ����
					break;
				}

				cout << "ISBN>>";
				unsigned short b_ISBN;
				cin >> b_ISBN;
								

				Book *b = new Book(p_expl, p_maker, p_price, b_title, b_author, b_ISBN);
				p[id++] = b; // �� ĳ����

				break;
			}
			case 2: { // ����CD(2)
				cout << "��ǰ����>>";
				string p_expl;
				getline(cin, p_expl);

				cout << "������>>";
				string p_maker;
				getline(cin, p_maker);

				cout << "����>>";
				unsigned short p_price;
				cin >> p_price;
				cin.ignore(); // �Է� ���� �������� ��

				cout << "�ٹ�����>>";
				string s_title;
				getline(cin, s_title);

				cout << "����>>";
				string s_author;
				getline(cin, s_author);

				CompactDisc *c = new CompactDisc(p_expl, p_maker, p_price, s_title, s_author);
				p[id++] = c; // �� ĳ����
				break;
			}
			default: {				
				break;
			} // default end				
			} // switch end
		} // if end
		else if (sel == 2) { // ��� ��ǰ ��ȸ
			for (unsigned short i = 0; i < id; i++) {
				cout << "--- ��ǰ ID : " << i << endl;
				p[i]->show();
				continue;
			} // for end
		}
		else break;
	} // while end
}