#include <bits/stdc++.h>
using namespace std;

class User {
    int user_id;
    string Username;
    string Password;
    public: vector<int>ArticleIDs;

    public:
        void SetUsername(string _username) { Username = _username; }
        void SetPassword(string _password) { Password = _password; }
        void SetUserId(int _user_id) { user_id = _user_id; }
        int GetUserId() { return user_id; }


    friend class Article;
};
//User Users[100];
vector<User> Users;
int UserCount = 0;

class Article {
    int ArticleId;
    string ArticleTitle;
    User Author;
    string Content;
    int ArticleCode;
    bool Acception;

    public:
        void SetTitle(string _title) { ArticleTitle = _title; }
        void SetArticleId(int _articleId) { ArticleId = _articleId; }
        void SetContent(string _content) { Content = _content; }
        void SetArticleCode(int _articleCode) { ArticleCode = _articleCode;}
        bool IsArticleValid() {
            return true;
            
        }
          

   friend class User;
   friend bool ValidateArticle(Article a);
};
//Article Articles[100];
vector <Article> Articles;
int ArticleCount = 0;


void RegisterUser() {
    cout << "USER REGISTER PAGE" << endl;
    User tempUser;
    cout << "Username: ";
    string name;
    cin >> name;
    tempUser.SetUsername(name);
    cout << "Password: ";
    string pass;
    cin >> pass;
    tempUser.SetPassword(pass);
    cout << "Register Done!";
    tempUser.SetUserId(UserCount++);
    Users[UserCount] = tempUser;
}
void LoginUser() {} // COMPLETE THIS FUCKIN TASK

void RegisterArticle() {
    cout << "ARTICLE REGISTER PAGE" << endl;
    Article tempArticle;

    cout << "Title: ";
    string title;
    cin >> title;
    tempArticle.SetTitle(title);
    cout << "Article Code: ";
    int code;
    cin >> code;
    tempArticle.SetArticleCode(code);
    tempArticle.SetArticleId(ArticleCount++);
    Articles[ArticleCount] = tempArticle;
    cout << "Register Done!";
    //tempArticle.Author.ArticleIDs(articleCount++);
}
bool ValidateArticle(Article article) {
            bool validTitle;
            bool validateContent;
            
        } 





int main() {
    cout << "WELCOME TO ARTICLE EVAL SYSTEM" << endl;
    firstpage:
    cout << "1. Sign Up\t2. Login" << endl;
    int command;
    cin >> command;
    switch(command) {
        case 1:
            RegisterUser();
            //goto login;
        case 2:
            LoginUser();
            goto panel;
        default:
            cout << "Error: Unknown command!!";
            goto firstpage;
    }
    panel:
        cout << "Panel";
    

    

    
}