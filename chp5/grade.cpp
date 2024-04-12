// grade.cpp
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include <list>
#include <vector>
#include <stdexcept>

//학생의 과락 여부를 설정하는 서술 함수
bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

double grade(double mt, double ft, double hw) {
	return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}


double grade(double mt, double ft, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("No homework!");

	return grade(mt, ft, median(hw));
}

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}

// 세 번째 버전 :
// 인덱스 대신 반복자를 사용하지만 여전히
// 성능 저하가 우려됨.
list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();
	
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter); // 역참조 : 반복자의 값
			iter = students.erase(iter); // 반복자의 메모리 위치 삭제
		}
		else {
			++iter;
		}
	}	
	return fail;
}
