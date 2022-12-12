// 다음과 같은 상속 관계를 가진 Product, Book, CompactDisk, ConversationBook 클래스를 작성하고 아래 실행 화면과 같이 상품을 관리하는 프로그램을 작성하라.
// Product ㅋ르래스는 상품의 식별자(id), 상품 설명, 생산자, 가격을 나타내는 정보를 포함한다.
// Book 클래스는 ISBN 번호, 저자, 책 제목 정보를 포함한다.
// CompactDisc 클래스는 앨범 제목, 가수 이름 정보를 포함한다.
// ConversationBook은 회화 책에서 다루는 언어 명 정보를 포함한다.
// 객체 지향 개념에 부합하도록 적절한 접근 지정자, 멤버 변수 및 함수, 생성자 등을 작성하라.
// main()에서는  최대 100개의 상품을 관리하며, 모든 상품의 정보를 조회할 수 있다.
// 상품의 식별자는 등록할 때 자동으로 붙인다.

#include "OpenChallenge.h"

static unsigned short id = 0;

int main() {
	unsigned short sel;
	Product* p[100]; // 최대 100개의 상품	
	
	cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;

	while (1) {
		cout << endl << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";

		cin >> sel;

		if (sel == 1) {
			cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ?";

			unsigned short sell;
			cin >> sell;
			cin.ignore(); // 입력 버퍼 관련으로 必

			switch (sell) {
			case 1:
			case 3: { // 책(1), 회화책(3)
				cout << "상품설명>>";
				string p_expl;
				getline(cin, p_expl);

				cout << "생산자>>";
				string p_maker;
				getline(cin, p_maker);

				cout << "가격>>";
				unsigned short p_price;
				cin >> p_price;
				cin.ignore(); // 입력 버퍼 관련으로 必

				cout << "책제목>>";
				string b_title;
				getline(cin, b_title);

				cout << "저자>>";
				string b_author;
				getline(cin, b_author);

				if (sell == 3) {
					cout << "언어>>";
					string b_len;
					getline(cin, b_len);

					cout << "ISBN>>";
					unsigned short b_ISBN;
					cin >> b_ISBN;

					ConversationBook* cb = new ConversationBook(p_expl, p_maker, p_price, b_title, b_author, b_ISBN, b_len);
					p[id++] = cb; // 업 캐스팅
					break;
				}

				cout << "ISBN>>";
				unsigned short b_ISBN;
				cin >> b_ISBN;
								

				Book *b = new Book(p_expl, p_maker, p_price, b_title, b_author, b_ISBN);
				p[id++] = b; // 업 캐스팅

				break;
			}
			case 2: { // 음악CD(2)
				cout << "상품설명>>";
				string p_expl;
				getline(cin, p_expl);

				cout << "생산자>>";
				string p_maker;
				getline(cin, p_maker);

				cout << "가격>>";
				unsigned short p_price;
				cin >> p_price;
				cin.ignore(); // 입력 버퍼 관련으로 必

				cout << "앨범제목>>";
				string s_title;
				getline(cin, s_title);

				cout << "가수>>";
				string s_author;
				getline(cin, s_author);

				CompactDisc *c = new CompactDisc(p_expl, p_maker, p_price, s_title, s_author);
				p[id++] = c; // 업 캐스팅
				break;
			}
			default: {				
				break;
			} // default end				
			} // switch end
		} // if end
		else if (sel == 2) { // 모든 상품 조회
			for (unsigned short i = 0; i < id; i++) {
				cout << "--- 상품 ID : " << i << endl;
				p[i]->show();
				continue;
			} // for end
		}
		else break;
	} // while end
}