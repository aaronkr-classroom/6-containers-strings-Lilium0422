#include "Student_info.h"

bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name; // True or False
}

istream& read(istream& is, Student_info& s) { // �����ϴ� ������ ���ϰ��� 2���̻��̶�
	//�л��� �̸�, �߰���� ����, �⸻��� ���� �о� ����
	is >> s.name >> s.midterm >> s.final;
	//���� ������ ����
	read_hw(cin, s.homework);
	return is; // return is , s; << in Python
}

// �Է� ��Ʈ������ ���� ������ �о vector<double>�� ����.
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		//���� ������ ����
		hw.clear();

		//���� ������ ����
		double x; // cin���� ����ϱ� 

		//�Һ��� :  homework�� ���ݱ��� �Է¹��� ���� ������ ����.
		while (in >> x) {
			hw.push_back(x);
		}
		//���� �л��� ���� �Է� �۾��� ����� ��Ʈ���� ����
		in.clear();
	}
	return in;
}