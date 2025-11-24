using namespace std;
#include <iostream>
#include<string>

// max size of history stack
const int Max_history=100;

// implemneting stack for browsing history
class BrowserHistory {
private:
	string history[Max_history];
	int top;
public:
	BrowserHistory() {
		top=-1;
	}

	// pushing url to histroy
	void visitPage(const string& url) {
		if (top>=Max_history-1) {
			cout<<"History is full. Cannot visit new page.\n";
			return ;
		}
		history[++top]=url;
		cout<<"visited: "<<url<<endl;
	}

	void goBack() {
		if (top<=0) {
			cout<<"No previos page to go back to."<<endl;
			return ;
		}
		top--;
		cout<<"Went back to: "<<history[top]<<endl;
	}

	void currentPage() {
		if (top==-1) {
			cout<<"No page visited yet."<<endl;
		}
		else {
			cout<<"Current Page: "<<history[top]<<endl;
		}
	}
};

int main()
{
	BrowserHistory bh;
	int choice;
	string url;
	do {
		cout<<endl<<"----- Browser History Manager ------"<<endl;;
		cout<<"1. Visit New PAge"<<endl;
		cout<<"2. Go Back"<<endl;
		cout<<"3. Show current Page"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter Choice: ";
		cin>>choice;
		switch(choice) {
		case 1:
			cout<<"Enter url: ";
			cin>>url;
			bh.visitPage(url);
			break;
		case 2:
			bh.goBack();
			break;
		case 3:
			bh.currentPage();
			break;
		case 4:
			cout<<"Exiting Browser History Manager"<<endl;
			break;
		default:
			cout<<"Invalid choice. Try again."<<endl;

		}
	}
	while(choice!=4);

	return 0;
}