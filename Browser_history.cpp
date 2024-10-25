#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BrowserHistory {
private:
    stack<string> backHistory;    
    stack<string> forwardHistory; 
    string currentPage;           

public:
    BrowserHistory() {
        currentPage = "Home"; 
    }

    
    void visitPage(const string &page) {
        if (!currentPage.empty()) {
            backHistory.push(currentPage);  
        }
        currentPage = page;              
        while (!forwardHistory.empty()) {
            forwardHistory.pop();
        }
        displayCurrentPage();
    }

   
    void goBack() {
        if (backHistory.empty()) {
            cout << "No pages to go back to!" << endl;
        } else {
            forwardHistory.push(currentPage); 
            currentPage = backHistory.top(); 
            backHistory.pop();               
            displayCurrentPage();
        }
    }

    
    void goForward() {
        if (forwardHistory.empty()) {
            cout << "No pages to go forward to!" << endl;
        } else {
            backHistory.push(currentPage);   
            currentPage = forwardHistory.top(); 
            forwardHistory.pop();            
            displayCurrentPage();
        }
    }
    void displayCurrentPage() {
        cout << "Current Page: " << currentPage << endl;
    }
};

int main() {
    BrowserHistory browser; 
    int choice;
    string page;

    while (true) {
        cout << "\n1. Visit Page\n2. Go Back\n3. Go Forward\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the page name to visit: ";
            cin >> page;
            browser.visitPage(page);
            break;
        case 2:
            browser.goBack();
            break;
        case 3:
            browser.goForward();
            break;
        case 4:
            cout << "Exiting the browser." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
