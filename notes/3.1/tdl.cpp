
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Item{
	private:
		string description;
		bool isComplete;
	public:
		Item(){};
		void ChangeDescription(string s){
		this->description = s;
		}
		string GetDesc(){ return description;}
};


class List{
	private:
	int selection;
	vector<Item> itemVect;
	vector<Item>::iterator it;
	void HandleSelection(){
		system("clear");
		switch(selection){
		case 1:
			AddItem();
			break;
		case 2:
			break;
		default:
			break;
		}
		system("clear");
		DisplayList();
	}
	public:
	List(){
	string s;
	ifstream outfile("file.txt");
	if(outfile.is_open()){
	while(getline(outfile,s)){
		Item i;
		i.ChangeDescription(s);
		itemVect.push_back(i);
	}
	}

	}
	~List(){
	system("rm file.txt");
	system("touch file.txt");
	ofstream infile("file.txt");
	if(infile.is_open()){
		while(infile.is_open()){
		for(it = itemVect.begin(); it!= itemVect.end();it++){
		infile<<it->GetDesc()<<endl;
		}
		infile.close();
		}
	}
	}
	void WelcomeMessage(void){
	system("clear");
	cout<<"\n\nWelcome to all the work you have to do"<<endl;
	DisplayList();
	}
	int Selection(void){
	cout<<"\n\nPlease select an option."<<endl;
	cin>>this->selection;
	this->HandleSelection();
	return selection;
	}
	void AddItem(){
	Item newItem;
	string s;
	cout<<"\n\nPlease Enter Your Description\n\n";
	while(getchar()!='\n');
	getline(cin,s);
	newItem.ChangeDescription(s);
	itemVect.push_back(newItem);
	}
	void DisplayList(){
	cout<<"\n\n___________________________________________\n";
	for (it = itemVect.begin(); it!= itemVect.end(); it++){
	cout<<it->GetDesc()<<endl;
	}
	cout<<"______________________________________________";
	}
/*
weionviwenvoienv'oiwenvoiernvioen
*/
};
int main(){
int s;
List list1;
list1.WelcomeMessage();
s=list1.Selection();

while(s!=0){


s = list1.Selection();
system("clear");
}
system("clear");
cout<<"\n\nGoodbye\n\n"<<endl;
}
