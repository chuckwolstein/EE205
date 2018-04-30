
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
		//cout<<selection<<endl;
		switch(selection){
		case 1:
			AddItem();
			break;	
		case 2:
			break;
		default:
			break;
		}
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
	cout<<"Welcome to all the work you have to do"<<endl;
	}
	int Selection(void){
	cout<<"Please select an option."<<endl;
	cin>>this->selection;
	this->HandleSelection();
	return selection;
	}
	void AddItem(){
	Item newItem;
	string s;
	cout<<"Please Enter Your Description without spaces"<<endl;
	cin>>s;
	newItem.ChangeDescription(s);
	itemVect.push_back(newItem);
	for(it = itemVect.begin(); it!= itemVect.end();it++){
		cout<<it->GetDesc()<<endl;
	}
	}
};
int main(){
int s;
List list1;
list1.WelcomeMessage();
s=list1.Selection();

while(s!=0){


s = list1.Selection();
}

cout<<"Goodbye"<<endl;
}
