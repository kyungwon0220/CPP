#include "DynamicMemoryAssignment.h"

int main() {
    char test1[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', '!', '!', '\0' };
    char test2[15] = { 's', 'e', 't', 'S', 't', 'r', 'i', 'n', 'g', 'T', 'E', 'S', 'T', '!', '\0' };
    char test3 = 'K';
    char test4[1101] = {'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'C',
                        'T', 'E', 'A', 'F', 'Q', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b',
                        'a', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'a', '2', '3', '4', '5', '6', '7', '8', '9', 'E', '\0'};

    char* p = new char[10];
    for (int i = 0; i <= 8; i++) p[i] = i + 65;
    p[9] = '\0';

    MyString testS1;
    MyString testS2('Y');
    MyString testS3(test1);
    MyString testS4(testS3);
    
    
    std::cout << "생성자, << cout Test**********" << std::endl;
    std::cout << "test1:" << testS1 << ", len:" << testS1.getLength() << std::endl;
    std::cout << "test2:" << testS2 << ", len:" << testS2.getLength() << std::endl;
    std::cout << "test3:" << testS3 << ", len:" << testS3.getLength() << std::endl;
    std::cout << "test4:" << testS4 << ", len:" << testS4.getLength() << std::endl;


    std::cout << std::endl << std::endl << "set / getString(), print(), prinln() Test**********" << std::endl;
    testS1.setString(test2);
    for (unsigned short i = 0; i < testS1.getLength(); i++) {
        std::cout << *(testS1.getString()+i) << ", ";
    }
    std::cout << std::endl;
    std::cout << testS1 << std::endl;
    testS1.println();
    testS1.print();


    std::cout << std::endl << std::endl << "insert Test**********" << std::endl;
    testS1.insert(1, 'K');
    testS1.println();    
    testS1.insert(5, 3, 'A');    
    testS1.println();
    testS1.insert(0, "XXXXX");    
    testS1.println();
    testS1.insert(4, 3, "FFFFFFFFFF");    
    testS1.println();
    testS1.insert(5, testS1);
    std::cout << "test1:" << testS1 << ", len:" << testS1.getLength() << std::endl;
    testS1.insert(0, testS4, 5, 4);
    std::cout << "test1:" << testS1 << ", len:" << testS1.getLength() << std::endl;


    std::cout << std::endl << std::endl << "at, [] Test**********" << std::endl;
    testS1.println();
    std::cout << testS1[8] << std::endl;
    std::cout << testS1.at(9) << std::endl;


    std::cout << std::endl << std::endl << "reverse() Test**********" << std::endl;
    testS3.println();
    testS3.reverse();
    testS3.println();


    std::cout << std::endl << std::endl << "append Test**********" << std::endl;
    testS1.println();
    testS1.append('O', 3);
    testS1.println();
    testS1.append(test1);
    testS1.println();
    testS1.append(test1, 5, 3);
    testS1.println();
    testS1.append(testS2);
    testS1.println();
    testS1.append(testS1, 10, 3);
    testS1.println();


    std::cout << std::endl << std::endl << "clear() Test**********" << std::endl;
    testS1.clear();
    testS2.clear();
    testS3.clear();
    testS1.println();
    testS2.println();
    testS3.println();


    std::cout << std::endl << std::endl << "=, += Test**********" << std::endl;
    testS1 = test1;
    testS2 = test2;
    testS3 = testS1;
    testS1.println();
    testS2.println();
    testS3.println();
    testS1 += testS2;
    testS2 += "JJJ";
    std::cout << "test1:" << testS1 << ", len:" << testS1.getLength() << std::endl;
    std::cout << "test2:" << testS2 << ", len:" << testS2.getLength() << std::endl;
    std::cout << "test3:" << testS3 << ", len:" << testS3.getLength() << std::endl;


    std::cout << std::endl << std::endl << "replace() Test**********" << std::endl;
    testS1.println();
    testS1.replace(5, 5, 10, 'Q');
    testS1.println();
    testS1.replace(5, 20, test1);
    testS1.println();
    testS1.replace(3, 10, test2, 5);
    std::cout << "test1:" << testS1 << ", len:" << testS1.getLength() << std::endl;
    testS1.replace(1, 7, test2, 5, 5);
    std::cout << "test1:" << testS1 << ", len:" << testS1.getLength() << std::endl;
    testS1.replace(2, 10, testS2);
    std::cout << "test1:" << testS1 << ", len:" << testS1.getLength() << std::endl;
    testS1.replace(1, 10, testS3, 4, 3);
    std::cout << "test1:" << testS1 << ", len:" << testS1.getLength() << std::endl;


    std::cout << std::endl << std::endl << "substr Test**********" << std::endl;
    testS1 = test4;
    std::cout << "test1:" << testS1 << ", len:" << testS1.getLength() << std::endl;
    std::cout << "test4:" << testS4 << ", len:" << testS4.getLength() << std::endl;
    testS4 = testS1.substr(999, 10);
    std::cout << "test1:" << testS1 << ", len:" << testS1.getLength() << std::endl;
    std::cout << "test4:" << testS4 << ", len:" << testS4.getLength() << std::endl;


    std::cout << std::endl << std::endl << "assign Test**********" << std::endl;
    testS4.assign(3, 'F');
    std::cout << "test4:" << testS4 << ", len:" << testS4.getLength() << std::endl;
    testS4.assign(test1);
    std::cout << "test4:" << testS4 << ", len:" << testS4.getLength() << std::endl;
    testS4.assign(test1, 3, 3);
    std::cout << "test4:" << testS4 << ", len:" << testS4.getLength() << std::endl;
    testS4.assign(testS2);
    std::cout << "test4:" << testS4 << ", len:" << testS4.getLength() << std::endl;
    // testS4.assign(testS1, 3, 4);
    std::cout << "test4:" << testS4 << ", len:" << testS4.getLength() << std::endl;


    std::cout << std::endl << std::endl << "compare Test**********" << std::endl;
    std::cout << testS4.compare("setStringTEST!JJJK") << std::endl;
    std::cout << testS4.compare("setStringTEST!JJ") << std::endl;
    std::cout << testS4.compare("setStringTEST!JJJ") << std::endl;
    std::cout << testS4.compare("setStringTEST!JJK") << std::endl;
    std::cout << testS4.compare("setStringTEST!JJI") << std::endl;
    std::cout << testS4.compare("setStringTEST!JJIK") << std::endl;
    std::cout << testS4.compare(testS4) << std::endl;


    std::cout << std::endl << std::endl << "이동 생성자 Test**********" << std::endl;
    std::cout << "test4:" << testS4 << ", len:" << testS4.getLength() << std::endl;
    MyString testS5 = std::move(testS4);
    std::cout << "test4:" << testS4 << ", len:" << testS4.getLength() << std::endl;
    std::cout << "test5:" << testS5 << ", len:" << testS5.getLength() << std::endl;
    testS4.append("abc");
    std::cout << "test4:" << testS4 << ", len:" << testS4.getLength() << std::endl;
    std::cout << "test5:" << testS5 << ", len:" << testS5.getLength() << std::endl;
}
