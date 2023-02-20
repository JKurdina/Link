#include <iostream>
#include <fstream>
using namespace std;

struct Link {
	int val;
	Link* next;
	Link(int _v, Link* _n = nullptr) : val(_v), next(_n) {};
};

class List {
	Link* start;
public:
	List() {
		start = new Link(0);
		start->next = start;
	}

	void add(int a) {
		Link* tmp = start;
		while (tmp->next != start) {
			if (tmp->next->val > a) {
				Link* b = new Link(a, tmp->next);
				tmp->next = b;
				return;
			}
			tmp = tmp->next;
		}
		Link* c = new Link(a, start);
		tmp->next = c;
	}

	void clean() {
		Link* tmp = start->next;
		while (tmp->next != start) {
			Link* a = tmp->next;
			start->next = tmp->next;
			delete tmp;
			tmp = a;
		}
	}

	List peresechenie(List list_2, List list_3) {
		Link* a = start->next;
		Link* b = list_2.start->next;
		Link* c = list_3.start->next;

		while ((a != start) || (b != list_2.start)) {
			if (a->val > b->val) {
				b = b->next;
			}
			else if(a->val < b->val) {
				a = a->next;
			}
			else {
				if (a->next->val == a->val) {             //чтобы избежать повторений
					a = a->next;
					continue;
				}
				else if (b->next->val == b->val) {
					b = b->next;
					continue;
				}
				else {
					list_3.add(a->val);
					a = a->next;
					b = b->next;
				}
			}
		}
		return list_3;
	}

	friend ostream& operator<<(ostream& out, List& list) {
		Link* tmp = list.start->next;
		while (tmp != list.start) {
			out << tmp->val<< " ";
			tmp = tmp->next;
		}
		out << "$";
		return out;
	}

	friend istream& operator>>(istream& in, List& list) {
		list.clean();
		string tmp;
		in >> tmp;
		string sep = "$";
		while (tmp != sep) {
			list.add(atoi(tmp.c_str()));
			in >> tmp;
		}
		return in;
	}
};

int main() {
	List list_1, list_2, list_3;

	ifstream file_1("List.txt");
	file_1 >> list_1;
	cout << list_1 << endl;

	
	
	list_2.add(5);
	list_2.add(15);
	list_2.add(15);
	list_2.add(3);
	list_2.add(3);
	cout << list_2 << endl;

	list_3 = list_1.peresechenie(list_2, list_3);
	cout << list_3 << endl;

	ofstream file_3("List_1.txt");
	file_3 << list_3;
	file_3.close();


}