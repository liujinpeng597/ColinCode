//#include<iostream>
//#include<list>
//#include<string>
//#include<random>
//using namespace std;
//
//struct Person {
//	string name;
//	int age;
//	int salary;
//	Person():age(0),salary(0){}
//};
//
//void printList(const list<Person*> lst) {
//	for (const Person* p : lst) {
//		cout << p->name << "," << p->age << "," << p->salary << endl;
//	}
//}
//
////自定义规则函数: bool(Person*,Person*)
//bool salaryAsc(Person* p1, Person* p2) {
//	return p1->salary < p2->salary;
//}
//
//bool ageDesc(Person* p1,Person* p2) {
//	return p1->age > p2->age;
//}
//
//bool rule(Person* p1) {
//	return p1->age > 30 && p1->salary<4000;
//}
//
//int main() {
//	random_device rd;
//	list<Person*>lst;
//	for (int i = 0; i < 10; i++) {
//		Person *per = new Person;
//		per->name = "张三" + to_string(i);
//		per->age = rd() % 21 + 20;
//		per->salary = rd() % 8001 + 1000;
//		lst.push_back(per);
//	}
//	cout << "---按工资升序排序---" << endl;
//	lst.sort(&salaryAsc); //按照我指定的规则排序
//	printList(lst);
//	cout << "--------------------" << endl;
//	cout << endl;
//	//遍历找到5000分界点
//	list<Person*>::iterator it = lst.begin();
//	while (it != lst.end()) {
//		if ((*it)->salary >= 5000) {
//			break;
//		}
//		it++;
//	}
//	cout << "-----五千分界点-----" << endl;
//	cout << (*it)->name << ","
//		<< (*it)->age << ","
//		<< (*it)->salary <<endl;
//	cout << "--------------------" << endl;
//	cout << endl;
//	cout << "--将大于五千的切割--" << endl;
//	list<Person*>tempLst;
//	tempLst.splice(tempLst.begin(), lst, it, lst.end());
//	printList(tempLst);
//	cout << "--------------------" << endl;
//	cout << endl;
//	cout << "将大于五千的按年龄降序排序" << endl;
//	tempLst.sort(&ageDesc);
//	printList(tempLst);
//	cout << "--------------------------" << endl;
//	cout << endl;
//	cout << "---将大于五千的放在表后---" << endl;
//	lst.insert(lst.end(), tempLst.begin(), tempLst.end());
//	printList(lst);
//	cout << "--------------------------" << endl;
//	cout << endl;
//	cout << "---将符合条件的人员移除---" << endl;
//	lst.remove_if(&rule);
//	printList(lst);
//	cout << "--------------------------" << endl;
//	cout << endl;
//	return 0;
//}